#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stff {
    char name[15];
    char jmbg[13];
    float slry;
    struct stff *next, *prev;
} Staff;

typedef struct {
    Staff *first, *last;
} List;

int sizeOfList(List *lst)
{
    Staff *running;
    int n=0;
    for(running = lst->first; running; running = running->next)
        n++;

    return n;
}

void remAllList(List *delist)
{
    Staff *runstf = delist->first, *old;

    while(runstf)
    {
        printf("\nEntered while runstaff, deleting: %s\n", runstf->name);
        old = runstf;
        runstf = runstf->next;
        free(old);
    }

    if(delist) {
        printf("\nDeleting list!\n");
        free(delist);
    }
}

void writeOutList(List lst)
{
    int numOfStaff = sizeOfList(&lst);
    printf("\nNum of staffs is: %d", numOfStaff);

    if(lst.first == NULL) {
        printf("\nNo entries!\n");
        return;
    }

    Staff *stf;
    stf=lst.first;

    while(stf)
    {
        printf("\n\nList of employees:\n");
        printf("\nJMBG of employed: %13s", stf->jmbg);
        printf("\nName of employed: %s", stf->name);
        printf("\nSalary of employed: %.2f", stf->slry);

        printf("\n\nPrev stf name: %s", stf->prev->name);
        printf("\nNExt stf name: %s", stf->next->name);

        stf=stf->next;
    }
}

void addNewStaff(List *flst)
{
    Staff *news =(Staff*) malloc(sizeof(Staff));
    int jmbglng = 0;

    char jmbg[13], name[15];
    float salary = 0.0;

    do {
        printf("\n\nJMBG of employed: ");
        scanf("%s", &jmbg);
        jmbglng = strlen(jmbg);
    } while((jmbglng > 13) || (jmbglng <= 0));
    printf("\nName of employed: ");
    scanf("%s", &name);
    printf("\nSalary of employed: ");
    scanf("%f", &salary);

    strcpy(news->name, name);
    strcpy(news->jmbg, jmbg);
    news->slry = salary;

    if(!flst->first) {
        flst->first = news;
        news->next = news->prev = NULL;
    } else {
        flst->last->next = news;
        news->prev = flst->last;
        news->next = NULL;
    }
    flst->last = news;
}

void modifyList(List *flst)
{
    int chrnum, jmbglng = 0;
    char jmbg[13], name[15];
    float salary = 0.0;
    do {
        printf("\nPlease enter jmbg to find and edit:");
        scanf("%s", &jmbg);
        jmbglng = strlen(jmbg);
    } while((jmbglng > 13) || (jmbglng <= 0));

    printf("\nUnet je string za pretragu: %s", jmbg);

    /*
        Find Staff by entered jmbg
    */
    Staff *mdfystf;
    for(mdfystf=flst->first;mdfystf;mdfystf=mdfystf->next)
    {
        if(strstr(mdfystf->jmbg, jmbg)) {
            printf("\nFound Staff, name %s, jmbg: %s\n", mdfystf->name, mdfystf->jmbg);
            break;
        }
    }

    do {
        printf("\nPlease enter new jbg for employed: ");
        scanf("%s", &jmbg);
        jmbglng = strlen(jmbg);
    } while((jmbglng > 13) || (jmbglng <= 0));
    printf("\nPlease enter new Name for employed: ");
    scanf("%s", &name);
    printf("\nPlease enter new Salary for employed: ");
    scanf("%f", &salary);

    strcpy(mdfystf->name, name);
    strcpy(mdfystf->jmbg, jmbg);
    mdfystf->slry = salary;

    return;
}

int main()
{
    printf("\/*BAZA ZAPOSLENIH\*/");
    List *flst;
    int funcs = 0;
    if((flst = (List*) malloc(sizeof(List))) == NULL) {
        fprintf(stderr, "\nNije uspelo zauzimanje memorije za listu!");
    }
    flst->first = flst->last = NULL;

    do {
        printf("\n1. PRIKAZ\n2. DODAJ\n3. MODIFIKUJ\n4. IZLAZ\n");
        printf("\nPlease make your choice=");
        scanf("%d", &funcs);

        switch (funcs)
        {
        case 1:
            {
                writeOutList(*flst);
                printf("\nList writeout is finished..\n");
                break;
            }
        case 2:
            {
                addNewStaff(flst);
                printf("\nStaff is added..\n");

                break;
            }
        case 3:
            {
                modifyList(flst);
                printf("\nList is modified.. \n");
                break;
            }
        case 4:
        default:
            {
                remAllList(flst);
                printf("\nList is deleted! Bye..\n");
                break;
            }
        }

    } while (funcs > 0 && funcs < 4);

    return 0;
}
