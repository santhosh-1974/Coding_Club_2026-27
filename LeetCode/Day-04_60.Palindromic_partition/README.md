Sure. Here is the README with the **code section removed**.

# Palindrome Partitioning

**LeetCode 131 — Palindrome Partitioning**

## Problem

Given a string `s`, partition `s` such that every substring of the partition is a palindrome.

Return all possible palindrome partitionings of `s`.

### Example

**Input:**

```text
s = "aab"
```

**Output:**

```text
[
    ["a","a","b"],
    ["aa","b"]
]
```

## Approach

This problem is solved using **Backtracking**.

At each index, try every possible substring starting from that index.

For each substring:

1. Check whether it is a palindrome.
2. If it is, add it to the current partition.
3. Recursively process the remaining part of the string.
4. Remove the substring after returning from recursion to try another possibility.

### Backtracking Pattern

```text
Choose → Explore → Undo
```

```text
For every possible ending position:
    If substring is palindrome:
        Choose substring
        Recursively solve remaining string
        Undo choice
```

## Algorithm

1. Start from index `0`.
2. Try all substrings `s[index...i]`.
3. Check if `s[index...i]` is a palindrome.
4. If it is a palindrome:

   * Add it to the current partition.
   * Recursively process the remaining string from `i + 1`.
   * Remove it from the current partition.
5. When `index == s.length()`, the current partition is complete, so add it to the answer.

## Complexity

Let `n` be the length of the string.

There can be up to `2^(n-1)` possible partitions.

Palindrome checking can take `O(n)` in the worst case.

Therefore, the overall time complexity is approximately:

```text
O(2^n × n²)
```

The recursion stack requires `O(n)` auxiliary space, excluding the space required to store the output.

## Key Pattern

This problem follows the **Backtracking / Partitioning** pattern.

The reusable structure is:

```text
For every possible choice:
    Check whether the choice is valid
    Choose
    Explore recursively
    Undo the choice
```

### Main Insight

> At every position, try every possible next partition and recursively solve the remaining string.

The important variables are:

* `index` → where the current partition starts
* `i` → where the current partition ends
* `i + 1` → starting position for the next recursive call
* `temp` → current partition
* `ans` → all valid partitions
