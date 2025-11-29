class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int r = sum % k;
        if(r == 0)
            return 0;
        
        return r;
    }
};