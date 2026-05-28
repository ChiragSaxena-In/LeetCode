#include <vector>
using namespace std;

/*
=========================================================
            Remove Duplicates from Sorted Array
                    (LeetCode 26)
=========================================================

Problem:
Remove duplicates from a sorted array in-place.

Each unique element should appear only once.
Return the number of unique elements.

Example:
Input  : [1,1,2]
Output : 2
Array  : [1,2,_]

Input  : [0,0,1,1,1,2,2,3,3,4]
Output : 5
Array  : [0,1,2,3,4,_...]

=========================================================
                        IDEA
=========================================================

Since the array is sorted:
- Duplicate elements are adjacent.

We use Two Pointers:

start
    -> points to last unique element

end
    -> searches for next unique element

When a new unique value is found:
- Move start forward
- Place new value at nums[start]

This keeps all unique elements at the beginning
of the array.

=========================================================
                    APPROACH
=========================================================

1. start points to first element.
2. end scans remaining array.
3. If nums[start] != nums[end]:
        - move start ahead
        - copy nums[end] into nums[start]
        - increase unique count
4. Continue until end reaches array end.
5. Return count of unique elements.

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(1)

=========================================================
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Edge case
        if (nums.empty()) {
            return 0;
        }

        int count = 1;

        int n = nums.size();

        int start = 0;
        int end = start + 1;

        while (end < n) {

            // Found new unique element
            if (nums[start] != nums[end]) {

                start++;

                nums[start] = nums[end];

                count++;
            }

            // Duplicate element
            end++;
        }

        return count;
    }
};