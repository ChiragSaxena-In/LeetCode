#include <iostream>
#include <vector>
using namespace std;

/*
===========================================================
27. Remove Element
===========================================================

Problem:
Given an integer array nums and an integer val, remove all
occurrences of val in-place.

The relative order of the remaining elements may be changed.

Return the number of elements that are not equal to val.

Example:
Input : nums = [3,2,2,3], val = 3
Output: 2

Explanation:
After removing all occurrences of 3, the first two elements
of nums contain [2,2]. The remaining elements are ignored.

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

Use two pointers to overwrite the elements equal to val.

- Pointer j scans every element.
- Pointer i keeps track of the position where the next
  valid element should be placed.

Whenever nums[j] is not equal to val, swap it with nums[i]
and move both pointers forward.

The first k elements of the array will contain all the
required elements.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Initialize two pointers:
      i = 0 (write pointer)
      j = 0 (read pointer)
2. Traverse the array using j.
3. If nums[j] != val:
      - Swap nums[i] and nums[j].
      - Increment i.
      - Increment count k.
4. Continue until j reaches the end.
5. Return k.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

O(n)

Each element is visited exactly once.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

Only constant extra space is used.

===========================================================
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = 0;

        int i = 0, j = 0;

        while (j < n) {
            if (nums[j] != val) {
                swap(nums[i], nums[j]);
                k++;
                i++;
            }
            j++;
        }

        return k;
    }
};