class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for(int x : nums) {
            if(isBinPalindrome(x)) {
                ans.push_back(0);
                continue;
            }

            int d = 1;
            while(true) {
                if(isBinPalindrome(x + d)) {
                    ans.push_back(d);
                    break;
                }
                if((x - d >= 0) && isBinPalindrome(x - d)) {
                    ans.push_back(d);
                    break;
                }
                d++;
            }
        }

        return ans;
    }
private: 
    bool isBinPalindrome(int x) {
        string s;
        
        while(x > 0) {
            s.push_back((x % 2) + '0');
            x /= 2;
        }

        if(s.empty()) s = "0";
        
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
};