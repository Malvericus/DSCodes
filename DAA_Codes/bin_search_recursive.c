#include <stdio.h>

int binarySearch(int arr[], int l, int h, int key) {

    if(h >= l) 
    {
        int mid = (l + h )/ 2;

        if (arr[mid] == key)
        {
           return mid;
        }

        if (arr[mid] > key)
        {
            return binarySearch(arr, l, mid-1, key);
        }

        return binarySearch(arr, mid+1, h, key);
    
    }
    return -1;
}

int main() {
    
    int arr[] = {3, 5, 11, 12, 17};
    int l = 1;
    int h = 5;

    int key;
    printf("Enter number to search: ");
    scanf("%d", &key);

    printf("Key found: %d at position: %d", key, binarySearch(arr, l, h, key));

    return 0;
}