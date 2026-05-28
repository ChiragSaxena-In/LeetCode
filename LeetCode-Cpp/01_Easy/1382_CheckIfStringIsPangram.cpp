#include <vector>
#include <string>
using namespace std;

/*
=========================================================
                Check if Sentence Is Pangram
                    (LeetCode 1832)
=========================================================

Problem:
A pangram is a sentence that contains every
letter from 'a' to 'z' at least once.

Return true if the given sentence is a pangram,
otherwise return false.

Example:
Input  : "thequickbrownfoxjumpsoverthelazydog"
Output : true

=========================================================
                        IDEA
=========================================================

We need to track whether each alphabet letter
appears in the string or not.

Since there are only 26 lowercase letters:
- Create a frequency array/vector of size 26.
- Mark characters as visited.

After traversal:
- If any character is missing
        -> not a pangram

Otherwise:
        -> pangram

=========================================================
                    APPROACH
=========================================================

1. If string length < 26:
        impossible to contain all alphabets

2. Create freq vector of size 26 initialized to false.

3. Traverse string:
        freq[s[i] - 'a'] = true

4. Traverse freq array:
        if any value is false
                return false

5. Otherwise return true.

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(1)
(26-sized array is constant space)

=========================================================
*/

class Solution {
public:
    bool checkIfPangram(string s) {

        int n = s.size();

        // Cannot contain all alphabets
        if (n < 26) {
            return false;
        }

        vector<bool> freq(26, false);

        // Mark visited characters
        for (int i = 0; i < n; i++) {

            freq[s[i] - 'a'] = true;
        }

        // Check if any alphabet is missing
        for (int i = 0; i < 26; i++) {

            if (freq[i] == false) {
                return false;
            }
        }

        return true;
    }
};