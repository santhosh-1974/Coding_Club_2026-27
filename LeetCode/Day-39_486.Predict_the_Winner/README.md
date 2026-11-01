# 486. Predict the Winner

## Question

You are given an array of scores `nums`. Two players take turns picking a number from either end of the array, with Player 1 going first. Each number is removed from the array once picked. Both players play optimally to maximize their own total score. Return `true` if Player 1 can win the game (or tie), otherwise `false`. If the total scores are equal, Player 1 is still considered the winner.

## Example

```text
Input: nums = [1,5,2]
Output: false
Explanation: Player 1 picks 1 (or 2); Player 2 then picks 5. Player 1 can never reach a score >= Player 2's.
```

## Constraints

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 10^7`

## Topics

- Array
- Math
- Dynamic Programming
- Game Theory (Minimax)

## Approach

1. Model the game with minimax on the subarray `[st, end]`: track the **score difference** (current player's total minus opponent's total). The current player maximizes the difference by taking either end; the opponent (next turn) minimizes it.
2. Recurrence: player turn → `max(nums[st] + f(st+1,end), nums[end] + f(st,end-1))`; opponent turn → `min(-nums[st] + f(st+1,end), -nums[end] + f(st,end-1))`. Player 1 wins iff `f(0, n-1) >= 0`.
3. Bottom-up DP: iterate over subarray start `i` from `n` down to `1`, and end `j` from `i+1` to `n`. `temp[j][1]` (player's turn on `[i..j]`) = `max(dp[j][0] + nums[i-1], temp[j-1][0] + nums[j-1])`; `temp[j][0]` (opponent's turn) = `min(dp[j][1] - nums[i-1], temp[j-1][1] - nums[j-1])`. Answer is `dp[n][1] >= 0`.

## Time Complexity

`O(n^2)` for the DP over all subarray ranges (`n <= 20`, so the recursion alone also passes).

## Space Complexity

`O(n^2)` states rolled into rolling rows of size `(n+1) x 2` → `O(n)` extra space.
