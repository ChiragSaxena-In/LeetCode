#include <vector>
using namespace std;

/*
=========================================================
                    Move Zeroes
                (LeetCode 283)
=========================================================

Problem:
Move all zeroes to the end of the array
while maintaining the relative order
of non-zero elements.

The operation must be done in-place.

Example:
Input  : [0,1,0,3,12]
Output : [1,3,12,0,0]

=========================================================
                        IDEA
=========================================================

We use the Two Pointer approach.

i
-> points to the position where the next
   non-zero element should be placed

j
-> scans the entire array

Whenever nums[j] is non-zero:
- Swap nums[i] and nums[j]
- Move i forward

This automatically:
- pushes non-zero elements forward
- shifts zeroes toward the end

=========================================================
                    APPROACH
=========================================================

1. Initialize:
        i = 0
        j = 0

2. Traverse array using j.

3. If nums[j] is non-zero:
        - swap(nums[i], nums[j])
        - increment i

4. Always increment j.

5. Final array will have:
        - all non-zero elements at front
        - all zeroes at end

=========================================================
                DRY RUN
=========================================================

nums = [0,1,0,3,12]

j = 0 -> zero
        skip

j = 1 -> non-zero
        swap(0,1)
        [1,0,0,3,12]
        i++

j = 3 -> non-zero
        swap(1,3)
        [1,3,0,0,12]

j = 4 -> non-zero
        swap(2,4)
        [1,3,12,0,0]

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(1)

=========================================================
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        // i -> position to place next non-zero
        // j -> scans the array
        int i = 0;
        int j = 0;

        while (j < n) {

            // Found non-zero element
            if (nums[j] != 0) {

                swap(nums[i], nums[j]);

                i++;
            }

            j++;
        }
    }
};