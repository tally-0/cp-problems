#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	pair<int, int> ll, lr, cur;
	while(cin >> m >> n && m != 1 && n != 1) {
		string r = "";
		ll = {0,1}, lr = {1,0}, cur = {1,1};
		
		while(cur.first != m || cur.second != n) {
			int a = m * cur.second, b = n * cur.first;
			if (a < b) {
				lr = cur;
				cur = {ll.first + cur.first, ll.second + cur.second};
				r += 'L';
			} else {
				ll = cur;
				cur = {cur.first + lr.first, cur.second + lr.second};
				r += 'R';
			}
		}
		
		cout << r << endl;
	}

	return 0;
}