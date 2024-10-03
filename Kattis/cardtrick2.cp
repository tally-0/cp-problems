#include<iostream>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int ans[13];
		queue<int> q;
		for(int i = 0; i < n; i++)
			q.push(i);
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < i; j++) {
				q.push(q.front());
				q.pop();
			}
			ans[q.front()] = i;
			q.pop();
		}
		for(int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}