#include <vector>
using namespace std;

/*
=========================================================
            Two Sum II - Input Array Is Sorted
                    (LeetCode 167)
=========================================================

Problem:
Given a sorted array, find two numbers such that:
        arr[i] + arr[j] == target

Return their 1-based indices.

Example:
Input  : arr = [2,7,11,15], target = 9
Output : [1,2]

=========================================================
                        IDEA
=========================================================

Since the array is already sorted,
we can use the Two Pointer approach.

- One pointer starts from left.
- Another pointer starts from right.

Cases:
1. Sum == target
        -> answer found

2. Sum < target
        -> move left pointer forward
        because we need a larger sum

3. Sum > target
        -> move right pointer backward
        because we need a smaller sum

=========================================================
                    APPROACH
=========================================================

1. Initialize:
        start = 0
        end   = n - 1

2. Run loop while start < end

3. Calculate current sum.

4. According to sum:
        - equal   -> return indices
        - smaller -> start++
        - larger  -> end--

5. Return answer.

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(1)

=========================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {

            int sum = arr[start] + arr[end];

            // Pair found
            if (sum == target) {

                return {start + 1, end + 1};
            }

            // Need larger sum
            else if (sum < target) {

                start++;
            }

            // Need smaller sum
            else {

                end--;
            }
        }

        // Problem guarantees one valid answer
        return {};
    }
};