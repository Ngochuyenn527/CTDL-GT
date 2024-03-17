#include<iostream>

using namespace std;

void selectionSort(int x[], int n){
	for(int i=0; i<n-1; i++){
		int min = i; //gan vi tri cua min tai i
		for(int j=i+1; j<n; j++){
			if(x[min]> x[j]){
				min = j; // thay doi vi tri cua min tai j
			}
		}
		int temp=x[i];
		x[i]=x[min];
		x[min]=temp;
	}
}

int main(){
	int n; cin>>n;
	int x[n];
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	selectionSort(x,n);
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
	return 0;
}
