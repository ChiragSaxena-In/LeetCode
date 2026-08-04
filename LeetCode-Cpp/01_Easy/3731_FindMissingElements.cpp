#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
===========================================================
3731. Find Missing Elements
===========================================================

Problem:
You are given an integer array nums consisting of unique
integers.

Originally, nums contained every integer within a certain
range, but some integers are now missing.

The smallest and largest integers of the original range
are still present in nums.

Return a sorted list of all the missing integers in this
range. If no integers are missing, return an empty list.

Example:
Input : [1, 3, 5]
Output: [2, 4]

Explanation:
The original range is [1, 5].
Missing numbers are 2 and 4.

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

Sort the array so that numbers appear in increasing order.

Start from the smallest number and keep checking every
integer until reaching the largest number.

If the current expected number is not equal to the current
array element, then that number is missing.

Otherwise, move to the next array element.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Sort the array.
2. Let k = smallest element.
3. Traverse the sorted array.
4. If nums[i] == k:
      Move to next element.
5. Otherwise:
      k is missing.
      Store it in the answer.
6. Continue until all array elements are processed.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Sorting : O(n log n)
Traversal : O(n)

Overall : O(n log n)

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

(Excluding the output array.)

===========================================================
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int k = nums[0];

        while (i < n) {
            if (nums[i] != k) {
                res.push_back(k);
                k++;
                continue;
            }

            i++;
            k++;
        }

        return res;
    }
};