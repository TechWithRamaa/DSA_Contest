class Solution {
public:
    int waviness(int x) {
        string s = to_string(x);
        int noOfDigits = s.size();
        
        if(noOfDigits < 3)
            return 0;

        int waviness = 0;
        for(int i = 1; i < noOfDigits - 1; i++) {
            if(s[i] > s[i - 1] && s[i] > s[i + 1])
                waviness++;
            else if(s[i] < s[i - 1] && s[i] < s[i + 1])
                waviness++;
        }

        return waviness;
    }

     int totalWaviness(int num1, int num2) {
         int totalWaviness = 0;
         for(int s = num1; s <= num2; s++) {
             totalWaviness += waviness(s);
         }
         return totalWaviness;
     }
};