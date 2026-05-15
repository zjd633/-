#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
}SLTNode;



void SLTNodePrint(SLTNode* phead);

SLTNode* BuySListNode(SLTDataType x);




void SLTNodePushBack(SLTNode** pphead,SLTDataType x);

void SLTNodePushFront(SLTNode** pphead,SLTDataType  x);




void SLTNodePopBack(SLTNode** pphead);

void SLTNodePopFront(SLTNode** pphead);





SLTNode* SLTNodeFind(SLTNode* phead, SLTDataType x);



void SLTNodeInsert(SLTNode** pphead,SLTNode* pos,SLTDataType x);

void SLTNodeInsertAfter(SLTNode* pos,SLTDataType x);    



void SLTNodeErase(SLTNode** pphead,SLTNode* pos);

void SLTNodeEraseAfter(SLTNode* pos);




void SLTNodeDestroy(SLTNode** pphead);