
// Given 2 sequences, find the length of longest subseq present in both.
// A subseq is a seq that appears in the same relative order, but not 
// necessarilly contiguous. A string of length n has 2^n possible subseqs.
//
// e.g.
// LCS for "ABCDGH" and "AEDFHR" is "ADH" of length 3
//
// NOTE:
// Assume characters are uppercase. 


// Returns greater of two integers
int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}


// Simple recrusive implementation of LCS algorithm
int lcsRecursive(char *X[], char *Y[], int m, int n) {
	if (m == 0 || n == 0) 
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcs(X, Y, m - 1, n - 1);
	else
}		return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));


// More efficient dynamic solution to LCS algorithm
int lcsDynamic(char *X[], char *Y[], int m, int n) {
	int a[m + 1][n + 1]; // create array

	// Build array bottom up
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {

			// If very last element 
			if (j == 0 || i == 0) 
				a[i][j] = 0;
			// If elements match
			else if (X[i - 1] == Y[j - 1]) 
				a[i][j] = a[i - 1][j - 1] + 1; // Add to score
			// If elements don't match
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		
		}
	}

	return a[m][n];
}


int main() {
	char s1[] = "ABCDGH";
	char s2[] = "AEDFHR";

	int l1 = strlen(s1);
	int l2 = strlen(s2);

	printf(lcsRecrusive(s1, s2, l1, l2));
	printf(lcsDynamic(s1, s2, l1, l2));

}
