#include<iostream>

using namespace std;
int n = 10;
  int kq[100];
  int a[100];
  int l[100];
  int p[100];
  
static void input(int a[], int n){
	cout<<"Moi ban nhap phan tu " <<endl;
	for(int i = 1; i <= n ; i++){
		cin>>a[i];
	}		
}
static void LIS(){
	 l[0] = 1;
  int lmax = 0 ;
	  for (int i = 1; i < n; i++) {
	    lmax = 0;
	    int jmax = 0;
	    for (int j = 0; j < i; j++) {
	      if (a[i] > a[j]) {
	        if (l[j] > lmax ) {
	          lmax = l[j];
	          jmax = j;
	        }
	      }
	    }
	    l[i] = lmax + 1;
	    p[i] = jmax;
	  }
	  cout<< "[i] =  ";
	  for (int i = 1; i <= n; i++) {
	    cout << i << "\t";
	  }
	  cout << endl;
	  cout<< "A[i] = ";
	  for (int i = 1; i <= n; i++) {
	    cout << a[i] << "\t";
	  }
	  cout << endl;
	    cout<< "L[i] = ";
	  for (int i = 1; i <=n ; i++) {
	    cout << l[i] << "\t";
	  }
	  cout << endl;
  	// Truy Vet
	int lenght_max = 0;
	for (int i = 1; i < n; i++){

		if (l[i] > l[lenght_max])
		{
			lenght_max = i;
		}
    }
	int m = 1;
	while (1)
	{
		int i = lenght_max;
		kq[m++] = a[i];
		lenght_max = p[i];
		if (p[lenght_max] == 0) {
			kq[m++] = a[lenght_max];
			break;
		}
	}
	for (int i = m - 1; i > 0; i--)
	{
		cout << kq[i] << " ";
	}
}
int main() {
  
  input(a,n);
  LIS();
 
}
