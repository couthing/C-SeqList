#include <stdbool.h>;

//ADT ������������� Abstract Data Type
//���û��typedef��SeqListzRֻ��һ������
//˳�����Դ�������͵����ݣ�����һ��DataType���͵����ݣ�ֻ���ֽ׶�DataType��һ��int����
//���ṹ����ڴ沼�֣�ΪʲôҪ����ָ�룬���������ӿ������������
typedef int DataType;
#define MAX_SIZE (100)
typedef struct SeqList{
	//100��ʾ������С
	DataType   array[MAX_SIZE];
	//size��ʾ������Ч����������
	//��һ�����ÿռ���±�
	int    size;
}SeqListR;

//��ʼ��/����
//seqList��ֵ��SeqListR��һ�����ͣ�ȡ��ַ���Ϊһ��ָ��
void SeqListInit(SeqListR *pSeq);
void SeqListDestory(SeqListR *pSeq);

//��ɾ���
//β��
void SeqListPushBack(SeqListR *pSeq, DataType data);
//ͷ��
void SeqListPushFront(SeqListR *pSeq, DataType data);
//�м����
void SeqListInsert(SeqListR *pSeq, int pos, DataType data);

//ɾ�������±���ɾ����
//ͷɾ
void SeqListPopBack(SeqListR *pSeq);

//βɾ
void SeqListPopFront(SeqListR *pSeq);

//�����±�ɾ��
void SeqListErase(SeqListR *pSeq, int pos);


//ɾ ������������ɾ����
//ɾ����һ��������data�����ɾ���ˣ�����0�����򷵻�-1
int SeqListRemove(SeqListR *pSeq, DataType data);

//ɾ ɾ������
void SeqListRemoveAll(SeqListR *pSeq, DataType data);

//����

//�� ������/˳����ң�˳����������
//�ҵ���һ�������ģ�����ҵ��ˣ��ͷ����±꣬���û�ҵ����ͷ���-1
int SeqListFind(const SeqListR *pSeq, DataType data);

//�鿴����
bool SeqListEmpty(const SeqListR *pSeq);

bool SeqListFull(const SeqListR *pSeq);

int SeqListSize(const SeqListR *pSeq);


//��ӡ
//const ����   
void SeqListPrint(const SeqListR *pSeq);

//ð������
void BubbleSort(SeqListR * pSeq);

//ѡ������
void SelectSortOP(SeqListR *Seq);

