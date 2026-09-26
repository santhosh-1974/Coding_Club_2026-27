# 97. Interleaving String

## Question

Given strings `s1`, `s2`, and `s3`, determine whether `s3` can be formed by **interleaving** `s1` and `s2` while maintaining the original character order of both strings.

## Examples

### Example 1

```text
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"

Output: false
```

### Example 2

```text
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"

Output: false
```

## Constraints

```text
1 <= s1.length, s2.length <= 100
1 <= s3.length <= 200
s1.length + s2.length == s3.length
```

## Topics

* Recursion
* Dynamic Programming
* 2D DP
* State / Choice
* Memoization

## Approach

At every position, `s3[k]` can come from:

```text
s1[i] → (i+1, j, k+1)
s2[j] → (i, j+1, k+1)
```

If both characters match, try **both choices**.

Important:

```text
k = i + j
```

So `k` is redundant in the optimized DP solution.

### DP State

```text
dp[i][j] = whether s1[i...] and s2[j...]
           can form s3[i+j...]
```

### Base Case

```text
i == n → remaining s2 must match remaining s3
j == m → remaining s1 must match remaining s3
```

## Complexity

### Optimized 2D DP

```text
Time:  O(n × m)
Space: O(n × m)
```

### Space-optimized DP

```text
Time:  O(n × m)
Space: O(m)
```
