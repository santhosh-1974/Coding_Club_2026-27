# 4056. Number of Intersecting Interval Pairs I

## Question

Given `n` closed intervals `[start, end]`, count the number of pairs `(i, j)` where `i < j` and the two intervals intersect.

Intervals that share an endpoint are also considered intersecting.

## Examples

**Example 1**

```text
Input:  [[1,2],[2,3],[3,4]]
Output: 2
```

**Example 2**

```text
Input:  [[1,5],[2,4],[3,6]]
Output: 3
```

**Example 3**

```text
Input:  [[1,2],[3,4],[5,6]]
Output: 0
```

## Constraints

```text
2 <= n <= 100
0 <= starti <= endi <= 100
```

## Exact Topics

* Arrays
* 2D Arrays
* Intervals
* Nested Loops
* Pairwise Comparison
* Interval Intersection

## Approach

Take every possible pair of intervals using two loops.

For two intervals `[a,b]` and `[c,d]`, they **do not intersect** if one lies completely before the other:

```text
b < c  OR  d < a
```

So they intersect when:

```text
a <= d && c <= b
```

Whenever this condition is true, increment the answer.

## TC & SC

* **Time:** `O(n²)` — check every pair
* **Space:** `O(1)` — only a counter and loop variables
