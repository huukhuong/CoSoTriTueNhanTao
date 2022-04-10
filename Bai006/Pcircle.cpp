#include <iostream>
using namespace std;

int prime[40];
int n;
int result[25];
int ch[40];
int count;
void eratos(int n) // sàng số nguyên tố rồi đánh dấu số nguyên tố đem vào mảng
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
    // out put là các số nguyên tố đã được đánh dấu vào mảng theo dạng 0, 1
    //  "1 là số nguyên tố và ngược lại"
}

void backtrack(int k){
    if(k == n * 2)
}
int main()
{
    eratos(39);
    cout << "Nhập vào một số :" << endl;
    cin >> n;
    result[0] = 1;
    ch[1] = 1;
    count = 0;
}