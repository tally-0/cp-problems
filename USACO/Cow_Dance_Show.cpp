#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, tmax;
	cin >> n >> tmax;
	vector<int> d(n);
	for (int &i : d) cin >> i;

	// monotonic func testing if k is possible
	auto f = [=] (int k) -> bool {
		int t = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i : d) {
			if (pq.size() == k) {
				t = pq.top();
				pq.pop();
			}
			pq.push(t + i);
		}
		while(pq.size()) {
			t = pq.top();
			pq.pop();
		}
		return t <= tmax;
	};
		
	// first true binary search
	int lo = 1, hi = n, med;
	while(lo <= hi) {
		med = lo + (hi - lo) / 2;
		if(f(med)) hi = med - 1;
		else lo = med + 1;
	}

	cout << lo << endl;

	return 0;
}