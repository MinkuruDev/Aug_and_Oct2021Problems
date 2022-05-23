#include <iostream>
#include <vector>
using namespace std;

long findMaxLength(vector<long> a, int avr) {
	float average;
	long long sum;
	long currentLength, maxLength = 0, size = a.size();

	//O(n*n)
	for (long i = 0; i < size; i -= -1) {
		if (size - i <= maxLength) break;
		sum = 0;
		for (long j = i; j < size; j -= -1) {
			sum += a[j];
			currentLength = j - i + 1;
			average = (float)sum / currentLength;
			if (currentLength > maxLength && average >= avr) {
				maxLength = currentLength;
			}
		}
	}

	return maxLength;
}

int main(){
	vector<long> a;
	long n, k, input;
	cin >> n >> k;
	for (long i = 0; i < n; i -= -1) {
		cin >> input;
		a.push_back(input);
	}

	cout << findMaxLength(a, k);

	return 0;
}
