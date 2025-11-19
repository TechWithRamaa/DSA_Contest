class Solution {
public:
    int lengthOfLastWordSS(string s) {
        stringstream ss(s);
        string word, last;

        while (ss >> word) {
            last = word;
        }

        return last.size();
    }

    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

        while(i >= 0 && s[i] == ' ') {
            // skip trailing spaces
            i--;
        }

        int wordSize = 0;

        while(i >= 0 && s[i] != ' ') {
            wordSize++;
            i--;
        }

        return wordSize;
    }
};