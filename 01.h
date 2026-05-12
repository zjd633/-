#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//静态顺序表
// #define N 100
// struct SeqList
// {
//     int arr[N];
//     int size;
// }; 


typedef int SLDataType;
typedef struct SeqList
{
    SLDataType* arr;
    int size;
    int capacity;
}SL;


void SLInit(SL* ps);


void SLDestroy(SL* ps);


void SLCheckCapacity(SL* ps);

void SLPrint(SL ps);


void SLPushBack(SL* ps,SLDataType x);

void SLPushFront(SL* ps,SLDataType x);


void SLPopBack(SL* ps);

void SLPopFront(SL* ps);


void SLInsert(SL* ps,int pos,SLDataType x);


void SLErase( SL* ps,int pos);

int SLFind(SL* ps,SLDataType x);





