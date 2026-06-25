#include <iostream>
#include <vector>
using namespace std;
/*
===========================================================
Sort a String
===========================================================

Problem:
Given a string consisting of lowercase English letters,
return the string after sorting all characters in
non-decreasing (alphabetical) order.

Example:
Input : "geeks"
Output: "eegks"

Input : "banana"
Output: "aaabnn"

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

Since the string contains only lowercase English letters
('a' to 'z'), we can count the frequency of each character.

After counting, reconstruct the string by appending each
character according to its frequency in alphabetical order.

This is a counting sort approach for characters.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Create a frequency array of size 26.
2. Traverse the string and count occurrences of each letter.
3. Iterate from 'a' to 'z'.
4. Append each character to the answer string as many
   times as its frequency.
5. Return the sorted string.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Counting frequencies : O(n)
Building answer      : O(n)

Overall: O(n)

where n = length of the string.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

Reason:
The frequency array always stores exactly 26 values,
regardless of input size.

===========================================================
*/

class Solution {
public:
    string sortString(string &s) {
        // Frequency array for lowercase letters
        vector<int> alpha(26, 0);

        int n = s.size();

        // Count occurrences of each character
        for (int i = 0; i < n; i++) {
            alpha[s[i] - 'a']++;
        }

        string sortedStr = "";

        // Reconstruct string in sorted order
        for (int i = 0; i < 26; i++) {
            int count = alpha[i];
            char currentChar = 'a' + i;

            while (count > 0) {
                sortedStr += currentChar;
                count--;
            }
        }

        return sortedStr;
    }
};