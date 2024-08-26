#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int i = 0;
	while(i < min(a.length(), b.length()) && a[i] == b[i])
		i++;
	int j = b.length() - 1;
    while(j >= 0 && b[j] == a[j + (a.length() - b.length())])
        j--;

	if (j - i < 0)
		cout << max((int)(b.length() - a.length()), 0);
	else
		cout << (j - i + 1);

	return 0;
}