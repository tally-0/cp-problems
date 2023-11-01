#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int cols[2][5];
string ans;
int k, cnt;

void backtrack(string str, int i) {
	if (i == 5) {
		if (++cnt == k)
			ans = str;
		return;
	}
	int shared = cols[0][i] & cols[1][i];
	for(int j = 0; j < 26 && cnt < k; j++)
		if (shared & (1 << j))
			backtrack(str + (char)(j + 'A'), i + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> k;
		memset(cols, 0, sizeof(cols));
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 6; j++) {
				for(int g = 0; g < 5; g++) {
					char c;
					cin >> c;
					cols[i][g] |= (1 << (c - 'A'));
				}
			}
		}

		ans = "NO";
		cnt = 0;
		backtrack("", 0);
		cout << ans << endl;
	}

	return 0;
}