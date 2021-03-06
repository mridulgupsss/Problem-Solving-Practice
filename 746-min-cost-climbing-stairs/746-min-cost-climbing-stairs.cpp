class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1)return cost[0];
        if (n==2) return min(cost[0], cost[1]);
        vector<int> dp(n+1, 0);
        dp[1]=cost[0]; dp[2]=min(cost[0], cost[1]);
        dp[3]=min(dp[2]+cost[2], cost[1]); // because we can also start from index 1 ;
        for(int i=4; i<=n; i++)
        {
            dp[i]=min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};