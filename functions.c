#include "includes.h"

char *getString()
{
    char buffer[512] = {0};
    fgets(buffer, 512, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    char *cpyBuffer = (char *)calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(cpyBuffer, buffer);
    return cpyBuffer;
}

int justLoggedLoop()
{
    printf(" -- Type pass! [type 0 for quit!] : ");
    char *str = getString();

    while (strcmp(str, "pass") != 0)
    {
        if (strcmp(str, "0") == 0)
        {
            free(str);
            return 1;
        }
        printf(" -- Type pass again! [type 0 for quit!] :");
        str = getString();
    }

    free(str);

    return 0;
}

void printMenu()
{
    printf("\n\n");
    printf(" 1. All contacts -- \n");
    printf(" 2. Add new contact -- \n");
}

int menuItemsLoop()
{
    char *str = NULL;

    while (1)
    {
        printMenu();
        printf(" -- Please enter menu option : ");
        str = getString();
        if (strcmp(str, "1") == 0)
        {
            free(str);
            return 1;
        }
        else if (strcmp(str, "2") == 0)
        {
            free(str);
            return 2;
        }
        else if (strcmp(str, "0") == 0)
        {
            free(str);
            return 0; // exit
        }
    }
}

void putContInStructs(char *txtFile, sContacts *arrOfStr)
{

    FILE *fp = fopen(txtFile, "r");
    if (!fp)
    {
        printf(" -- File is not exist! -- \n");
    }
    else
    {
        char buffer[512] = {0};
        char miniBuffer[512] = {0};
        char *fg = fgets(buffer, 512, fp);
        int cntOfRows = 0;
        int cntOfCols = 0;
        int cnt = 0;
        while (fg != NULL)
        {
            int stLen = strlen(buffer);
            for (int i = 0; i <= stLen; i++)
            {
                miniBuffer[cnt++] = buffer[i];
                if (buffer[i] == ',' || buffer[i] == '\n' || (i == stLen))
                {
                    miniBuffer[cnt - 1] = '\0';
                    switch (cntOfCols)
                    {
                    case 0:
                        arrOfStr[cntOfRows].name = (char *)calloc(strlen(miniBuffer) + 1, sizeof(char));
                        strcpy(arrOfStr[cntOfRows].name, miniBuffer);
                        break;
                    case 1:
                        arrOfStr[cntOfRows].tel = (char *)calloc(strlen(miniBuffer) + 1, sizeof(char));
                        strcpy(arrOfStr[cntOfRows].tel, miniBuffer);
                        break;
                    default:
                        break;
                    }
                    cntOfCols++;
                    memset(miniBuffer, 0, strlen(miniBuffer));
                    cnt = 0;
                }
            }

            cntOfCols = 0;
            cntOfRows++;
            memset(buffer, 0, strlen(buffer));
            fg = fgets(buffer, 512, fp);
        }
        arrOfStr[cntOfRows].name = NULL;
    }
}

int countOfRows(char *txtFile)
{
    FILE *fp = fopen(txtFile, "r");
    if (!fp)
    {
        return 0;
    }
    else
    {
        char buffer[512] = {0};
        char *fg = fgets(buffer, 512, fp);
        if (fg == NULL)
        {
            return 0;
        }
        int countRows = 0;
        while (fg != NULL)
        {
            ++countRows;
            memset(buffer, 0, strlen(buffer));
            fg = fgets(buffer, 512, fp);
        }
        return countRows;
    }
}

void printStructs(sContacts *arrOfStructs)
{
    for (int i = 0; arrOfStructs[i].name != NULL; i++)
    {
        printf(" \n Name : %s | Telephone : %s | \n ", arrOfStructs[i].name, arrOfStructs[i].tel);
    }
}

void freeStructs(sContacts *arrOfStructs)
{
    for (int i = 0; arrOfStructs[i].name != NULL; i++)
    {
        free(arrOfStructs[i].name); 
        free(arrOfStructs[i].tel);
    }

    free(arrOfStructs);
}
