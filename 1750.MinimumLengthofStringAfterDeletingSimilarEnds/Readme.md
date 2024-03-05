# 1750. Minimum Length of String After Deleting Similar Ends

## Medium

Given a string `s` consisting only of characters `'a'`, `'b'`, and `'c'`. You are asked to apply the following algorithm on the string any number of times:

1. Pick a **non-empty** prefix from the string `s` where all the characters in the prefix are equal.

2. Pick a **non-empty** suffix from the string `s` where all the characters in this suffix are equal.

3. The prefix and the suffix should not intersect at any index.

4. The characters from the prefix and suffix must be the same.

5. Delete both the prefix and the suffix.

Return the **minimum length** _of `s` after performing the above operation any number of times (possibly zero times)._

## Example 1:

Input: `s = "ca"`

Output: 2

**Explanation:** You can't remove any characters, so the string stays as is.

## Example 2:

Input: s = `"cabaabac"`

Output: 0

**Explanation**: An optimal sequence of operations is:

- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".

## Example 3:

Input: s = `"aabccabba"`

Output: 3

**Explanation**: An optimal sequence of operations is:

- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".

## Constraints:

- `1 <= s.length <= 10^5`

- `s` only consists of characters `'a'`, `'b'`, and `'c'`.

# Solution

## Intuition

We need to remove suffix and prefix hence two pointers are used

## Approach

- Start by initialising i = 0 and j = n-1

- Start a loop with a condition of i < j

- Save the characters at i and j to a and b

- Now if `a == b` , we have a same suffix and prefix which matches the condition given

  - Increment i till s[i] == a and i<=j. These are the charaters which are equal to a a or b at the suffix side

  - Similarly decrement j till s[j] == b and i<=j.These are the charaters which are equal to a a or b at the prefix side

  - Checking for i<=j is necessary to handle the condition when suffix and prefix intersects
    Eg: bababbbbbbbbbaabbaaaab

- If a != b break the loop as suffix is not equal to prefix

- After the end of loop

  - If i>j return 0

  - return j-i+1 which is the length of the resultant string.

## Complexity

Time complexity:

$$O(n)$$

Space complexity:

$$O(1)$$

![Alt text](Acceptance.png "a title")

## Code

```
class Solution {
public:
    int minimumLength(string s) {

        int i = 0;
        int j = s.length()-1;
        while(i<j){
            char a = s[i];
            char b = s[j];
            if (a == b){
                while (s[i] == a && i<=j){
                    i++;
                }
                while(s[j] == b && i<=j){
                    j--;
                }
            }
            else{
                break;
            }
        }
        if (j<i){
            return 0;
        }
        return j-i+1;
    }
};
```
