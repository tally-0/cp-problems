#include<iostream>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, arr[10000]; 
	while(cin >> n && n) {
		arr[0] = 0;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] += arr[i - 1];
		}
		int ans = INT_MIN;
		for(int i = 0; i < n; i++) {
			for(int j = i; j <= n; j++) {
				ans = max(arr[j] - arr[i], ans);
			}
		}
		if (ans)
			cout << "The maximum winning streak is " << ans << "." << endl;
		else
			cout << "Losing streak." << endl;
	}

	return 0;
}