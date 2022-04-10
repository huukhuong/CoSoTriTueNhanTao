#include <cstdio>
#include<iostream>

int n, prime[40], result[25], ch[40];
int tp[10005][25], count;

void eratos(int n) // sàng số nguyên tố
{
    for (int i = 0; i < n + 1; i++)
    {
        prime[i] = 1;
        prime[0] = prime[1] = 0;
    }
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
            {
                for (int i = 0; i < k; i++)
                {
                    tp[count][i] = result[i];
                }
                count++;
            }
        }
    }
    else
        for (int i = 1; i <= 2 * n; i++)
        {
            if (ch[i] == 0 && prime[result[k - 1] + i] == 1)
            {  
                result[k] = i;
                ch[i] = 1;
                backtrack(k + 1);
                ch[i] = 0;
            }
        }
}

void show()
{
    for (int i = 0; i < count; i++)
    {
        printf("%d", tp[i][0]);
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            printf(" %d", tp[i][j]);
        }
        putchar('\n');
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
    show();
    return 0;
}