#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string str[50];
	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			cin >> str[i];
		sort(str, str + n, [](const string& lhs, const string& rhs) {
			return rhs + lhs < lhs + rhs;
		});
		for(int i = 0; i < n; i++)
			cout << str[i];
		cout << endl;
	}

	return 0;
}