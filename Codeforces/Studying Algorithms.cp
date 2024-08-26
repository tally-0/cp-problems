#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, a[100]; 
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	int sum = 0, ans = 0;
	while(sum <= x && ans < n) {
		sum += a[ans];
		ans++;
	}
	
	cout << ans - (ans != n);

	return 0;
}