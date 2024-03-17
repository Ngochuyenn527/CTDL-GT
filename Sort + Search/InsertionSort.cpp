//sx tang dan day so theo pp sx chen
#include<iostream>

using namespace std;

void insertionSort(int x[], int n){
	for(int i=1; i<n; i++){
		// gom n-1 lan 
		int tam = x[i];
		int j=i-1;
		while(j>=0 && x[j]>tam){// dieu kien de while
			x[j+1] = x[j];
			j--;
		}
		x[j+1]= tam;
	}
	
}

int main(){
	int n; cin>>n;
	int x[n];
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	insertionSort(x,n);
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
	return 0;
	
}
