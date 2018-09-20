/*                       
                  Quick Sort(퀵 정렬)
				  2015.10.20
				                                   */


/*
///////////////// 오름차순 ////////////////////					   
#include <stdio.h>

int Quicksort(int arr[], int left, int right){
	int pivot = arr[left]; // 맨왼쪽값이 피봇 
	int low = left+1; // 피봇을 제외한 맨 왼쪽값 
	int high = right; // 맨 오른쪽값 
	int _sav; // 값 교체 
	
	while(low<=high){
		while(arr[low]<=pivot && low<=right){ // 우선순위가 높은값을 만날때까지 
			low++;
		}
		
		while(arr[high]>=pivot && high>=left+1){ // 우선순위가 낮은값을 만날때까지 
			high--;
		}
		
		if(low<=high){_sav=arr[low]; arr[low]=arr[high]; arr[high]=_sav;} // high가 더 크거나 같을때 자리교체 
	}
	
	_sav=arr[high]; arr[high]=pivot; arr[left]=_sav;
	return high; // 재귀함수호출을 위해 
}

void QuickNsort(int arr[], int left, int right){
	if(left<=right){
		int pivot = Quicksort(arr, left, right);
		QuickNsort(arr, left, pivot-1); // 왼쪽 
		QuickNsort(arr, pivot+1, right); // 오른쪽 
	}
}
	

int main(){
    int test[10] = {2,1,6,87,47,3,78,43,0,46};
    
    QuickNsort(test, 0, 9);
    
    for(int i=0; i<10; i++)printf("%d ",test[i]);
}
*/














////////////////// 내림차순 //////////////////////////

#include <stdio.h>

int Quicksort(int arr[], int left, int right){
	int pivot = arr[left]; // 맨왼쪽값이 피봇 
	int low = left+1; // 피봇을 제외한 맨 왼쪽값 
	int high = right; // 맨 오른쪽값 
	int _sav; // 값 교체 
	
	while(low<=high){
		while(arr[low]>=pivot && low<=right){ // 우선순위가 높은값을 만날때까지 
			low++;
		}
		
		while(arr[high]<=pivot && high>=left+1){ // 우선순위가 낮은값을 만날때까지 
			high--;
		}
		
		if(low<=high){_sav=arr[low]; arr[low]=arr[high]; arr[high]=_sav;} // high가 더 크거나 같을때 자리교체 
	}
	
	_sav=arr[high]; arr[high]=pivot; arr[left]=_sav;
	return high; // 재귀함수호출을 위해 
}

void QuickNsort(int arr[], int left, int right){
	if(left<=right){
		int pivot = Quicksort(arr, left, right);
		QuickNsort(arr, left, pivot-1); // 왼쪽 
		QuickNsort(arr, pivot+1, right); // 오른쪽 
	}
}
	

int main(){
    int test[10] = {2,1,6,87,47,3,78,43,0,46};
    
    QuickNsort(test, 0, 9);
    
    for(int i=0; i<10; i++)printf("%d ",test[i]);
} 
