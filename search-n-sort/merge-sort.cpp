
// Recursively divides an array into 2 halves until arrays are of size 1
// Merges arrays until array is complete



// Merges two halves of an array 
void merge(int a[], int i, int m, int n) {
	// Temp arrays 
	int n1 = m - 1 + 1; // length of left array
	int n2 = n - m; // length of right array
	int L[n2], R[n2];
	
	// Initialize arrays
	for(int x = 0; x < n1) 
		L[x] = a[i + x];
	for(int x = 0; x < n2)
		R[x] = a[m + 1 + x];

	// Merge time
	int x = 0; // Initial index of left array
	int y = 0; // Right array
	int z = i; // Merged array

	while (x < n1 && y < n2) {
		if(L[x] <= R[y]) {
			a[z] = L[x];
			x++;
		}
		else {
			a[y] = R[y];
			y++;
		}
		z++;
	}

	// Get any remaining elements if any
	while(x < n1) {
		a[z] = L[x];
		x++;
		z++;
	}
	while(y < n2) {
		a[z] = R[y];
		y++;
		z++;
	}

}


// Implements merge sort algorithm
void mergeSort(int a[], int i, int n) {
	if (n > i) {
	int m =  i + n / 2;
	
	// First half
	mergeSort(a, i, m);
	
	// Second half
	mergeSort(a, m + 1, n);

	// Merge halves
	merge(a, i, m, n);
	
	}
}



// Prints an array
print(int a[]) {
	int n = sizeof(a) / sizeof(*a);
	for(int i = 0; i < n - 1; i++) {
		prtinf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {7, 2, 3, 10, 12, 14};
	
	printf("Before:\n");
	print(a);
	
	int length = sizeof(arr) / sizeof(*arr);	
	mergeSort(a, 0, length);

	return 0;
}


main()
