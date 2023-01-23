#include <stdio.h>

int binary_search_loop(int key, int arr[], int low, int high)
{
    int middle;

    do {
        middle = (low + high) / 2;
        if(arr[middle] == key)
            return middle + 1;
        else if(arr[middle] > key)
            high = middle - 1;
        else
            low = middle + 1;
    }while(low <= high);

    return -1;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int key;

    scanf("%d", &key);
    printf("%d\n", binary_search_loop(key, arr, 0, sizeof(arr)/sizeof(int) - 1));
}