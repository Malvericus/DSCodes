#include <stdio.h>


int linearSearch(int arr[], int n, int key) {

    int num = 0;
    for (int i = 0; i < n; i++) {
        
        if (arr[i] == key) 
        {
            num = arr[i];
        }
    
    }

    return num;
}

int main() {
    
    int arr[] = {2, 4, 0, 1, 9};
    int key;

    printf("Enter number to search: ");
    scanf("%d", &key);

    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = linearSearch(arr, n, key);

    printf("The linearly searched number is: %d ", result);
    

    return 0;
}

