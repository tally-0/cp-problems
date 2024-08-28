#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ii tasks[1000];
	for(int t = 1; cin >> n && n; t++) {
		for(int i = 0; i < n; i++)
			cin >> tasks[i].first >> tasks[i].second;

		sort(tasks, tasks + n, [](const ii& lhs, const ii& rhs) {
			if (lhs.second == rhs.second)
				return lhs.first < rhs.first;
			return lhs.second > rhs.second;
		});
		int ans = 0, cur = 0;
		for(int i = 0; i < n; i++) {
			cur += tasks[i].first;
			ans = max(ans, cur + tasks[i].second);
		}

		cout << "Case " << t << ": " << ans << endl;
	}

	return 0;
}