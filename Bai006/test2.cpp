#include <iostream>
#include <math.h>
#include <algorithm>3
#define MAX 100
using namespace std;

int A[MAX][MAX];
int C[MAX], B[MAX];
int n;
int d; // số lượng chu trình


void print(int a[100][100])
{
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void init(int n) // khởi tạo giá trị mặc định của chu trình
{
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            A[i][j] = 0;
        }
    }
}

bool isPrime(int n) // Hàm kiểm tra các số nguyên tố.
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void matran(int n) // khởi tạo ma trận kề
{
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            int sum = i + j;
            int diff = abs(i - j);
            if (isPrime(sum))
            {  
                A[i][j] = 1;
            }
        }
    }
}

void Result(void) // in chu trình 
{

    for (int i = n; i > 0; i--)
        cout << B[i] << " ";
    d++; // tăng biến đếm các chu trình có thể tìm được
    cout << endl;
}

void Hamilton(int *B, int *C, int i) // duyệt chu trình Hamilton với tham số đầu vào là Ma trận kề A
{
    int j, k;
    for (j = 1; j <= n; j++)
    {
        if (A[B[i - 1]][j] == 1 && C[j] == 0)
        {
            B[i] = j;
            C[j] = 1;
            if (i < n)
                Hamilton(B, C, i + 1);
            else if (B[i] == B[0])
                Result();
            C[j] = 0;
        }
    }
}

int main()
{
    B[0] = 1; 
    cin >> n;
    int i = 1;
    d = 0;
    init(n);
    matran(n);
    n = 2 * n;
    Hamilton(B, C, i);
    cout << d;
}