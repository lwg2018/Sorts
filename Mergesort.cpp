/*
                2015.10.19
                ��������
				                      */
				                      
				                      
/////////// �������� ///////////////									
#include <stdio.h>
#include <stdlib.h>

void MergeNsort(int arr[], int left, int mid, int right){
	int L,R;
	int *_arr; // ���ĵ� �迭�� ������ ���� 
	int i=left,j;
	
	_arr = (int*)malloc(sizeof(int)*(right+1));
	L=left; R=mid+1;
	
	while(L<=mid && R<=right){ 
		if(arr[L]<arr[R])*(_arr+i)=arr[L++]; // ���ʰ��� �����ʰ��� ���Ͽ� �켱������� ���� 
		else *(_arr+i)=arr[R++];
		i++;
	}
	
	if(L>mid){ // L�� �� ���������� 
		for(j=R;j<=right;i++){
			*(_arr+i)=arr[j++];
		}
	}
	
	else{
		for(j=L;j<=mid;i++){ // R�� �� ���������� 
			*(_arr+i)=arr[j++];
		}
	}
	
	for(i=left;i<=right;i++)arr[i]=*(_arr+i); // ���ĵ� �迭�� ���� 
	free(_arr);
}

void Mergesort(int arr[], int left, int right){
	int mid;
	
	if(left<right){
		mid = (left+right)/2;
		
		Mergesort(arr, left, mid);
		Mergesort(arr, mid+1, right);
		
		MergeNsort(arr, left, mid, right);
	}
}

int main(){
	int test[10] = {2,6,7,27,13,0,-5,2676,12,-16};
	
	Mergesort(test,0,9);
	for(int i=0;i<10;i++)printf("%d ",test[i]);
}










//////////// �������� /////////////////////

#include <stdio.h>
#include <stdlib.h>

void MergeNsort(int arr[], int left, int mid, int right){
	int L,R;
	int *_arr; // ���ĵ� �迭�� ������ ���� 
	int i=left,j;
	
	_arr = (int*)malloc(sizeof(int)*(right+1));
	L=left; R=mid+1;
	
	while(L<=mid && R<=right){ 
		if(arr[L]>arr[R])*(_arr+i)=arr[L++]; // ���ʰ��� �����ʰ��� ���Ͽ� �켱������� ���� 
		else *(_arr+i)=arr[R++];
		i++;
	}
	
	if(L>mid){ // L�� �� ���������� 
		for(j=R;j<=right;i++){
			*(_arr+i)=arr[j++];
		}
	}
	
	else{
		for(j=L;j<=mid;i++){ // R�� �� ���������� 
			*(_arr+i)=arr[j++];
		}
	}
	
	for(i=left;i<=right;i++)arr[i]=*(_arr+i); // ���ĵ� �迭�� ���� 
	free(_arr);
}

void Mergesort(int arr[], int left, int right){
	int mid;
	
	if(left<right){
		mid = (left+right)/2;
		
		Mergesort(arr, left, mid);
		Mergesort(arr, mid+1, right);
		
		MergeNsort(arr, left, mid, right);
	}
}

int main(){
	int test[10] = {2,6,7,27,13,0,-5,2676,12,-16};
	
	Mergesort(test,0,9);
	for(int i=0;i<10;i++)printf("%d ",test[i]);
} 

