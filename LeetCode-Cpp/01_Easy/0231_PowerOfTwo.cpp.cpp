class Solution {
public:
    // Brute Force Approach
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;

        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 2 != 0 && n == 1) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }

    /*
    // Optimized Approach
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return (n & (n - 1)) == 0; 
        // Example: 16 (10000) & 15 (01111) = 0 -> true
        //          15 (01111) & 14 (01110) = 14 -> false
    }
    */

    // Intuition (Brute Force): Keep dividing by 2; if we reach exactly 1, it's a power of 2.
    // Any odd number (except 1) in the process means it's not a power of 2.
    
    // Intuition (Optimized): A power of 2 has exactly one bit set. n & (n-1) clears the lowest set bit.
    // If the result is 0, it confirms there was only one bit set → power of 2.
};
