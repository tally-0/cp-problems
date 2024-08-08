#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	pair<int, string> persons[101];
	int n;
	cin >> n;

	int d, m, y;
	for(int i = 0; i < n; i++) {
		cin >> persons[i].second >> d >> m >> y;
		persons[i].first = y * 10000 + m * 100 + d;
	}

	sort(persons, persons + n);

	cout << persons[n - 1].second << endl;
	cout << persons[0].second << endl;

	return 0;
}