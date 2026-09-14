# LeetCode 698 - Partition to K Equal Sum Subsets

## Question

Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide `nums` into `k` non-empty subsets such that the sum of the elements in every subset is equal.

Otherwise, return `false`.

## Example

**Input:**

`nums = [4,3,2,3,5,2,1]`  
`k = 4`

**Output:**

`true`

**Explanation:**

The array can be divided into:

`[5]`  
`[1,4]`  
`[2,3]`  
`[2,3]`

Each subset has sum `5`.

## Constraints

- `1 <= k <= nums.length <= 16`
- `1 <= nums[i] <= 10^4`
- The sum of all elements of `nums` is at most `10^4`

## Approach

Use **Backtracking** to build one subset at a time.

1. Calculate the total sum of the array.
2. If `total % k != 0`, return `false` because the array cannot be divided into equal-sum subsets.
3. Calculate the target sum of each subset:
   `target = total / k`
4. Sort the array in descending order so larger elements are considered first. This helps invalid branches fail earlier.
5. Maintain a `used[]` array to track elements that have already been selected.
6. Build the current subset using the variable `sum`.
7. If `sum == target`, the current subset is complete. Start building the next subset.
8. If `k == 1`, return `true` because the remaining elements must form the final subset.
9. Skip an element if it is already used or if adding it makes the current sum greater than `target`.
10. If the current choice does not lead to a solution, undo the choice and try another element.

### Backtracking Pattern

`Choose -> Explore -> Undo`

```cpp
used[i] = true;

if (helper(...))
    return true;

used[i] = false;