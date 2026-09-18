LeetCode 2110 — Number of Smooth Descent Periods

Question

Given an integer array prices, count the number of contiguous subarrays where every consecutive price decreases by exactly 1. A single element is also valid.

Example

Input:  [3,2,1,4]
Output: 7

Constraints

1 <= prices.length <= 10^5
1 <= prices[i] <= 10^5

Topics

* Arrays
* Sliding Window / Running Streak
* Counting
* Dynamic Programming

Approach

Maintain the length of the current valid descent streak.

* If prices[i] == prices[i-1] - 1 → streak++
* Otherwise → streak = 1
* Add streak to the answer.

answer += streak

Time Complexity

O(n)

Space Complexity

O(1)