#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a < b)
			cout << "<" << endl;
		else if (a > b)
			cout << ">" << endl;
		else
			cout << "=" << endl;
	}

	return 0;
}