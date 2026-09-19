# Delete and Earn

## Question

You are given an integer array `nums`.

When you choose a number `x`:

* You earn `x` points for every occurrence of `x`.
* Every occurrence of `x - 1` and `x + 1` is deleted.

Return the maximum points you can earn.

## Examples

### Example 1

```text
Input:  nums = [3,4,2]
Output: 6

Choose 4 → earn 4
Delete 3
Choose 2 → earn 2

Total = 6
```

### Example 2

```text
Input:  nums = [2,2,3,3,3,4]
Output: 9

Choose 3 → earn 3 × 3 = 9
Delete 2 and 4

Total = 9
```

### Example 3

```text
Input:  nums = [1]
Output: 1
```

## Constraints

```text
1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^4
```

## Topics

* Recursion
* Dynamic Programming
* Memoization
* Hash Map
* Sorting
* Take / Skip Pattern

## Approach

1. Count the frequency of every number.
2. Convert each number into its total points:

```text
points[x] = x × frequency[x]
```

3. If you take `x`, you cannot take `x - 1` or `x + 1`.
4. Therefore, at every value:

```text
Take → points[x] + solve(next valid value)
Skip → solve(next value)
```

5. Take the maximum:

```text
solve(x) = max(take, skip)
```

This is the **Take / Skip DP pattern**.

## Time Complexity

### Recursion without Memoization

```text
O(2^n)
```

### With Memoization

```text
O(n)
```

after the values are prepared.

### Sorting

```text
O(n log n)
```

Overall:

```text
O(n log n)
```

## Space Complexity

```text
O(n)
```

for the frequency map, arrays, and memoization.
