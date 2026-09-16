# LC 140 — Word Break II

## Question

Given a string `s` and a dictionary `wordDict`, return **all possible sentences** formed by splitting `s` into valid dictionary words.

## Example

```text
s = "catsanddog"
wordDict = ["cat","cats","and","sand","dog"]

Output:
["cat sand dog", "cats and dog"]
```

## Constraints

```text
1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
lowercase English letters
```

## Topics

```text
Recursion
Backtracking
DFS
Memoization
HashSet
Dynamic Programming
```

## Approach

```text
dfs(start)

1. If start == n → return [""]

2. If start is in memo → return memo[start]

3. Try every substring s[start...end]

4. If substring is in wordSet:
      recursively solve dfs(end)
      append current word to every result

5. Store result in memo[start]
```

### Pattern

```text
Choose → Recurse → Combine → Memoize
```

## Time Complexity

```text
O(2^N) 
```

Output can itself contain exponentially many sentences.

## Space Complexity

```text
O(N + output size)
```
