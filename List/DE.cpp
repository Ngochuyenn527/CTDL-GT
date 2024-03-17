#include<bits/stdc++.h>

using namespace std;

struct ipad{
	int id;
	char ten[20];
	double gia;
	int nam;
};

struct node{
	ipad infor;
	node *next;
};

typedef node* tro;

tro l;

void input(ipad &x){
	cout<<"id: "; cin>>x.id;
	cout<<"ten: "; fflush(stdin); gets(x.ten);
	cout<<"gia: "; cin>>x.gia;
	cout<<"nam: "; cin>>x.nam;
}

void input_list(tro &l){
	tro q=l;
	l=NULL;
	for(int i=0; i<3; i++){
		ipad x;
		input(x);
		tro p= new node;
		p->infor = x;
		p->next = NULL;
		
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
	cout<<setw(10)<<"ID";
	cout<<setw(15)<<"TEN";
	cout<<setw(20)<<"GIA";
	cout<<setw(25)<<"NAM"<<endl;
	
	tro q=l;
	int i=1;
	while(q != NULL){
		ipad x = q->infor;
		cout<<i;
		cout<<setw(10)<<x.id;
		cout<<setw(15)<<x.ten;
		cout<<setw(20)<<x.gia;
		cout<<setw(25)<<x.nam<<endl;
		
		q=q->next;
		i++;
		
	}
}

// b. add_vtk
void add_vt(tro &l, int k){
	if(k>0 && k<=3){
		tro p=new node;
		p->infor.id = 7;
		strcpy(p->infor.ten, "huyen");
		p->infor.gia = 7777;
		p->infor.nam= 2024;

		int i=1;
		tro h, q=l;
		
		if(k==1){
			p->next=l;
			l=p;
		}
		else{
			while(q != NULL){
				if(i==k) break;
				i++;
				h=q;
				q=q->next;
			}
			p->next = h->next;
			h->next =p;
		}
	}
}

// c. xoa_vtk
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

// d.xoa mat hang co namsx = 1998
void del_nsx(tro &l){
	int k=1;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.nam == 1998) break;
		k++;
	}
	
	int i=1;
	tro h, q=l;
	if(k==1){
		l=l->next;
		delete(q);
		display(l);
	}
	else if( k>=2 && k<=3){
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
	else{
		cout<<"\nno infor to delete\n";
	}
}

// f. display gia min
void display_giamin(tro &l){
	int min = l->infor.gia;
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.gia <min) min = q->infor.gia;
	}
	
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.gia == min){

					ipad x = q->infor;

					cout<<setw(10)<<x.id;
					cout<<setw(15)<<x.ten;
					cout<<setw(20)<<x.gia;
					cout<<setw(25)<<x.nam<<endl;

		}
	}
	
}

//g. display list co gia >5 trieu
void display_gia5(tro &l){
	
				cout<<"STT";
				cout<<setw(10)<<"ID";
				cout<<setw(15)<<"TEN";
				cout<<setw(20)<<"GIA";
				cout<<setw(25)<<"NAM"<<endl;
			
	int i=1;	
	for(tro q=l; q != NULL; q=q->next){
		if(q->infor.gia > 5){
					ipad x = q->infor;
					cout<<i;
					cout<<setw(10)<<x.id;
					cout<<setw(15)<<x.ten;
					cout<<setw(20)<<x.gia;
					cout<<setw(25)<<x.nam<<endl;
					
		}
		i++;
	}
}

// h. display giaban tb nam 2022;
void display_giatb2022(tro &l){
	int sum=0, dem=0;
	for(tro q=l; q!= NULL; q= q->next){
		if(q->infor.nam == 2022){
			sum += q->infor.gia ;
			dem++;
		}
	}
	
	cout<<"Gia ban trung binh cac ipad trong nam 2022: "<<(float) sum/dem<<"\n";
}

// J. display vitri 3
void display3(tro &l){
	int k=3;
				cout<<"STT";
				cout<<setw(10)<<"ID";
				cout<<setw(15)<<"TEN";
				cout<<setw(20)<<"GIA";
				cout<<setw(25)<<"NAM"<<endl;
				
	int i=1;
	for(tro q=l; q != NULL; q=q->next){
		if(i==k){
					ipad x = q->infor;
					cout<<i;
					cout<<setw(10)<<x.id;
					cout<<setw(15)<<x.ten;
					cout<<setw(20)<<x.gia;
					cout<<setw(25)<<x.nam<<endl;
					
		}
		i++;
	}
}

int main(){
	input_list(l);
	display(l);
	add_vt(l,2);
		display(l);
	del_vt(l,3);
		display(l);
//	del_nsx(l);
//	display_giamin(l);
//	display_gia5(l);
//	display_giatb2022(l);
//	display3(l);

	return 0;
}
