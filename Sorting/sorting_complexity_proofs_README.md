# Sorting Algorithms --- Complexity Proofs

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
n → n/2 + n/2

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
log₂ n

Therefore:
T(n) = n × log₂ n

Hence:
T(n) = O(n log n)

## Final Result

-   **Best Case:** O(n log n)
-   **Average Case:** O(n log n)
-   **Worst Case:** O(n log n)

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
T(n) = O(n log n)

## Worst Case

Suppose the pivot is always the smallest or largest element.

The partitions become:
\[ 0+(n-1) \]

Therefore:
\[ T(n)=T(n-1)+cn \]

Expanding:
\[ T(n)=T(n-2)+c(n-1)+cn \]

Eventually:
T(n) = c(1 + 2 + 3 + ... + n)

We know:
1 + 2 + 3 + ... + n = n(n + 1) / 2

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
(n - 1) + (n - 2) + (n - 3) + ... + 1

This is:
n(n - 1) / 2

Therefore:
T(n) = n(n - 1) / 2

Expanding:
T(n) = (n² - n) / 2

Ignoring constants and lower-order terms:
T(n) = O(n²)

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
T(n)=O(n)

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
(n - 1), (n - 2), (n - 3), ..., 1

times.

Therefore total comparisons are:
(n - 1) + (n - 2) + ... + 1
= n(n - 1) / 2

Thus:
T(n) = n(n - 1) / 2
T(n) = (n² - n) / 2

Ignoring constants and lower-order terms:
T(n) = O(n²)

## Best Case

Even if the array is already sorted, Selection Sort still searches for
the minimum element in the remaining unsorted portion.

Therefore:
T(n)=O(n^2)

## Final Result

-   **Best Case:** O(n²)
-   **Average Case:** O(n²)
-   **Worst Case:** O(n²)


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
O(n)

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
O(log n)

Therefore, one `heapify()` operation takes:
O(log n)

It happens approximately `n` times:
n × O(log n) = O(n log n)

## Total Complexity
O(n) + O(n log n)

Since `n log n` dominates `n`:
**T(n) = O(n log n)**

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


