#include <vector>
using namespace std;

/*
    LeetCode: 1470. Shuffle the Array

    Problem:
    Given an array nums of size 2n in the form:

        [x1, x2, ..., xn, y1, y2, ..., yn]

    Return the array in the form:

        [x1, y1, x2, y2, ..., xn, yn]

    Example:
        Input:  nums = [2, 5, 1, 3, 4, 7], n = 3
        Output: [2, 3, 5, 4, 1, 7]

    IDEA:
    The first half of nums contains all x values.
    The second half of nums contains all y values.

    For every index i:
        x value = nums[i]
        y value = nums[i + n]

    In the answer array:
        x value goes to even index 2 * i
        y value goes to odd index 2 * i + 1

    APPROACH:
    1. Create an answer array of size 2n.
    2. Traverse from i = 0 to n - 1.
    3. Place nums[i] at ans[2 * i].
    4. Place nums[i + n] at ans[2 * i + 1].
    5. Return the answer array.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }

        return ans;
    }
};