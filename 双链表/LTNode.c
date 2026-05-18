#include "01.h"



LTNode* BuyNode(LTDataType x)
{
	LTNode* newnode=(LTNode*)malloc(sizeof(LTNode));
	if(newnode==NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->prev=newnode;
	newnode->next=newnode;
	newnode->data=x;
	return newnode;
}




void LTNodeInit(LTNode** phead)
{
	*phead=BuyNode(-1);
}




void LTNodePrint(LTNode* phead)
{
	LTNode* pcur=phead->next;
	while(pcur!=phead)
	{
		printf("%d->",pcur->data);
		pcur=pcur->next;
	}
	printf("NULL\n");
}




void LTNodePushBack(LTNode* phead,LTDataType x)
{
	assert(phead);
	LTNode* newnode=BuyNode(x);
	newnode->prev=phead->prev;
	newnode->next=phead;
	phead->prev->next=newnode;
	phead->prev=newnode;
}





void LTNodePushFront(LTNode* phead,LTDataType x)
{
	assert(phead);
	LTNode* newnode=BuyNode(x);
	newnode->prev=phead;
	newnode->next=phead->next;
	phead->next->prev=newnode;
	phead->next=newnode;
}




void LTNodePopBack(LTNode* phead)
{
	assert(phead&&phead->next!=phead);
	LTNode* del=phead->prev;
	del->prev->next=phead;
	phead->prev=del->prev;
	free(del);
	del=NULL;
}






void LTNodePopFront(LTNode* phead)
{
	assert(phead&&phead->next!=phead);
	LTNode* del=phead->next;
    phead->next=del->next;
	del->next->prev=phead;
	free(del);
	del=NULL;
}





LTNode* LTNodeFind(LTNode* phead,LTDataType x)
{
	assert(phead&&phead->next!=phead);
	LTNode* pcur=phead->next;
	while(pcur!=phead)
	{
		if(pcur->data==x)
		{
			return pcur;
		}
		pcur=pcur->next;
	}
	return NULL;
}




void LTNodeInsert(LTNode* pos,LTDataType x)
{
	assert(pos);
	LTNode* newnode=BuyNode(x);
	newnode->prev=pos;
	newnode->next=pos->next;
	pos->next->prev=newnode;
	pos->next=newnode;
}



void LTNodeErase(LTNode* pos)
{
	assert(pos);
	pos->prev->next=pos->next;
	pos->next->prev=pos->prev;
	free(pos);
	pos=NULL;
}




void LTNodeDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* pcur=phead->next;
   
	while(pcur!=phead)
	{ 
        LTNode* next=pcur->next;
		free(pcur);
		pcur=next;
	}
	free(phead);
	phead=NULL;
}