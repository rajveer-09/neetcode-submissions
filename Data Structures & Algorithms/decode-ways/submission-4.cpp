class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (s[0] == '0') return 0;
        if (n == 1) return 1;

        vector<int> dp(n, 0);

        // if s[i] != '0' -> ans[i] += ans[i-1];
        // if valid s(i-1) + s(i) && s[i-1] != '0' -> ans[i] += ans[i-2]

        dp[0] = 1;

        // First two characters
        if (s[1] == '0') {
            dp[1] = (s[0] == '1' || s[0] == '2') ? 1 : 0;
        } else {
            dp[1] = 1;
            if (stoi(s.substr(0, 2)) <= 26)
                dp[1] = 2;
        }

        for (int i = 2; i < n; i++) {

            // Take current character as one digit
            if (s[i] != '0')
                dp[i] += dp[i - 1];

            // Take current + previous as two digits
            if (s[i - 1] != '0' &&
                stoi(s.substr(i - 1, 2)) <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n - 1];
    }
};