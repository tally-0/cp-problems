#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
typedef pair<int,int> ii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ii a[6];
	for(int i = 0; i < n; i++) {
		int b;
		cin >> b;
		a[--b].first++;
		a[b].second = i + 1;
	}
	int c = -1, d = -1;
	for(int i = 0; i < 6; i++) {
		if (a[i].first == 1) {
			c = i;
			d = a[i].second;
		}
	}
	if (d < 0)
		cout << "none";
	else
		cout << d;

	return 0;
}