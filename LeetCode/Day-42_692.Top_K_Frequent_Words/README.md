# LeetCode 692 - Top K Frequent Words



## Problem



Given an array of strings `words` and an integer `k`, return the `k` most frequent strings.



Return the answer sorted by the frequency from highest to lowest. Words that have the same frequency are sorted by their lexicographical order.



## Example



Input:

words = ["i","love","leetcode","i","love","coding"], k = 2



Output:

["i","love"]



Explanation:

"i" and "love" are the two most frequent words. Note that "i" comes before "love" due to a lower alphabetical order.



## Approach



Use hashing + sorting.



Steps:



- Count the frequency of every word using an `unordered_map`

- Move the (word, frequency) pairs into a vector

- Sort the vector with a custom comparator:

  - Higher frequency comes first

  - If frequencies are equal, the lexicographically smaller word comes first

- Take the first `k` words as the answer



## Complexity



Time Complexity: O(n log n)



Space Complexity: O(n)



where n is the number of words.



## Topics



- Array

- Hash Table

- String

- Sorting

- Heap (Priority Queue)



## LeetCode



Problem 692 - Top K Frequent Words
