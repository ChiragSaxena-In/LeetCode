#include <vector>
using namespace std;

/*
    LeetCode: 1431. Kids With the Greatest Number of Candies

    Problem:
    Given an array candies, where candies[i] represents the number of candies
    the ith kid has, and an integer extraCandies.

    Return a boolean array where ans[i] is true if giving extraCandies to the
    ith kid makes them have the greatest number of candies among all kids.

    Example:
        Input:  candies = [2, 3, 5, 1, 3], extraCandies = 3
        Output: [true, true, true, false, true]

    IDEA:
    First find the current maximum number of candies.
    Then check for every kid whether:

        candies[i] + extraCandies >= maximum candies

    If yes, that kid can have the greatest number of candies.

    APPROACH:
    1. Find the maximum value in candies.
    2. Create a boolean answer array.
    3. For each kid:
        - Add extraCandies to their current candies.
        - Compare it with maxCandies.
        - Store true or false.
    4. Return the answer array.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n);

        int maxCandies = candies[0];

        for (int i = 0; i < n; i++) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }

        for (int i = 0; i < n; i++) {
            ans[i] = candies[i] + extraCandies >= maxCandies;
        }

        return ans;
    }
};