#include <iostream>
#include <vector>
using namespace std;
/*
===========================================================
75. Sort Colors
===========================================================

Problem:
Given an array nums containing only 0s, 1s, and 2s,
sort the array in-place so that objects of the same
color are adjacent, with the colors in the order:
0 (Red), 1 (White), 2 (Blue).

Example:
Input : [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

Since the array contains only three possible values
(0, 1, and 2), we can count the frequency of each
value and then overwrite the array accordingly.

Step 1:
Count occurrences of 0, 1, and 2.

Step 2:
Fill the array with:
- all 0s
- then all 1s
- then all 2s

This is essentially a counting sort approach.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Create a frequency array of size 3.
2. Traverse nums and count occurrences.
3. Traverse the frequency array.
4. Rewrite nums using the stored frequencies.
5. Return the modified array.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Counting frequencies : O(n)
Rebuilding array     : O(n)

Overall: O(n)

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

Reason:
The frequency array always stores exactly 3 values,
regardless of input size.

===========================================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // Frequency array for 0, 1, and 2
        vector<int> occ(3, 0);

        // Count occurrences
        for (int i = 0; i < n; i++) {
            occ[nums[i]]++;
        }

        // Rewrite the array in sorted order
        int index = 0;

        for (int color = 0; color < 3; color++) {
            int count = occ[color];

            while (count > 0) {
                nums[index] = color;
                index++;
                count--;
            }
        }
    }
};