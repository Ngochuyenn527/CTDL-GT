//sx day tang dan, roi tim kiem
#include<iostream>

using namespace std;

void bubbleSort(int x[], int n){
	for(int i=1; i<n; i++){
		for(int j=n-1; j>=i; j--){
			if(x[j]<x[j-1]){
				int temp = x[j];
				x[j] = x[j-1];
				 x[j-1] = temp;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}

}

void insertionSort(int x[], int n){
	for(int i=1; i<n; i++){
		int tam = x[i];
		int j=i-1;
			while(j>=0 && tam<x[j]){
				x[j+1] = x[j];
				j--;
			}
			x[j+1] = tam;
	}
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
}

void selectionSort(int x[], int n){
	for(int i=0; i<n-1; i++){
		int min=i;
		for(int j=i+1; j<n; j++){
			if(x[min]>x[j]){
				min = j;
			}
		}
		int temp = x[i];
		x[i]=x[min];
		x[min]=temp;
	}
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
}

int BinarySearch(int x[],int k, int left, int right){
	if(left>right) return -1;
	else{
			int mid = (left+right)/2;
			if(x[mid]==k) return mid;
			else if(k>x[mid]) return BinarySearch(x,k,mid+1,right);
		    else return BinarySearch(x,k,left,mid-1);
	}
}

int main(){
	int n;  cin>>n;
	int x[n];
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	bubbleSort(x,n); cout<<"\n";
	selectionSort(x,n); cout<<"\n";
	insertionSort(x,n); cout<<"\n";
	cout<<BinarySearch(x,74,0,n-1);
	return 0;
}



