#include <stdio.h>

int sorted_seq_search(int key, int arr[], int low, int high) 
{
    int i;
    for(i = low; i < high; i++) {
        if(arr[i] == key)
            return i + 1;    
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int key;

    scanf("%d", &key);
    printf("%d\n", sorted_seq_search(key, arr, 0, sizeof(arr)/sizeof(int)));
}