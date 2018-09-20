/*             
               2015.10.15
               자료구조  : Heap (힙)
			                                */
											

/*
// C언어 우선순위를 입력으로 받는 불완전한 우선순위 큐										
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

using namespace std;

typedef char HData;
typedef int Priority;

typedef struct _heapElem{
	Priority pr;  // 값이 작을수록 높은 우선순위
	HData data;
}HeapElem;

typedef struct _heap{
	int numOfData; // 데이터 수
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
int GetHiPriChildIDX(Heap* ph, int idx); 
HData HDelete(Heap* ph);

int GetParentIDX(int idx){ // 부모 노드의 인덱스 값 반환
    return idx/2;
}

int GetLChildIDX(int idx){ // 왼쪽 자식 노드의 인덱스 값 반환 
	return idx*2;
}

int GetRChildIDX(int idx){ // 오른쪽 자식 노드의 인덱스 값 반환 
	return idx*2+1;
}

int main(){
	Heap heap;
	HeapInit(&heap);
	
	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));
	
	
	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));
	
	while(!HIsEmpty(&heap))
	printf("%c \n", HDelete(&heap));
	
	return 0;
}

void HeapInit(Heap* ph){ // 힙의 초기화 
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph){  // 힙이 비었는지 확인 
	if(ph->numOfData == 0)return TRUE;
	
	else return FALSE;
}

int GetHiPriChildIDX(Heap* ph, int idx){ // 두개의 자식노드중 우선순위가 높은 노드 인덱스값 반환 
	if(GetLChildIDX(idx)>ph->numOfData)return 0; // 자식노드가 없다면 
	else if(GetLChildIDX(idx)==ph->numOfData)return GetLChildIDX(idx); // 자식노드가 한개라면 
	
	else{ // 자식노드가 두개라면 
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
		    return GetRChildIDX(idx);
		else
		    return GetLChildIDX(idx);
		}
}

void HInsert(Heap* ph, HData data, Priority pr){ // 힙에 데이터 저장 
	int idx = ph->numOfData+1; // 저장될 데이터의 인덱스값은 맨 마지막 
	HeapElem nelem = {pr, data}; // 하나의 노드에 저장할 노드 복사 
	
	while(idx != 1){ // 인덱스가 전체의 루트노드일경우 종료 
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr)){ // 우선순위 비교 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		
		else break;
	}
	
	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph){ // 힙에 데이터 삭제 
	HData retData = (ph->heapArr[1]).data; // 루트노드의 데이터 복사 
	HeapElem lastElem = ph->heapArr[ph->numOfData]; // 맨 마지막 노드 복사 
	
	int parentIdx = 1; // 부모노드의 인덱스값 
	int childIdx; // 우선순위가 높은 자식노드의 인덱스값 
	
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)){ // 자식노드가 없을경우 종료 
        if(lastElem.pr <= ph->heapArr[childIdx].pr)break; 
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem; // 최종으로 구한 자리에 노드 대입 
    ph->numOfData -= 1;
    return retData;
}
*/


// 쓸만한 수준의 힙으로 구현한 우선순위 큐. 따로 우선순위를 입력받지 않는다

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

using namespace std;

typedef char HData;
typedef int Priority;
typedef int PriorityComp(HData d1, HData d2); 

typedef struct _heap{
	PriorityComp* comp;
	int numOfData; // 데이터 수
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
int GetHiPriChildIDX(Heap* ph, int idx); 
HData HDelete(Heap* ph);

int DataPriorityComp(char ch1, char ch2){
	return ch2-ch1;
}

int GetParentIDX(int idx){ // 부모 노드의 인덱스 값 반환
    return idx/2;
}

int GetLChildIDX(int idx){ // 왼쪽 자식 노드의 인덱스 값 반환 
	return idx*2;
}

int GetRChildIDX(int idx){ // 오른쪽 자식 노드의 인덱스 값 반환 
	return idx*2+1;
}

int main(){
	Heap heap;
	HeapInit(&heap, DataPriorityComp);
	
	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));
	
	
	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));
	
	while(!HIsEmpty(&heap))
	printf("%c \n", HDelete(&heap));
	
	return 0;
}

void HeapInit(Heap* ph, PriorityComp pc){ // 힙의 초기화 
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph){  // 힙이 비었는지 확인 
	if(ph->numOfData == 0)return TRUE;
	
	else return FALSE;
}

int GetHiPriChildIDX(Heap* ph, int idx){ // 두개의 자식노드중 우선순위가 높은 노드 인덱스값 반환 
	if(GetLChildIDX(idx)>ph->numOfData)return 0; // 자식노드가 없다면 
	else if(GetLChildIDX(idx)==ph->numOfData)return GetLChildIDX(idx); // 자식노드가 한개라면 
	
	else{ // 자식노드가 두개라면 
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)],ph->heapArr[GetRChildIDX(idx)]) < 0)
		    return GetRChildIDX(idx);
		else
		    return GetLChildIDX(idx);
		}
}

void HInsert(Heap* ph, HData data){ // 힙에 데이터 저장 
	int idx = ph->numOfData+1; // 저장될 데이터의 인덱스값은 맨 마지막 
	
	while(idx != 1){ // 인덱스가 전체의 루트노드일경우 종료 
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0){ // 우선순위 비교 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		
		else break;
	}
	
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph){ // 힙에 데이터 삭제 
	HData retData = ph->heapArr[1]; // 루트노드의 데이터 복사 
	HData lastElem = ph->heapArr[ph->numOfData]; // 맨 마지막 노드 복사 
	
	int parentIdx = 1; // 부모노드의 인덱스값 
	int childIdx; // 우선순위가 높은 자식노드의 인덱스값 
	
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)){ // 자식노드가 없을경우 종료 
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)break; 
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem; // 최종으로 구한 자리에 노드 대입 
    ph->numOfData -= 1;
    return retData;
}
