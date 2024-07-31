#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p[2] = { 0 };
	string input;
	cin >> input;

	for(int i = 0; i < input.length(); i += 2)
		p[input[i] - 'A'] += (input[i + 1] == '1' ? 1 : 2);
	
	cout << (p[0] > p[1] ? 'A' : 'B') << endl;

	return 0;
}