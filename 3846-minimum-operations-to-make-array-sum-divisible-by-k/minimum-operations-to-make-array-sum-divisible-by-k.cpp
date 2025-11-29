class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int r = ((sum % k) + k) % k; // safe modulo => use it when numerator can take negative values, and when result should not be negative
        if(r == 0)
            return 0;
        
        return r;
    }
};