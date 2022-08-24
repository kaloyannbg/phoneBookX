#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>

struct sContacts {
    char *name;
    char *tel;
};

typedef struct sContacts sContacts;

char *getString();

int justLoggedLoop();

int menuItemsLoop();

void printContacts(char *txtFile);

int countOfRows(char *txtFile);

void putContInStructs(char *txtFile, sContacts *arrOfStr);

void printStructs(sContacts *arrOfStructs);

void freeStructs(sContacts *arrOfStructs);

#endif