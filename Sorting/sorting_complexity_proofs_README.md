# Sorting Algorithms --- Complexity Proofs

This README explains how to prove the time complexity of each sorting
algorithm directly from the code. The main idea is:

> **Code → identify loops/recursive calls → count operations → form T(n)
> → simplify using Big-O.**

You do not need to prove every individual statement. Focus on the loops,
comparisons, swaps, and recursive calls that dominate the running time.

------------------------------------------------------------------------

# 1. Merge Sort --- Complexity Proof

## Important Code

``` c
void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
```

The `merge()` function processes all elements in the current range.

## Step 1: Divide

The array of size `n` is divided into two parts:

\[ n `\rightarrow `{=tex}`\frac{n}{2}`{=tex} + `\frac{n}{2}`{=tex} \]

There are two recursive calls:

``` c
mergeSort(a, low, mid);
mergeSort(a, mid + 1, high);
```

Therefore, the recursive part contributes:

\[ 2T(n/2) \]

## Step 2: Merge

The `merge()` function compares and copies the elements. At each level,
approximately `n` elements are processed.

Therefore, merging takes:

\[ O(n) \]

## Step 3: Recurrence

Hence:

\[ T(n)=2T(n/2)+cn \]

Using the recurrence-tree method:

  Level     Work
  ------- ------
  0            n
  1            n
  2            n
  3            n
  ...        ...
  log₂n        n

Number of levels:

\[ `\log`{=tex}\_2 n \]

Therefore:

\[ T(n)=n`\log`{=tex}\_2n \]

Hence:

\[ `\boxed{T(n)=O(n\log n)}`{=tex} \]

## Final Result

-   **Best Case:** O(n log n)
-   **Average Case:** O(n log n)
-   **Worst Case:** O(n log n)

### What to explain in viva

> Merge Sort always divides the array into two halves, and merging takes
> linear time at every level. There are log n levels, so the total
> complexity is n × log n = O(n log n).

------------------------------------------------------------------------

# 2. Quick Sort --- Complexity Proof

## Important Code

``` c
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}
```

The `for` loop executes approximately `n - 1` times.

Therefore, partitioning takes:

\[ O(n) \]

The final complexity depends on how the pivot divides the array.

## Best/Average Case

Suppose the pivot divides the array approximately equally:

\[ T(n)=2T(n/2)+cn \]

This is the same recurrence as Merge Sort.

Therefore:

\[ `\boxed{T(n)=O(n\log n)}`{=tex} \]

## Worst Case

Suppose the pivot is always the smallest or largest element.

The partitions become:

\[ 0+(n-1) \]

Therefore:

\[ T(n)=T(n-1)+cn \]

Expanding:

\[ T(n)=T(n-2)+c(n-1)+cn \]

Eventually:

\[ T(n)=c(1+2+3+`\cdots`{=tex}+n) \]

We know:

\[ 1+2+3+`\cdots`{=tex}+n=`\frac{n(n+1)}{2}`{=tex} \]

Therefore:

\[ T(n)=O(n\^2) \]

## Final Result

-   **Best Case:** O(n log n)
-   **Average Case:** O(n log n)
-   **Worst Case:** O(n²)

### What to point out from the code

``` c
for (j = low; j < high; j++)
```

This gives O(n) partitioning.

Then:

``` c
quickSort(...);
quickSort(...);
```

These are recursive calls. The shape of the partition determines whether
the result is O(n log n) or O(n²).

------------------------------------------------------------------------

# 3. Bubble Sort --- Complexity Proof

## Important Code

``` c
for (i = 0; i < n - 1; i++)
{
    swapped = 0;

    for (j = 0; j < n - i - 1; j++)
    {
        if (a[j] > a[j + 1])
        {
            // swap
        }
    }
}
```

The inner loop executes:

-   `n - 1` times in the first pass
-   `n - 2` times in the second pass
-   `n - 3` times in the third pass
-   ...
-   `1` time in the last pass

Total comparisons:

\[ (n-1)+(n-2)+(n-3)+`\cdots`{=tex}+1 \]

This is:

\[ `\frac{n(n-1)}{2}`{=tex} \]

Therefore:

\[ T(n)=`\frac{n(n-1)}{2}`{=tex} \]

Expanding:

\[ T(n)=`\frac{n^2-n}{2}`{=tex} \]

Ignoring constants and lower-order terms:

\[ `\boxed{T(n)=O(n^2)}`{=tex} \]

## Best Case

The optimized code contains:

``` c
if (swapped == 0)
    break;
```

If the array is already sorted, the algorithm stops after one pass.

The first pass performs approximately:

\[ n-1 \]

comparisons.

Therefore:

\[ `\boxed{T(n)=O(n)}`{=tex} \]

## Final Result

-   **Best Case:** O(n)
-   **Average Case:** O(n²)
-   **Worst Case:** O(n²)

### What to point out in viva

Point to:

``` c
if (swapped == 0)
    break;
```

Because when a complete pass makes no swaps, the array is already sorted
and the algorithm terminates.

------------------------------------------------------------------------

# 4. Selection Sort --- Complexity Proof

## Important Code

``` c
for (i = 0; i < n - 1; i++)
{
    min = i;

    for (j = i + 1; j < n; j++)
    {
        if (a[j] < a[min])
            min = j;
    }

    // swap
}
```

The inner loop executes:

\[ n-1, n-2, n-3,`\ldots`{=tex},1 \]

times.

Therefore total comparisons are:

\[ (n-1)+(n-2)+`\cdots`{=tex}+1 \]

\[ =`\frac{n(n-1)}{2}`{=tex} \]

Thus:

\[ T(n)=`\frac{n(n-1)}{2}`{=tex} \]

\[ T(n)=`\frac{n^2-n}{2}`{=tex} \]

Ignoring constants and lower-order terms:

\[ `\boxed{T(n)=O(n^2)}`{=tex} \]

## Best Case

Even if the array is already sorted, Selection Sort still searches for
the minimum element in the remaining unsorted portion.

Therefore:

\[ `\boxed{T(n)=O(n^2)}`{=tex} \]

## Final Result

-   **Best Case:** O(n²)
-   **Average Case:** O(n²)
-   **Worst Case:** O(n²)

### Important viva point

Selection Sort performs almost the same number of comparisons regardless
of the initial ordering of the array. Therefore, its best, average, and
worst-case time complexity are all O(n²).

------------------------------------------------------------------------

# 5. Heap Sort --- Complexity Proof

## Important Code

``` c
for (i = n / 2 - 1; i >= 0; i--)
    heapify(a, n, i);

for (i = n - 1; i > 0; i--)
{
    swap(&a[0], &a[i]);
    heapify(a, i, 0);
}
```

There are two major parts.

## Part 1: Building the Heap

The first loop builds the heap:

``` c
for (i = n / 2 - 1; i >= 0; i--)
    heapify(a, n, i);
```

The total complexity of building a heap is:

\[ `\boxed{O(n)}`{=tex} \]

> Important: Building a heap is O(n), not O(n log n).

## Part 2: Removing Elements

The second loop runs approximately `n` times:

``` c
for (i = n - 1; i > 0; i--)
```

Each iteration calls:

``` c
heapify(a, i, 0);
```

The height of a binary heap is:

\[ O(`\log `{=tex}n) \]

Therefore, one `heapify()` operation takes:

\[ O(`\log `{=tex}n) \]

It happens approximately `n` times:

\[ n`\times `{=tex}O(`\log `{=tex}n)=O(n`\log `{=tex}n) \]

## Total Complexity

\[ O(n)+O(n`\log `{=tex}n) \]

Since `n log n` dominates `n`:

\[ `\boxed{T(n)=O(n\log n)}`{=tex} \]

## Final Result

-   **Best Case:** O(n log n)
-   **Average Case:** O(n log n)
-   **Worst Case:** O(n log n)

------------------------------------------------------------------------

# Sorting Algorithms --- Quick Comparison

  -------------------------------------------------------------------------
  Algorithm   Main code                Best         Average           Worst
              observation                                   
  ----------- ------------- --------------- --------------- ---------------
  Merge Sort  Two halves +       O(n log n)      O(n log n)      O(n log n)
              linear merge                                  

  Quick Sort  Linear             O(n log n)      O(n log n)           O(n²)
              partition +                                   
              recursive                                     
              partitions                                    

  Bubble Sort Nested                   O(n)           O(n²)           O(n²)
              decreasing                                    
              loops                                         

  Selection   Nested                  O(n²)           O(n²)           O(n²)
  Sort        decreasing                                    
              loops                                         

  Heap Sort   n heapify          O(n log n)      O(n log n)      O(n log n)
              operations ×                                  
              log n                                         
  -------------------------------------------------------------------------

------------------------------------------------------------------------

# How to Write the Complexity Proof in the Lab Record

After every program, add a section named:

## Complexity Analysis

For example, for Bubble Sort:

``` text
Outer loop executes: n - 1 times

Inner loop executions:
(n - 1) + (n - 2) + ... + 1

= n(n - 1) / 2
= (n² - n) / 2

Ignoring constants and lower-order terms:

T(n) = O(n²)
```

Then write:

``` text
Best Case  : O(n)
Average    : O(n²)
Worst Case : O(n²)
```

This is much stronger than simply writing the final Big-O value because
it shows exactly how the complexity was obtained from the code.

------------------------------------------------------------------------

# Key Idea to Remember

> **Code → identify loops/recursive calls → count operations → form T(n)
> → simplify using Big-O.**

For sorting algorithms, focus mainly on:

-   Number of loop iterations
-   Number of comparisons
-   Number of swaps
-   Recursive calls
-   Work done by functions such as `merge()`, `partition()`, and
    `heapify()`
