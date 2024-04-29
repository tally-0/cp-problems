#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string name;
	cin >> name;

	bool appeared[26] = { false };
	for(int i = 0; i < name.length(); i++)
		appeared[name[i] - 'a'] = true;

	int sum = 0;
	for(const bool &i : appeared)
		sum += i;

	if (sum % 2)
		cout << "IGNORE HIM!";
	else
		cout << "CHAT WITH HER!";

	return 0;
}