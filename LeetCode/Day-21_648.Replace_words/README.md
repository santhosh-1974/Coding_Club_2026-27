# 648. Replace Words

## Question

Given a dictionary of roots and a sentence, replace every word in the sentence with its
**shortest root** from the dictionary that is a prefix of that word.

If no root exists, keep the original word.

Return the resulting sentence.

## Examples

### Example 1

Input:
dictionary = ["cat","bat","rat"]
sentence = "the cattle was rattled by the battery"

Output:
"the cat was rat by the bat"

### Example 2

Input:
dictionary = ["a","b","c"]
sentence = "aadsfasf absbs bbab cadsfafs"

Output:
"a a b c"

### Example 3

Input:
dictionary = ["catt","cat","bat","rat"]
sentence = "the cattle was rattled by the battery"

Output:
"the cat was rat by the bat"

## Constraints

- 1 <= dictionary.length <= 1000
- 1 <= dictionary[i].length <= 100
- dictionary[i] consists of lowercase English letters.
- 1 <= sentence.length <= 10^6
- sentence consists of lowercase English letters and spaces.
- Words are separated by a single space.

## Topics

- String
- Hash Set
- Prefix
- String Parsing
- Greedy

## Approach

1. Put all dictionary roots into an `unordered_set`.
2. Process the sentence character by character.
3. Build each word/prefix character by character.
4. Whenever the current prefix exists in the set:
   - It is the shortest root for that word.
   - Add it to the answer.
   - Skip the remaining characters of that word.
5. If no root is found, add the complete word.
6. Remove the final extra space if necessary.

### Key Idea

Because we build the word from **left to right**, the **first prefix found in the
dictionary is automatically the shortest root**.

## Time Complexity

`O(S)`

Where `S` = length of the sentence.

Each character is processed essentially once.

## Space Complexity

`O(D + S)`

- `D` = total size of dictionary
- `S` = output string
