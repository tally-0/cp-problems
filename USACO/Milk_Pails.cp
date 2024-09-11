#include<iostream>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("pails.in");
	ofstream cout("pails.out");

	int x, y, m; 
	cin >> x >> y >> m;

	int ans = 0;
	for(int i = 0; i < 1001; i++)
		for(int j = 0; j < 1001; j++)
			if (i * x + j * y <= m)
				ans = max(ans, i * x + j * y);

	cout << ans;

	return 0;
}