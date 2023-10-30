#include<stdio.h>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
	printf("PERFECTION OUTPUT\n");

	int n;
	while(scanf("%d", &n) == 1 && n) {
		int s = 1;
		for(int u = 2; u <= (int)sqrt(n); u++) {
			if (!(n % u)) s += u + (int)(n/u);
		}
		if (s < n || n == 1) printf("%5d  DEFICIENT\n", n);
		else if (s > n) printf("%5d  ABUNDANT\n", n);
		else printf("%5d  PERFECT\n", n);
	}
	printf("END OF OUTPUT\n");
	return 0;
}