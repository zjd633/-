#include "SLTNode.h"

void SListTest01()
{
    struct SListNode* plist = NULL;

    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushFront(&plist, 0);
    SListPrint(plist);

    assert(SListFind(plist, 2) != NULL);
    assert(SListFind(plist, 9) == NULL);

    SListPopFront(&plist);
    SListPopBack(&plist);
    SListPrint(plist);

    SListDestroy(&plist);
    assert(plist == NULL);
}

int main()
{
    SListTest01();
    return 0;
}