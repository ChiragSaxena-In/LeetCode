#include <vector>
using namespace std;

/*
    Problem: Largest Element in an Array

    Given an array arr, find and return the largest element.

    Example:
    Input:  arr = {1, 8, 7, 56, 90}
    Output: 90

    Explanation:
    The largest element in the array is 90.

    IDEA:
    Assume the first element is the largest.
    Then scan the remaining array from index 1.
    Whenever a bigger element is found, update the largest value.

    APPROACH:
    1. Store arr[0] as the current largest element.
    2. Traverse the array from index 1 to n - 1.
    3. If arr[i] is greater than the current largest element, update it.
    4. Return the final largest element.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Intuition:
    To find the largest element, every element must be checked at least once.
    We keep one variable that stores the largest value found so far.
*/

class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxElement = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (maxElement < arr[i]) {
                maxElement = arr[i];
            }
        }

        return maxElement;
    }
};