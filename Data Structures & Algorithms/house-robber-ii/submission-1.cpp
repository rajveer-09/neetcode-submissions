class Solution {
public:
    int robb(vector<int>& nums, int st, int n) {
        vector<int> dp(n);
        dp[st] = nums[st];
        
        if(n == st + 1) return dp[st];

        dp[st + 1] = max(nums[st], nums[st+1]);

        // ans(n) = Max(ans(n - 1), ans(n - 2) + nums[i])

        for(int i = st + 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        // case 1 : 0 ---  n-1
        // case 2: 1 --- n
        // ek hi vector ki do -> do kyuki different cases completely run horhe

        return max(robb(nums, 0, n-1), robb(nums, 1, n));
    }
};
