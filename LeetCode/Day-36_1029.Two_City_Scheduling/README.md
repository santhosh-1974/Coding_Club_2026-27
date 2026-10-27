# 1029. Two City Scheduling

## Question

A company is planning to interview `2n` people. Given the array `costs` where `costs[i] = [aCost_i, bCost_i]`, the cost of flying the `i`-th person to city `a` is `aCost_i`, and the cost of flying the `i`-th person to city `b` is `bCost_i`.

Return the minimum cost to fly every person to a city such that exactly `n` people arrive in each city.

## Example

```text
Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
```

## Constraints

- `2 <= costs.length <= 100`
- `costs.length` is even.
- `1 <= aCost_i, bCost_i <= 1000`

## Topics

- Array
- Greedy
- Sorting

## Approach

1. Sort the people by the difference `aCost - bCost`. People at the front save the most by going to city `a`; people at the back save the most by going to city `b`.
2. Pair the sorted list from both ends: the first half goes to city `a`, the second half goes to city `b`.
3. Sum `aCost` for the front pointer and `bCost` for the back pointer while moving them inward.

## Time Complexity

`O(n log n)` for the sort, plus `O(n)` for the sweep.

## Space Complexity

`O(1)` extra space (ignoring the sort's internal usage).
