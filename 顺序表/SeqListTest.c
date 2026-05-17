#include "01.h"


void SLtest01()
{
    SL s1;
    SLInit(&s1);
    SLPushFront(&s1,1);
    SLPushBack(&s1,2);
    SLInsert(&s1,2,3);
    SLInsert(&s1,3,4);
    SLInsert(&s1,4,5);
    SLPrint(s1);

    SLErase(&s1,0);
    SLPrint(s1);

    SLPopBack(&s1);
    SLPrint(s1);

    SLPopFront(&s1);
    SLPrint(s1);

    printf("%d\n", SLFind(&s1,3));
    SLDestroy(&s1);
}


int main()
{
    SLtest01();
    return 0;
}