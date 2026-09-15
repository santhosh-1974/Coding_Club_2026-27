# Restore IP Addresses

## Question

Given a string `s` containing only digits, return all possible valid IP addresses that can be formed by inserting three dots into the string.

A valid IP address consists of exactly four integers:

* Each integer is between `0` and `255`.
* Leading zeros are not allowed.
* Each integer contains one to three digits.

---

## Example

### Input

```text
s = "25525511135"
```

### Output

```text
["255.255.11.135", "255.255.111.35"]
```

---

## Constraints

```text
1 <= s.length <= 20
s consists of digits only.
```

---

## Topics

* Recursion
* Backtracking
* String Manipulation
* Substrings
* Validation

---

## Approach

Use **backtracking** to divide the string into exactly four valid segments.

At every recursive call:

1. Try taking `1`, `2`, or `3` digits as the current segment.
2. Check whether the segment is valid:

   * Value must be between `0` and `255`.
   * Leading zeros are not allowed.
3. If valid, recursively process the remaining string.
4. After selecting the first three segments, the remaining substring becomes the fourth segment.
5. If the fourth segment is valid, add the constructed IP address to the answer.

For example:

```text
25525511135

255 | 255 | 11 | 135
255 | 255 | 111 | 35
```

---

## Time Complexity

```text
O(3^4 * N)
```

Since an IP address contains only 4 segments, the number of possible partitions is bounded by a small constant.

---

## Space Complexity

```text
O(N)
```

for the recursion/string construction, excluding the output.
