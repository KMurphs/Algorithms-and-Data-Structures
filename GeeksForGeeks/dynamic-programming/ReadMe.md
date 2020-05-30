# Dynamic Programming

Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again. 

Following are the two main properties of a problem that suggests that the given problem can be solved using Dynamic programming:

* **Optimal Substructure** (aka a recursive invariant)
* **Overlapping Subproblems** (aka needs a table to store results)


## Optimal Substructure

> A given problem has Optimal Substructure Property if **optimal solution of the given problem** can be obtained by using **optimal solutions of its subproblems**.

We can find a recursive solution that contributes to the solution of the bigger problem by providing solutions to subproblems, e.g:
```
if last chars are identical
  L("AGGTAB", "GXTXAYB") = 1 + L("AGGTA", "GXTXAY")

else
  L("ABCDGH", "AEDFHR") = MAX (L("ABCDG", "AEDFHR"), L("ABCDGH", "AEDFH"))

Solution for Longest Common Subsequence problem
```

## Overlapping Subproblems

Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems. Dynamic Programming is mainly used when solutions of same subproblems are needed again and again.

Usually, considering the tree of solution dependencies should put in evidence that same solution are needed at different points.

The obvious thing to do in this case is to store results, which can be done in two ways:
* Memoization (Top - Down)
* Tabulation (Bottom - Up)

### **Memoization**

The memoized program for a problem is similar to the recursive version (without storage) with a small modification that it looks into a lookup table before computing solutions.

If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later.

### **Tabulation**

The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table. 

For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on.


# References
https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/
https://www.geeksforgeeks.org/optimal-substructure-property-in-dynamic-programming-dp-2/