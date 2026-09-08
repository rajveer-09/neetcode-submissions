class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum & 1) return false;

        int tg = sum / 2;

        vector<vector<bool>>dp(tg + 1, vector<bool>(n, false));// target, lenght of array

        for(int i = 0; i < n; i++){
            dp[0][i] = true;
        }

   

        for(int t = 1; t <= tg; t++){
            for(int i = 1; i < n; i++){
                // take=
                if(t - nums[i] >= 0) dp[t][i] = dp[t - nums[i]][i - 1];
                // skip
                dp[t][i] = dp[t][i] | dp[t][i-1];
            }
        }
        

        return dp[tg][n-1];
    }
};
