# LeetCode 91 — Decode Ways

## Question

A message containing letters from `A-Z` can be encoded as numbers:

```text
A → 1
B → 2
...
Z → 26
```

Given a string `s` containing only digits, return the number of ways to decode it.

A valid decoding cannot contain numbers with leading zeros.

### Examples

**Example 1**

```text
Input:  s = "12"
Output: 2
Explanation: "AB", "L"
```

**Example 2**

```text
Input:  s = "226"
Output: 3
Explanation: "BZ", "VF", "BBF"
```

**Example 3**

```text
Input:  s = "06"
Output: 0
```

## Topics

* Recursion
* Dynamic Programming
* 1D DP
* String
* Bottom-Up DP

## Approach

Define:

```text
dp[i] = number of ways to decode s[i...n-1]
```

At each index:

* Take **1 digit** → `dp[i + 1]`
* Take **2 digits** if the number is `10–26` → `dp[i + 2]`
* If `s[i] == '0'` → `0` ways

Base case:

```text
dp[n] = 1
```

Fill the DP array from **right to left**.

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(n)
```
