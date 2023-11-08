#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'
typedef long long ll;

int n, q, d, m, v[200];
ll mem[200][200][10];

ll dp(int i, int s, int k) {
	if (!s && !k)
		return 1;
	if (i == n || !k)
		return 0;
	if (mem[i][s][k] == -1)
		mem[i][s][k] = dp(i + 1, s, k) + dp(i + 1, ((ll)s + (ll)v[i]) % (ll)d, k - 1);
	return mem[i][s][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int tc = 1; cin >> n >> q && n + q; tc++) {
		for(int i = 0; i < n; i++)
			cin >> v[i];
		
		cout << "SET " << tc << ":" << endl;
		for(int qc = 1; qc <= q; qc++) {
			cin >> d >> m;
			cout << "QUERY " << qc << ": ";
			memset(mem, 0xff, sizeof(mem));
			cout << dp(0, 0, m) << endl;
		}
	}

	return 0;
}