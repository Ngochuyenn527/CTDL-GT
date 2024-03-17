#include<bits/stdc++.h>

using namespace std;

//1.Khai Bao
#define MAX 4

struct SinhVien{
	double msv;
	char hodem[50];
	char ten[50];
	char gioitinh[10];
	int namsinh;
	float diemtk;
};

struct List{
	int count;
	SinhVien e[MAX];
};

//khoi tao dsrong
void creat(List &L){
	L.count=-1;
}

//kiem tra danh sach rong
int empty(List L){
	return (L.count==-1);
	// rong tra ve 1
}

//kiem tra danh sach day
int full(List L){
	return (L.count == MAX-1);
	// day se tra ve 1, nguoc lai 0
}

//nhap phan thong tin 1 sv
void input(SinhVien &s){
	cout<<"Nhap thong tin sinh vien :\n";
	cout<<"Nhap msv : ";cin>>s.msv;
	cout<<"Nhap hodem : ";fflush(stdin); gets(s.hodem);
	cout<<"Nhap ten : "; fflush(stdin); gets(s.ten);
	cout<<"Nhap gioi tinh : ";fflush(stdin); gets(s.gioitinh);
	cout<<"Nhap nam sinh : ";fflush(stdin); cin>>s.namsinh;
	cout<<"Nhap diemtk : ";fflush(stdin); cin>>s.diemtk;
}

void nhapds(List &L){
	SinhVien s;
	L.count = 0;
	do{
		cout<<"Nhap sv thu "<<L.count + 1<<"\n";
		input(s);
		L.count++;
		L.e[L.count] = s;
		
	}
	while(L.count<MAX-2);
}
//hien thi danh sach
   void display(List L){
   	cout<<"STT";
   	cout<<setw(10)<<"msv";
   	cout<<setw(5)<<"hodem";
   	cout<<setw(5)<<"ten";
   	cout<<setw(5)<<"gioitinh";
   	cout<<setw(10)<<"namsinh";
   	cout<<setw(20)<<"diemtk";
   	cout<<endl;
	for(int i=0; i<=L.count; i++){
	cout<<i+1;
	cout<<setw(10)<<L.e[i].msv;
   	cout<<setw(5)<<L.e[i].hodem;
   	cout<<setw(5)<<L.e[i].ten;
   	cout<<setw(5)<<L.e[i].gioitinh;
   	cout<<setw(10)<<L.e[i].namsinh;
   	cout<<setw(20)<<L.e[i].diemtk<<endl;
	}
}

//them mot phan tu vao cuoi danh sach
int add(List &L, SinhVien x){
	if(full(L)) return 0;
	else{
		L.count++;
		L.e[L.count]=x;
		return 1;
	}
}


///loai bo phan tu thu k ra khoi danh sach
int remove(int k, List &L){
	if(k>0 &&k<=L.count+1){	
		for(int i=k;i<L.count;i++)
			L.e[i-1]=L.e[i];
		L.count--;
		return 1;
	}
}

//3.Chen them sv vao vtri thu 3 <=> i=2, k=3
int insert(int k, List &L, SinhVien x){
	cout<<"Nhap tt sv can bo sung "<<endl;
	input(x);
	if(k<=L.count+1 && k>0 && !full(L)){
		for(int i=L.count; i>=k-1; i--){
			L.e[i+1] = L.e[i];
		}
		L.e[k-1] = x;
		L.count++;
		return 1;
	}
	else return 0;
}

int main(){
	List L;
	SinhVien x;
	creat(L);
	cout<<empty(L)<<endl;
	cout<<full(L)<<endl;
	
	nhapds(L);
	
	display(L);
	
    cout<<"\nNhap tt cua ptu muon chen\n";
	input(x);
	cout<<add(L,x)<<endl;
	
	remove(3,L);
	display(L);
	
	SinhVien y;
	cout<<"check"<<insert(3,L,y)<<endl;
	cout<<L.count;
	display(L);
	return 0;
}







