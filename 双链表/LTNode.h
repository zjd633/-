#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType; 
typedef struct LTNode
{
    LTDataType data;
    struct LTNode* next;
    struct LTNode* prev;
} LTNode;



LTNode* BuyNode(LTDataType x);



void LTNodeInit(LTNode** phead);



void LTNodePrint(LTNode* phead);



void LTNodePushBack(LTNode* phead,LTDataType x);


void LTNodePushFront(LTNode* phead,LTDataType x);




void LTNodePopBack(LTNode* phead);


void LTNodePopFront(LTNode* phead);




LTNode* LTNodeFind(LTNode* phead,LTDataType x);






void LTNodeInsert(LTNode* pos,LTDataType x);


void LTNodeErase(LTNode* pos);






void LTNodeDestroy(LTNode* phead);