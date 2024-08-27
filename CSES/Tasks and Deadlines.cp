#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	pair<int, int> tasks[200000];
	for(int i = 0; i < n; i++)
		cin >> tasks[i].first >> tasks[i].second;
	
	sort(tasks, tasks + n);
	ll t = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		t += tasks[i].first;
		ans += tasks[i].second - t;
	}

	cout << ans;

	return 0;
}