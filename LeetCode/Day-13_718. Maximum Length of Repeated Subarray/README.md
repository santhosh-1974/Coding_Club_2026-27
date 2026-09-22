# LC 718 — Maximum Length of Repeated Subarray

## 1. Question

Given two integer arrays `nums1` and `nums2`, return the maximum length of a **subarray** that appears in both arrays.

A subarray must be **continuous**.

Example:

nums1 = [1,2,3,2,1]
nums2 = [3,2,1,4,7]

Answer = 3

Because `[3,2,1]` appears in both. :contentReference[oaicite:0]{index=0}


## 2. Examples

### Example 1

Input:
nums1 = [1,2,3,2,1]
nums2 = [3,2,1,4,7]

Output:
3

Common subarray:
[3,2,1]


### Example 2

Input:
nums1 = [0,0,0,0,0]
nums2 = [0,0,0,0,0]

Output:
5

Common subarray:
[0,0,0,0,0]


### Example 3

Input:
nums1 = [1,2,3]
nums2 = [4,5,6]

Output:
0

No common subarray.


## 3. Topics

- Dynamic Programming
- 2D DP
- Longest Common Substring / Subarray
- Continuous Matching
- Diagonal DP


## 4. Approach

Define:

`dp[i][j]` = length of the common subarray ending at
`nums1[i-1]` and `nums2[j-1]`.

### Transition

If elements match:

`dp[i][j] = dp[i-1][j-1] + 1`

If elements don't match:

`dp[i][j] = 0`

Why `0`?

Because a subarray must be continuous. A mismatch breaks the current matching sequence.

Keep the maximum value found:

`answer = max(answer, dp[i][j])`


## 5. DP Pattern

```text
Current elements match?
        |
    +---+---+
    |       |
   YES      NO
    |       |
 diagonal   0
   + 1
    |
 extend
 matching
 streak