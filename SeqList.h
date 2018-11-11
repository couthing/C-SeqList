#include <stdbool.h>;

//ADT 抽象的数据类型 Abstract Data Type
//如果没有typedef，SeqListzR只是一个变量
//顺序表可以存各种类型的数据，定义一个DataType类型的数据，只是现阶段DataType是一个int类型
//理解结构体的内存布局，为什么要定义指针，参数，理解接口是怎样定义的
typedef int DataType;
#define MAX_SIZE (100)
typedef struct SeqList{
	//100表示容量大小
	DataType   array[MAX_SIZE];
	//size表示数组有效个数的数量
	//下一个可用空间的下标
	int    size;
}SeqListR;

//初始化/销毁
//seqList的值是SeqListR的一个类型，取地址后变为一级指针
void SeqListInit(SeqListR *pSeq);
void SeqListDestory(SeqListR *pSeq);

//增删查改
//尾插
void SeqListPushBack(SeqListR *pSeq, DataType data);
//头插
void SeqListPushFront(SeqListR *pSeq, DataType data);
//中间插入
void SeqListInsert(SeqListR *pSeq, int pos, DataType data);

//删（根据下标做删除）
//头删
void SeqListPopBack(SeqListR *pSeq);

//尾删
void SeqListPopFront(SeqListR *pSeq);

//根据下标删除
void SeqListErase(SeqListR *pSeq, int pos);


//删 （根据数据做删除）
//删除第一个遇到的data，如果删除了，返回0，否则返回-1
int SeqListRemove(SeqListR *pSeq, DataType data);

//删 删除所有
void SeqListRemoveAll(SeqListR *pSeq, DataType data);

//改略

//查 （二分/顺序查找）顺序表是无序的
//找到第一个遇到的，如果找到了，就返回下标，如果没找到，就返回-1
int SeqListFind(const SeqListR *pSeq, DataType data);

//查看属性
bool SeqListEmpty(const SeqListR *pSeq);

bool SeqListFull(const SeqListR *pSeq);

int SeqListSize(const SeqListR *pSeq);


//打印
//const 不变   
void SeqListPrint(const SeqListR *pSeq);

//冒泡排序
void BubbleSort(SeqListR * pSeq);

//选择排序
void SelectSortOP(SeqListR *Seq);

