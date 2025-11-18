class Solution {
public:
    // intuition is skipping bits smartly - no need to iterate through the whole array
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, N = bits.size();

        // go till second last
        while(i < N - 1) {
            if(bits[i] == 1)
                i += 2;
            else 
                i += 1;
        }

        return i == N - 1; // if i is parked at last index
    }

     bool isOneBitCharacter2(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            i += bits[i] + 1;
        }
        return i == bits.size() - 1;
    }
};

    