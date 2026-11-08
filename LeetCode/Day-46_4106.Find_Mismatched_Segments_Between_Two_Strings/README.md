# LeetCode 4106 - Find Mismatched Segments Between Two Strings
## Problem
Given two strings `s1` and `s2` of the same length, find every **mismatched segment** — a maximal contiguous range of indices where the characters of `s1` and `s2` differ at every index.

Return a 2D array containing `[sub1, sub2]` for each segment, where `sub1` and `sub2` are the corresponding substrings from `s1` and `s2`, in increasing order of starting index. If there are none, return an empty array.

## Example
Input:
s1 = "earth", s2 = "empty"
Output:
[["ar","mp"],["h","y"]]
Explanation:
Indices 1 and 2 differ → ["ar","mp"]. Index 4 differs → ["h","y"].

Input:
s1 = "action", s2 = "nation"
Output:
[["ac","na"]]

Input:
s1 = "hot", s2 = "hot"
Output:
[]

## Approach
Single linear scan over both strings (they have equal length):

1. Maintain two running buffers `temp1` and `temp2` for the current mismatched run.
2. If `s1[i] == s2[i]`, the current mismatched segment (if any) ends — flush the buffers into the answer and reset them.
3. If they differ, append the characters to the buffers, extending the segment.
4. After the loop, flush once more to catch a segment that ends at the last index.

Since a segment is flushed exactly when a match breaks it (or at the end), the output is naturally in increasing order of starting indices.

## Complexity
Time Complexity: O(n) — each character is visited once.
Space Complexity: O(n) — for the output substrings and buffers.

## Topics
- String
- Simulation

## LeetCode
Problem 4106 - Find Mismatched Segments Between Two Strings
