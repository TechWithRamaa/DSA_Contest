class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minimumOperations = 0;

        for(int n : nums) {
            if(n % 3 != 0) {
                minimumOperations++;
            }      
        }

        return minimumOperations;
    }
};