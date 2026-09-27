# Topic: Maximum Equal Adjacent Pairs

## Question
Given a 1-indexed integer array `nums`, choose two distinct values `x` and `y` and replace every occurrence of `x` with `y` at most once. Return the maximum number of adjacent pairs having equal elements.

## Examples

### Example 1
Input:
[2,8,2,5,5,6]

Output:
3

Explanation:
Replace `8 → 2`:
[2,2,2,5,5,6]

Equal adjacent pairs = 3.

### Example 2
Input:
[1,2,1,2]

Output:
2

Replace `1 → 2`:
[2,2,2,2]

Equal adjacent pairs = 3.

### Example 3
Input:
[1,2,3,4]

Output:
1

Replace `1 → 2`:
[2,2,3,4]

## Constraints
- `1 <= nums.length <= 10^5`
- `nums[i]` can be positive/negative integers.
- Choose distinct `x` and `y`.
- Replacement is global: **every occurrence** of `x` changes to `y`.

## Topic
Hash Map + Adjacent Pair Counting

## Approach
1. Count existing equal adjacent pairs.
2. For every unequal adjacent pair `(x,y)`, count its frequency.
3. Treat `(x,y)` and `(y,x)` as the same pair.
4. Replacing one value with the other creates one new equal pair for every occurrence of that pair.
5. Answer = existing pairs + maximum pair frequency.

## Key Observation
For an operation `x → y`, only these can become equal:

`x y → y y`

or

`y x → y y`

So we only need to count adjacent unequal pairs.

## Time Complexity
`O(n)` expected using `unordered_map`.

## Space Complexity
`O(n)`.

## Important
**Do NOT use sliding window.**

The replacement is **global**, so `x` and `y` can be far apart and still be affected by the same operation.

Example:

`[1,2,3,1,2]`

`1 → 2`

becomes:

`[2,2,3,2,2]`

Both separated regions are affected by one operation.