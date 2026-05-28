#include <string>
using namespace std;

/*
=========================================================
                Defanging an IP Address
                    (LeetCode 1108)
=========================================================

Problem:
Replace every '.' in the IP address with "[.]".

Example:
Input  : "1.1.1.1"
Output : "1[.]1[.]1[.]1"

=========================================================
                        IDEA
=========================================================

Traverse the string character by character.

- If current character is '.'
        -> add "[.]"

- Otherwise
        -> add the character normally

We build the final answer in a new string.

=========================================================
                    APPROACH
=========================================================

1. Create an empty result string.
2. Traverse the given IP address.
3. For every character:
        - '.'  -> append '[', '.', ']'
        - else -> append original character
4. Return final string.

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(n)

=========================================================
*/

class Solution {
public:
    string defangIPaddr(string s) {

        int n = s.size();

        string res;

        for (int i = 0; i < n; i++) {

            // Replace '.' with "[.]"
            if (s[i] == '.') {

                res.push_back('[');
                res.push_back('.');
                res.push_back(']');
            }

            // Normal character
            else {

                res.push_back(s[i]);
            }
        }

        return res;
    }
};