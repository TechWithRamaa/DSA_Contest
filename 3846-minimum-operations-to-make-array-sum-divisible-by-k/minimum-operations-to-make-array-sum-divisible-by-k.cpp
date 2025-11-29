class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int r = ((sum % k) + k) % k; // safe modulo => use it when numerator can take negative values, and when result should not be negative
        if(r == 0)
            return 0;
        
        return r;
    }
};


/*
✔️ When should you use safe modulo?

You should use it anytime one of these can happen:

* a might be negative
* a might overflow into negative (e.g., subtracting large values)
* you're using modulo for:
    * circular arrays
    * prefix sums with modulo
    * hashing
    * dp with modulo
    * time or index wrapping
    * remainder-based logic

✔️ When it's NOT needed?

If you're absolutely sure:
    * the number a is non-negative
    * and k is positive

Then:
    a % k

is already safe.
*/