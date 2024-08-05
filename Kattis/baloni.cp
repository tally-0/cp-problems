#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[1000001] = { 0 };
	for(int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if (arr[h + 1] > 0)
			arr[h + 1]--;
		arr[h]++;
	}

	int ans = 0;
	for(int i = 0; i < 1000001; i++)
		ans += arr[i];

	cout << ans;

	return 0;
}