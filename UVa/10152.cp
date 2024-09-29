#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n;
	cin >> k;
	string s;
	while(k--) {
		cin >> n;
		cin.ignore();
		vector<string> o(n);
		for (string &i : o)
			getline(cin, i);
		vector<string> g(n);
		for (string &i : g)
			getline(cin, i);

		int j = n - 1;
		for (int i = n - 1; i >= 0; i--)
			if (o[i] == g[j])
				j--;

		while (j >= 0)
			cout << g[j--] << endl;
		cout << endl;
	}
	return 0;
}