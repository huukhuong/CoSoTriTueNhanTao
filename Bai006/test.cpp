#include <cstdio>

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

int n, prime[40], result[25], ch[40];
int tp[10005][25], count;

void eratos(int n) // sàng số nguyên tố
{
    REP(i, n + 1)
    prime[i] = 1;
    prime[0] = prime[1] = 0;
    int i = 2;
    while (i * i <= n)
    {
        for (int j = i + i; j <= n; j += i)
            prime[j] = 0;
        do
            ++i;
        while (i * i <= n && !prime[i]);
    }
}

void backtrack(int k) // quay lui
{
    if (k == 2 * n)
    {
        if (prime[result[k - 1] + result[0]])
        {
            if (count < 10000)
                REP(i, k)
            tp[count][i] = result[i];
            count++;
        }
    }
    else
        // FOR(i, 1, 2 * n)
        for (int i = 1; i <= 2 * n; i++)
        {
            if (!ch[i] && prime[result[k - 1] + i])
            {
                result[k] = i;
                ch[i] = 1;
                backtrack(k + 1);
                ch[i] = 0;
            }
        }
}

int main()
{
    eratos(39);
    scanf("%d", &n);
    result[0] = 1;
    ch[1] = 1;
    count = 0;
    backtrack(1);
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d", tp[i][0]);
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            printf(" %d", tp[i][j]);
        }
        putchar('\n');
    }
    return 0;
}