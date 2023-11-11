#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int q, k, set[5001] = { 0 };

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	int q, k, mem[5000] = { 0 };
	mem[0] = 1;
	cin >> q >> k;
	while(q--) {
		string op;
		int x;
		cin >> op >> x;
		if (op == "+")
			for(int i = k; i >= x; i--)
				mem[i] = (mem[i] + mem[i - x]) % 998244353;
		else
			for(int i = x; i <= k; i++)
				mem[i] = (mem[i] + 998244353 - mem[i - x]) % 998244353;
		cout << mem[k] << endl;
	}

	return 0;
}
