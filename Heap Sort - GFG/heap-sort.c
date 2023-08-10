//{ Driver Code Starts
// Heap Sort in C
#include <stdio.h>
  
// Function to swap the the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  
// } Driver Code Ends
//User function Template for C


void heapify(int arr[], int n, int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int max = i;

    if (left < n && arr[left] > arr[max])
        max = left;

    if (right < n && arr[right] > arr[max])
        max = right;

    if (max != i) {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

// Main function to do heap sort
void buildHeap(int arr[], int n) {
    for (int i = n - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Heap Sort
    int last = n - 1;
    while (last) {
        swap(arr, arr + last);
        heapify(arr, last--, 0);
    }
}

//{ Driver Code Starts.
  
// Driver code
int main() {
    int t;
    scanf("%d",&t);
    while (t--){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    buildHeap(arr, n);
    printArray(arr, n);
    }
  }
// } Driver Code Ends