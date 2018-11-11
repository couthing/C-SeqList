#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>;

void  SeqListInit(SeqListR *pSeq)
{
	//pSeq��һ�������ĵ�ַ��������Ϊ0���൱�ں����ڶ������ϲ�����0��
	assert(pSeq != NULL);

	pSeq->size = 0;

	//if (pSeq = NULL){
	//	//��pSeq�����ж�(�൱�ں����ڶ������ϰ���0����Ҫ��������������ж�)
	//}
}

void  SeqListDestory(SeqListR *pSeq)
{
	assert(pSeq != NULL);

	pSeq->size = 0;
}

//β��
void SeqListPushBack(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE){
		printf("����\n");
		return;
	}

	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
}

//ͷ��
//һ��һ��Ԫ���ƣ�������ϰ��/memmove
//1. ���򣺴Ӻ���ǰ��
//2. ѭ����������ÿ�������ĺ��壩
//       1.���ݵ��±� 
//       2.�ռ���±�
void SeqListPushFront(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE){
		printf("����\n");
		return;
	}

	//������
#if i//i�ĺ����������±�
	//[size-1,0] [i]�Ƶ�[i+1]
	for (int i = pSeq->size - 1; i >= 0; i--){
		pSeq->array[i + 1] = pSeq->array[i];
	}
#else j//j�ĺ����ǿռ��±�
	//[size,0) [i-1]�Ƶ�[i]
	for (int j = pSeq->size; j > 0; j--){
		pSeq->array[j] = pSeq->array[j - 1];
	}
#endif
	pSeq->array[0] = data;
	pSeq->size++;
}


//�м����
//��������
void SeqListInsert(SeqListR *pSeq, int pos, DataType data){
	assert(pSeq->size<MAX_SIZE);
	assert(pos>=0&&pos<=pSeq->size);
	//ǰ��Ĳ������м����һ���������Ԫ��������һ��
    //j�ĺ����ǿռ��±�
	//[size,pos) [i-1]�Ƶ�[i] �Ӻ���ǰ
	for (int j = pSeq->size; j > pos; j--){
		pSeq->array[j] = pSeq->array[j - 1];
	}

	pSeq->array[pos] = data;
	//��Ҫ��
	pSeq->size += 1;

}

//��ӡ
void SeqListPrint(const SeqListR *pSeq)
{
	for (int i = 0; i < pSeq->size; i++){
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}


//βɾ
void SeqListPopBack(SeqListR *pSeq){
	assert(pSeq != NULL);     //�����ַ����Ϊ��
	assert(pSeq->size > 0);   //˳���Ϊ��

	pSeq->size--;
}


//ͷɾ
void SeqListPopFront(SeqListR *pSeq){
	assert(pSeq != NULL);     //�����ַ����Ϊ��
	assert(pSeq->size > 0);   //˳���Ϊ��

	//���ݰ���
	//1. �����±� [1 ,size - 1] or [1, size)
	//2. �ռ��±� [0, size - 2] or [1, size - 1)
	//i�����ǿռ���±�
	for (int i = 0; i <= pSeq->size - 2; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

//�����±�ɾ��
void SeqListErase(SeqListR *pSeq, int pos){
	assert(pSeq != NULL);     //�����ַ����Ϊ��
	assert(pSeq->size > 0);   //˳���Ϊ��
	assert(pos >= 0 && pos < pSeq->size);   //�����insert�����һ����û�� == size�����
	for (int i = pos; i <= pSeq->size - 2; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}


//����
int SeqListFind(const SeqListR *pSeq, DataType data){
	for (int i = 0; i < pSeq->size; i++){
		if (data == pSeq->array[i]){
			return i;
		}
	}
	return -1;
}

//����������ɾ��
//int SeqListRemove(SeqListR *pSeq, DataType data){
//	int pos = SeqListFind(pSeq, data);
//	if (pos = -1){
//		return -1;
//	}
//	else{
//		SeqListErase(pSeq, pos);
//		return 1;
//	}
//	
//}


//ɾ������
void SeqListRemoveAll(SeqListR *pSeq, DataType data){
	//0(n^2)
	//while (SeqListRemove(pSeq, data) != -1) {};

#if 0
	//0(n) �ռ临�Ӷ�0(1)
	//�½�һ����СΪpSeq->size �Ŀռ�
	DataType *extra = (DataType *)malloc(sizeof(DataType)* pSeq->size);

	int i = 0, j = 0;
	//�½����飬�Ѳ�����data������copy��extra
	for (; i < pSeq->size; i++){
		if (pSeq->array[i] != data){
			extra[j++] = pSeq->array[i];
		}
	}

	//j�պþ���ʣ�µ����ݸ���
	//��extra copy����
	for (int k = 0; k < j; k++){
		pSeq->array[k] = extra[k];
	}
	pSeq->size = j;
	free(extra);
}
	
#endif
	//0(n) �ռ临�Ӷ�0(1)
	int i = 0, j = 0;
	//�½����飬�Ѳ�����data������copy��extra
	for (; i < pSeq->size; i++){
		if (pSeq->array[i] != data){
			pSeq->array[j++] = pSeq->array[i];
		}
	}

	pSeq->size = j;
}


//�鿴����
bool SeqListEmpty(const SeqListR *pSeq){
	return pSeq->size == 0;
}

bool SeqListFull(const SeqListR *pSeq){
	return pSeq->size == MAX_SIZE;
}

int SeqListSize(const SeqListR *pSeq){
	return pSeq->size;
}


void Swap(DataType *a, DataType *b){
	DataType t = *a;
	*a = *b;
	*b = t;
}

//ð������
void BubbleSort(SeqListR * pSeq){
	int i, j;
	bool sorted = true;
	for (i = 0; i < pSeq->size - 1; i++){
		sorted = true;  //��������
		for (j = 0; j < pSeq->size - 1 - i; j++){
			if (pSeq->array[j] > pSeq->array[j + 1]){
				//û�ҵ������
			  //Swap(&pSeq->array[j])
				Swap(pSeq->array + j,pSeq->array + j + 1);
				sorted = false;
			}
		}

		//һ��ð�ݹ����У�һ�ν�����û�У������Ѿ�����
		if (sorted){
			break;
		}
	}
}


typedef unsigned int size_t;
//ѡ������
void SelectSortOP(SeqListR *Seq){
	size_t minSpace = 0;
	size_t maxSpace = Seq->size - 1;

	//������ֻʣһ���� ���� �����
	while (minSpace < maxSpace)
	{
		size_t minPos = minSpace; //�����һ��������С��
		size_t maxPos = minSpace; //�����һ����������
		for (size_t j = minSpace; j <= maxSpace; j++){
			if (Seq->array[j] < Seq->array[minPos]){
				minPos = j;
			}

			if (Seq->array[j] > Seq->array[maxPos])
				maxPos = j;
		}

		Swap(Seq->array + minSpace, Seq->array + minPos);
		//���������������ڵĵ�һ����ʱ��
		if (minSpace == maxPos){
			maxPos = minPos;
		}

		Swap(Seq->array + maxSpace, Seq->array + maxPos);

		minSpace++; maxSpace--;
	}
}

















