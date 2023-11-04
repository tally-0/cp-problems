#include<iostream>
#include<cstring>
#include<climits>
#include<iomanip>

using namespace std;

#define endl '\n'

int h, k, vals[10], pos[200];
int ans, ansvals[10];

void getpos(int i, int ck, int s) {
	pos[s] = true;
	if (i == h)
		return;
	for(int j = 0; j <= ck; j++)
		getpos(i + 1, ck, s + vals[j]);
}

void backtrack(int i, int mp) {
	if (i == k) {
		if (mp > ans) {
			ans = mp;
			memcpy(ansvals, vals, sizeof(vals));
		}
		return;
	}
	for(int j = vals[i - 1] + 1; j <= mp + 1; j++) {
		memset(pos, false, sizeof(pos));
		vals[i] = j;
		getpos(0, i, 0);
		int nmp;
		for(nmp = mp; pos[nmp]; nmp++);
		nmp--;
		backtrack(i + 1, nmp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> h >> k && h + k) {
		vals[0] = 1;
		ans = 0;
		
		backtrack(1, h);

		for(int i = 0; i < k; i++)
			cout << setw(3) << ansvals[i];
		cout << " ->" << setw(3) << ans << endl;
	}

	return 0;
}