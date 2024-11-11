#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge_sort(int arr[], int start, int end, int mid) {
    int i = start, j = mid + 1, k = start;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result[n];

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            result[k] = arr[i];
            i++;
            k++;
        }
        else {
            result[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        result[k] = arr[i];
        i++;
        k++;
    }

      while (j <= end)
    {
        result[k] = arr[j];
        j++;
        k++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = result[i];
    }

}

void merge_init(int arr[], int start, int end) {
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_init(arr, start, mid);
        merge_init(arr, mid+1, end);
        merge_sort(arr, start, end, mid);
    }
    
}

int main() {
    int n = 9;
    int arr[] = {5, 2, 1, 3, 4, 6, 9, 8, 7};
    int start = 0, end = n-1;

    merge_init(arr, start, end);
    display(arr, n);
}