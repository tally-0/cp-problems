#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cout << i << " Abracadabra" << endl;

	return 0;
}