#include <vector>
using namespace std;

/*
===========================================================
268. Missing Number
===========================================================

Problem:
Given an array nums containing n distinct numbers in the
range [0, n], return the only number in the range that
is missing from the array.

Example:
Input : [3,0,1]
Output: 2

Explanation:
Numbers from 0 to 3 should be:
0, 1, 2, 3

The number 2 is missing.

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

If no number were missing, the sum of numbers from
0 to n would be:

    n * (n + 1) / 2

We calculate:

1. Expected sum using the formula.
2. Actual sum of elements in the array.
3. Their difference gives the missing number.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Find the expected sum of numbers from 0 to n.
2. Traverse the array and calculate the actual sum.
3. Subtract the actual sum from the expected sum.
4. Return the result.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

O(n)

We traverse the array once.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

Only a few variables are used.

===========================================================
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        // Calculate the actual sum of array elements
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Expected sum of numbers from 0 to n
        int expectedSum = (n * (n + 1)) / 2;

        // Difference gives the missing number
        return expectedSum - sum;
    }
};