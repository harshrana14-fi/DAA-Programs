# Searching Algorithms --- Complexity Proofs

This README explains how to prove the time complexity of each searching
algorithm directly from the code. The main idea is:

> **Code → identify loops/recursive calls → count operations → form T(n)
> → simplify using Big-O.**

You do not need to prove every individual statement. Focus on the loop,
comparisons, and the way the search space changes.

------------------------------------------------------------------------

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

\[ T(n)=1 \]

Therefore:

\[ `\boxed{T(n)=O(1)}`{=tex} \]

## Worst Case

The element is at the last position, or the element does not exist.

The loop executes `n` times:

\[ T(n)=n \]

Therefore:

\[ `\boxed{T(n)=O(n)}`{=tex} \]

## Average Case

On average, the element is found around the middle of the array.

Approximately:

\[ T(n)`\approx`{=tex}`\frac{n}{2}`{=tex} \]

Ignoring constants:

\[ `\boxed{T(n)=O(n)}`{=tex} \]

## Final Result

-   **Best Case:** O(1)
-   **Average Case:** O(n)
-   **Worst Case:** O(n)

### What to explain in viva

> Linear Search checks elements sequentially. In the worst case it may
> have to check all n elements, so its time complexity is O(n).

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

\[ n \]

After one iteration:

\[ `\frac{n}{2}`{=tex} \]

After two iterations:

\[ `\frac{n}{4}`{=tex} \]

After three iterations:

\[ `\frac{n}{8}`{=tex} \]

After `k` iterations:

\[ `\frac{n}{2^k}`{=tex} \]

The search ends when approximately one element remains:

\[ `\frac{n}{2^k}`{=tex}=1 \]

Therefore:

\[ n=2\^k \]

Taking logarithm base 2:

\[ k=`\log`{=tex}\_2 n \]

Therefore:

\[ `\boxed{T(n)=O(\log n)}`{=tex} \]

## Best Case

If the middle element is the required element, only one comparison is
required:

\[ `\boxed{T(n)=O(1)}`{=tex} \]

## Average/Worst Case

The search space continues to be divided into halves:

\[ `\boxed{T(n)=O(\log n)}`{=tex} \]

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

# How to Write the Complexity Proof in the Lab Record

After every program, add a section named:

## Complexity Analysis

For Linear Search:

``` text
Best case:
Element is at the first position.

Number of comparisons = 1

T(n) = O(1)
```

For the worst case:

``` text
Element is at the last position or absent.

Number of comparisons = n

T(n) = O(n)
```

For Binary Search:

``` text
Search space:

n → n/2 → n/4 → n/8 → ... → 1

After k iterations:

n / 2^k = 1

Therefore:

2^k = n

k = log₂n

Hence:

T(n) = O(log n)
```

This shows the mathematical reasoning behind the Big-O value rather than
simply stating the complexity.

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
