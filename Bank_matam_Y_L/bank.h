#ifndef BANK_H
#define BANK_H

#include "branch.h"

 /*this function's is manage all bank changes*/

void inituilize_Bank();
void update_Bank_Parameters();
int client_in_bank();
double average_Number_Of_Accounts_In_Branches(Tree* branchTree);
void print_Bank_Parameters();
void calculate_Profit_Of_Last_Year();


#endif
