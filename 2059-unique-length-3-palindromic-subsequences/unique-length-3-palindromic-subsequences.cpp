class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> frequencyArray(26, 0);
        int sSize = s.size();

        for (char c : s) {
            frequencyArray[c - 'a']++;
        }

        vector<bool> seenSet(26, false);
        bool countingSet[26][26] = {false};
        // countingSet[alphabet][mid]

        int palindromeCount = 0;
        for (int i = 0; i < sSize; i++) {
            int midS = s[i] - 'a';
            frequencyArray[midS]--;

            for (int c = 0; c < 26; c++) {
                if (seenSet[c] && frequencyArray[c] > 0 &&
                    !countingSet[c][midS]) {
                    palindromeCount++;
                    countingSet[c][midS] = true;
                }
            }
            seenSet[midS] = true;
        }

        return palindromeCount;
    }
};
