#include <stdlib.h>
#include <stdlib.h>
#include <string.h>


#include "phonebook_opt.h"


entry *findName(char lastName[], entry *pHead)
{

    //hash version
    int hashNumber=hash(lastName);
    entry *find;
    find=hashTable[hashNumber].pNext;

    while (find != NULL) 
    {
        if (strcasecmp(lastName, find->lastName) == 0) 
        {
            return find;
        }
        find = find->pNext;
    }
    //reduce entry version
    /*
    while (pHead != NULL) 
    {
        if (strcasecmp(lastName, pHead->lastName) == 0)
        {
            printf(" %12s  is found!\n", lastName);
            return pHead;
        }
        pHead = pHead->pNext;
    }
    */



    printf(" %12s  is found!\n", lastName);
    return NULL;
}

entry *append(char lastName[], entry *lne)
{
    /* allocate memory for the new entry and put lastName in it.*/
    // hash version
    int hashNumber = hash(lastName);
    tmp = (entry*) malloc(sizeof(entry));

    if (hashTable[hashNumber].pNext == NULL) //empty
    {   
        hashTable[hashNumber].pNext=tmp;
    } else 
    {
        tmp->pNext = hashTable[hashNumber].pNext;
        hashTable[hashNumber].pNext=tmp;
    }
    
    strcpy(tmp->lastName, lastName);

    //reduce entry version
    /*
    lne->pNext = (entry *) malloc(sizeof(entry));
    lne = lne->pNext;
    strcpy(lne->lastName, lastName);
    lne->pNext = NULL;
    */
    return lne;
}



int hash (char lastName[])
{
    int seed = 26;
    long long hashNum = 0;
    
    while (*lastName)
        hashNum = hashNum*seed+(*lastName++);

    return hashNum%8192;
}
