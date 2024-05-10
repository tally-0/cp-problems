#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int c = 1; c <= t; c++) {
		int solved[10001] = { 0 }, s;
		for(int i = 0; i < 3; i++) {
			cin >> s;
			int p;
			while(s--) {
				cin >> p;
				if (solved[p] == 0 || solved[p] == i + 1)
					solved[p] = i + 1;
				else
					solved[p] = 4;
			}
		}

		int count[5] = { 0 };
		for(int i = 0; i < 10001; i++)
			count[solved[i]]++;

		int winner[4], best = 0;
		for(int i = 1; i < 4; i++) {
			if (best < count[i]) {
				winner[1] = winner[2] = winner[3] = false;
				winner[i] = true;
				best = count[i];
			} else if (best == count[i])
				winner[i] = true;
		}

		cout << "Case #" << c << ":" << endl;
		
		for(int i = 1; i < 4; i++) {
			if (!winner[i])
				continue;
			cout << i << " " << best;
			for (int j = 0; j < 10001; j++)
				if (solved[j] == i)
					cout << " " << j;
			cout << endl;
		}
	}

	return 0;
}