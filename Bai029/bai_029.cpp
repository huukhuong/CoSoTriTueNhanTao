#include <iostream>

void readFile(int &m, int &n, int arr[1000][1000])
{
    FILE *f = fopen("PAINT.INP", "rt");
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == 0 || i == m + 1 || j == 0 || j == n + 1)
                arr[i][j] = 0;
            else
                fscanf(f, "%d", &arr[i][j]);
        }
    }
    fclose(f);
}

void paint(int m, int n, int arr[1000][1000])
{
    int s = m * n;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (arr[i][j] > arr[i - 1][j])
                s += (arr[i][j] - arr[i - 1][j]);
            if (arr[i][j] > arr[i + 1][j])
                s += (arr[i][j] - arr[i + 1][j]);
            if (arr[i][j] > arr[i][j - 1])
                s += (arr[i][j] - arr[i][j - 1]);
            if (arr[i][j] > arr[i][j + 1])
                s += (arr[i][j] - arr[i][j + 1]);
        }
    }
    FILE *f = fopen("PAINT.OUT", "wt");
    fprintf(f, "%d", s);
    fclose(f);
}

int main()
{
    int m, n, arr[1000][1000];
    std::cout << "Bai 029 running...\n";
    readFile(m, n, arr);
    paint(m, n, arr);
    std::cout << "Success...\n";
    return 0;
}