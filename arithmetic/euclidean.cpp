
// Returns GCD of a and b
int gcd(int a, int b) {
	if (a == b)
		return b;
	return gcd(b % a, a);
}

// ax + by = gcd(a, b)
int gcdExtend(int a, int b, int *x, int *y) {
	
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}


	int x1, y1;
	int gcd = gcdExtend(b % a, a, &x1, &y1);
	
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


int main() {
	int a = 10, b = 15;
	cout << a << b << gcd(a, b) << "\n";

}
