#include<iostream>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	int ans = INT_MIN, s = 0, a;
	while(n--) {
		cin >> a;
		s += a - p;
		ans = max(s, ans);
		s = max(s, 0);
	}
	
	cout << ans << endl;

	return 0;
}