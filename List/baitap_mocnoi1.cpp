#include<bits/stdc++.h>
using namespace std;
struct giaovien{
	char hoten[20];
	string gioitinh;
	int namsinh;
};

struct node{
	giaovien infor;
	node *next;
};
typedef node* tro;

void input(giaovien &x){
	cout<<"HOTEN: "; fflush(stdin); gets(x.hoten);
	cout<<"GIOITINH: ";  fflush(stdin); getline(cin, x.gioitinh);
	cout<<"NAMSINH: "; fflush(stdin); cin>>x.namsinh;
}

void input_list(tro &l){
	tro q=l;
	l=NULL;
	for(int i=0; i<3; i++){
		cout<<"Nhap thong tin cua giao vien thu "<<i+1<<" :\n";
		giaovien x;
		input(x);
		tro p = new node;
		p->infor = x;
		p->next = NULL;
		
		if(l== NULL){
			l=p;
		}
		else{
			q->next =p;
		}
		q=p;
	}
}

void display_list(tro &l){
	cout<<"STT";
	cout<<setw(15)<<"HOTEN";
	cout<<setw(25)<<"GIOITINH";
	cout<<setw(33)<<"NAMSINH"<<endl;
	
	tro q=l;
	int i=0;
	while(q != NULL){
		giaovien x = q->infor;
		cout<<1+i;
		cout<<setw(15)<<x.hoten;
		cout<<setw(25)<<x.gioitinh;
		cout<<setw(33)<<x.namsinh<<endl;
		q=q->next;
		i++;
	}
}

tro timvt(int vt, tro &l){
	tro q=l;
	int dem=0;
	if(vt==0) return l;
	else{
		while(q->next != NULL && vt != dem){
			q=q->next;
			dem++;
		}
		return q;
	}
}

void display_gtnam(tro &l){
	cout<<endl;
	cout<<"Danh sach giao vien nam la: \n";
	cout<<"STT";
	cout<<setw(15)<<"HOTEN";
	cout<<setw(25)<<"GIOITINH";
	cout<<setw(33)<<"NAMSINH"<<endl;
	
	tro q=l;
	int i=0;
	while(q != NULL){
		giaovien x = q->infor;
		if(q->infor.gioitinh == "nam"){
			cout<<1+i;
			cout<<setw(15)<<x.hoten;
			cout<<setw(25)<<x.gioitinh;
			cout<<setw(33)<<x.namsinh<<endl;
		}
		q=q->next;
		i++;
	}
}
//co 2 cach chen ptu moi
/* cach 1: nhap tu ban phim
		giaovien h;
		cout<<"Nhap thong tin can chen: \n";
		input(h);
		tro P = new node;
		P->infor = h;
*/

/*cach 2: creat 1 ptu moi luon trong source code (P) - khuyen khich dung cach nay vi bai thi cuoi ki se la code tren giay
		tro P= new node;
		strcpy(P->infor.hoten, "Ngoc Huyenn");
		P->infor.gioitinh = "nu";
		P->infor.namsinh = 77777;
*/
void add_vt(tro &L, int k){
	if(k>0 && k<=4){
		giaovien h;
		cout<<"Nhap thong tin can chen: \n";
		input(h);
		tro P = new node;
		P->infor = h;
		
		tro H, Q=L;
		int i=1;
		if(k==1){
			P->next = L;
			L=P;
		} 
		else{
			while(Q != NULL){
			if(i==k) break;
			i++;
			H=Q;
			Q=Q->next;
		}
		P->next = H->next;
		H->next = P;
		}
			
	}	
	display_list(L);
}

void add_aftervt(tro &L, int k){
	if(k>0 && k<=4){
		giaovien h;
		cout<<"Nhap thong tin can chen: \n";
		input(h);
		tro P = new node;
		P->infor = h;
		
		tro H, Q=L;
		int i=0;
		while(Q	 != NULL){
			if(i==k) break;
			i++;
			H=Q;
			Q=Q->next;
		}
		P->next = H->next;
		H->next = P;
	}
}


//add truoc sinh vien co nam sinh cao nhat
void add_beforegv(tro &L){
	int max = L->infor.namsinh;
	for(tro Q=L; Q != NULL; Q=Q->next){
		if(Q->infor.namsinh > max) max = Q->infor.namsinh;
	}
	
	int k=1;
	for(tro Q=L; Q != NULL; Q=Q->next){
		if(Q->infor.namsinh == max) break;
		k++;
	}
	
	tro Q=L;

	tro P= new node;
	strcpy(P->infor.hoten, "Ngoc Huyenn");
	P->infor.gioitinh = "nu";
	P->infor.namsinh = 77777;

	
	if(k==1){ //addfirst
		P->next = L;
		L=P;	
	}
	
	else if(k==2){// add truoc 2 => add sau 1
		P->next = L->next;
		L->next =P;
	}

	else{
		int i=1;
		while(Q != NULL){
			if(i+1==k) break;
			i++;
			Q=Q->next;
		}
		P->next = Q->next;
		Q->next = P; 
	}
	
}


//add SAU sinh vien co nam sinh cao nhat
void add_aftergv(tro &L){
	int max = L->infor.namsinh;
	for(tro Q=L; Q != NULL; Q=Q->next){
		if(Q->infor.namsinh > max) max = Q->infor.namsinh;
	}
	
	int k=1;
	for(tro Q=L; Q != NULL; Q=Q->next){
		if(Q->infor.namsinh == max) break;
		k++;
	}
	
	tro Q=L;
	tro P= new node;
	strcpy(P->infor.hoten, "Ngoc Huyenn");
	P->infor.gioitinh = "nu";
	P->infor.namsinh = 77777;
	
		int i=0;
		tro H;
		while(Q != NULL){
			if(i==k) break;
			i++;
			H=Q;
			Q=Q->next;
		}
		P->next = 	H->next;
		H->next = P; 

	
}


//xoa Sinhvien co namsinh  cao nhat
void delgv(tro &L){
	
	//tim sinhvien
	int max = L->infor.namsinh;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.namsinh > max) max = Q->infor.namsinh;
	}
	
	//tim vi tri cua sinhvien co diem cao nhat
	int k=1;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.namsinh == max) break;
		k++;
	}
	
	tro P=L;
	if(k==1){ // == delfirst
		L=L->next;
		delete P;
	}
	else{
		int i=1;
		tro H ;
		while(P != NULL){
			if(i==k) break;
			i++;
			H=P;
			P=P->next;
		}
		H->next = P->next;
		delete(P);
	}
}


//xoa Sinhvien SAU sv co namsinh  cao nhat
void del_aftergv(tro &L){
	
	//tim sinhvien
	int max = L->infor.namsinh;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.namsinh > max) max = Q->infor.namsinh;
	}
	
	//tim vi tri cua sinhvien co diem cao nhat
	int k=1;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.namsinh == max) break;
		k++;
	}
	
	tro P=L;


		int i=0;
		tro H ;
		while(P != NULL){
			if(i==k) break;
			i++;
			H=P;
			P=P->next;
		}
		H->next = P->next;
		delete(P);
}

//xoa Sinhvien TRUOC sv co namsinh  cao nhat
void del_beforegv(tro &L){
	
	//tim sinhvien
	int max = L->infor.namsinh;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.namsinh > max) max = Q->infor.namsinh;
	}
	
	//tim vi tri cua sinhvien co diem cao nhat
	int k=1;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.namsinh == max) break;
		k++;
	}
	
	tro P=L;
	if(k==1){ // ==del2
		cout<<"No before";
	}
	else if(k==2){
		L=L->next;
		delete P;
	}
	else{
		int i=1;
		tro H ;
		while(P != NULL){
			if(i+1==k) break;
			i++;
			H=P;
			P=P->next;
		}
		H->next = P->next;
		delete(P);
	}
}



int main(){
	tro l;
	input_list(l);
	display_list(l);
	display_gtnam(l);
	
//	cout<<"Danh sach sau khi xoa giao vien co nam sinh min la: \n";
//	delete_namsinhmin(l);
	//display_list(l);
//	chenvtri3(l);
//add_vt(l, 1);
add_beforegv(l);	display_list(l);
//add_aftergv(l);	display_list(l);

//delgv(l);	display_list(l);
//del_aftergv(l);	display_list(l);
//del_beforegv(l);	display_list(l);
//add_beforegv(l);	display_list(l);




	return 0;
}
