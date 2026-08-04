#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
===========================================================
977. Squares of a Sorted Array
===========================================================

Problem:
Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number, also sorted
in non-decreasing order.

Example:
Input : [-4, -1, 0, 3, 10]
Output: [0, 1, 9, 16, 100]

Explanation:
Squaring the numbers gives:
[16, 1, 0, 9, 100]

Sorting them results in:
[0, 1, 9, 16, 100]

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

Since the array is already sorted, the largest square will
always come from either:

- The leftmost (most negative) element, or
- The rightmost (largest positive) element.

Use two pointers to compare their absolute values and place
the larger square at the end of the answer array.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Create an answer array of size n.
2. Initialize:
      i = 0
      j = n - 1
      k = n - 1
3. Compare abs(nums[i]) and abs(nums[j]).
4. Place the larger square at res[k].
5. Move the corresponding pointer.
6. Decrement k.
7. Repeat until i > j.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

O(n)

Each element is processed exactly once.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(n)

For the output array.

===========================================================
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return {nums[0] * nums[0]};

        vector<int> res(n);

        int i = 0;
        int j = n - 1;
        int k = n - 1;

        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                res[k] = nums[i] * nums[i];
                i++;
            } else {
                res[k] = nums[j] * nums[j];
                j--;
            }
            k--;
        }

        return res;
    }
};