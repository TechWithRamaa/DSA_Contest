class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] != b[1]) 
                return a[1] < b[1]; // sort by end ascending
            return a[0] > b[0];    // start descending
        });

        int p1 = -1, p2 = -1;  // last two selected points
        int ans = 0;

        for (auto &in : intervals) {
            int l = in[0], r = in[1];

            bool p1In = (p1 >= l && p1 <= r);
            bool p2In = (p2 >= l && p2 <= r);

            if (p1In && p2In) {
                continue;
            }
            else if (p2In) {
                // add one point
                ans++;
                p1 = p2;
                p2 = r;
            }
            else {
                // add two points
                ans += 2;
                p1 = r - 1;
                p2 = r;
            }
        }
        return ans;
    }
};
