#include "SeqList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void Test(){
	//��ʼ��һ��SeqListR��������seqList��������������ֵ�������
	SeqListR seqList;
	SeqListInit(&seqList);
	//seqList��ֵ��Ҫ�����仯
	//��ʼ����˳�����һ���յ�˳���
	assert(seqList.size == 0);

	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 0);
	SeqListPushBack(&seqList, 9);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 8);
	SeqListPushBack(&seqList, 7);
	SeqListPushBack(&seqList, 3);

	//�����βεĴ�С

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
