#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

#define MAX 100
using namespace std;

int A[MAX][MAX];
int C[MAX], B[MAX];
int n;
int d;      // số lượng chu trình
int sodinh; // số đỉnh = 2n;
string s;

string numberToString(unsigned int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}
void readFile() // hàm đọc file
{   
    ifstream file;
    file.open("CIRCLE.INP");
    file >> n;
    file.close();
}

void writeFile()
{
    // dữ liệu về các chu trình đã được gán vào biến s ở trong hàm Result();
    ofstream file("CIRCLE.OUT");
    file << d; // in số lượng chu trình tìm thấy
    file << '\n';
    file << s;  // in biến s
    file.close();
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
    for (int i = 2; i <= sqrt(n); i++)
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
    d++;
    for (int i = sodinh; i > 0; i--)
    {
        cout << B[i] << " ";
        string geek = numberToString(B[i]); // chuyen so thanh chu roi
        s.append(geek);                     // gan vao bien "s" de luu vao file
        s.append(" ");
    }
    s.append("\n");
    // tăng biến đếm các chu trình có thể tìm được
    cout << endl;
}

void Hamilton(int *B, int *C, int i) // duyệt chu trình Hamilton với tham số đầu vào là Ma trận kề A
{
    int j, k;
    for (j = 1; j <= sodinh; j++)
    {
        if (A[B[i - 1]][j] == 1 && C[j] == 0)
        {
            B[i] = j;
            C[j] = 1;
            if (i < sodinh)
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
    readFile();
    int i = 1; // xuất phát từ đỉnh 1
    d = 0;     // gán biến đếm số lượng chu trình = 0 ;
    init(n);   // khởi tạo ma trận
    matran(n); // tạo ma trận kề
    sodinh = 2 * n;
    Hamilton(B, C, i); // chuyển ma trận kề thành chu trình
    writeFile();
    system("pause");
    return 0 ;
}