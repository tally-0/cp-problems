#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r;
	cin >> r;
	string routines[10];
	for(int i = 0; i < r; i++)
		cin >> routines[i];

	sort(routines, routines + r);
	int minqc = INT_MAX;
	do {
		int qc = 0;
		for(int i = 0; i < r - 1; i++) {
			int k = 0;
			for(int j = 0; j < routines[i].length(); j++) {
				while(k < routines[i+1].length() && routines[i+1][k] < routines[i][j])
					k++;
				if (k >= routines[i+1].length())
					break;
				if (routines[i+1][k] == routines[i][j])
					qc++;
			}
		}
		minqc = min(minqc, qc);
	} while(next_permutation(routines, routines + r));

	cout << minqc;

	return 0;
}