#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, p[20005];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> p[i];
		
		sort(p, p + n);
		int ans = 0;
		for(int i = n % 3; i < n; i += 3)
			ans += p[i];
	
		cout << ans << endl;
	}

	return 0;
}