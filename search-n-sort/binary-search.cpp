#include <stdio.h>

// Search sorted array to find index location of a given element

int binarySearch(int a[], int x) {
	int n = sizeof(a);
	int i = 0;

	while(i < n) {
		int mid = i + (n - 1) / 2; 

		if(a[mid] < x)
			i = mid + 1;
		else
			n = mid - 1	
	}
	// Element not present
	return -1;
}

int binarySearchRecursive(int a[], int x, int i, int n) {
	if (n >= i) {
		int m = i + (n - 1) / 2;

		if (a[mid] == x) 
			return m;
		else if (a[m] > x)
			return binarySearchRecursive(a, x, i, m - 1);
		else
			return binarySearchRecrusive(a, x, m + 1, n);
	}

	// Element not present
	return -1
}

int main() {
	int arr[] = {1, 2, 5, 7, 10};
	int arr2[] = {1, 2, 7, 10};

	cout << binarySearch(arr, 2); << "\n";
	cout << binarySearchRecursive(arr2, 7, 0, sizeof(arr)) << "\n";
}

main()




