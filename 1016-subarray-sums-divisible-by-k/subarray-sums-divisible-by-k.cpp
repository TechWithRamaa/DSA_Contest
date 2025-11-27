class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modMap;
        // map <runningSumThatIsDivisibleByK, noOfSubaarays>
        // there can be multiple xK that satisifes this like k, 2k, 3k, 4k, ...

        int result = 0;
        int runningSum = 0;
        modMap[0] = 1;

        for(auto num : nums) {
            runningSum += num;

            // Handles negative values safely
            // Always returns a number in [0, k-1]
            // Common trick used in hashing, prefix mod, and circular array problems.
            // (-2 % 5 + 5) % 5 == (−2 + 5) % 5 == 3 % 5 == 3
            int mod = (runningSum % k + k) % k; // group modulo, bucketing
            if(modMap.count(mod))
                result += modMap[mod];

            modMap[mod]++; // increment the count of subarrays for the current modulo group
        }

        return result;
    }
};