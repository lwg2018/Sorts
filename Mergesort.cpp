/*
                2015.10.19
                병합정렬
				                      */
				                      
				                      
/////////// 오름차순 ///////////////									
#include <stdio.h>
#include <stdlib.h>

void MergeNsort(int arr[], int left, int mid, int right){
	int L,R;
	int *_arr; // 정렬된 배열을 저장할 공간 
	int i=left,j;
	
	_arr = (int*)malloc(sizeof(int)*(right+1));
	L=left; R=mid+1;
	
	while(L<=mid && R<=right){ 
		if(arr[L]<arr[R])*(_arr+i)=arr[L++]; // 왼쪽값과 오른쪽값을 비교하여 우선순위대로 저장 
		else *(_arr+i)=arr[R++];
		i++;
	}
	
	if(L>mid){ // L이 다 저장됐을경우 
		for(j=R;j<=right;i++){
			*(_arr+i)=arr[j++];
		}
	}
	
	else{
		for(j=L;j<=mid;i++){ // R이 다 저장됐을경우 
			*(_arr+i)=arr[j++];
		}
	}
	
	for(i=left;i<=right;i++)arr[i]=*(_arr+i); // 정렬된 배열을 대입 
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










//////////// 내림차순 /////////////////////

#include <stdio.h>
#include <stdlib.h>

void MergeNsort(int arr[], int left, int mid, int right){
	int L,R;
	int *_arr; // 정렬된 배열을 저장할 공간 
	int i=left,j;
	
	_arr = (int*)malloc(sizeof(int)*(right+1));
	L=left; R=mid+1;
	
	while(L<=mid && R<=right){ 
		if(arr[L]>arr[R])*(_arr+i)=arr[L++]; // 왼쪽값과 오른쪽값을 비교하여 우선순위대로 저장 
		else *(_arr+i)=arr[R++];
		i++;
	}
	
	if(L>mid){ // L이 다 저장됐을경우 
		for(j=R;j<=right;i++){
			*(_arr+i)=arr[j++];
		}
	}
	
	else{
		for(j=L;j<=mid;i++){ // R이 다 저장됐을경우 
			*(_arr+i)=arr[j++];
		}
	}
	
	for(i=left;i<=right;i++)arr[i]=*(_arr+i); // 정렬된 배열을 대입 
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

