#include<cstdio>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
    int n;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n) && n) {
        int s = 1;
        for(int m = 2; m <= sqrt(n); m++)
            if (!(n % m))
                s += m + (n / m);
        
        if (s < n || n == 1)
            printf("%5d  DEFICIENT\n", n);
        else if (s > n)
            printf("%5d  ABUNDANT\n", n);
        else
            printf("%5d  PERFECT\n", n);
    }
    printf("END OF OUTPUT\n");

    return 0;
}
