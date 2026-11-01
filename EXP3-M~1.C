#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
	int mid = left + (right - left) / 2;

	if (arr[mid] == key)
	    return mid;   // Element found

	if (arr[mid] < key)
	    left = mid + 1;   // Search in right half
	else
	    right = mid - 1;  // Search in left half
    }

    return -1;   // Element not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 23;

    int result = binarySearch(arr, 0, size - 1, key);

    clrscr();

    if (result == -1)
	printf("Element is not present in the array.\n");
    else
	printf("Element is present at index %d.\n", result);
       getch();
    return 0;
}

