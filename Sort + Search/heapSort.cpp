//heapSort tang dan
#include<iostream>

using namespace std;

void heapify(int a[], int k, int n){
	if(k <= n/2 - 1){ // cac nut a[n/2-1] -> a[0] moi co con
		int j=2*k+1; // parent (i) -> leftchild (2*i+1), rightchild (2*i+2)
		if(j<n-1 && a[j]<a[j+1]){
			j++; 
		}
		if(a[k] < a[j]){  //gtri lon hon len lam root
			int temp=a[k];
			a[k]=a[j];
			a[j]=temp;
			heapify(a,j,n); 
		}
	}
}

void buildHeap(int a[], int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(a,i,n);
	}
}

void heapSort(int a[], int n){
	buildHeap(a,n);
	for(int i=n-1; i>=1; i--){
		int temp=a[0]; // doi cho ptu dau va cuoi
		a[0]=a[i];
		a[i]=temp;
		heapify(a,0,i); // xet tiep tu goc dau tien
	}
}

int main(){
	int n, a[n];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	heapSort(a,n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
	
}



