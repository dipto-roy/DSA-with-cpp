#include<iostream>

using namespace std;

int BS(int* arr, int n, int key){
  int low, high, mid;
	low = 0;
	high = n-1;
	while(low<=high){
		mid = (low+high) >> 1;
		if (arr[mid] == key){
			return mid;
		}
		else if(arr[mid] < key) {
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return -1;
}

void sort(int* arr,int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}		
		}
	}
}

void print(int* a, int n){
	int i;
	for(i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[100];
	int i, n, key;
	cin>>n;
	for(i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr, n);
	cin >> key;
	cout<< BS(arr, n, key) << endl;
	return 0;
}