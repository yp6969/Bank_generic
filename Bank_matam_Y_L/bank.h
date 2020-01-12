#ifndef BANK_H
#define BANK_H

#include "branch.h"

 /*this function's is manage all bank changes*/
void updateBankParameters();
void inituilizeBank();
int clientNuberOfBank();
void calculateProfitOfLastYear();
void printBankParameters();
int isBankFull();
int isBankEmpty();
double averageNumberOfAccountsInBranches(Branch_tree* branchHead , int* cnt_clients);


#endif
