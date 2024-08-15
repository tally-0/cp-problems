#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, arr[1000];
	while(cin >> n) {
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		int swaps = 0;
		for(int i = 0; i < n; i++) {
			for(int j = n - 1; j > i; j--) { 
				if (arr[j - 1] > arr[j]) { 
					swap(arr[j], arr[j - 1]);
					swaps++;
				}
			}
		}
		cout << "Minimum exchange operations : " << swaps << endl;
	}

	return 0;
}