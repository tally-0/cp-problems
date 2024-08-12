#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int a, b, c, d, e[3];
		cin >> a >> b >> c >> d >> e[0] >> e[1] >> e[2];
		sort(e, e + 3);
		int tot = a + b + c + d + (e[1] + e[2]) / 2;
		cout << "Case " << t << ": ";
		if (tot >= 90)
			cout << 'A';
		else if (tot >= 80)
			cout << 'B';
		else if (tot >= 70)
			cout << 'C';
		else if (tot >= 60)
			cout << 'D';
		else
			cout << 'F';
		cout << endl;
	}

	return 0;
}