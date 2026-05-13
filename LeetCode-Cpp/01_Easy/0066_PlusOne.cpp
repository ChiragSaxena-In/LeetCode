#include <vector>
using namespace std;
/*
    Problem: Plus One

    Definition:
    You are given a large integer represented as an array of digits.
    Each digits[i] represents one digit of the number.

    Add 1 to the number and return the updated digit array.

    Example:
    Input:  digits = [1, 2, 3]
    Output: [1, 2, 4]

    Explanation:
    123 + 1 = 124

    Example:
    Input:  digits = [9, 9, 9]
    Output: [1, 0, 0, 0]

    Explanation:
    999 + 1 = 1000
*/

/*
    IDEA:
    We should not convert the array into an integer because the number can be very large.

    Instead, we simulate normal addition from the last digit.

    If the current digit is less than 9:
        - simply add 1
        - return the answer

    If the current digit is 9:
        - 9 + 1 becomes 10
        - current digit becomes 0
        - carry moves to the left

    If all digits are 9, then all become 0 and we insert 1 at the beginning.
*/

/*
    APPROACH:
    1. Start from the last digit.
    2. If digits[i] < 9:
        - increment it by 1
        - return digits
    3. Otherwise, digits[i] is 9:
        - make it 0
        - continue to the previous digit
    4. If the loop finishes, it means all digits were 9.
    5. Insert 1 at the beginning.
*/

/*
    Time Complexity: O(n)
    Space Complexity: O(1)

    Note:
    Inserting at the beginning of a vector takes O(n), but no extra answer vector is used.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {

            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};