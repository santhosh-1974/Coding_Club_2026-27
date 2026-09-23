# LeetCode 2091 — Removing Minimum and Maximum From Array

## Question

Given an array `nums` of **distinct integers**, remove both the **minimum** and **maximum** element using the minimum number of operations.

In one operation, you can remove an element from either:

* The **beginning** of the array
* The **end** of the array

Return the minimum number of operations required.

---

## Example 1

```text
Input:  nums = [2,10,7,5,4,1,8,6]

Output:  5
```

Explanation:

Remove `2` elements from the beginning and `3` from the end.

---

## Example 2

```text
Input:  nums = [0,-4,19,1,8,-2,-3,5]

Output:  3
```

---

## Example 3

```text
Input:  nums = [101]

Output:  1
```

---

## Constraints

```text
2 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
nums contains distinct integers.
```

---

## Topics

* Array
* Greedy
* Two Pointers

---

## Key Observation

Find the indices of:

```text
minIndex = index of minimum element
maxIndex = index of maximum element
```

For an element at index `i`, there are **3 ways** to remove it:

```text
1. Remove from left:
   i + 1

2. Remove from right:
   n - i

3. Remove from both sides:
   (i + 1) + (n - j)
```

For minimum and maximum at indices `a` and `b`, assume:

```text
a = min(a,b)
b = max(a,b)
```

Then only **3 strategies** matter.

### Strategy 1 — Remove both from left

```text
b + 1
```

### Strategy 2 — Remove both from right

```text
n - a
```

### Strategy 3 — Remove one from each side

```text
(a + 1) + (n - b)
```

Take the minimum of the three.

---

## Approach

```text
1. Find index of minimum element.
2. Find index of maximum element.
3. Let:
      a = min(minIndex, maxIndex)
      b = max(minIndex, maxIndex)

4. Calculate:
      left  = b + 1
      right = n - a
      both  = (a + 1) + (n - b)

5. Return min(left, right, both).
```

---

## Complexity

```text
Time Complexity:  O(n)

Space Complexity: O(1)
```

We scan the array once to find the minimum and maximum indices.

---

## Pattern

```text
Array
  ↓
Find min/max indices
  ↓
3 possible removal strategies
  ↓
Take minimum
```

**Main pattern:** `Greedy / Array / Index-based optimization`
