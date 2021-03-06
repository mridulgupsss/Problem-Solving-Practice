class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& A, int change, int numLaps) {
        int N = A.size(), len = 0;
        vector<long> best(numLaps, LONG_MAX), dp(numLaps + 1, INT_MAX);
        for (int i = 0; i < N; ++i) {
            long f = A[i][0], r = A[i][1], sum = change, p = 1; // We assume we also need `change` time to use the first tire so that we don't need to treat the first tire as a special case
            for (int j = 0; j < numLaps; ++j) {
                sum += f * p;
                if (f * p >= f + change) break; // If using the same tire takes no less time than changing the tire, stop further using the current tire
                best[j] = min(best[j], sum);
                len = max(len, j + 1);
                p *= r;
            }
        }
        dp[0] = 0; // dp[i + 1] is the minimum time to finish `numLaps` laps
        for (int i = 0; i < numLaps; ++i) {
            for (int j = 0; j < len && i - j >= 0; ++j) { // try using the same tire in the last `j+1` laps
                dp[i + 1] = min(dp[i + 1], dp[i - j] + best[j]);
            }
        }
        return dp[numLaps] - change; // minus the `change` we added to the first tire
    }
};