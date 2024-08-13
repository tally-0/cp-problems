#include<iostream>
#include<list>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	while(cin >> str) {
		list<char> beiju;
		auto it = begin(beiju);
		for(int i = 0; i < str.length(); i++) {
			if (str[i] == '[')
				it = begin(beiju);
			else if (str[i] == ']')
				it = end(beiju);
			else
				beiju.insert(it, str[i]);
		}
		for(it = begin(beiju); it != end(beiju); it++)
			cout << *it;
		cout << endl;
	}

	return 0;
}