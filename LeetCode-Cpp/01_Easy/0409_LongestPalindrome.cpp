#include <iostream>
#include <vector>
using namespace std;

/*
===========================================================
409. Longest Palindrome
===========================================================

Problem:
Given a string containing uppercase and lowercase English
letters, return the length of the longest palindrome that
can be built using those characters.

Example:
Input : "abccccdd"
Output: 7

Explanation:
The longest palindrome possible is "dccaccd" (or similar),
with length 7.

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

A palindrome is symmetric, meaning characters must appear
in pairs.

Example:

    a b c d c b a

Every character except the middle character needs a pair.

For every character frequency:
- If frequency is even:
    We can use all occurrences.
- If frequency is odd:
    We can use frequency - 1 occurrences to make pairs.
    One odd character can be placed in the center.

Greedy Choice:
Take every possible pair and use one odd character as
the center if available.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Create two frequency arrays:
   - lower for lowercase letters
   - upper for uppercase letters

2. Count the frequency of every character.

3. Traverse all frequencies:
   - Add even frequencies completely.
   - For odd frequencies, add one less than the frequency
     and mark that an odd character exists.

4. Add 1 to the answer if any odd frequency was found,
   because one character can occupy the center.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Counting characters : O(n)
Traversing frequency arrays : O(26)

Overall: O(n)

where n = length of string.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

Reason:
Only two fixed-size arrays of length 26 are used.

===========================================================
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();

        if (n < 2) return n;

        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count frequency of characters
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lower[s[i] - 'a']++;
            } 
            else {
                upper[s[i] - 'A']++;
            }
        }

        int res = 0;
        bool sawOdd = false;

        // Calculate contribution of lowercase letters
        for (int i = 0; i < 26; i++) {
            if (lower[i] % 2 == 0) {
                res += lower[i];
            } 
            else {
                res += lower[i] - 1;
                sawOdd = true;
            }

            // Calculate contribution of uppercase letters
            if (upper[i] % 2 == 0) {
                res += upper[i];
            } 
            else {
                res += upper[i] - 1;
                sawOdd = true;
            }
        }

        // One odd frequency character can be placed in center
        return res + sawOdd;
    }
};