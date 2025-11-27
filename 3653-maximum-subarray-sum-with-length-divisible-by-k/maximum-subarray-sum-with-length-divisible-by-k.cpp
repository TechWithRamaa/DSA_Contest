class Solution {
public:
    // Length that are divisible by k can be multiple like k, 2k, 3k, 4k, etc
    long long maxSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<long long> minPrefix(k, LLONG_MAX);

        long long prefix = 0;
        long long ans = LLONG_MIN;

        minPrefix[0] = 0;

        for(int i = 1; i <= N; i++) {
            prefix += nums[i-1];
            int rem = i % k;

            if(minPrefix[rem] != LLONG_MAX) {
                ans = max(ans, prefix - minPrefix[rem]);    // prefix[4] - smallest previous
            }

            minPrefix[rem] = min(minPrefix[rem], prefix);   // live calculation
        }

        return ans;
    }
};