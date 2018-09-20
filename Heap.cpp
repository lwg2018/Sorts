/*             
               2015.10.15
               �ڷᱸ��  : Heap (��)
			                                */
											

/*
// C��� �켱������ �Է����� �޴� �ҿ����� �켱���� ť										
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

using namespace std;

typedef char HData;
typedef int Priority;

typedef struct _heapElem{
	Priority pr;  // ���� �������� ���� �켱����
	HData data;
}HeapElem;

typedef struct _heap{
	int numOfData; // ������ ��
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
int GetHiPriChildIDX(Heap* ph, int idx); 
HData HDelete(Heap* ph);

int GetParentIDX(int idx){ // �θ� ����� �ε��� �� ��ȯ
    return idx/2;
}

int GetLChildIDX(int idx){ // ���� �ڽ� ����� �ε��� �� ��ȯ 
	return idx*2;
}

int GetRChildIDX(int idx){ // ������ �ڽ� ����� �ε��� �� ��ȯ 
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

void HeapInit(Heap* ph){ // ���� �ʱ�ȭ 
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph){  // ���� ������� Ȯ�� 
	if(ph->numOfData == 0)return TRUE;
	
	else return FALSE;
}

int GetHiPriChildIDX(Heap* ph, int idx){ // �ΰ��� �ڽĳ���� �켱������ ���� ��� �ε����� ��ȯ 
	if(GetLChildIDX(idx)>ph->numOfData)return 0; // �ڽĳ�尡 ���ٸ� 
	else if(GetLChildIDX(idx)==ph->numOfData)return GetLChildIDX(idx); // �ڽĳ�尡 �Ѱ���� 
	
	else{ // �ڽĳ�尡 �ΰ���� 
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
		    return GetRChildIDX(idx);
		else
		    return GetLChildIDX(idx);
		}
}

void HInsert(Heap* ph, HData data, Priority pr){ // ���� ������ ���� 
	int idx = ph->numOfData+1; // ����� �������� �ε������� �� ������ 
	HeapElem nelem = {pr, data}; // �ϳ��� ��忡 ������ ��� ���� 
	
	while(idx != 1){ // �ε����� ��ü�� ��Ʈ����ϰ�� ���� 
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr)){ // �켱���� �� 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		
		else break;
	}
	
	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph){ // ���� ������ ���� 
	HData retData = (ph->heapArr[1]).data; // ��Ʈ����� ������ ���� 
	HeapElem lastElem = ph->heapArr[ph->numOfData]; // �� ������ ��� ���� 
	
	int parentIdx = 1; // �θ����� �ε����� 
	int childIdx; // �켱������ ���� �ڽĳ���� �ε����� 
	
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)){ // �ڽĳ�尡 ������� ���� 
        if(lastElem.pr <= ph->heapArr[childIdx].pr)break; 
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem; // �������� ���� �ڸ��� ��� ���� 
    ph->numOfData -= 1;
    return retData;
}
*/


// ������ ������ ������ ������ �켱���� ť. ���� �켱������ �Է¹��� �ʴ´�

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
	int numOfData; // ������ ��
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

int GetParentIDX(int idx){ // �θ� ����� �ε��� �� ��ȯ
    return idx/2;
}

int GetLChildIDX(int idx){ // ���� �ڽ� ����� �ε��� �� ��ȯ 
	return idx*2;
}

int GetRChildIDX(int idx){ // ������ �ڽ� ����� �ε��� �� ��ȯ 
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

void HeapInit(Heap* ph, PriorityComp pc){ // ���� �ʱ�ȭ 
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph){  // ���� ������� Ȯ�� 
	if(ph->numOfData == 0)return TRUE;
	
	else return FALSE;
}

int GetHiPriChildIDX(Heap* ph, int idx){ // �ΰ��� �ڽĳ���� �켱������ ���� ��� �ε����� ��ȯ 
	if(GetLChildIDX(idx)>ph->numOfData)return 0; // �ڽĳ�尡 ���ٸ� 
	else if(GetLChildIDX(idx)==ph->numOfData)return GetLChildIDX(idx); // �ڽĳ�尡 �Ѱ���� 
	
	else{ // �ڽĳ�尡 �ΰ���� 
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)],ph->heapArr[GetRChildIDX(idx)]) < 0)
		    return GetRChildIDX(idx);
		else
		    return GetLChildIDX(idx);
		}
}

void HInsert(Heap* ph, HData data){ // ���� ������ ���� 
	int idx = ph->numOfData+1; // ����� �������� �ε������� �� ������ 
	
	while(idx != 1){ // �ε����� ��ü�� ��Ʈ����ϰ�� ���� 
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0){ // �켱���� �� 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		
		else break;
	}
	
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph){ // ���� ������ ���� 
	HData retData = ph->heapArr[1]; // ��Ʈ����� ������ ���� 
	HData lastElem = ph->heapArr[ph->numOfData]; // �� ������ ��� ���� 
	
	int parentIdx = 1; // �θ����� �ε����� 
	int childIdx; // �켱������ ���� �ڽĳ���� �ε����� 
	
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)){ // �ڽĳ�尡 ������� ���� 
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)break; 
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem; // �������� ���� �ڸ��� ��� ���� 
    ph->numOfData -= 1;
    return retData;
}
