// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <algorithm>
// #include <cmath>
// #include <sstream>
// #include <string>
// #include <stdlib.h>
// #include <fstream>

// using namespace std;

// int n, x[100], dd[100];
// bool Prime[100][100];
// int res[100] = { 0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144 }; // mang so cach tim duoc vong so nguyen to
// string s = ""; // ket qua se luu vao bien s va ghi bien s ra file

// string numberToString(unsigned int n)
// {
//     stringstream ss;
//     ss << n;
//     return ss.str();
// }

// int stringToNumber(string s)
// {
//     return atoi(s.c_str());
// }

// int readFile()
// {
//     fstream f;
//     f.open("CIRCLE.INP", ios::in); // doc du lieu tu file CIRCLE.INP
//     string data;
//     getline(f, data);
//     n = stringToNumber(data); // lay du lieu tu file xong gan vao bien n
//     f.close();
//     return n;
// }

// void writeFile(string data)
// {

//     fstream f;
//     f.open("CIRCLE.OUT", ios::out); // ghi du lieu ra file
//     f << data;
//     f.close();
// }

// bool isPrime(int n)
// { // ham kiem tra so nguyen to
//     if (n <= 1) {
//         return false;
//     }
//     for (int i = 2; (i * i) <= n; i++) {
//         if (n % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// void dq(int t)
// {
//     if (t == n + 1) {
//         if (!Prime[x[1]][x[n]]) {
//             return;
//         }
//         for (int i = 1; i <= n; i++) {
//             cout << x[i] << " ";
//             string geek = numberToString(x[i]); // chuyen so thanh chu roi
//             s.append(geek); // gan vao bien "s" de luu vao file
//             s.append(" ");
//         }
//         s.append("\n");
//         cout << endl;
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//         if (dd[i] == 0 && Prime[x[t - 1]][i]) {
//             x[t] = i;
//             dd[i] = 1;
//             dq(t + 1);
//             dd[i] = 0;
//         }
//     //	cout<<"test"<<s;
// }

// void setdata(int n)
// {
//     for (int i = 1; i <= n; i++) {
//         for (int j = i; j <= n; j++) {
//             Prime[i][j] = isPrime(i + j);
//             Prime[j][i] = Prime[i][j]; // s�ng so nguyen to dua vao mang
//         }
//         // cout<<endl;
//     }
//     x[1] = 1;
//     dd[1] = 1;
//     //	 for (int i = 0; i < n; i++){
//     //	        for (int j = 0; j < n; j++) {
//     //	           	cout<<"yes["<<i<<"]["<<j<<"] = "<<yes[i][j]<<" ";
//     //	        }
//     //	        cout<<endl;
//     //	}
//     string geek = numberToString(res[n / 2]);
//     s.append(geek);
//     s.append("\n"); // luu so cach tim duoc vao chuoi
// }
// int main()
// {
//     n = readFile(); // gan n = du lieu trong file CIRCLE.INP
//     n *= 2;
//     cout << res[n / 2] << endl;
//     setdata(n);
//     dq(2);
//     writeFile(s);
//     cout << "Da ghi du lieu vao file CIRCLE.OUT" << endl;
//     system("pause");
//     return 0;
// }
