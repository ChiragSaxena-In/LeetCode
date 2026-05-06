#include <vector>
using namespace std;

/*
    LeetCode: 1920. Build Array from Permutation

    Problem:
    Given a zero-based permutation nums, build an array ans such that:

        ans[i] = nums[nums[i]]

    Return the resulting array.

    Example:
        Input:  nums = [0, 2, 1, 5, 3, 4]
        Output: [0, 1, 2, 4, 5, 3]

    IDEA:
    Each nums[i] tells us an index.
    We simply go to that index again and store nums[nums[i]] in the answer array.

    APPROACH:
    1. Find the size of nums.
    2. Create an answer array of the same size.
    3. For every index i:
        - nums[i] gives another index.
        - nums[nums[i]] gives the final value.
    4. Store that value in ans[i].
    5. Return ans.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};