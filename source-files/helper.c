//
// Created by johan on 3/31/16.
//

#include "../header-files/helper.h"

def_args getDefaults() {
    def_args defaults = {"resources/BillsNeeded.csv", "resources/transactionlist.xls"};
    return defaults;
}


FILE* openFile(char* directory) {
    FILE* file = fopen(directory, "r");
    if(file == NULL) {
        fprintf(stderr, "Can't open the file %s.\n", directory);
    }
    return file;
}

char* getArgvalueOrDefault(char* argValue, char* defaultValue) {
    return argValue == NULL ? defaultValue : argValue;
}

/**
 * Lets find out if we have command line arguments
 */
void transferCommandLineArguments(int argc, char **argv, char **myArray) {
    int i;
    for(i = 1; i < argc; i++) {
        myArray[i - 1] = argv[i];
    }
};
