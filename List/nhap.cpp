#include<bits/stdc++.h>

using namespace std;

struct Hocphan{
	int mahp;
	char tenhp[20];
	int stc;
};

struct Node{
	Hocphan infor;
	Node *next;
};

typedef Node* tro;

tro L;

void input(Hocphan &h){
	cout<<"mahp: "; cin>>h.mahp;
	cout<<"tenhp: "; fflush(stdin);gets(h.tenhp);
	cout<<"stc: "; cin>>h.stc;	
}

void input_list(tro &L){
	tro Q=L;
	L=NULL;
	for(int i=0; i<3; i++){
		Hocphan h;
		tro P = new Node;
		P->infor = h;
		P->next = NULL;
		
		if(L==NULL){
			L=P;
		}
		else{
			Q->next = P;
		}
		Q=P;
	}
}

void display(tro &L){
	cout<<"STT";
	cout<<setw(20)<<"MHP";
	cout<<setw(25)<<"THP";
	cout<<setw(30)<<"STC"<<endl;
	
	tro Q=L;
	int i=0;
	while(Q != NULL){
		Hocphan h = Q->infor;
		cout<<i+1;
		cout<<setw(20)<<h.mahp;
		cout<<setw(25)<<h.tenhp;
		cout<<setw(30)<<h.stc<<endl;
		i++;
		Q=Q->next;
	}
}

//add 
void addfirst(tro &L){
	Hocphan h;
	input(h);
	tro P = new Node;
	P->infor = h;
	
	P->next = L;
	L=P;
}

void add2(tro &L){   //add2 <=> sau 1
	Hocphan x;
	input(x);
	tro P=new Node;
	P->infor=x;
	
	P->next = L->next;
	L->next = P;
}


void addlast(tro &L){
	Hocphan h ;
	input(h);
	tro P = new Node;
	P->infor = h;
	
	tro Q=L;
	while(Q->next != NULL){
		Q = Q->next;
	}
	Q->next = P;
}

//add vt
void add_vt(tro &L, int k){
	if(k>0 && k<=4){
		giaovien h;
		tro P = new node;
		P->infor = h;
		
		tro H, Q=L;
		int i=1;
		if(k==1){ //addfirst
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

void add_beforevt(tro &L, int k){
	if(k>0 && k<=4){
		tro P = new Node;
		P->infor.mahp = 77;
		strcpy(P->infor.tenhp, "Giai Tich"); // cach gán cho kieu char
		P->infor.stc = 7
	
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
}

void add_aftervt(tro &L, int k){
	if(k>0 && k<=4){
		Hocphan h;
		cout<<"Nhap thong tin can chen: \n";
		input(h);
		tro P = new Node;
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


//add TRUOC sinh vien co nam sinh cao nhat
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
	giaovien x;
	input(x);
	tro P= new node;
	P->infor = x;
	
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
	giaovien x;
	input(x);
	tro P= new node;
	P->infor = x;

		int i=0;
		tro H;
		while(Q != NULL){
			if(i==k) break;
			i++;
			H=Q;
			Q=Q->next;
		}
		P->next = H->next;
		H->next = P; 
	
}



//delete
void delfirst(tro &L){
	tro P = L;
	L=L->next;
	delete(P);
}

void del2(tro &L){
	tro P = L->next;
	L->next = P->next;
	delete(P);
}


void dellast(tro &L){
	tro Q=L;
	while(Q->next != NULL){
		Q=Q->next;
	}
	delete(Q);
}

void del_vt(tro &l, int k){
	if(k>0 && k<=3){
		int i=1;
		tro h, q=l;
		if(k==1){
			l=l->next;
			delete(q);
		}
		else{
			while(q != NULL){
				if(i==k) break;
				i++;
				h=q;
				q=q->next;
			}
			h->next = q->next;
			delete(q);
		}
	}
}

void del_beforevt(tro &L, int k){
	if(k>0 && k<=3){
		int i=1;
		tro H, Q=L ;
	if(k==1){ 
		cout<<"No before";
	}
	
	else if(k==2){ //del1
		L=L->next;
		delete P;
	}
	
	else{
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
	display(L);
}

void del_aftervt(tro &L, int k){
	if(k>0 && k<=3){
		int i=0;
		tro H, Q=L;
		while(Q != NULL){
			if(i==k) break;
			i++;
			H=Q;
			Q=Q->next;
		}
		H->next = Q->next;
		delete(Q);	
	}
	display(L);
}


//xoa Sinhvien co diem cao nhat
void delgv(tro &L){
	
	//tim sinhvien
	int max = L->infor.stc;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.stc > max) max = Q->infor.stc;
	}
	
	//tim vi tri cua sinhvien co diem cao nhat
	int k=1;
	for(tro Q=L; Q!=NULL; Q=Q->next){
		if(Q->infor.stc == max) break;
		k++;
	}
	
	tro P=L;
	if(k==1){
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
	if(k==1){ 
		cout<<"No before";
	}
	else if(k==2){ //DEL1
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
	input_list(L);
	display(L);
	add_vt(L, 3);
	dellast(L);
	del_vt(L,1);
	
}
