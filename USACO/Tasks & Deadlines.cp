#include <iostream>
#include <vector>
#include <pair>
#include <algorithm>

#define vii vector<pair<int, int>>
#define lli long long int

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vii tasks(n)
	int a, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> d;
		tasks[i] = make_pair(a, d);
	}

	sort(tasks.begin(), tasks.end());

	lli reward = 0, last_finish = 0;
	for (auto task : tasks) {
		last_finish += task.first;
		reward += task.second - last_finish;
	}

	cout << reward;

	return 0;
}