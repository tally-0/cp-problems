#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, arr[200000];
	cin >> n >> t;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	if (t == 1) {
		int a[7777] = { 0 };
		for(int i = 0; i < n; i++) {
			if (arr[i] > 7777)
				continue;
			if (a[7777 - arr[i]] != 0) {
				cout << "YES";
				return 0;
			}
			a[arr[i]] = 1;
		}
		cout << "NO";
		return 0;
	}

	if (t == 2) {
		sort(arr, arr + n);
		cout << (unique(arr, arr + n) == arr + n ? "Unique" : "Contains duplicate");
		return 0;
	}

	if (t == 3) {
		sort(arr, arr + n);
		int cc = 1;
		for(int i = 1; i < n; i++) {
			if (arr[i - 1] == arr[i])
				cc++;
			else
				cc = 1;
			if (cc > n / 2) {
				cout << arr[i];
				return 0;
			}
		}
		cout << -1;
		return 0;
	}

	if (t == 4) {
		sort(arr, arr + n);
		if (n % 2)
			cout << arr[n / 2];
		else
			cout << arr[(n - 1) / 2] << " " << arr[(n + 1) / 2];
		return 0;
	}
	
	if (t == 5) {
		sort(arr, arr + n);
        for(int i = lower_bound(arr, arr + n, 100) - arr; i < n; i++)
			if(arr[i] < 1000) 
				cout << arr[i] << " ";
			else
				break;
        return 0;
	}

	return 0;
}