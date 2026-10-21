# 1525. Number of Good Ways to Split a String

## Question

Given a string `s`, split it into two non-empty strings `left` and `right` so that `left + right == s`. A split is good if the number of distinct characters in `left` equals the number of distinct characters in `right`. Return the number of good splits.

## Examples

### Example 1

Input: `s = "aacaba"`

Output: `2`

Explanation: The good splits are `"aa" | "caba"` and `"aaca" | "ba"`.

### Example 2

Input: `s = "abcd"`

Output: `1`

Explanation: The good split is `"ab" | "cd"`.

### Example 3

Input: `s = "aaaaa"`

Output: `4`

Explanation: Every split has one distinct character on each side.

## Constraints

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

## Topics

- String
- Hash Table
- Prefix and Suffix Counting

## Approach

1. Build a prefix array where each index stores the number of distinct characters up to that index.
2. Build a suffix array where each index stores the number of distinct characters from that index to the end.
3. Check every split between adjacent characters and count the splits where the prefix and suffix counts match.

## Time Complexity

`O(n)` expected time using hash set operations.

## Space Complexity

`O(n)` for the prefix and suffix count arrays.
