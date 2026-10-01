# 140. Word Break II

## Question

Given a string `s` and a dictionary `wordDict`, return all possible sentences formed by splitting `s` into words from the dictionary. Return the sentences in any order.

## Example

```text
Input: s = "catsanddog", wordDict = ["cat", "cats", "and", "sand", "dog"]
Output: ["cats and dog", "cat sand dog"]
```

## Constraints

- `1 <= s.length <= 20`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 10`
- `s` and `wordDict[i]` contain only lowercase English letters.

## Topics

- String
- Backtracking
- Trie
- Dynamic Programming

## Approach

1. Store the dictionary words in an `unordered_set` for fast lookups.
2. Starting at the current index, try every possible next substring.
3. When a substring is in the dictionary, append it to the sentence and recursively continue from the next index.
4. When the end of the string is reached, remove the trailing space and save the completed sentence.

## Time Complexity

The number of valid sentences can be exponential in the length of `s`. The recursion explores each valid segmentation and checks candidate substrings.

## Space Complexity

`O(N)` recursion depth, excluding the output. The output can contain exponentially many sentences.
