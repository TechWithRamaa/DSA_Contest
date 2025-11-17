class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        // O(n)
        for (char c : word) 
            freq[c - 'a']++;

        // collect only nonzero frequencies
        vector<int> f;
        // O(26) = O(1)
        for (int x : freq) 
            if (x > 0) 
                f.push_back(x);

        // O(26 log 26) = O(1)
        sort(f.begin(), f.end()); // sorting helps limit the range of t

        int n = f.size();
        int ans = INT_MAX;

        // Try every frequency as a possible lower bound t
        // t will be chosen from the actual frequencies

        // O(26 × 26) = O(1)
        for (int t : f) {
            long long deletions = 0;

            for (int x : f) {
                if (x < t) {
                    // too small: delete everything
                    deletions += x;
                }  else if (x > t + k) {
                    // too large: trim down to (t+k)
                    deletions += x - (t + k);
                }
                // else inside [t, t+k]: keep fully
            }

            ans = min(ans, (int)deletions);
        }
        // O(n) + O(1) + O(1) + O(1)
        // = O(n)
        return ans;
    }
};


