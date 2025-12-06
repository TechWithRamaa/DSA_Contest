class Solution {
public:
    bool completePrime(int num) {
        int t = num;
        
        while(t > 0) {
            if(!isPrime(t)) {
                return false;
            }
            
            t /= 10;
        }

        long long base = 10;
        long long limit = 1LL * num * 10;

        while(base <= limit) {
            long long suffix = num % base;
            if(!isPrime(suffix)) {
                return false;
            }
            
            base *= 10;
        }
        
        return true;
    }
private:
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n % 2 == 0) return n == 2;

        for(int i = 3; i * i <= n; i += 2) {
            if(n % i == 0)
                return false;
        }

        return true;
    }
};