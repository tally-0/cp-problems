#include<iostream>

using namespace std;

#define endl '\n'

int sod(int n) {
    int s = 0;
	while(n) {
		s += n % 10;
		n /= 10;
	}
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n && n) {
        int s = sod(n), p = 11;
		while(sod(p * n) != s)
			p++;
        cout << p << endl;
    }

    return 0;
}