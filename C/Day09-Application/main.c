#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct familyBills {
    int bill;
    char recepient[15];
    char payer[15];
    float amount;
    int indicator;
    struct familyBills *prev, *next;
} DbBill;

typedef struct list {
    DbBill *first, *last;
} List;

void addNewBill(List *list)
{
    DbBill *newbill;
    if((newbill = ((DbBill*) malloc(sizeof(DbBill)))) == NULL) {
        printf("\nProblem with memory allocation!");
        return;
    }

    printf("\nPlease enter new bill number: ");
    scanf("%d", &newbill->bill);
    getchar();
    printf("\nPlease enter new recepient name: ");
    char rec[15];
    //scanf("%s%*c", &rec);
    gets(rec);
    strcpy(newbill->recepient, rec);
    printf("\nPlease enter new payer name: ");
    //scanf("%s", &newbill->payer);
    gets(&newbill->payer);

    printf("\nPlease enter amount to pay: ");
    scanf("%f", &newbill->amount);

    char* p;
    printf("\nPlease enter if bill is payed (y/n): ");
    p = getch();
    newbill->indicator = (p == 'y') ? 1 : 0;

    if(!list->first) {
        list->first = newbill;
        newbill->prev = NULL;
    } else {
        newbill->prev = list->last;
        list->last->next = newbill;
    }
    list->last = newbill;
    newbill->next = NULL;

    return;
}

void setTestData(List* list)
{
    printf("\nInto setTestData...\n");

    for(int i=0; i<5; i++)
    {
        DbBill *newbill;
        if((newbill = ((DbBill*) malloc(sizeof(DbBill)))) == NULL) {
            printf("\nProblem with memory allocation!");
            return -1;
        }

        newbill->bill = i+1;
//        strcpy(newbill->recepient, "Recepient ");
        sprintf(newbill->recepient, "Recepient %02d", i+1);
//        strcpy(newbill->payer, "Payer ");
        sprintf(newbill->payer, "Payer %02d", i+1);
        newbill->amount = 100.00 + i * 100;
        newbill->indicator = ((i+1)%2==0) ? 0 : 1;

        if(!list->first) {
            list->first = newbill;
            newbill->prev = NULL;
        } else {
            newbill->prev = list->last;
            list->last->next = newbill;
        }
        list->last = newbill;
        newbill->next = NULL;
    }
    return;
}

void writeOutAll(List *list, int rec, int npyd)
{
    DbBill *wobill;
    if((wobill = (DbBill*) malloc(sizeof(DbBill))) == NULL) {
        printf("\nMemory allocation for DbBill succeded!");
        exit(0);
    }

    if((wobill = list->first) == NULL){
        printf("\nNo entries found\n");
        return;
    }

    if (rec > 0){ //case 4
        rec = 0;
        char recN[15];
        printf("\nPlease enter name of recipient:\n");
        scanf("%s", &recN);
        printf("\nEntered to search %s.", recN);
        //    for(wobill;list->last;wobill->next)
        while(wobill)
        {
            if(strstr(wobill->recepient, recN)) {
                printf("\nFound %s in: \n", recN);
                printf("\nBill: %d.", wobill->bill);
                printf("\nRecepient name: %s", wobill->recepient);
                printf("\nPayer: %s", wobill->payer);
                printf("\nAmount: %.2f", wobill->amount);

                char* s = wobill->indicator ? "Yes" : "Nop";
                printf("\nBill is payed: %s\n", s);
                rec+=1;
            }
            wobill = wobill->next;
        }
        printf("\nFound %d results!", rec);
    } else if (npyd > 0) { //case 5
        npyd = 0;
        while(wobill)
        {
            if(!wobill->indicator) {
                printf("\nBill: %d.", wobill->bill);
                printf("\nRecepient name: %s", wobill->recepient);
                printf("\nPayer: %s", wobill->payer);
                printf("\nAmount: %.2f", wobill->amount);

                char* s = wobill->indicator ? "Yes" : "Nop";
                printf("\nBill is payed: %s\n", s);
                npyd+=1;
            }

            wobill = wobill->next;
        }
        printf("\nFound %d results!", npyd);
    } else { //case 6
        printf("\nBills from db are:\n");
        //    for(wobill;list->last;wobill->next)
        while(wobill)
        {
            printf("\nBill: %d.", wobill->bill);
            printf("\nRecepient name: %s", wobill->recepient);
            printf("\nPayer: %s", wobill->payer);
            printf("\nAmount: %.2f", wobill->amount);

            char* s = wobill->indicator ? "Yes" : "Nop";
            printf("\nBill is payed: %s\n", s);

            wobill = wobill->next;
        }
    }


    return;
}

void payExistingBill(List *list)
{
    DbBill *existBill;
    if((existBill = (DbBill*) malloc(sizeof(DbBill))) == NULL) {
        printf("\nMemory allocation for DbBill failed!\n");
        exit(0);
    }

    int billToPay, count = 0;
    printf("\nPlease enter bill number to pay: ");
    scanf("%d", &billToPay);

    existBill = list->first;
    while(existBill)
    {
        if(existBill->bill == billToPay){
            printf("\nFound bill number %d to be payed.", existBill->bill);
            printf("\nRecepient name: %s, ", existBill->recepient);
            printf("Payer: %s, ", existBill->payer);
            printf("nAmount: %.2f, ", existBill->amount);

            existBill->indicator = 1;
            char* s = existBill->indicator ? "Yes" : "Nop";
            printf("\nBill is payed: %s!\n", s);
            break;
        }
        existBill = existBill->next;
    }
}

void delAllData(List *list, int num)
{
    DbBill *delBill, *oldBill;
    if((delBill = (DbBill*) malloc(sizeof(DbBill))) == NULL) {
        printf("\nAllocation problem for DbBill!\n");
        exit(0);
    }

    delBill = list->first;
    if(num > 0){
        int exactBill;
        printf("\nWhich bill to delete?");
        scanf("%d", &exactBill);
        while(delBill)
        {
            if(delBill->bill == exactBill){
                printf("\nPronasao bill - %s - %d.", delBill->recepient, delBill->bill);

                oldBill = delBill;
                if(delBill->prev){
                    delBill->prev->next = delBill->next ? delBill->next : NULL;
                } else {
                    list->first = delBill->next ? delBill->next : NULL;
                }
                if(delBill->next){
                    delBill->next->prev = delBill->prev ? delBill->prev : NULL;
                } else {
                    list->last = delBill->prev ? delBill->prev : NULL;
                }
                free(oldBill);
//                break;
            }
            delBill = delBill->next;
        }
    } else {
        while(delBill)
        {
            printf("\nDelete from database: %d. - %s.", delBill->bill, delBill->payer);
            oldBill = delBill;
            delBill = delBill->next;
            free(oldBill);
        }
        list->first = list->last = NULL;
    }
    return;
}

int main()
{
    printf("/*Familly Bills DB*/");

    List *familyList;
    if((familyList = (List*) malloc(sizeof(List))) == NULL) {
        printf("\nAllocation for list succeded!\n");
        exit(0);
    }
    familyList->first = familyList->last = NULL;

    char setDbData = 'n';
    printf("\n\nDo you want to set test data? (y/n) > ");
    setDbData = getch();

    if(setDbData == 'y') {
        printf("Unet je %c", setDbData);

        setTestData(familyList);
    } else {
        printf("Unet je %c", setDbData);
    }

    int again = 0;
    do {
        printf("\n\nPlease enter your choice:");
        printf("\n1. Dodavanje novog računa.");
        printf("\n2. Plaćanje postojećeg računa.");
        printf("\n3. Brisanje računa sa određenim brojem.");
        printf("\n4. Prikaz podataka računa sa unetim nazivom primaoca.");
        printf("\n5. Prikaz svih računa koji nisu plaćeni.");
        printf("\n6. Prikaz svih računa u bazi.");
        printf("\n7. Brisanje svih računa u bazi.");
        printf("\n8. Izlaz iz programa.\n");

        scanf("%d", &again);

        switch(again)
        {
        case 1:
            {
                addNewBill(familyList);
                break;
            }
        case 2:
            {
                payExistingBill(familyList);
                break;
            }
        case 3:
            {
                delAllData(familyList, 1);
                break;
            }
        case 4:
            {
                writeOutAll(familyList, 1, 0);
                break;
            }
        case 5:
            {
                writeOutAll(familyList, 0, 1);
                break;
            }
        case 6:
            {
                writeOutAll(familyList, 0, 0);
                break;
            }
        case 7:
            {
                delAllData(familyList, 0);
                break;
            }
        default:
            {
                delAllData(familyList, 0);
                free(familyList);
                again = 8;
            }
        }

    } while(again != 8);



    printf("\n\nBye :)\n");
    return 0;
}
