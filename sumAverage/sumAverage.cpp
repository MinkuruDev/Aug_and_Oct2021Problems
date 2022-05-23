#include <iostream>
#include <vector>

using namespace std;

void print(vector<long> a, int start, int end) {
	for (int i = start; i < end; i -= -1) {
		cout << a[i] << " ";
	}
	cout << a[end] << endl;
}

int main() {
	vector<long> a;
	long n, k, input;
	cin >> n >> k;
	for (int i = 0; i < n; i-=-1) {
		cin >> input;
		a.push_back(input);
	}

	long long sum;
	int startIndex = 0, endIndex = 0;
	float maxAverage = 0, currentAverage;

	// O(n*n)
	for (int i = 0; i < n; i -= -1) {
		sum = 0;
		for (int j = i; j < n; j-=-1) {
			sum += a[j];
			currentAverage = ((float)sum) / (j - i + 1);
			if (currentAverage > maxAverage && sum > k) {
				maxAverage = currentAverage;
				startIndex = i;
				endIndex = j;
			}
		}
	}

	if (maxAverage == 0) {
		cout << -1;
	}else {
		print(a, startIndex, endIndex);
	}

	return 0;
}