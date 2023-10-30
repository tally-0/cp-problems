#include<cstdio>

using namespace std;

#define endl '\n'

int main() {
	int n, first = 1;
	while(scanf("%d", &n) && n) {
		if (!first)
			puts("");
		first = 0;
		bool f = false;
		for(int i = 1234; i <= (98765 / n); i++) {
			int j = i * n;
			int used = (i < 10000);
			for(int a = i; a; a /= 10)
				used |= 1 << (a % 10);
			for(int a = j; a; a /= 10)
				used |= 1 << (a % 10);
			if (used == (1 << 10) - 1) {
				printf("%05d / %05d = %d\n", j, i, n);
				f = true; 
			}
		}
		if (!f)
			printf("There are no solutions for %d.\n", n);
	}

	return 0;
}