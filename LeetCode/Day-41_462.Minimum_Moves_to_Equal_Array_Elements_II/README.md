# LeetCode 462 - Minimum Moves to Equal Array Elements II



## Problem



Given an integer array `nums` of size `n`, return the minimum number of moves required to make all array elements equal.



In one move, you can increment or decrement an element of the array by `1`.



Test cases are designed so that the answer fits in a 32-bit integer.



## Example



Input:

[1,2,3]



Output:

2



Explanation:

Increment 1 twice or decrement 3 once, then decrement 2 once → total 2 moves: [2,2,2]



## Approach



Use the median.



When all elements must be made equal using +/- 1 moves, the optimal target value is the **median** of the array. Making every element equal to the median minimizes the total sum of absolute differences.



Steps:



- Sort the array and find the median `mid = nums[n/2]`

- For every element, add `abs(num - mid)` to the answer



## Complexity



Time Complexity: O(n log n)



Space Complexity: O(1)



## Topics



- Array

- Math

- Sorting

- Greedy



## LeetCode



Problem 462 - Minimum Moves to Equal Array Elements II
