#include "SeqList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void Test(){
	//开始有一个SeqListR（别名）seqList（变量）变量的值是随机的
	SeqListR seqList;
	SeqListInit(&seqList);
	//seqList的值需要发生变化
	//初始化的顺序表是一个空的顺序表
	assert(seqList.size == 0);

	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 0);
	SeqListPushBack(&seqList, 9);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 8);
	SeqListPushBack(&seqList, 7);
	SeqListPushBack(&seqList, 3);

	//减少形参的大小

	SeqListPrint(&seqList);
	printf("\n");
	BubbleSort(&seqList);
	SeqListPrint(&seqList);
	printf("\n");
	SelectSortOP(&seqList);
	SeqListPrint(&seqList);
	printf("\n");
	
}

int main()
{
	Test();
	system("pause");
	return 0;
}
