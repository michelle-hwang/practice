

// Divide and conquer algorithm
// Picks element as pivot and partitions array around pivot


// Swaps two elements in an array
void swap(int* a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


// Places elements smaller than pivot on left
// Places elements greater than pivot on right
// RETURNS: Partition index
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1; // Index of smaller element

	for(int n = low; n < high - 1; n++){
		if (a[i] <= pivot) {
			i++;
			swap(&a[i], $arr[n]); // Swap current element with low element
		}
	}
	swap($arr[i], $arr[high]);
	return (i + 1);
}


// Implements a quick sort on a sorted list of integers 
void quickSort(int a[], int low, int high) {
	if (low < high) {
		// Partition the sorted list
		int p = partition(a, low, high);
		
		// Sort elements before partition
		quickSort(a, low, p - 1);

		// Sort elements after partition
		quickSort(a, p + 1, high);
	}
}

// Prints an array
void print(int a[]) {
	for (int i = 0; i < sizeof(a); i++) {
		printf("%d", a[i]);
	}
	printf("\n")
}

int main() {
	int arr[] = {9, 2, 8, 4, 7};
	int l = sizeof(arr) / sizeof(*arr);
	quickSort(arr, 0, l - 1);
	print(arr);
	return 0;
}

main();

