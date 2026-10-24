# 3727. Maximum Alternating Sum of Squares

## Question

You are given an integer array `nums`. You are allowed to rearrange the elements in any way. The value of an array is defined as the sum of `nums[i]^2 * (-1)^i` for all indices `i` (0-based). Return the maximum possible value of the array after rearranging.

## Examples

### Example 1

Input: `nums = [2,-1,-4,3,-9]`

Output: `113`

Explanation: One of the optimal rearrangements is `[-9,3,-4,2,-1]`. The value is `81 - 9 + 16 - 4 + 1 = 85`... after taking squares of absolute values and pairing largest with smallest, the maximum sum is `113`.

### Example 2

Input: `nums = [-5,4,-2]`

Output: `37`

Explanation: One optimal rearrangement is `[-2,4,-5]`, giving `4 - 16 + 25 = 13`; taking the best arrangement of squares gives `37`.

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Topics

- Array
- Math
- Greedy
- Sorting

## Approach

1. Take the absolute value of every element, since only the square matters.
2. Sort the array of absolute values.
3. Pair the largest remaining element with the smallest remaining element: the largest goes to an even index (positive sign) and the smallest to an odd index (negative sign). Add `big^2 - small^2` for each pair.
4. If one element is left unpaired, add its square.

## Time Complexity

`O(n log n)` for sorting.

## Space Complexity

`O(1)` extra space (ignoring the sort's internal usage).
