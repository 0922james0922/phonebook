#include <stdlib.h>
#include <stdlib.h>
#include <string.h>


#include "phonebook_opt.h"


entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) 
    {
        if (strcasecmp(lastName, pHead->lastName) == 0)
        {
            printf(" %12s  is found!\n", lastName);
            return pHead;
        }
        pHead = pHead->pNext;
    }
    printf(" %12s  is found!\n", lastName);
    return NULL;
}

entry *append(char lastName[], entry *lne)
{
    /* allocate memory for the new entry and put lastName in it.*/
    lne->pNext = (entry *) malloc(sizeof(entry));
    lne = lne->pNext;
    strcpy(lne->lastName, lastName);
    lne->pNext = NULL;

    return lne;
}


