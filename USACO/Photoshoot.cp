#include<iostream>
#include<map>
#include<string>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, res = 0;
	string str;
	cin >> n >> str;
	char last = str[0];
	for(int i = 0; i < n; i += 2) {
		if (str[i] == str[i+1]) continue;
		if (str[i] != last) {
			res++;
			last = str[i];
		}
	}
	if (last== 'G') res++;

	cout << res << endl;

	return 0;
}