class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        // Numbers ending with 0 (but not 0 itself) can't be palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long long int rev_num = 0;
        for(int i = x; i > 0; i /= 10){
            rev_num = rev_num*10 + i%10;
        }

        if (rev_num == x) {
            return true;
        } else {
            return false;
        }
    }

    // Intuition: Reverse the number and compare with the original.
    // Negative numbers and numbers ending with 0 (except 0 itself) cannot be palindromes.
};
