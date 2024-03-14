# Pushswap

## Overview
Pushswap is a simple sorting algorithm project in which the goal is to sort a stack of numbers using a limited set of operations. The project focuses on algorithmic problem-solving and understanding the principles of stack manipulation.

## Principle
The principle of Pushswap revolves around two stacks, named stack A and stack B. Initially, all numbers to be sorted are placed on stack A, and stack B is empty. The objective is to arrange the numbers on stack A in ascending order, using a defined set of operations, while adhering to the following constraints:
- Only the following operations are allowed:
  - `sa`: Swap the first two elements of stack A.
  - `sb`: Swap the first two elements of stack B.
  - `ss`: Do `sa` and `sb` simultaneously.
  - `pa`: Push the first element of stack B to stack A.
  - `pb`: Push the first element of stack A to stack B.
  - `ra`: Rotate stack A (shift all elements up by one).
  - `rb`: Rotate stack B (shift all elements up by one).
  - `rr`: Do `ra` and `rb` simultaneously.
  - `rra`: Reverse rotate stack A (shift all elements down by one).
  - `rrb`: Reverse rotate stack B (shift all elements down by one).
  - `rrr`: Do `rra` and `rrb` simultaneously.
- At the end of the sorting, stack A must be sorted in ascending order, and stack B must be empty.

## Usage
To run Pushswap, follow these steps:
1. Clone the repository:

```git clone https://github.com/Lilien86/42-push_swap```
```cd 42-push_swap```

2. Compilation

```make```

3. Run

```./push_wap 4 8 12 -7 ect..```
