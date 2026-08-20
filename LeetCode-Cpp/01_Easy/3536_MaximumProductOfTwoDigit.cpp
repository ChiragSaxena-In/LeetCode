#include <iostream>
using namespace std;

/*
===========================================================
3536. Maximum Product of Two Digit
(Note: This solution is for the variant where the input is
an integer and the task is to find the product of its two
largest digits.)
===========================================================

Problem:
Given an integer n, return the product of the two largest
digits present in n.

Example:
Input : 1246
Output: 24

Explanation:
The two largest digits are 6 and 4.
Their product is 6 × 4 = 24.

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

There is no need to store or sort the digits.

Traverse the number once while keeping track of the largest
and second largest digits seen so far.

Whenever a larger digit is found:
- Update the second largest.
- Update the largest.

Otherwise, if the digit is larger than the current second
largest, update only the second largest.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Initialize largest and secondLargest.
2. Extract digits one by one using modulo (%) and division (/).
3. Update the two largest digits accordingly.
4. Return their product.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

O(d)

where d is the number of digits.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

Only two variables are used.

===========================================================
*/

class Solution {
public:
    int maxProduct(int n) {
        int largest = -1;
        int secondLargest = -1;

        while (n) {
            int digit = n % 10;

            if (digit > largest) {
                secondLargest = largest;
                largest = digit;
            } else if (digit > secondLargest) {
                secondLargest = digit;
            }

            n /= 10;
        }

        return largest * secondLargest;
    }
};