class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> sFreqMap;

        int sSize = s.length();
        for (int i = 0; i < sSize; i++) {
            sFreqMap[s[i]]++;
        }

        int tSize = t.length();
        for (int i = 0; i < tSize; i++) {
            sFreqMap[t[i]]--;
            if (sFreqMap[t[i]] < 0) {
                return t[i];
            }
        }
        return '?';
    }
};