#include "SLTNode.h"

void SLTNodePrint(SLTNode* phead)
{
    SLTNode* pcur=phead;
    while(pcur)
    {
        printf("%d->",pcur->data);
        pcur=pcur->next;
    }
    printf("NULL\n");
}



SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode=(SLTNode*)malloc(sizeof(SLTNode));
    if(newnode==NULL)
    {
        perror("malloc");
        exit(-1);
    }
	newnode->next=NULL;
	newnode->data=x;
	return newnode;
}



void SLTNodePushBack(SLTNode** pphead,SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode=BuySListNode(x);
	if(*pphead==NULL)
	{
		*pphead=newnode;
	}
	else
	{
		SLTNode* ptail=*pphead;
		while(ptail->next)
		{
			ptail=ptail->next;
		}
		ptail->next=newnode;
	}
	
}




void SLTNodePushFront(SLTNode** pphead,SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode=BuySListNode(x);
	newnode->next=*pphead;
	*pphead=newnode;
}



void SLTNodePopBack(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	if((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead=NULL;
	}
	else
	{
		SLTNode* prev=*pphead;
		SLTNode* ptail=*pphead;
		while(ptail->next)
		{
			prev=ptail;
			ptail=ptail->next;
		}
		prev->next=NULL;
		free(ptail);
		ptail=NULL;
	}
}
	
	
void SLTNodePopFront(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	SLTNode* next=(*pphead)->next;
	free(*pphead);
	*pphead=next;

}


SLTNode* SLTNodeFind(SLTNode* phead,SLTDataType x)
{
	SLTNode* pcur=phead;
	while(pcur)
	{
		if(pcur->data==x)
		{
			return pcur;
		}
		pcur=pcur->next;
	}
	return NULL;
}


void SLTNodeInsert(SLTNode** pphead,SLTNode* pos,SLTDataType x)
{
	assert(pphead&&*pphead);
	assert(pos);
	if(*pphead==pos)
	{
		SLTNodePushFront(pphead,x);
	}
	else
	{
		SLTNode* newnode=BuySListNode(x);
		SLTNode* prev=*pphead;
		while(prev->next!=pos)
		{
			prev=prev->next;
		}
		newnode->next=pos;
		prev->next=newnode;
	}
}



void SLTNodeInsertAfter(SLTNode* pos,SLTDataType x)
{
	assert(pos);
	SLTNode* newnode=BuySListNode(x);
	newnode->next=pos->next;
	pos->next=newnode;
}




void SLTNodeErase(SLTNode** pphead,SLTNode* pos)
{
	assert(pphead&&*pphead);
	assert(pos);
	if(*pphead==pos)
	{
		SLTNodePopFront(pphead);
	}
	else
	{
		SLTNode* prev=*pphead;
		while(prev->next!=pos)
		{
			prev=prev->next;
		}
		SLTNode* del=pos->next;
		prev->next=del;
		free(pos);
		pos=NULL;
	}
}




void SLTNodeEraseAfter(SLTNode* pos)
{
	assert(pos&&pos->next);
	SLTNode* next=pos->next;
	pos->next=next->next;
	free(next);
	next=NULL;
}



void SLTNodeDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur=*pphead;
	while(pcur)
	{
		SLTNode* next=pcur->next;
		free(pcur);
		pcur=next;
	}
	*pphead=NULL;
}