class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost kaha se decide hoga jaha jarhe ya jaha se jarhe ?
        int n = cost.size();
        vector<int> dp(n); // cost to jump from ith index
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1], dp[i -2]) + cost[i];
        }

        return min(dp[n-2], dp[n-1]);
    }
};
