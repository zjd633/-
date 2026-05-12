#include "01.h"


void SLInit(SL* ps)
{
    ps->arr=NULL;
    ps->capacity=ps->size=0;
}



void SLDestroy(SL* ps)
{
    if(ps->arr)
    {
        free(ps->arr);
    }
    ps->arr=NULL;
    ps->capacity=ps->size=0;
}


void SLCheckCapacity(SL* ps)
{
    if(ps->size==ps->capacity)
    {
        int Newcapacity=ps->capacity==0?4:2*ps->capacity;
        SLDataType* tmp=(SLDataType*)realloc(ps->arr,Newcapacity*sizeof(SLDataType));
        if(tmp==NULL)
        {
            perror("realloc");
            exit(-1);
        }
        ps->arr=tmp;
        ps->capacity=Newcapacity;

    }
}

void SLPushBack(SL* ps,SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++]=x;
}


void SLPushFront(SL* ps,SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for(int i=ps->size;i>0 ;i--)
	{
		ps->arr[i]=ps->arr[i-1];
	}
	ps->arr[0]=x;
	ps->size++;
}


void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}


void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for(int i=0;i<ps->size-1;i++)
	{
		ps->arr[i]=ps->arr[i+1];
	}
	ps->size--;
}






void SLInsert(SL* ps,int pos,SLDataType x)
{
	assert(ps);
	assert(pos>=0&&pos<=ps->size);
    SLCheckCapacity(ps);
	for(int i=ps->size;i>pos;i--)
	{
		ps->arr[i]=ps->arr[i-1];
	}
	ps->arr[pos]=x;
	ps->size++;
}


void SLErase(SL* ps,int pos)
{
	assert(ps);
	assert(pos>=0&&pos<ps->size);
	for(int i=pos;i<ps->size-1;i++)
	{
		ps->arr[i]=ps->arr[i+1];
	}
	ps->size--;
}





void SLPrint(SL ps)
{
	for(int i=0;i<ps.size;i++)
	{
		printf("%d ",ps.arr[i]);
	}
	printf("\n");
}



int SLFind(SL* ps,SLDataType x)
{
    assert(ps);
    for(int i=0;i<ps->size;i++)
	if(ps->arr[i]==x)
	{
		return i;
	}
	return -1;
}