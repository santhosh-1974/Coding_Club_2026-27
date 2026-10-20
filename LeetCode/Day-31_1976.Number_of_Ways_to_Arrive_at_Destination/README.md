# 1976. Number of Ways to Arrive at Destination

## Question

There are `n` intersections numbered from `0` to `n - 1`, connected by bidirectional roads. Each road has a travel time. Return the number of different ways to travel from intersection `0` to intersection `n - 1` in the shortest possible time, modulo `10^9 + 7`.

## Examples

### Example 1

Input: `n = 7`, `roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[6,5,1],[3,5,1],[2,5,1],[0,4,5],[4,6,2]]`

Output: `4`

### Example 2

Input: `n = 2`, `roads = [[1,0,10]]`

Output: `1`

## Constraints

- `1 <= n <= 200`
- `n - 1 <= roads.length <= n * (n - 1) / 2`
- `roads[i].length == 3`
- `0 <= ui, vi <= n - 1`
- `ui != vi`
- `1 <= timei <= 10^9`
- There is at most one road between each pair of intersections.
- The graph is connected.

## Topics

- Graph
- Dynamic Programming
- Dijkstra's Algorithm

## Approach

1. Build an adjacency list for the undirected roads.
2. Run Dijkstra's algorithm from intersection `0`, tracking the shortest distance to each intersection.
3. Track the number of shortest paths to each intersection. A shorter route replaces its path count; an equally short route adds to it modulo `10^9 + 7`.
4. Skip outdated priority-queue entries and return the path count for intersection `n - 1`.

## Time Complexity

`O((n + E) log n)`, where `E` is the number of roads.

## Space Complexity

`O(n + E)` for the adjacency list, distance and path arrays, and priority queue.
