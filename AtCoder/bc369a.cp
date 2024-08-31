#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	
	int dif = abs(a - b);
	if (!dif)
		cout << 0;
	else
		if (dif % 2)
			cout << 2;
		else
			cout << 1;


	return 0;
}