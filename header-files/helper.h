//
// Created by johan on 3/31/16.
//
#include <stdio.h>

#ifndef BILLSCHECKER_HELPER_H
#define BILLSCHECKER_HELPER_H

typedef struct {
    const char* DEFAULT_BILLS_NEEDED_FILE;
    const char* DEFAULT_TRANSACTIONS_FILE;
} def_args;

def_args getDefaults();

FILE* openFile(char*);

void transferCommandLineArguments(int, char **, char **);

char* getArgvalueOrDefault(char*, char*);

#endif //BILLSCHECKER_HELPER_H
