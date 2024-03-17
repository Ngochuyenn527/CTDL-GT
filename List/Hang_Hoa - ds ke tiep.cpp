#include<bits/stdc++.h>
#define MAX 4
using namespace std;

struct Hanghoa{
	char mahang[25];
	char tenhang[25];
	char dvt[25];
	int sl, dongia;
	long thanhtien;
};

struct List{
	int count;
	Hanghoa e[MAX];
};

void nhap(Hanghoa &x){
	cout<<"Nhap ma hang: "; fflush(stdin); gets(x.mahang);
	cout<<"Nhap ten hang: "; fflush(stdin); gets(x.tenhang);
	cout<<"Nhap don vi tinh: "; fflush(stdin); gets(x.dvt);
	cout<<"Nhap so luong: "; cin>>x.sl;
	cout<<"Nhap don gia: "; cin>>x.dongia;
	x.thanhtien = x.dongia * x.sl;
	cout<<endl;
}

void nhapds(List &L){
	Hanghoa x;
	L.count = 0;
	for(int i=0; i<MAX; i++){
		cout<<"Nhap thong tin cho don hang thu "<< i+1 <<":\n";
		nhap(x);
	    L.e[L.count] = x;
	    cout<<"\n";
	    L.count++;
	}
}

void hienthi(List L){
	cout<<"STT";
	cout<<setw(10)<<"MA HANG";
	cout<<setw(11)<<"TEN HANG";
	cout<<setw(12)<<"DON VI TINH";
	cout<<setw(13)<<"SO LUONG";
	cout<<setw(14)<<"DON GIA";
	cout<<setw(15)<<"THANH TIEN";
	cout<<endl;
	for(int i=0; i<L.count; i++){
		cout<<i+1;
		cout<<setw(10)<<L.e[i].mahang;
		cout<<setw(11)<<L.e[i].tenhang;
		cout<<setw(12)<<L.e[i].dvt;
		cout<<setw(13)<<L.e[i].sl;
		cout<<setw(14)<<L.e[i].dongia;
		cout<<setw(15)<<L.e[i].thanhtien;
		cout<<"\n";
	}
}

//xoa ptu thu 3 <=> i=2
int xoa(List &L, int k){
	if(k>0 && k<=L.count+1){
		for(int i=k-1; i<MAX; i++){
		L.e[i] = L.e[i+1];
	}
		L.count--;
		return 1;
	}
	else return 0;
}

void xoaptu3(List &L){
	if(xoa(L,3)){
		cout<<"Xoa thanh cong\n";
		cout<<"Danh sach sau khi xoa:\n";
		hienthi(L);
	}
	else cout<<"Xoa khong thanh cong!\n";
}

//chen vao vi tri dau tien
int add(List &L, int k, Hanghoa &x){
  	if(k>0 && k<=L.count+1){
  		for(int i=L.count; i>=k-1; i--){
  			L.e[i+1] = 	L.e[i];
		  }
		  L.e[k-1] = x;
		  L.count++;
		  return 1;
	  }	
	else return 0;
}

void chenptu1(List &L){
	Hanghoa y;
	cout<<"Nhap tt hang hoa muon chen: \n";
	nhap(y);
	if(add(L,1,y)){
		cout<<"Chen thanh cong! \n";
		cout<<"Danh sach sau khi chen la: \n";
		hienthi(L);
	}
	else cout<<"CHEN KHONG THANH CONG";
}

//sx giam dan cua thanh tien theo pp noi bot
void sx(List &L){
	for(int i=1; i<L.count+1; i++){
		for(int j=L.count; j>=i;j--){
			if(L.e[j].thanhtien > L.e[j-1].thanhtien){
				int temp = L.e[j].thanhtien;
				L.e[j].thanhtien = L.e[j-1].thanhtien;
				L.e[j-1].thanhtien = temp;
			}
		}
	}
	hienthi(L);
}

int main(){
	List L;
	nhapds(	L);
	hienthi(L);
	cout<<"\nXoa ptu thu 3: \n";
	xoaptu3(L);
	cout<<"\nChen vao vi tri dau tien: \n";
	chenptu1(L);
	cout<<"\nDanh sach sau khi sx theo chieu giam dan thanh tien: \n";
	sx(	L);
	return 0;
}
