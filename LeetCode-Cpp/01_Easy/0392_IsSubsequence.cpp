#include <iostream>
#include <string>
using namespace std;

/*
===========================================================
392. Is Subsequence
===========================================================

Problem:
Given two strings s and t, return true if s is a subsequence
of t, or false otherwise.

A subsequence of a string is formed by deleting some (or no)
characters without changing the relative order of the
remaining characters.

Example:
Input : s = "abc", t = "ahbgdc"
Output: true

Explanation:
Characters 'a', 'b', and 'c' appear in t in the same order,
so "abc" is a subsequence of "ahbgdc".

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

Traverse the larger string t while keeping a pointer on s.

Whenever the current character of t matches the current
character of s, move the pointer in s forward.

If the pointer reaches the end of s, then every character
of s has been found in the correct order.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Initialize a pointer k = 0 for string s.
2. Traverse string t from left to right.
3. If t[i] matches s[k], increment k.
4. After traversal, if k equals the length of s,
   return true.
5. Otherwise, return false.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

O(n)

where n = length of string t.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

Only a few variables are used.

===========================================================
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0;
        int count = s.size();
        int n = t.size();

        for (int i = 0; i < n && k < count; i++) {
            if (t[i] == s[k]) {
                k++;
            }
        }

        return (k == count);
    }
};