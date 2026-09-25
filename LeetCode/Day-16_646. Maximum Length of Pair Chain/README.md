# 646. Maximum Length of Pair Chain

## Question
You are given `n` pairs `[a, b]` where `a < b`.

A pair `[a, b]` can follow `[c, d]` if:

`b < c`

Return the **maximum length of a chain** that can be formed.

---

## Examples

### Example 1
Input:
`pairs = [[1,2],[2,3],[3,4]]`

Output:
`2`

Explanation:
`[1,2] -> [3,4]`

---

### Example 2
Input:
`pairs = [[1,2],[7,8],[4,5]]`

Output:
`3`

Explanation:
`[1,2] -> [4,5] -> [7,8]`

---

### Example 3
Input:
`pairs = [[1,10],[2,3],[4,5],[6,7]]`

Output:
`3`

Explanation:
`[2,3] -> [4,5] -> [6,7]`

---

## Constraints

- `n == pairs.length`
- `1 <= n <= 1000`
- `-1000 <= a < b <= 1000`

---

## Topics

- Greedy
- Sorting
- Intervals
- Dynamic Programming (alternative)

---

## Approach — Greedy

1. Sort pairs by their **ending value**.
2. Keep track of the end of the last selected pair.
3. If `currentStart > lastEnd`, select the pair.
4. Continue until all pairs are processed.

### Why?
Choosing the pair that **ends earliest** leaves the maximum possible space for future pairs.

---

## Complexity

### Time
`O(n log n)` — sorting

### Space
`O(1)` extra space (excluding sorting space)

---

## Key Pattern

**Interval problems → if maximizing the number of non-overlapping intervals, try sorting by END.**