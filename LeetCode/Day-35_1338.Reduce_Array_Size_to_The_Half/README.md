# 1338. Reduce Array Size to The Half

## Question

Given an integer array `arr`, choose a set of integers and remove every occurrence of each chosen integer. Return the minimum size of the set needed to remove at least half of the elements.

## Example

```text
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
```

## Constraints

- `2 <= arr.length <= 10^5`
- `arr.length` is even.
- `1 <= arr[i] <= 10^5`

## Topics

- Array
- Hash Table
- Greedy
- Sorting

## Approach

1. Count the frequency of each distinct value.
2. Sort the frequencies in descending order.
3. Select the highest frequencies first until the number of remaining elements is at most half the original array size.
4. Return how many distinct values were selected.

## Time Complexity

`O(n + d log d)`, where `d` is the number of distinct values.

## Space Complexity

`O(d)` for the frequency map and sorted frequencies.
