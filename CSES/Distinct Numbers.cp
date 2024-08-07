#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, arr[200000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	cout << (int)(unique(arr, arr + n) - arr);

	return 0;
}