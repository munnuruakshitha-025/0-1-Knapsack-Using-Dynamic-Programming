# 0/1 Knapsack Using Dynamic Programming

## Aim

To implement the 0/1 Knapsack problem using Dynamic Programming and determine the maximum possible value that can be obtained within the given knapsack capacity.

## Problem Statement

Given a set of items, where each item has a specific weight and value, and a knapsack with a limited capacity, select items such that the total value is maximized without exceeding the capacity.

In the 0/1 Knapsack problem, each item can either be completely selected or completely rejected. An item cannot be divided into fractions.

## Case Study

### Student Backpack Optimization

A student needs to pack important items into a backpack for college. Each item has a specific weight and value based on its usefulness.

The backpack has a limited weight capacity. The student needs to select a combination of items that provides the maximum total value without exceeding the backpack's weight limit.

Since each item is either selected completely or not selected at all, this situation can be modeled using the 0/1 Knapsack problem.

### Example Items

| Item       | Weight | Value |
| ---------- | ------ | ----- |
| Book       | 1 kg   | ₹1    |
| Laptop     | 3 kg   | ₹4    |
| Headphones | 4 kg   | ₹5    |
| Power Bank | 5 kg   | ₹7    |

Knapsack Capacity = 7 kg

The objective is to select items that maximize the total value while keeping the total weight within 7 kg.

## Dynamic Programming Approach

Dynamic Programming is used because the problem contains overlapping subproblems and optimal substructure.

A two-dimensional DP table is created:

`dp[i][w]`

where:

* `i` represents the number of items considered.
* `w` represents the current knapsack capacity.
* `dp[i][w]` represents the maximum value that can be obtained using the first `i` items with capacity `w`.

For every item, there are two choices:

1. **Exclude the item**
2. **Include the item**, if its weight is within the current capacity.

The maximum of these two choices is stored in the DP table.

## Recurrence Relation

If the weight of the current item is less than or equal to the current capacity:

```text
dp[i][w] = max(
    value[i] + dp[i-1][w-weight[i]],
    dp[i-1][w]
)
```

Otherwise:

```text
dp[i][w] = dp[i-1][w]
```

## Algorithm

1. Read the number of items.
2. Read the weight and value of each item.
3. Read the knapsack capacity.
4. Create a DP table of size `(n+1) × (capacity+1)`.
5. Initialize the first row and first column to zero.
6. For every item:

   * Check every possible capacity.
   * If the item fits, choose the maximum between including and excluding the item.
   * Otherwise, exclude the item.
7. Display the complete DP table.
8. Store the maximum value from `dp[n][capacity]`.
9. Trace the DP table backwards to identify the selected items.
10. Create a solution vector where `1` represents a selected item and `0` represents an unselected item.
11. Display the solution vector.
12. Display the selected items, total weight, and maximum value.

## Program

The implementation is provided in `0_1_Knapsack_DP.cpp`.

## Sample Input

```text
4
1 1
3 4
4 5
5 7
7
```

Where:

* `4` = number of items
* Each following line contains `weight value`
* `7` = knapsack capacity

## Sample DP Table

```text
     0 1 2 3 4 5 6 7
I0   0 0 0 0 0 0 0 0
I1   0 1 1 1 1 1 1 1
I2   0 1 1 4 5 5 5 5
I3   0 1 1 4 5 6 6 9
I4   0 1 1 4 5 7 8 9
```

## Sample Solution Vector

```text
0 1 1 0
```

This means:

| Item   | Solution         |
| ------ | ---------------- |
| Item 1 | 0 - Not Selected |
| Item 2 | 1 - Selected     |
| Item 3 | 1 - Selected     |
| Item 4 | 0 - Not Selected |

## Sample Output

```text
DP Table:

     0 1 2 3 4 5 6 7
I0   0 0 0 0 0 0 0 0
I1   0 1 1 1 1 1 1 1
I2   0 1 1 4 5 5 5 5
I3   0 1 1 4 5 6 6 9
I4   0 1 1 4 5 7 8 9

Solution Vector:
0 1 1 0

Selected Items:
Item 2 - Weight: 3, Value: 4
Item 3 - Weight: 4, Value: 5

Total Weight: 7
Maximum Value: 9
```

## Complexity Analysis

Let:

* `n` = number of items
* `W` = knapsack capacity

### Time Complexity

The DP table has `n × W` states, and each state takes constant time to calculate.

**Time Complexity = O(n × W)**

### Space Complexity

The two-dimensional DP table requires:

**Space Complexity = O(n × W)**

## Advantages

* Produces the optimal solution.
* Handles the 0/1 restriction correctly.
* Avoids solving the same subproblem repeatedly.
* Makes the decision process visible through the DP table.
* Suitable for problems with overlapping subproblems and optimal substructure.

## Limitations

* The space requirement can be large for very high capacity values.
* The algorithm depends on the numerical capacity of the knapsack, so it can be expensive when the capacity is very large.

## Why Dynamic Programming Works

The 0/1 Knapsack problem has optimal substructure and overlapping subproblems.

The optimal solution for a particular item and capacity can be constructed from solutions to smaller item and capacity combinations. Dynamic Programming stores these smaller results so that they do not need to be calculated repeatedly.

Unlike Fractional Knapsack, items cannot be divided. Therefore, a greedy approach based only on value, weight, or value-to-weight ratio does not always guarantee the optimal solution.

## Technologies Used

* C++
* Data Structures and Algorithms
* Dynamic Programming

## Key Concepts

* 0/1 Knapsack
* Dynamic Programming
* DP Table
* Solution Vector
* Recurrence Relation
* Optimal Substructure
* Overlapping Subproblems
* Optimization
* Time and Space Complexity

## Result

The 0/1 Knapsack problem was successfully implemented using Dynamic Programming. The algorithm determines the optimal combination of items that maximizes the total value without exceeding the given knapsack capacity. The DP table and solution vector are also displayed to show the decision-making process.
