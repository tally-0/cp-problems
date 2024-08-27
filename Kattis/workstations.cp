#include<iostream>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> arv, dep;
	for(int a, b; cin >> a >> b; arv.push(a), dep.push(a + b));

	int ans = 0;
	while(!arv.empty()) {
		while(arv.top() - dep.top() > m)
			dep.pop();
		if (arv.top() >= dep.top()) {
			dep.pop();
			ans++;
		}
		arv.pop();
	}

	cout << ans;
		
	return 0;
}