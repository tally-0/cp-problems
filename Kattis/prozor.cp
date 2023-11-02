#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char w[101][101];
	int r, s, k, sum[101][101];

	cin >> r >> s >> k;

	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= s; j++) {
			cin >> w[i][j];
			if (w[i][j] == '*')
				sum[i][j]++;
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}

	int ms = 0, mi, mj;
	for(int i = k; i <= r; i++) {
		for(int j = k; j <= s; j++) {
			int s = sum[i-1][j-1] - sum[i-k+1][j-1] - sum[i-1][j-k+1] + sum[i-k+1][j-k+1];
			if (s > ms) {
				ms = s;
				mi = i;
				mj = j;
			}
		}
	}

	for(int i = mi; i > (mi - k); i--)
		w[i][mj] = w[i][mj-k+1] = '|';
	for(int i = mj; i > (mj - k); i--)
		w[mi][i] = w[mi-k+1][i] = '-';
	w[mi][mj] = w[mi][mj-k+1] = w[mi-k+1][mj] = w[mi-k+1][mj-k+1] = '+';

	cout << ms << endl;
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= s; j++)
			cout << w[i][j];
		cout << endl;
	}

	return 0;
}