#include <climits> //for INT_MAX
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int i = 1;
        while (true) {
            if (i > INT_MAX / i) break;
            if (i * i > x) break;
            i++;
        }
        return --i;
    }
};

/*
Intuition:
Start from i = 1 and increment until i*i would exceed x. The check i > INT_MAX / i
prevents overflow when squaring large i. Once i*i > x, the integer sqrt is i-1,
so return --i. This returns floor(sqrt(x)) using only loops and conditionals.
*/
