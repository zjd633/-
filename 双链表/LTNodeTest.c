#include "01.h"

void LTTest01()
{
    LTNode* plist = NULL;
    LTNodeInit(&plist);

    LTNodePushBack(plist, 1);
    LTNodePushBack(plist, 2);
    LTNodePushBack(plist, 3);
    LTNodePushFront(plist, 0);
    LTNodePrint(plist);

    assert(LTNodeFind(plist, 2) != NULL);
    assert(LTNodeFind(plist, 9) == NULL);

    LTNodePopFront(plist);
    LTNodePrint(plist);

    LTNodePopBack(plist);
    LTNodePrint(plist);

    LTNodeDestroy(plist);
}

int main()
{
    LTTest01();
    return 0;
}
