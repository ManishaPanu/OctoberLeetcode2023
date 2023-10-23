class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        long long i=4;
        while(i != n) {
            i = i*4;
            if(i > n) return false;
        }
        return true;
    }
};
