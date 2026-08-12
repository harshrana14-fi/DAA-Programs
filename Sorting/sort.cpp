#include <iostream>
using namespace std;

// Bubble Sort
void bubble(int a[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}

// Insertion Sort
void insertion(int a[], int n) {
    for(int i=1;i<n;i++) {
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

// Merge Sort
void merge(int a[], int l, int m, int r) {
    int i=l,j=m+1,k=0, b[r-l+1];

    while(i<=m && j<=r)
        b[k++]=(a[i]<a[j])?a[i++]:a[j++];

    while(i<=m) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=b[k];
}

void mergeSort(int a[], int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

// Quick Sort
int partition(int a[], int l, int r) {
    int p=a[r], i=l-1;
    for(int j=l;j<r;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[], int l, int r) {
    if(l<r) {
        int p=partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

// Display
void print(int a[], int n) {
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    cout << "Harsh Jatoliya" << endl;
    cout << "Enr. No. : 13114803124" << endl;
    cout << endl;
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int a[n], b[n];

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

        cout << endl;

    // Bubble
    for(int i=0;i<n;i++) b[i]=a[i];
    bubble(b,n);
    cout<<"Sorted array using Bubble sort: "; print(b,n);

    // Insertion
    for(int i=0;i<n;i++) b[i]=a[i];
    insertion(b,n);
    cout<<"Sorted array using Insertion sort: "; print(b,n);

    // Merge
    for(int i=0;i<n;i++) b[i]=a[i];
    mergeSort(b,0,n-1);
    cout<<"Sorted array using Merge sort: "; print(b,n);

    // Quick
    for(int i=0;i<n;i++) b[i]=a[i];
    quickSort(b,0,n-1);
    cout<<"Sorted array using Quick sort: "; print(b,n);

    cout << endl;

    return 0;
}