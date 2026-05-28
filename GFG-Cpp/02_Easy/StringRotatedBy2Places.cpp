#include <string>
using namespace std;

/*
=========================================================
            Check if Strings Are Rotations by 2 Places
=========================================================

Problem:
Check whether string s2 can be obtained by:
- rotating s1 clockwise by 2 places
                OR
- rotating s1 anti-clockwise by 2 places

Example:
Input  : s1 = "amazon"
         s2 = "azonam"

Output : true

Explanation:
"amazon" rotated anti-clockwise by 2 becomes:
"azonam"

=========================================================
                        IDEA
=========================================================

We create two helper functions:

1. Clockwise Rotation by 2
        Example:
        "amazon" -> "onamaz"

2. Anti-clockwise Rotation by 2
        Example:
        "amazon" -> "azonam"

Then compare both rotated strings with s2.

If either matches:
        return true

Otherwise:
        return false

=========================================================
                    APPROACH
=========================================================

Clockwise Rotation:
-------------------
- Store last two characters.
- Shift remaining characters right by 2.
- Place saved characters at front.

Anti-clockwise Rotation:
------------------------
- Store first two characters.
- Shift remaining characters left by 2.
- Place saved characters at end.

Main Function:
---------------
1. Check sizes.
2. Generate clockwise rotated string.
3. Compare with s2.
4. Generate anti-clockwise rotated string.
5. Compare again.

=========================================================
                TIME AND SPACE COMPLEXITY
=========================================================

Time Complexity  : O(n)
Space Complexity : O(1)
(ignoring returned string copies)

=========================================================
*/

class Solution {
public:

    // Rotate string clockwise by 2
    string rotateclockwiseby2(string s) {

        int n = s.size();

        char last = s[n - 1];
        char last1 = s[n - 2];

        // Shift characters right by 2
        for (int i = n - 1; i >= 2; i--) {

            s[i] = s[i - 2];
        }

        // Place saved characters at front
        s[1] = last;
        s[0] = last1;

        return s;
    }

    // Rotate string anti-clockwise by 2
    string rotateanticlockwiseby2(string s) {

        int n = s.size();

        char first = s[0];
        char second = s[1];

        // Shift characters left by 2
        for (int i = 0; i < n - 2; i++) {

            s[i] = s[i + 2];
        }

        // Place saved characters at end
        s[n - 2] = first;
        s[n - 1] = second;

        return s;
    }

    bool isRotated(string& s1, string& s2) {

        // Different sizes cannot be rotations
        if (s1.size() != s2.size()) {
            return false;
        }

        // Rotation by 2 not possible for size 1
        if (s1.size() == 1 || s2.size() == 1) {
            return false;
        }

        // Check clockwise rotation
        string s3 = rotateclockwiseby2(s1);

        if (s3 == s2) {
            return true;
        }

        // Check anti-clockwise rotation
        s3 = rotateanticlockwiseby2(s1);

        return s3 == s2;
    }
};