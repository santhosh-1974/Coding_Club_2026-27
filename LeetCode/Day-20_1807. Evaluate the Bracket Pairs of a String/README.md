# 1807. Evaluate the Bracket Pairs of a String

## Question

You are given a string `s` containing lowercase English letters and parentheses.

You are also given a 2D string array `knowledge`, where each pair `[key, value]` represents:
- `key` → a key
- `value` → the value associated with that key

For every `(key)` in `s`, replace it with its corresponding value from `knowledge`.

If the key does not exist, replace it with `"?"`.

Return the resulting string.

---

## Examples

### Example 1
Input:
s = "(name)is(age)yearsold"
knowledge = [["name","bob"],["age","two"]]

Output:
"bobistwoyearsold"

### Example 2
Input:
s = "hi(name)"
knowledge = [["a","b"]]

Output:
"hi?"

### Example 3
Input:
s = "(a)(a)(a)aaa"
knowledge = [["a","yes"]]

Output:
"yesyesyesaaa"

---

## Constraints

- `1 <= s.length <= 10^5`
- `1 <= knowledge.length <= 10^5`
- `knowledge[i].length == 2`
- `1 <= key.length, value.length <= 10`
- `s` contains lowercase English letters, `(`, and `)`.

---

## Topics

- Hash Map
- String
- String Parsing

---

## Approach

1. Store every `[key, value]` in a **Hash Map**.
2. Traverse `s` character by character.
3. If the character is not `(`, append it to the answer.
4. When `(` is found:
   - Find the corresponding `)`.
   - Extract the key between them.
   - Look up the key in the Hash Map.
   - Append its value, or `"?"` if it doesn't exist.
5. Return the answer.

### Key Idea

Use a **Hash Map for O(1) average lookup** and scan the string once.

---

## Time Complexity

**O(n + k)**

- `n` = length of `s`
- `k` = total size of `knowledge`

## Space Complexity

**O(k + n)**

- Hash Map → `O(k)`
- Result string → `O(n)`