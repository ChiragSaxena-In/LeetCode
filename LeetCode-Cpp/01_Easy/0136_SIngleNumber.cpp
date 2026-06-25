#include <vector>
using namespace std;

/*
===========================================================
136. Single Number
===========================================================

Problem:
Given a non-empty array of integers, every element
appears exactly twice except for one element.

Return the element that appears only once.

Example:
Input : [4,1,2,1,2]
Output: 4

-----------------------------------------------------------
IDEA
-----------------------------------------------------------

Use the XOR operator.

Important XOR Properties:

1. a ^ a = 0
2. a ^ 0 = a
3. XOR is commutative and associative

Since every number appears twice, identical numbers
cancel each other when XORed together.

After XORing all elements, only the unique element
remains.

Example:

4 ^ 1 ^ 2 ^ 1 ^ 2

= 4 ^ (1 ^ 1) ^ (2 ^ 2)

= 4 ^ 0 ^ 0

= 4

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

1. Initialize answer as 0.
2. XOR every element with answer.
3. Duplicate elements cancel out.
4. Return the remaining value.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

O(n)

Traverse the array once.

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(1)

No extra data structures are used.

===========================================================
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};