# 3723. Maximize Sum of Squares of Digits

## Question

You are given two positive integers `num` and `sum`. Return a string of length `num` representing the number with the maximum possible sum of squares of its digits, such that the sum of its digits equals `sum`. If no such number exists, return an empty string.

## Example

```text
Input: num = 2, sum = 17
Output: "98"
Explanation: 9 + 8 = 17 and 9^2 + 8^2 = 145, which is the maximum possible.
```

## Constraints

- `1 <= num <= 10^5`
- `1 <= sum <= 9 * num`

## Topics

- Greedy
- Math

## Approach

1. Greedy: to maximize the sum of squares of digits, put the largest digits first. Since `x^2` grows faster than `x`, concentrating the sum into 9s is optimal.
2. Fill each of the `num` positions with `min(9, sum)` and subtract from the remaining `sum`.
3. If after filling all positions `sum` is still non-zero, no valid number exists — return `""`.

## Time Complexity

`O(num)` — one pass to build the string.

## Space Complexity

`O(num)` for the result string.
