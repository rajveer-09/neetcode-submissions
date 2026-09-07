class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        
        if(n == 1) return dp[0];

        dp[1] = max(nums[0], nums[1]);

        // ans(n) = Max(ans(n - 1), ans(n - 2) + nums[i])

        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};
