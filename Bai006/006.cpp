#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

int n, x[100], dd[100];
bool yes[100][100];
int res[100] = { 0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144 }; // mang so cach tim duoc vong so nguyen to
int dem = 0;
string s = "";

int readFile()
{
    fstream f;
    f.open("CIRCLE.INP", ios::in); // doc du lieu tu file input.txt
    string data;
    getline(f, data);
    stringstream geek(data); // su dung str stream de luu so n
    n = 0;
    geek >> n;
    f.close();
    return n;
}

void writeFile(string data)
{

    fstream f;
    f.open("CIRCLE.OUT", ios::out); // ghi du lieu ra file
    f << data;
    f.close();
}
bool isPrime(int n)
{ // ham kiem tra so nguyen to
    if (n <= 1) {
        return false;
    }
    for (int i = 2; (i * i) <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void dq(int t)
{
    if (t == n + 1) {
        if (!yes[x[1]][x[n]]) {
            return;
        }
        dem++;
        for (int i = 1; i <= n; i++) {
            //	cout<<x[i]<<" ";
            ostringstream str1;
            str1 << x[i];
            string geek = str1.str();
            s.append(geek);
            s.append(" ");
        }
        s.append("\n");
        //cout<<endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0 && yes[x[t - 1]][i]) {
            x[t] = i;
            dd[i] = 1;
            dq(t + 1);
            dd[i] = 0;
        }
    //	cout<<"test"<<s;
}

void setdata(int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            yes[i][j] = isPrime(i + j);
            yes[j][i] = yes[i][j];
        }
    x[1] = 1;
    dd[1] = 1;

    ostringstream str1;
    str1 << res[n / 2];
    string geek = str1.str();
    s.append(geek);
    s.append("\n");
}
int main()
{
    n = readFile(); // gan n = du lieu trong file input.txt
    n *= 2;
    setdata(n);
    dq(2);
    writeFile(s);
}
