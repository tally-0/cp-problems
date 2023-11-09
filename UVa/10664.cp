#include<iostream>
#include<sstream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, arr[20], mem[200];
	cin >> m;
	cin.ignore();
	while(m--) {
		string str;
		getline(cin, str);
		stringstream ss(str);
		n = 0;
		int s = 0, a;
		while(ss >> a) {
			arr[n++] = a;
			s += a;
		}
		if (s % 2)
			cout << "NO" << endl;
		else {
			memset(mem, false, sizeof(mem));
			mem[0] = true;
			for(int i = 0; i < n; i++)
				for(int j = 200 - arr[i]; j >= 0; j--)
					mem[j + arr[i]] |= mem[j];
			cout << (mem[s / 2] ? "YES" : "NO") << endl;
		}
	}

	return 0;
}