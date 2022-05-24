
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

void nhapmt(int arr[][20],int n,int m) //Nhap ma tran
{
    ifstream inputfile("input.txt");
    
    if (!inputfile.is_open()) 
    cout<<"Error opening file" ;

    for (int r = 0; r < n; r++) 
    {
        for (int c = 0; c < m; c++) 
        {
          inputfile >> arr[r][c];  
        }
    }
}

void inmt(int arr[][20],int n,int m) // in ma tran
{
  
   for (int r = 0; r < n; r++)
    {
        switch (r)
        {
        case 0:
            cout<<"alpha"<<"\t";
            break;
        case 1:
            cout<<"beta "<<"\t";
            break;
        case 2:
            cout<<"gamma"<<"\t";
            break;    
        case 3:
            cout<<"a"<<"\t";
            break;
        case 4:
            cout<<"b"<<"\t";
            break;
        case 5:
            cout<<"c"<<"\t";
            break;
        case 6:
            cout<<"S"<<"\t";
            break;
        case 7:
            cout<<"hC"<<"\t";
            break;

        default:
            break;
        }
        for (int c = 0; c < m; c++)
        {
            cout << arr[r][c] << "\t";
        }
        cout<<endl;
    }
    cout<<endl;
} 

void kh_1(int arr[][20],int i,int m)  // kich hoat dong ma cac bien da co gia tri ban dau

{
    for(int j=0;j<m;j++)
    {
        if (arr[i][j]==-1)
        {
            arr[i][j]=1;
        }
    }
}

void MangNN(int arr[][20],int n,int m)
{
    kh_1(arr,0,m);  //dinh alpha, beta, a duoc kich hoat
    kh_1(arr,1,m);
    kh_1(arr,3,m);
    cout<<"Ma tran sau khi kich hoat duoc alpha, beta, a:"<<endl;
    inmt(arr,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==-1)
            {
                kh_1(arr,i,m);
                break;
            }
        }
        switch (i)
        {
        case 3:
            cout<<"Ma tran sau khi kich hoat duoc gamma:"<<endl;
            inmt(arr,n,m);
            break;
        case 5:
            cout<<"Ma tran sau khi kich hoat duoc b:"<<endl;
            inmt(arr,n,m);
            break;
        case 6:
            cout<<"Ma tran sau khi kich hoat duoc c:"<<endl;
            inmt(arr,n,m);
            break;
        case 7:
            cout<<"Ma tran sau khi kich hoat duoc S:"<<endl;
            inmt(arr,n,m);
            break;
        default:
            break;
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
    return s;
}

void ketqua(int arr[][20],int n,int j) //dua ra ket qua
{
    float alpha,beta,a;
    cout<<"\nTinh duoc gia tri theo cong thuc Heron:"<<endl;
    cout<<"Dien tich S = "<<giatri(alpha,beta,a);
    
}

int main()
{
    int n=8,m=5,arr[20][20],j=1;
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

    nhapmt(arr,n,m);
    cout<<"Ma tran ban dau la \n";
    inmt(arr,n,m);
    MangNN(arr,n,m);
    ketqua(arr,n,j);
    getch();
}

