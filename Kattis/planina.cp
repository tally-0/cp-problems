#include<iostream>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int side = 2 * (pow(2, n - 1)) + 1;
	cout << side * side << endl;

	return 0;
}