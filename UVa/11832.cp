#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int n, f, t[40];
int mem[41][80001], ansa[40], anss[40];

bool dp(int i, int v) {
	if (i == n)
		return (v == f);
	if (mem[i][v + 40000] == -1) {
		bool a = dp(i + 1, v + t[i]);
		bool s = dp(i + 1, v - t[i]);
		if (a)
			ansa[i] = true;
		if (s)
			anss[i] = true;
		mem[i][v + 40000] = (a || s);
	}
	return mem[i][v + 40000];
}
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> f && n + f) {
		for(int i = 0; i < n; i++)
			cin >> t[i];
		
		memset(mem, -1, sizeof(mem));
		memset(ansa, false, sizeof(ansa));
		memset(anss, false, sizeof(anss));
		if (dp(0, 0)) {
			for(int i = 0; i < n; i++) {
				if (ansa[i] == anss[i])
					cout << "?";
				else if (ansa[i])
					cout << "+";
				else
					cout << "-";
			}
			cout << endl;
		} else
			cout << "*" << endl;
	}

	return 0;
}