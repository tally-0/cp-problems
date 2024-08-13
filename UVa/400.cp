#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string name[101];
	int n;
	while(cin >> n) {
		int maxlen = 0;
		for(int i = 0; i < n; i++) {
			cin >> name[i];
			maxlen = max(maxlen, (int)name[i].length());
		}
		sort(name, name + n);
		int cols = (60 - maxlen) / (maxlen + 2) + 1;
		int rows = (n + cols - 1) / cols;

		cout << "------------------------------------------------------------" << endl;
		for(int i = 0; i < rows; i++) {
			for(int j = i; j < n; j += rows)
				cout << setw(maxlen + 2) << setiosflags(ios::left) << name[j];
			cout << endl;
		}
	}

	return 0;
}