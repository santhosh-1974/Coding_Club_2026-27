# LeetCode 1930 - Unique Length-3 Palindromic Subsequences
## Problem
Given a string `s`, return the number of **unique** palindromes of length three that are a subsequence of `s`. Even if there are multiple ways to obtain the same subsequence, it is counted only once.

## Example
Input:
s = "aabca"
Output:
3
Explanation: "aba", "aaa" and "aca".

Input:
s = "adc"
Output:
0

Input:
s = "bbcbaba"
Output:
4
Explanation: "bbb", "bcb", "bab" and "aba".

## Approach
Every length-3 palindrome looks like `xyx` — the same character on both ends with anything in the middle. So for each of the 26 letters as the outer character:

1. Record the **first** occurrence index `f[c]` and the **last** occurrence index `l[c]` of every character in `s`.
2. If a character occurs at least twice (`l[c] > f[c]`), any distinct character appearing strictly between those two positions forms a unique palindrome `c·mid·c`.
3. Scan the range `(f[c], l[c])` exclusively, counting distinct middle characters with a small boolean seen-array; add that count to the answer.

Since only 26 possible outer characters and 26 possible middle characters exist, the total work is bounded by 26 full scans of the string.

(The `v` / prefix-count bookkeeping at the top of the code is auxiliary/dead output used while building the idea and does not affect the returned answer.)

## Complexity
Time Complexity: O(26 · n) ≈ O(n) — for each letter, one scan of the gap between its first and last occurrence.
Space Complexity: O(26) — first/last index arrays and per-letter seen flags.

## Topics
- Bit Manipulation
- Hash Table
- String
- Prefix Sum

## LeetCode
Problem 1930 - Unique Length-3 Palindromic Subsequences
