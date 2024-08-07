#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int board[9][9] = { 0 };
	string s;
	for(int i = 2; i < 7; i++) {
		cin >> s;
		for(int j = 2; j < 7; j++)
			if (s[j] == 'k')
				board[i][j] = 1;
	}

	int valid = true, count = 0;
	for(int i = 2; i < 7 && valid; i++) {
		for(int j = 2; j < 7 && valid; j++) {
			if (board[i][j])
				count++;
			else
				continue;
			if (board[i + 1][j + 2])
				valid = false;
			if (board[i + 1][j - 2])
				valid = false;
			if (board[i - 1][j + 2])
				valid = false;
			if (board[i - 1][j - 2])
				valid = false;
			if (board[i + 2][j + 1])
				valid = false;
			if (board[i + 2][j - 1])
				valid = false;
			if (board[i - 2][j + 1])
				valid = false;
			if (board[i - 2][j - 1])
				valid = false;
		}
	}
	if (count != 9)
		valid = false;

	if (valid)
		cout << "valid";
	else
		cout << "invalid";			

	return 0;
}