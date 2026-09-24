# 718. Maximum Length of Repeated Subarray

## Question

Given two integer arrays `nums1` and `nums2`, return the **maximum length of a subarray** that appears in both arrays.

A subarray must contain **contiguous elements**.

## Examples

### Example 1

**Input:**
`nums1 = [1,2,3,2,1]`  
`nums2 = [3,2,1,4,7]`

**Output:** `3`

**Explanation:** `[3,2,1]` appears in both arrays.

### Example 2

**Input:**
`nums1 = [0,0,0,0,0]`  
`nums2 = [0,0,0,0,0]`

**Output:** `5`

### Example 3

**Input:**
`nums1 = [1,2,3,2,1]`  
`nums2 = [3,2,1,2,7]`

**Output:** `3`

## Constraints

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 100`

## Topics

- Dynamic Programming
- 2D DP
- Longest Common Subarray
- Subarray

## Approach

Define:

`dp[i][j]` = length of the common subarray ending at `nums1[i-1]` and `nums2[j-1]`.

If:

`nums1[i-1] == nums2[j-1]`

then:

`dp[i][j] = dp[i-1][j-1] + 1`

Otherwise:

`dp[i][j] = 0`

Keep track of the maximum `dp[i][j]`.

**Important:** This is different from Longest Common Subsequence. A subarray must be **contiguous**, so when elements don't match, we reset to `0`.

## Time Complexity

`O(n × m)`

## Space Complexity

`O(n × m)`