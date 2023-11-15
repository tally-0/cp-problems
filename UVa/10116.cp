#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

int r, c, s;
string rows[10];
int len[11][10];

pair<pii,pii> check(int i, int j, int pi, int pj) {
	len[i][j] = len[pi][pj] + 1;
	int a = i, b = j;
	if (rows[i][j] == 'N')
		a--;
	else if (rows[i][j] == 'E')
		b++;
	else if (rows[i][j] == 'S')
		a++;
	else if (rows[i][j] == 'W')
		b--;
	if (a < 0 || b < 0 || a >= r || b >= c)
		return { { i, j }, { -1, -1 } };
	if (len[a][b] != -1)
		return { { i, j }, { a, b } };
	return check(a, b, i, j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> r >> c >> s && r + c + s) {
		s--;
		for(int i = 0; i < r; i++)
			cin >> rows[i];

		memset(len, -1, sizeof(len));
		len[10][0] = 0;
		pair<pii,pii> ans = check(0, s, 10, 0);
		if (ans.second.first == -1)
			cout << len[ans.first.first][ans.first.second] << " step(s) to exit" << endl;
		else
			cout << len[ans.second.first][ans.second.second] - 1 << " step(s) before a loop of " << len[ans.first.first][ans.first.second] - len[ans.second.first][ans.second.second] + 1 << " step(s)" << endl;
	}

	return 0;
}