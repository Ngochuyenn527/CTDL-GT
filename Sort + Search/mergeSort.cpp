//mergeSort : mix two sorted array => one array
#include<iostream>

using namespace std;

//merge function
void merge(int a[], int l, int m, int r){
	int i=l;
	int j=m+1;
	int k=l;
	
}
//merge sort function
void mergeSort(int a[], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a, m+1, r);
		merge(a,l,m,r);
	}
}
int main(){
	int a[5];
	for(int i=0; i<5; i++){
		cin>>a[i];
	}
	cout<<"Befor mefer sort:\n";
	for(int i=0; i<5; i++){
		cout<<a[i];
	}
	
	//mergeSort function
	cout<<"After merge sort:\n";
	for(int i=0; i<5; i++){
		cout<<a[i];
	}
}

