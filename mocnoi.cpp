#include<bits/stdc++.h>
//Nhap thong tin danh sach 3 sinh vien
using namespace std;
struct sinhvien{
	int id;
	char name[25];
	double gpa; 
}; 

struct Node{
	sinhvien data;
	Node *next; 
};

typedef Node* tro;

void nhap(sinhvien &x){
	cout<<"Id: ";cin>>x.id;
	cout<<"Ten: "; fflush(stdin); gets(x.name);
	cout<<"GPA: "; cin>> x.gpa; 
} 

void nhapds(tro &L){
	tro P,Q;
	sinhvien x;
	int d = 0;
	L=NULL;
	do{
		cout<<"Nhap thong tin sinh vien "<<d+1<<"\n";
		nhap(x);
		P = new Node;
		P->data = x;
		P->next = NULL;
		if(L==NULL){
			L=P;
		}
		else{
			Q->next = P;
		}
		Q=P;
		d++;
	}
	while(d<3);
}

void hienthi(tro &L){
	cout<<"STT";
	cout<<setw(15)<<"MA";
	cout<<setw(27)<<"HO TEN";
	cout<<setw(33)<<"DIEM"<<endl;
	if(L==NULL){
		cout<<"ds rong";
		return;
	}
	tro Q=L;
	int i=0;
	while(Q != NULL){
		sinhvien x = Q->data;
		cout<<i+1;
		cout<<setw(15)<<x.id;
		cout<<setw(27)<<x.name;
		cout<<setw(33)<<x.gpa<<endl;
		Q=Q->next;
		i++;
	}
}

tro timvt(int vt, tro L){
	int dem=0; 
	tro Q = L;
	if(vt==0) return L;
	else{
		while(Q->next != NULL && dem != vt){
			Q=Q->next;
			dem++;
		}
		return Q;
	}
}

//Tính trung binh GPA - dem va in ra sv co GPA  > diem tb GPA
void(tro &L){
	
}

//chen thong tin cua 1 sv vao vi tri k
int add(tro &L, int k, sinhvien&x){
	if(k>0 && k<=4){
		tro P = new Node;
		P->data = x;
		tro Q=L;
		int i=1;
		while(Q != NULL){
			if(i==k) break;
			i++;
			Q=Q->next;
		}
		P->next = Q->next;
		Q->next = P;
		return 1;
	}
	else return 0;
}

int chenptu1(tro &L){
	sinhvien y;
	cout<<"\nNhap thong tin sinh vien can chen: \n";
	nhap(y);
	if(add(L, 1, y)){
		cout<<"Chen thanh cong !\n";
		cout<<"Danh sach sau khi chen la: \n";
		hienthi(L);
	}
	else cout<<"Chen khong thanh cong";
}

//so sanh con tro Q dau tien voi cac con tro con lai P
tro timmax(tro L){
	tro Q=L;
	tro P = Q->next;
	while(P != NULL){
		if(Q->data.gpa < P->data.gpa){
			Q=P;
		}
		P = P->next; 
	}
	return Q; // Q la max 
}

void xoamax(tro &L){
	tro P,Q;
	P = timmax(L);
	if(P==L){
		L=L->next;
		delete(P);
	}
	else{
		Q=L;
		while(Q->next != P){
			Q = Q->next;
		}
		Q->next = P->next;
		delete(P);
	}
}

//sx danh sach co diem GPA giam dan
void sapxep(tro &L){
	if(L==NULL){
		cout<<"danh sach rong";
	}
	else{
		tro Q=L;
		sinhvien x;
		while(Q != NULL){
			tro P = Q->next;
			while(P != NULL){
				if(Q->data.gpa < P->data.gpa){
				// doi cho sinh vien not doi co diem
				x = Q->data;
				Q->data = P->data;
				P->data = x;
			    }
			P = P->next;
			}
		Q = Q->next;
		}
	}
}

/* void sort(int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
	}
} */
void sort(tro &L){
	for(tro Q=L; Q->next != NULL; Q=Q->next){
		for(tro P=Q->next; P->next !=NULL; P=P->next){
			if(Q->data.gpa < P->data.gpa){
				sinhvien x = Q->data;
				Q->data = P->data;
				P->data = x;
			}
		}
	}
}

//Chen 1 sv dung truoc sv co id = 123;
void chends(tro &L){
	tro Q, P;
	sinhvien x;
	cout<<"\nNhap thong tin sinh vien muon chen: \n";
	nhap(x);
	tro H = new Node;
	H->data = x;
	if(L->data.id == 123){
		H->next = L;
		L=H;
		return;
	}
	else{
		Q=L;
		while(Q->next != NULL && Q->data.id != 123){
			P=Q;
			Q=Q->next;
		}
		H->next = P->next;
		P->next = H;
	}
}



int main(){
	sinhvien x; 
	tro L;
	nhapds(L);
	hienthi(L); 
	// vi tri thu 2 nghia la vi tri co i=2 va co STT = 3
	cout<<"\nThong tin ten cua sinh vien can tim la: "<<timvt(2,L)->data.name<<"\n";
	chenptu1(L);
	
	cout<<"\nDanh sach sau khi xoa sinh vien co GPA max la: \n";
	xoamax(L);
	hienthi(L);
	
	sapxep(L);
	cout<<"\nSap xep sinh vien co GPA giam dan CACH 1 la:  \n";
	hienthi(L);
	
	sort(L);
	cout<<"\nSap xep sinh vien co GPA giam dan CACH 2 la:  \n";
	hienthi(L);
	
	chends(L);
	cout<<"\nDanh sach sau khi chen sau 1 sv TRUOC sv co id = 123 \n";
	hienthi(L);
	
	return 0; 
} 
