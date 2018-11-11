#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>;

void  SeqListInit(SeqListR *pSeq)
{
	//pSeq是一个变量的地址，不可能为0（相当于函数在定义域上不包含0）
	assert(pSeq != NULL);

	pSeq->size = 0;

	//if (pSeq = NULL){
	//	//对pSeq进行判断(相当于函数在定义域上包括0，但要对它进行特殊的判断)
	//}
}

void  SeqListDestory(SeqListR *pSeq)
{
	assert(pSeq != NULL);

	pSeq->size = 0;
}

//尾插
void SeqListPushBack(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE){
		printf("满了\n");
		return;
	}

	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
}

//头插
//一个一个元素移（处于练习）/memmove
//1. 方向：从后往前移
//2. 循环（程序中每个变量的含义）
//       1.数据的下标 
//       2.空间的下标
void SeqListPushFront(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE){
		printf("满了\n");
		return;
	}

	//移数据
#if i//i的含义是数据下标
	//[size-1,0] [i]移到[i+1]
	for (int i = pSeq->size - 1; i >= 0; i--){
		pSeq->array[i + 1] = pSeq->array[i];
	}
#else j//j的含义是空间下标
	//[size,0) [i-1]移到[i]
	for (int j = pSeq->size; j > 0; j--){
		pSeq->array[j] = pSeq->array[j - 1];
	}
#endif
	pSeq->array[0] = data;
	pSeq->size++;
}


//中间插入
//条件编译
void SeqListInsert(SeqListR *pSeq, int pos, DataType data){
	assert(pSeq->size<MAX_SIZE);
	assert(pos>=0&&pos<=pSeq->size);
	//前面的不动，中间加入一个，后面的元素往后移一个
    //j的含义是空间下标
	//[size,pos) [i-1]移到[i] 从后往前
	for (int j = pSeq->size; j > pos; j--){
		pSeq->array[j] = pSeq->array[j - 1];
	}

	pSeq->array[pos] = data;
	//不要忘
	pSeq->size += 1;

}

//打印
void SeqListPrint(const SeqListR *pSeq)
{
	for (int i = 0; i < pSeq->size; i++){
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}


//尾删
void SeqListPopBack(SeqListR *pSeq){
	assert(pSeq != NULL);     //传入地址不能为空
	assert(pSeq->size > 0);   //顺序表不为空

	pSeq->size--;
}


//头删
void SeqListPopFront(SeqListR *pSeq){
	assert(pSeq != NULL);     //传入地址不能为空
	assert(pSeq->size > 0);   //顺序表不为空

	//数据搬移
	//1. 数据下标 [1 ,size - 1] or [1, size)
	//2. 空见下标 [0, size - 2] or [1, size - 1)
	//i含义是空间的下标
	for (int i = 0; i <= pSeq->size - 2; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

//根据下标删除
void SeqListErase(SeqListR *pSeq, int pos){
	assert(pSeq != NULL);     //传入地址不能为空
	assert(pSeq->size > 0);   //顺序表不为空
	assert(pos >= 0 && pos < pSeq->size);   //这里和insert情况不一样，没有 == size的情况
	for (int i = pos; i <= pSeq->size - 2; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}


//查找
int SeqListFind(const SeqListR *pSeq, DataType data){
	for (int i = 0; i < pSeq->size; i++){
		if (data == pSeq->array[i]){
			return i;
		}
	}
	return -1;
}

//根据数据做删除
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


//删除所有
void SeqListRemoveAll(SeqListR *pSeq, DataType data){
	//0(n^2)
	//while (SeqListRemove(pSeq, data) != -1) {};

#if 0
	//0(n) 空间复杂度0(1)
	//新建一个大小为pSeq->size 的空间
	DataType *extra = (DataType *)malloc(sizeof(DataType)* pSeq->size);

	int i = 0, j = 0;
	//新建数组，把不等于data的数据copy到extra
	for (; i < pSeq->size; i++){
		if (pSeq->array[i] != data){
			extra[j++] = pSeq->array[i];
		}
	}

	//j刚好就是剩下的数据个数
	//从extra copy回来
	for (int k = 0; k < j; k++){
		pSeq->array[k] = extra[k];
	}
	pSeq->size = j;
	free(extra);
}
	
#endif
	//0(n) 空间复杂度0(1)
	int i = 0, j = 0;
	//新建数组，把不等于data的数据copy到extra
	for (; i < pSeq->size; i++){
		if (pSeq->array[i] != data){
			pSeq->array[j++] = pSeq->array[i];
		}
	}

	pSeq->size = j;
}


//查看属性
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

//冒泡排序
void BubbleSort(SeqListR * pSeq){
	int i, j;
	bool sorted = true;
	for (i = 0; i < pSeq->size - 1; i++){
		sorted = true;  //假设有序
		for (j = 0; j < pSeq->size - 1 - i; j++){
			if (pSeq->array[j] > pSeq->array[j + 1]){
				//没找到更大的
			  //Swap(&pSeq->array[j])
				Swap(pSeq->array + j,pSeq->array + j + 1);
				sorted = false;
			}
		}

		//一次冒泡过程中，一次交换都没有，所以已经有序
		if (sorted){
			break;
		}
	}
}


typedef unsigned int size_t;
//选择排序
void SelectSortOP(SeqListR *Seq){
	size_t minSpace = 0;
	size_t maxSpace = Seq->size - 1;

	//区间内只剩一个数 或者 零个数
	while (minSpace < maxSpace)
	{
		size_t minPos = minSpace; //假设第一个就是最小的
		size_t maxPos = minSpace; //假设第一个就是最大的
		for (size_t j = minSpace; j <= maxSpace; j++){
			if (Seq->array[j] < Seq->array[minPos]){
				minPos = j;
			}

			if (Seq->array[j] > Seq->array[maxPos])
				maxPos = j;
		}

		Swap(Seq->array + minSpace, Seq->array + minPos);
		//最大的数就是区间内的第一个的时候
		if (minSpace == maxPos){
			maxPos = minPos;
		}

		Swap(Seq->array + maxSpace, Seq->array + maxPos);

		minSpace++; maxSpace--;
	}
}

















