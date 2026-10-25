# 948. Bag of Tokens

## Question

You are given an integer array `tokens` and an integer `power`. Each token can be played at most once:

- Play a token face up by spending its value in power to gain 1 score.
- Play a token face down by spending 1 score to gain its value in power.

Return the maximum score you can achieve.

## Example

```text
Input: tokens = [100, 200, 300, 400], power = 200
Output: 2
```

## Constraints

- `0 <= tokens.length <= 1000`
- `0 <= tokens[i], power < 10^4`

## Topics

- Array
- Two Pointers
- Greedy
- Sorting

## Approach

1. Sort the tokens in ascending order.
2. When possible, play the cheapest remaining token face up to gain score.
3. If there is not enough power and at least one score, play the most expensive remaining token face down to gain power.
4. Track the highest score reached and stop when neither move is possible.

## Time Complexity

`O(n log n)` for sorting the tokens.

## Space Complexity

`O(1)` extra space, excluding the space used internally by sorting.
