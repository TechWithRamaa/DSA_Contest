class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> newNums(2*n, 0);
        int nI = 0;
        for(int i = 0; i < n; i++) {
            newNums[nI] = nums[i];
            newNums[nI+1] = nums[i+n];
            nI+=2;
        }

        return newNums;
    }
};