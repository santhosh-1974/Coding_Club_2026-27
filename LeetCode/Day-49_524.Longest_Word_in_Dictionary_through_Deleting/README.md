# LeetCode 524 - Longest Word in Dictionary through Deleting
## Problem
Given a string `s` and a string array `dictionary`, return the longest string in the `dictionary` that can be formed by deleting some of the characters of `s` (i.e., the word is a **subsequence** of `s`). If there is more than one possible result, return the longest word with the **smallest lexicographical order**. If there is no possible result, return the empty string.

## Example
Input:
s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output:
"apple"

Input:
s = "abpcplea", dictionary = ["a","b","c"]
Output:
"a"

Input:
s = "abce", dictionary = ["abe","abc"]
Output:
"abc"

## Approach
Sorting + subsequence check:

1. Sort the dictionary with a custom comparator — longer words come first; among equal lengths, lexicographically smaller words come first. Then the first valid match found is automatically the best answer.
2. For each word in the sorted dictionary:
   - Skip it if it is longer than `s` (can never be a subsequence).
   - Walk through `s` once with a pointer `i` on the word: every time `s[j]` equals `word[i]`, advance `i`. If `i` reaches the word's length, the word is a subsequence of `s` — return it immediately.
3. If no word qualifies, return `""`.

A word is formable by deleting characters of `s` exactly when it is a subsequence of `s`, so this two-pointer scan decides membership in O(len(s)).

## Complexity
Let `n = len(s)`, `d = dictionary size`, `L` = total length of all dictionary words.
Time Complexity: O(d log d + L log d) worst case — sorting plus a subsequence scan per candidate; commonly stated as O(n · d + ΣL) in simpler variants.
Space Complexity: O(1) extra (ignoring the sort's in-place work).

## Topics
- Array
- Two Pointers
- String
- Sorting

## LeetCode
Problem 524 - Longest Word in Dictionary through Deleting
