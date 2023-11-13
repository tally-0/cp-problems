#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int diff[1000000] = { 0 };
	while(k--) {
		int a, b;
		cin >> a >> b;
		a--;
		diff[a]++;
		diff[b]--;
	}
	
	int sum[10000001];
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
		sum[i] = diff[i - 1] + sum[i - 1];
	sort(sum, sum + n + 1);

	cout << sum[n / 2 + 1] << endl;

	return 0;
}