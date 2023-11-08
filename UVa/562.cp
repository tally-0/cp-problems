#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, mem[50000];
	cin >> n;
	while(n--) {
		cin >> m;
		memset(mem, false, sizeof(mem));
		mem[0] = true;
		int s = 0;
		for(int i = 0, v; i < m; i++) {
			cin >> v;
			s += v;
			for(int j = 50000 - v; j >= 0; j--)
				mem[j + v] |= mem[j];
		}

		int ans = -1;
		for(int i = 0; i <= s / 2 && ans < 0; i++) {
			if (mem[s / 2 + i] || mem[s / 2 - i])
				ans = i * 2 + s % 2;
		}
		cout << ans << endl;
	}
		
	return 0;
}