
// Find min sum
int findMinRec(int a[], int i, int total, int calc) {
	if (i == 0)
		return(abs((total - calc) - calc));
	else
		return(min(findMin(a, i - 1, total, calc + a[i - 1]), 
			   findMin(a, i - 1, total, calc)));
}

// Returns min difference between sums of 2 subsets
int findMin(int a[], int n) {
	int total = 0;
	for (int i = 0; i < n; i++)
		total += a[i];
	return findMinRec(a, n, total, 0);
}

// Uses dynamic programming to get min diff between
// sums of 2 subsets
int findMinDynamic(int a[], int n) {
	// Get sum of entire set
	int sum;
	for (int i = 0; i < n; i++)
		sum += a[i];

	// 1 if some subset from 1st to ith has sum equal to j
	// 0 otherwise
	bool dp[n + 1][sum + 1];
	
	// A sum = 0 is possible
	for (int i = 0; i <= n; i++)
		dp[i][0] true; // 1st col = true

	// If 0 elements, then sum = 0
	for (int j = 1; j <= sum; j++)
		dp[0][j] = false; // 1st row = false


	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= sum + 1; j++) {
			// If ith excluded
			dp[i][j] = dp[i-1][j];
			
			// If ith included
			if (arr[i - 1] <= j)
				dp[i][j] |= dp[i - 1][j - arr[i - 1]];
		}
	}


	int diff = INT_MAX;

	// Find largest j such that dp[n][j] is true
	// where j loops from sum/2 to 0
	for (int j = sum / 2; j >= 0; j--) {
		if (dp[n][j] == true) {
			diff = sum - 2 * j;
			break;
		}
	}
	
	return diff;
}

int main() {
	int arr[] = {2, 4, 6, 1, 3, 7};
	int n = sizeof(arr) / sizeof(*arr);

	findMin(arr, n);
}





