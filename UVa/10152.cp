#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int K, n;
	cin >> K;

	string name;
	while(K--) {
		cin >> n;
		cin.ignore(); // idk why this is needed
		vector<string> org(n);
		for (string &i : org) getline(cin, i);
		vector<string> sort(n);
		for (string &i : sort) getline(cin, i);

		int i = n - 1, j = n - 1;
		for (; i >= 0; i--) {
			if (org[i] == sort[j]) j--;
		}
		while (j >= 0) cout << sort[j--] << endl;
		cout << endl;
	}
	return 0;
}