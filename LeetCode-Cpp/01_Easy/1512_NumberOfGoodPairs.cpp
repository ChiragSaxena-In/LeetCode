#include <vector>
using namespace std;

/*
    LeetCode: 1512. Number of Good Pairs

    Problem:
    Given an array nums, return the number of good pairs.

    A pair (i, j) is called good if:

        nums[i] == nums[j] and i < j

    Example:
        Input:  nums = [1, 2, 3, 1, 1, 3]
        Output: 4

    Explanation:
        Good pairs are:
        (0, 3), (0, 4), (3, 4), (2, 5)

    IDEA:
    Check every pair (i, j), where j comes after i.
    If both values are equal, then it is a good pair.

    APPROACH:
    1. Start res with 0.
    2. Run i from 0 to n - 2.
    3. Run j from i + 1 to n - 1.
    4. If nums[i] == nums[j], increase res.
    5. Return res.

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    res++;
                }
            }
        }

        return res;
    }
};