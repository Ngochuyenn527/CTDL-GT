#include<bits/stdc++.h>

using namespace std;

struct sinhvien{
	int sbd;
	char ten[20];
	int nam;
	char lop[20];
	double diem;
};

struct node{
	sinhvien infor;
	node *next;
};

typedef node* tro;

tro l;

void input(sinhvien &x){
	cout<<"sbd: "; cin>>x.sbd;
	cout<<"ten: "; fflush(stdin); gets(x.ten);
	cout<<"nam: "; cin>>x.nam;
	cout<<"lop: "; fflush(stdin); gets(x.lop);
	cout<<"diem: "; cin>>x.diem;
}

void input_list(tro &l){
	tro q=l;
	l=NULL;
	for(int i=0; i<3; i++){
			sinhvien x;
			input(x);
			tro p= new node;
			p->infor = x;
			p->next= NULL;
			
			if(l==NULL){
				l=p;
			}
			else{
				q->next = p;
			}
			q=p;
	}
	

}

void display(tro &l){
    cout<<"STT";
	cout<<setw(10)<<"SBD";
	cout<<setw(10)<<"TEN";
	cout<<setw(10)<<"NAM";
	cout<<setw(10)<<"LOP";
	cout<<setw(10)<<"DIEM"<<endl;
	
	
	tro q=l;
	int i=1;
	while(q != NULL){
		sinhvien x = q->infor;
		    cout<<i;
			cout<<setw(10)<<x.sbd;
			cout<<setw(10)<<x.ten;
			cout<<setw(10)<<x.nam;
			cout<<setw(10)<<x.lop;
			cout<<setw(10)<<x.diem<<endl;
			
			q=q->next;
			i++;
	}

}

// c. xoa sinhvien vi tri 3
void del_vt3(tro &l){
	int k=3;
	int i=1;
	tro h, q=l;
	while(q != NULL){
		if(i==k) break;
		i++;
		h=q;
		q=q->next;
	}
	h->next = q->next;
	delete(q);
	display(l);
}

// d. show sv lop A1
void show_lopA1(tro &l){
	cout<<"STT";
	cout<<setw(10)<<"SBD";
	cout<<setw(10)<<"TEN";
	cout<<setw(10)<<"NAM";
	cout<<setw(10)<<"LOP";
	cout<<setw(10)<<"DIEM"<<endl;
	
	int i=1;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.lop == "A1"){
			sinhvien x= q->infor;
			cout<<i;
			cout<<setw(10)<<x.sbd;
			cout<<setw(10)<<x.ten;
			cout<<setw(10)<<x.nam;
			cout<<setw(10)<<x.lop;
			cout<<setw(10)<<x.diem<<endl;
			i++;
		}
	}
}


// e.show sv diem max
void show_diemmax(tro &l){
	int max = l->infor.diem;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.diem > max) max = q->infor.diem;
	}
	
	cout<<"STT";
	cout<<setw(10)<<"SBD";
	cout<<setw(10)<<"TEN";
	cout<<setw(10)<<"NAM";
	cout<<setw(10)<<"LOP";
	cout<<setw(10)<<"DIEM"<<endl;
	
	int i=1;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.diem == max){
			sinhvien x= q->infor;
			cout<<i;
			cout<<setw(10)<<x.sbd;
			cout<<setw(10)<<x.ten;
			cout<<setw(10)<<x.nam;
			cout<<setw(10)<<x.lop;
			cout<<setw(10)<<x.diem<<endl;
			i++;
		}
	}
	
}

// f. chen truoc sv co diem min
void insert_before(tro &l){
	int min=l->infor.diem;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.diem < min) min = q->infor.diem;
	}
	
	int k=1;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.diem == min) break;
		k++;
	}
	
	tro p=new node;
	p->infor.sbd = 7;
	strcpy(p->infor.ten, "huyen");
	p->infor.nam = 2022;
	strcpy(p->infor.lop, "huyen");
	p->infor.diem = 10;

	int i=1;
	tro q=l;
	if(k==1){
		p->next = l;
		l=p;
	}
	else if(k==2){
		p->next = l->next;
		l->next =p;
	}
	else{
		while(q != NULL){
			if(i+1==k) break;
			i++;
			q=q->next;
		}
		p->next = q->next;
		q->next = p;
	}
}


// f. chen sau sv co diem min
void insert_after(tro &l){
	int min=l->infor.diem;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.diem < min) min = q->infor.diem;
	}
	
	int k=1;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.diem == min) break;
		k++;
	}
	
	sinhvien x;
	input(x);
	tro p=new node;
	p->infor = x;

	int i=0;
	tro h, q=l;
		while(q != NULL){
			if(i==k) break;
			i++;
			h=q;
			q=q->next;
		}
		p->next = h->next;
		h->next = p;
}

void add_last(tro &l){
	sinhvien x;
	input(x);
	tro p= new node;
	p->infor = x;
	
	tro q=l;
	while(q->next!=NULL){
		q=q->next;
	}
	q->next = p;
}




int main(){
	input_list(l);
	display(l);
//	del_vt3(l);
//	show_lopA1(l);
//	show_diemmax(l);
//	insert_before(l);
//	display(l);
//	
	insert_after(l);
	display(l);
//	add_last(l);
//	display(l);

}
