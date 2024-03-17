#include<bits/stdc++.h>
using namespace std;

//sx tang dan
void bubbleSort(string a[], int n){
	for(int i=1; i<n; i++){
		for(int j=n-1; j>=i; j--){
			if(a[j]<a[j-1]){
				string temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

void selectionSort(string a[], int n){
	for(int i=0; i<n-1; i++){
		int min = i;
		for(int j=i+1; j<n; j++){
			if(a[min] > a[j]){
				min = j;
			}
		}
		string temp = a[min];
			a[min ] =a[i];
			a[i] = temp;
	}
}

void insertionSort(string a[], int &n){
	for(int i=1; i<n; i++){
		string tam = a[i];
		int j=i-1;
			while(j>=0 && a[j] > tam){
				a[j+1] = a[j];
				j--;
			}
			a[j+1]=tam;
		}
	}

int main(){
	string words[] = {"John", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    int n = sizeof(words) / sizeof(words[0]);
    insertionSort(words,n);
    for (int i = 0; i < n; ++i) {
        cout << words[i] << " ";
        
    }
}
