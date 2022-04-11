#include <iostream>
using namespace std;

struct VienChuc
{
    int mavienchuc;
    char tenvienchuc[30];
    int namsinh;
    int namvaolam;
    float hesoluong
};
typedef VienChuc VC;

void printLine(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "_";
    }
    cout << endl;
}
void nhapThongTinSV(VC &vc)
{   cout<<"Nhap ma vien chuc"<<endl;
    cin>>vc.mavienchuc;
    cout << "\n Nhap ten: ";
    fflush(stdin);
    gets(vc.ten);
    cout<<"\n Nhap nam sinh"<<endl;
    cin>>vc.namsinh;
    cout<<"\n Nhap nam vao lam"<<endl;
    cin>>vc.namvaolam;
    cout<<"\n He so luong"<<endl;
    cin>>vc.hesoluong;

}

void nhapSV(VC a[], int id, int n) {
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n], id);
    printLine(40);
}
int main()
{
}