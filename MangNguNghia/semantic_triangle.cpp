
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

int n,m,j;
int x[20][20];

void nhapmt(int x[][20],int n,int m) //Nhap ma tran
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<"x["<<i<<","<<j<<"]=";
            cin>>x[i][j];
        }
    }
}

void inmt(int x[][20],int n,int m) // in ma tran
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<setw(4)<<x[i][j];
            
        }
        cout<<endl;
    }
} 

void kh_1(int x[][20],int i,int m)  // kich hoat dong ma cac bien da co gia tri ban dau

{
    for(int j=1;j<=m;j++)
    {
        if (x[i][j]==-1)
        {
            x[i][j]=1;
        }
    }
}

int dem_1(int x[][20],int n,int j) //dem gia tri = 1 trong cot
{
    int dem=0;
    for(int i=1;i<=n;i++)
    {
        if (x[i][j]==1)
        {
            dem=dem++;
        }
    }
    return dem;
}
int dem_k0(int x[][20],int n,int j) //dem gia tri khac 0 trong cot
{
    int dem=0;
    for(int i=1;i<=n;i++)
    {
        if (x[i][j]!=0)
        {
            dem=dem++;
        }
    }
    return dem;
}
void kh_2(int x[][20],int i,int m) //kich hoat cac phan tu dong i
{
    for (int j=1;j<=m;j++)
    {
        if(x[i][j]==-1)
        {
            x[i][j]=1;
        }
    }
}
int dong_kh(int x[][20],int n,int j) //tim dong duoc kich hoat
{
    int vt;
    for(int i=1;i<=n;i++)
    {
        if(x[i][j]==-1)
        {
            vt=i;
            return vt;
        }
    }
    return 0;
}

// neu cot j ma tong tai dem_1 +1 == dem_k0
// kich hoat dong ma co gia tri bang -1 trong cot j

void MangNN(int x[][20],int n,int m)
{
    kh_1(x,1,m);  //dinh alpha, beta, a duoc kich hoat
    kh_1(x,2,m);
    kh_1(x,4,m);

    for(int j=1;j<=m;j++)
    {
        if(dem_1(x,n,j)+1 ==dem_k0(x,n,j))
        {
            kh_2(x,dong_kh(x,n,j),m);
        }
    }
}
float giatri(float alpha,float beta,float a)
{
    float delta,b,c,s,hc;
    alpha=1.5708, beta=0.6446, a=5;
    b=(a*sin(beta))/sin(alpha);
    delta=3.1416 - alpha - beta;
    c=(b*sin(delta))/sin(beta);
    float p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    hc=(s/c)*2;
    return hc;
}

void ketqua(int x[][20],int n,int j) //dua ra ket qua
{
    float alpha,beta,a;
    //gia tri can tinh nam trong cong thuc thu j
    //nhap gia tri j
    cout<<"\nNhap so cong thuc co chua gia tri can tinh: ";
    cin>>j;
    
    if(dem_1(x,n,j)==dem_k0(x,n,j))
    {
        cout<<"\nTinh duoc gia tri theo cong thuc"<<endl;
        cout<<"Chieu cao hc = "<<giatri(alpha,beta,a);
    }
    else
    {
        cout<<"\nKhong tinh duoc gia tri theo cac cong thuc"<<endl;
        cout<<"\nVi nhung bien lien quan khong the tinh duoc theo cong thuc";

    }
}

int main()
{
    int n=8,m=5,a[20][20],j;
    //float alpha=1.5708,beta=0.6446,a=5;
    /*  Ma tran ban dau (alpha,beta,a kich hoat truoc)
            (1) (2) (3) (4) (5)
    alpha   -1  -1  0   0   0
    beta    -1  -1  -1  0   0
    gamma   -1  0   -1  0   0
    a       0   -1  0   -1  0
    b       0   -1  -1  -1  0
    c       0   0   -1  -1  -1
    S       0   0   0   -1  -1
    hC      0   0   0   0   -1
    */
    //kiet lac
    cout<<"Nhap gia tri ma tran \n";
    nhapmt(x,n,m);
    cout<<"Ma tran ban dau la \n";
    inmt(x,n,m);
    MangNN(x,n,m);
    cout<<"Ma tran ket qua la\n";
    ketqua(x,n,j);
    getch();
}

