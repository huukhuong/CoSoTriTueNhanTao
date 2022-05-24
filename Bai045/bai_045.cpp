/* n = 1
0
1
n = 2
00
01
11
10
n = 3
000
001
011
010
110
111
101
100*/

#include <bits/stdc++.h>
#include <fstream> 
using namespace std;

int main(){
	// khởi tạo chuõi
	string s[10000];
	//khai báo số bit = n
	int n;
	cin>>n;
	// số lượng phần tử = 2 mũ n
	int k =pow(2,n);
	//khởi tạo phần tử đầu tiên
	s[1]="0";
	s[2]="1";
	if(n>1){		// nếu n lớn hơn 1 thì tính gray tiếp theo
		int t =2;	// vị trí lấy đối xứng
		for(int i = 2; i<=n; i++){	//tính lần lượt các gray, duyệt từ gray thứ 2 tới thứ n
			int l=pow(2,i);		//sô lượng các mã gray thứ i
			for(int j= 1; j<=t; j++){
				s[l-j+1] = "1" + s[j];	//sao chép và đảo ngược toàn bộ gray thứ n-1
				s[j] = "0" + s[j];	//nửa đầu thêm 0 nửa sau thêm 1
			}
			t= l;
		}
	}
	//tạo file
	ofstream f("GRAYCODE.OUT");
	for(int j = 1; j<=k; j++){	//duyệt từng phần tử để lưu vào file
		cout<<s[j]<<" ";
		f<< s[j]<<" ";
	}
	f.close();	//đóng file
}
