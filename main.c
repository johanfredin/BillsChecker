/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: johan
 *
 * Created on February 25, 2016, 9:44 PM
 */
#include "header-files/bill.h"
#include "header-files/helper.h"

short verboseOptionEnabled = 0;

const short ARG_IDX_BILLS_NEEDED = 0;
const short ARG_IDX_TRANSACTIONS = 1;

FILE* openFile(char*);
void checkBills(Bill*, FILE* file);

/*
 * 
 */
int main(int argc, char** argv) {

    def_args defaults = getDefaults();

    char * arguments[2] = {NULL, NULL};
    transferCommandLineArguments(argc, argv, arguments);

    // Retrieve the file containing required bills
    char *neededBillsFileDir = getArgvalueOrDefault(arguments[ARG_IDX_BILLS_NEEDED], defaults.DEFAULT_BILLS_NEEDED_FILE);
    
    // Retrieve the file containing the current bills
    char *billsFileDir = getArgvalueOrDefault(arguments[ARG_IDX_TRANSACTIONS], defaults.DEFAULT_TRANSACTIONS_FILE); //
    
    FILE *requiredBillsFile = openFile(neededBillsFileDir);
    FILE *transactionsFile = openFile(billsFileDir);
    
    // If the files are null we shut down the program
    if(requiredBillsFile == NULL || transactionsFile == NULL) {
        return EXIT_FAILURE;
    }
    
    // Retrieve the first bill and make a linked list
    Bill *bill = getLinkedBillsFromFile(requiredBillsFile);

    fclose(requiredBillsFile);

    // Check if we missed any bills
    checkBills(bill, transactionsFile);

    fclose(transactionsFile);

    // Finally remove the bills
    removeBills(bill);
     
    return (EXIT_SUCCESS);
    
}





