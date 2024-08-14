#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	pair<int, string> cups[20];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin.ignore();
		if ('a' <= cin.peek() && cin.peek() <= 'z')
			cin >> cups[i].second >> cups[i].first;
		else {
			cin >> cups[i].first >> cups[i].second;
			cups[i].first >>= 1;
		}
	}
	sort(cups, cups + n);
	for(int i = 0; i < n; i++)
		cout << cups[i].second << endl;

	return 0;
}