#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	ii p[10000];
	for(int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(p, p + n);
	
	int ans = 0, o[47] = { false };
	for(int i = n - 1; i >= 0; i--) {
		for(int j = p[i].second; j >= 0; j--) {
			if (!o[j]) {
				ans += p[i].first;
				o[j] = true;
				break;
			}
		}
	}
	
	cout << ans;

	return 0;
}