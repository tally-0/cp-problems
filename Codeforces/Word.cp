#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

void to_upper(string &a) {
	for (int i = 0 ; i < (int)a.size(); i++) {
		if ( a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; 
	}
}

void to_lower(string &a) { 
	for ( int i = 0; i < (int)a.size(); i++) {
		if ( a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') count++;
	}

	if (count > s.size() - count) to_upper(s);
	else to_lower(s);

	cout << s << endl;

	return 0;
}