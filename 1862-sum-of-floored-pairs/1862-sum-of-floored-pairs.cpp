class Solution {
public:
    int sumOfFlooredPairs(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size(), ans = 0;
        sort(begin(A), end(A));
        for (int i = 0; i < N; ) {
            long j = i + 1;
            while (j < N && A[j] == A[j - 1]) ++j; // skip the duplicates of `A[i]`
            long dup = j - i;
            ans = (ans + dup * dup % mod) % mod; // the `dup` duplicates add `dup * dup` to the answer
            while (j < N) {
                long div = A[j] / A[i], bound = A[i] * (div + 1);
                long next = lower_bound(begin(A) + j, end(A), bound) - begin(A); // find the first number `A[next] >= A[i] * (div + 1)`
                ans = (ans + (next - j) * div % mod * dup % mod) % mod; // Each A[t] (j <= t < next) will add `div * dup` to the answer.
                j = next;
            }
            i += dup;
        }
        return ans;
    }
};