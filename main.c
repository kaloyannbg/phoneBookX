#include "includes.h"

int main(int argc, char const *argv[])
{

    int isLogged = justLoggedLoop();
    int countOfConts = 0;
    if (!isLogged)
    {

        int iMenuGet = -5000;
        while (iMenuGet != 0)
        {
            iMenuGet = menuItemsLoop();
            if (iMenuGet == 1)
            {
                countOfConts = countOfRows("contacts.cvs");
                printf(" -- All Contacts -- \n\n");
                if(countOfConts > 0)
                {
                    sContacts *arrOfS = (sContacts *)calloc(countOfConts+1, sizeof(sContacts));
                    putContInStructs("contacts.cvs", arrOfS);
                    printStructs(arrOfS);
                    freeStructs(arrOfS);
                }
            }
            else if (iMenuGet == 2)
            {
                printf("f");
            }
        }
    }
    else
    {
        printf(" -- [[[[[[ BYE ]]]]]] ");
    }

    return 0;
}
