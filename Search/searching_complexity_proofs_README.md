# Searching Algorithms --- Complexity Proofs

# 1. Linear Search --- Complexity Proof

## Important Code

``` c
for (i = 0; i < n; i++)
{
    if (a[i] == key)
        return i;
}
```

The algorithm checks the elements one by one from the beginning.

## Best Case

The required element is at the first position.

Only one comparison is required:
T(n)=1

Therefore:
T(n) = O(1)

## Worst Case

The element is at the last position, or the element does not exist.

The loop executes `n` times:
T(n)=n 

Therefore:
T(n) = O(n)

## Average Case

On average, the element is found around the middle of the array.

Approximately:
T(n) ≈ n / 2

Ignoring constants:
T(n) = O(n)

## Final Result

-   **Best Case:** O(1)
-   **Average Case:** O(n)
-   **Worst Case:** O(n)

------------------------------------------------------------------------

# 2. Binary Search --- Complexity Proof

## Important Code

``` c
while (low <= high)
{
    int mid = low + (high - low) / 2;

    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        low = mid + 1;
    else
        high = mid - 1;
}
```

Binary Search works only when the array is sorted.

The important observation is that after every iteration, the search
space is reduced to approximately half.

## Step 1: Search Space Reduction

Initially:
n

After one iteration:
n / 2

After two iterations:
n/4

After three iterations:
n/8

After `k` iterations:
n/2^k

The search ends when approximately one element remains:
n/2^k = 1

Therefore:
n=2\^k

Taking logarithm base 2:
k = log₂ n

Therefore:
T(n) = O(log n)

## Best Case

If the middle element is the required element, only one comparison is
required:
T(n) = O(1)

## Average/Worst Case

The search space continues to be divided into halves:
T(n) = O(log n)

## Final Result

-   **Best Case:** O(1)
-   **Average Case:** O(log n)
-   **Worst Case:** O(log n)

### What to point out in the code

The key lines are:

``` c
mid = low + (high - low) / 2;
```

and then either:

``` c
low = mid + 1;
```

or:

``` c
high = mid - 1;
```

These statements eliminate approximately half of the remaining elements
after every iteration.

------------------------------------------------------------------------

# Searching Algorithms --- Quick Comparison

  Algorithm       Requirement              Best    Average      Worst
  --------------- ---------------------- ------ ---------- ----------
  Linear Search   No sorting required      O(1)       O(n)       O(n)
  Binary Search   Array must be sorted     O(1)   O(log n)   O(log n)

------------------------------------------------------------------------

# Key Idea to Remember

> **Linear Search:** One-by-one checking → at most n elements → O(n).

> **Binary Search:** Half of the search space is eliminated each time →
> log₂n iterations → O(log n).

For searching algorithms, focus mainly on:

-   Number of comparisons
-   Number of loop iterations
-   Whether the search space is reduced
-   Whether the input array needs to be sorted
