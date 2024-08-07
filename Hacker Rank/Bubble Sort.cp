#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int& i : a)
		cin >> i;

	int swaps = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swaps++;
			}
		}
	}

	cout << "Array is sorted in " << swaps << " swaps." << endl;
	cout << "First Element: " << a[0] << endl;
	cout << "Last Element: " << a[n - 1] << endl;

	return 0;
}