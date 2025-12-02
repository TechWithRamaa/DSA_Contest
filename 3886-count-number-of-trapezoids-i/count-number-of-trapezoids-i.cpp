class Solution2 {
public:
    int countTrapezoids2(vector<vector<int>>& points) {
        // Each valid pair must have same y -> horizontal segment
        // So group points by y-coordinate
        unordered_map<int, vector<int>> mp;
        for(auto &p : points) {
            int x = p[0], y = p[1];
            mp[y].push_back(x);
        }

        long long count = 0;

        // For every distinc y-layer
        for(auto &entry : mp) {
            auto &xs = entry.second; // vector

            if(xs.size() < 2) 
                continue;
            
            sort(xs.begin(), xs.end()); // sort x so we can iterate segments

            // Create sweep-line events
            
            // segment = [xs[i], xs[j]]
            vector<pair<int,int>> events; 
            int n = xs.size();

            // A horizontal segment is formed by any pair (i < j)
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int L = xs[i];
                    int R = xs[j];
                    events.push_back({L, +1}); // segment start
                    events.push_back({R, -1}); // segment end
                }
            }

             // Sort events by x, but starts (+1) must come before ends (-1)
            sort(events.begin(), events.end(),
                [](auto &a, auto &b) {
                    if (a.first == b.first)
                        return a.second > b.second;
                    return a.first < b.first;
                }
            );

            long long active = 0;

            // Sweep-line to count overlapping segments
            for (auto &e : events) {
                int type = e.second;
                if (type == +1) {
                    count += active; // every active segment forms an overlap
                    active++;
                } else {
                    active--;
                }
            }

        }

        return count;
    }
};

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        const int mod = 1e9 + 7;
        long long ans = 0, sum = 0;
        for (auto& point : points) {
            pointNum[point[1]]++;
        }
        for (auto& [_, pNum] : pointNum) {
            long long edge = (long long)pNum * (pNum - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % mod;
    }
};