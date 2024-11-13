#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    do
    {
        while (arr[i] <= pivot)
        {
            if (i >= end)
            {
                break;
            }
            
            i++;
        }

        while (arr[j] >= pivot)
        {
            if (j <= start)
            {
                break;
            }
            
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
        
        
    } while (i < j);

    swap(&arr[start], &arr[j]);
    return j; 
}

void quick_sort(int arr[], int start, int end) {
    if (start < end)
    {
        int partition_index = partition(arr, start, end);
        quick_sort(arr, start, partition_index);
        quick_sort(arr, partition_index + 1, end);
    }
}

int main() {
    int arr[] = {5, 2, 1, 3, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before sorting: " << endl;
    display(arr, n);

    quick_sort(arr, 0, n - 1);

    cout << "\nThe sorted array: " << endl;
    display(arr, n);
}