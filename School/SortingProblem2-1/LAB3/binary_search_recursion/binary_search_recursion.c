#include <stdio.h>

int binary_search_recursion(int key, int arr[], int low, int high)
{
    int middle;

    if(low > high)
        return -1;
    
    middle = (low + high) / 2;
    if(arr[middle] == key)
        return middle + 1;
    else if(arr[middle] > key)
        return binary_search_recursion(key, arr, low, middle - 1);
    else
        return binary_search_recursion(key, arr, middle + 1, high);
    
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int key;

    scanf("%d", &key);
    printf("%d\n", binary_search_recursion(key, arr, 0, sizeof(arr)/sizeof(int) - 1));
}