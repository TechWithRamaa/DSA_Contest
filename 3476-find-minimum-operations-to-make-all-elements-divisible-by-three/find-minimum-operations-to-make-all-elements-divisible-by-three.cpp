class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minimumOperations = 0;

        for(int n : nums) {
            if(n % 3 == 0) {
                continue;
            } else if (n % 3 == 1 || n % 3 == 2) {
                minimumOperations++;
            }
        }

        return minimumOperations;
    }
};