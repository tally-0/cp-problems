#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, mat[100][100];
	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> mat[i][j];
		int row = -1, col = -1;
		for(int i = 0; i < n && row > -2 && col > -2; i++) {
			int rs = 0, cs = 0;
			for(int j = 0; j < n; j++) {
				rs += mat[i][j];
				cs += mat[j][i];
			}
			if (rs % 2)
				if (row != -1)
					row = -2;
				else
					row = i;
			if (cs % 2)
				if (col != -1)
					col = -2;
				else
					col = i;
		}
		if (col == -2 || row == -2 || (row != col && (row == -1 || col == -1))) {
			cout << "Corrupt" << endl;
			continue;
		}
		if (col == -1 && row == -1) {
			cout << "OK" << endl;
			continue;
		}
		cout << "Change bit (" << row + 1 << "," << col + 1 << ")" << endl;
	}

	return 0;
}