#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define endl '\n'

int n, c[100], m;
int mem[31001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> c[i];

	memset(mem, 0xff, sizeof(mem));
	mem[0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= 30000; j++) {
			if (mem[j] >= 0)
				mem[j + c[i]] = ((mem[j + c[i]] == -1) ? i : -2);
			else if (mem[j] == -2)
				mem[j + c[i]] = -2;
		}
	}
					
	cin >> m;
	int s;
	while(m--) {
		cin >> s;
		if (mem[s] == -1) {
			cout << "Impossible" << endl;
			continue;
		}
		if (mem[s] == -2) {
			cout << "Ambiguous" << endl;
			continue;
		}
		int path[30000], pn = 0;
		while(s > 0) {
			path[pn++] = mem[s];
			s -= c[mem[s]];
		}
		sort(path, path + pn);
		for(int i = 0; i < pn; i++)
			cout << path[i] + 1 << " ";
		cout << endl;
	}

	return 0;
}