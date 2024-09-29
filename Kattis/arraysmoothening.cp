#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, a;
	cin >> n >> k;
	unordered_map<int, int> o;
	while(n--) {
		cin >> a;
		if (!o.count(a))
			o[a] = 0;
		o[a]++;
	}

	priority_queue<int> pq;
	for(const auto& it : o)
		pq.push(it.second);
	while(k--) {
		pq.push(pq.top() - 1);
		pq.pop();
	}
	
	cout << pq.top();

	return 0;
}