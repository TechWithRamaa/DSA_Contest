class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, -1000000000); // large negative
        dp[0] = 0;

        for (int x : nums) {
            vector<int> next = dp;

            for (int r = 0; r < 3; r++) {
                int newRem = (r + x) % 3;
                next[newRem] = max(next[newRem], dp[r] + x);
            }

            dp = next;
        }

        return dp[0];
    }
};