# LeetCode 1433 - Check If a String Can Break Another String
## Problem
Given two strings `s1` and `s2` of the same length consisting of lowercase English letters, string `x` **breaks** string `y` if `x[i] >= y[i]` (in alphabetical order) for **all** indices `i` in the range `0...n-1`.

Return `true` if **either** string can break the other, otherwise return `false`.

## Example
Input:
s1 = "abc", s2 = "xya"
Output:
true
Explanation:
"ayx" is a permutation of s2 and breaks "abc" since a > a (equal), y > b, x > c.

Input:
s1 = "abe", s2 = "acd"
Output:
false
Explanation:
No permutation of one string can break the other in either direction.

Input:
s1 = "leetcodee", s2 = "interviewle"
Output:
true

## Approach
Sort both strings first. After sorting, if one string can break the other, then the **sorted** versions satisfy the dominance relation directly (permutation freedom means sorting gives the best possible alignment):

1. Sort `s1` and `s2`.
2. Scan index by index and check if `s1[i] <= s2[i]` holds for every index → then `s2` breaks `s1`.
3. Otherwise, scan again and check if `s1[i] >= s2[i]` holds for every index → then `s1` breaks `s2`.
4. If neither scan completes, return `false`.

## Complexity
Time Complexity: O(n log n) — dominated by sorting both strings.
Space Complexity: O(log n) — sorting overhead (recursion stack).

## Topics
- String
- Greedy
- Sorting

## LeetCode
Problem 1433 - Check If a String Can Break Another String
