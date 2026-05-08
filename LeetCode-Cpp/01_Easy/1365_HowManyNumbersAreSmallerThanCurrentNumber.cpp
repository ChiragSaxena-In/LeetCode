#include<vector>
using namespace std;

/*
    Problem: 1365. How Many Numbers Are Smaller Than the Current Number

    Given an array nums, for each nums[i], find how many numbers in the array
    are smaller than nums[i].

    Example:
    Input:  nums = {8, 1, 2, 2, 3}
    Output: {4, 0, 1, 1, 3}

    Explanation:
    For 8 -> smaller numbers are 1, 2, 2, 3 => 4
    For 1 -> no smaller number => 0
    For 2 -> smaller number is 1 => 1
    For 2 -> smaller number is 1 => 1
    For 3 -> smaller numbers are 1, 2, 2 => 3
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        /*
            IDEA:
            For every element nums[i], compare it with every other element nums[j].
            Count how many elements are smaller than nums[i].
        */

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (nums[j] < nums[i]) {
                    count++;
                }
            }

            res[i] = count;
        }

        return res;
    }
};

/*
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Intuition:
    For each element, we simply scan the whole array and count how many values
    are smaller than it. This is the most direct brute force approach.
*/