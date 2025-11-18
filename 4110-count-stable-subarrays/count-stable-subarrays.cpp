class Solution {
public:
    /*
    A stable subarray means:

    For every i < j, nums[i] ≤ nums[j]
    In other words → the subarray is non-decreasing.

    So we must count how many non-decreasing contiguous subarrays exist.
    */
    vector<long long> countStableSubarrays(vector<int>& nums,
                                           vector<vector<int>>& queries) {
        int n = nums.size();

        // -------- 1) Build maximal non-decreasing segments --------
        struct Seg {
            int L, R;
            long long val;
        };
        vector<Seg> segs;

        int start = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) { // break of "stable" region
                int L = start, R = i - 1;
                long long len = R - L + 1;
                segs.push_back({L, R, len * (len + 1) / 2});
                start = i;
            }
        }

        // last segment
        {
            int L = start, R = n - 1;
            long long len = R - L + 1;
            segs.push_back({L, R, len * (len + 1) / 2});
        }

        int S = segs.size();

        // -------- 2) Prepare arrays for binary search and prefix sums --------
        vector<int> segL(S), segR(S);
        vector<long long> pref(S);

        for (int i = 0; i < S; i++) {
            segL[i] = segs[i].L;
            segR[i] = segs[i].R;
            pref[i] = segs[i].val + (i ? pref[i - 1] : 0);
        }

        // helper: find segment index that contains x
        auto findSeg = [&](int x) {
            int idx =
                upper_bound(segL.begin(), segL.end(), x) - segL.begin() - 1;
            return idx;
        };

        // -------- 3) Answer queries --------
        vector<long long> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int sL = findSeg(l);
            int sR = findSeg(r);

            if (sL == sR) {
                // whole query lies inside one stable segment
                long long len = r - l + 1;
                ans.push_back(len * (len + 1) / 2);
                continue;
            }

            // left partial segment
            long long leftLen = segR[sL] - l + 1;
            long long leftVal = leftLen * (leftLen + 1) / 2;

            // right partial segment
            long long rightLen = r - segL[sR] + 1;
            long long rightVal = rightLen * (rightLen + 1) / 2;

            // segments fully between sL and sR
            long long midVal = 0;
            if (sR - sL > 1) {
                midVal = pref[sR - 1] - pref[sL];
            }

            ans.push_back(leftVal + midVal + rightVal);
        }

        return ans;
    }
};

/*
    If the problem was just asking count of subarrays that satisfy stable
property

    long long countStableSubarrays(vector<int>& nums) {
    long long ans = 0;
    long long run = 1;  // at least each single element is stable

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] >= nums[i-1]) {
            run++;  // extend the stable run
        } else {
            ans += run * (run + 1) / 2; // add all subarrays in this run
            run = 1; // reset
        }
    }

    // don't forget the last run
    ans += run * (run + 1) / 2;

    return ans;

    TC ~ O(N) and SC ~ O(1)
}

*/