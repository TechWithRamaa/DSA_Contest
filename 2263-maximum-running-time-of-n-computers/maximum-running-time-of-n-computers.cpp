class Solution {
private:
    bool isFeasibleForGiven(int n, vector<int>& batteries, long long predictedMaxNoOfTimes) {
        long long predictedTotalBatteryCapacity = n * predictedMaxNoOfTimes;
        long long have = 0;
        for(long long capacity : batteries) {
            have += min(capacity, predictedMaxNoOfTimes);
        }

        return have >= predictedTotalBatteryCapacity;
    }
public:
    // O(m).log(s/n)
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalBatteryCapacity = 0;
        for(int capacity : batteries) {
            totalBatteryCapacity += capacity;
        }

        long long low = 0, high = (totalBatteryCapacity / n);
        long long maximumNoOfTimes = 0;
        
        while(low <= high) { // O log(totalBatteryCapacity / n)
            long long mid = low + (high - low) / 2;
            long long predictedMaximumNoOfTimes = mid;

            bool verdict = isFeasibleForGiven(n, batteries, predictedMaximumNoOfTimes); // O(no of batteries)

            if(verdict) {
                low = mid + 1;
                maximumNoOfTimes = predictedMaximumNoOfTimes;
            } else {
                high = mid - 1;
            } 
        }

        return maximumNoOfTimes;
    }
};

/*
Problem Summary

You have:

    n computers
    batteries[i] = how many minutes that battery can power a computer
    You can swap batteries between computers freely at any time
    All computers must run simultaneously for x minutes
    
Goal → Find the maximum x.
*/

/*
🔥 Key Insight

If each computer must run x minutes, then total energy needed:
    n * x

But each battery with capacity b contributes:
    min(b, x)

Because if a battery is bigger than x, you never need more than x from it.
*/

/*
🎯 We need to check:
    Can we run all n computers for x minutes?

    Check:
        sum(min(battery[i], x)) >= n * x
    If true → x is feasible
    Else → x is not feasible
*/

/*
    🚀 Use Binary Search on x

    Why?

        x is monotonic
        If we can run for x = 100 minutes,
        we can run for any x < 100
        But not for any x > 100

    ⏳ Search Range
        lo = 0
        hi = totalBatteryCapacity / n
*/