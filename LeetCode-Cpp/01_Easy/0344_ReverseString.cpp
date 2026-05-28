#include <vector>
using namespace std;

/*
=========================================================
                Reverse String (LeetCode 344)
=========================================================

Problem:
Reverse the given character array in-place.

Example:
Input  : ['h','e','l','l','o']
Output : ['o','l','l','e','h']

=========================================================
                        IDEA
=========================================================

We use the Two Pointer approach.

- One pointer starts from the beginning.
- Another pointer starts from the end.
- Swap both characters.
- Move both pointers toward the center.

We only need to iterate till n/2 because:
- After halfway, all characters are already swapped.

=========================================================
                    APPROACH
=========================================================

1. Find size of vector.
2. Run loop from i = 0 to n/2.
3. Swap:
        s[i] with s[n - i - 1]
4. Array gets reversed in-place.

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(1)

=========================================================
*/

class Solution {
public:
    void reverseString(vector<char>& s) {

        int n = s.size();

        // Swap characters from both ends
        for (int i = 0; i < n / 2; i++) {

            swap(s[i], s[n - i - 1]);
        }
    }
};