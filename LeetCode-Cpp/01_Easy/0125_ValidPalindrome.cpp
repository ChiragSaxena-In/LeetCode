#include <vector>
#include <cctype>
#include <string>
using namespace std;

/*
=========================================================
            Valid Palindrome (LeetCode 125)
=========================================================

Problem:
Check whether a string is a palindrome after:
- Removing all non-alphanumeric characters
- Converting uppercase letters to lowercase

A palindrome reads the same forward and backward.

Example:
Input  : "A man, a plan, a canal: Panama"
Output : true

Input  : "race a car"
Output : false

=========================================================
                        IDEA
=========================================================

We first clean the string:
- Keep only letters and digits
- Convert everything to lowercase

Then we check:
- First character with last
- Second with second last
- Continue till middle

If any pair mismatches:
- Not a palindrome

=========================================================
                    APPROACH
=========================================================

1. Traverse original string.
2. Keep only alphanumeric characters using isalnum().
3. Convert characters to lowercase using tolower().
4. Store cleaned characters in temp.
5. Compare characters from both ends.
6. If mismatch found -> return false.
7. Otherwise return true.

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(n)

=========================================================
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();

        string temp;

        // Create cleaned lowercase string
        for (int i = 0; i < n; i++) {

            if (isalnum(s[i])) {
                temp += tolower(s[i]);
            }
        }

        n = temp.size();

        // Check palindrome
        for (int i = 0; i < n / 2; i++) {

            if (temp[i] != temp[n - i - 1]) {
                return false;
            }
        }

        return true;
    }
};