class Solution {
public:
    int minimumFlips(int n) {
        string s = "";

        while(n > 0) {
            s += char('0' + (n % 2));
            n /= 2;
        }

        string revString = s;
        reverse(revString.begin(), revString.end());

        int flips = 0;
        int length = s.size();
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != revString[i])
                flips++;
        }
    
        return flips;
    }
};


// 7
//  1 1 1
//  4 2 1

// 10
// 1 0 1 0
// 8 4 2 1

// 0 1 0 1