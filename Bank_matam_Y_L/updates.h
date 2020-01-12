#ifndef UPDATES_H
#define UPDATES_H

#include "input.h"

#define ADD 1
#define DELETE -1

/**********************************************************/
/*           updates the bank parameters                  */
/* isInput is flag that means if the date come ftom the user*/
void updateNameOfBank(char** nameOfBank , int isInput);
void updateNumberOfBranch(int* numberOfBranch , int temp , int isInput);
void updateNumberOfBankClients(int* numberOfBankClient , int temp , int isInput);
void updateSumOfAllBankClients(double* sumOfAllBankClients , double temp , int isInput);
void updateBankProfitOfLastYear(double* profitOfLastYear , double temp , int isInput);
void updateNumberOfBankActiveLoan(int* numberOfActiveLoans , int temp , int isInput);

/*****************************************************************/
/*          updates the branches parameters                      */
/* isInput is flag that means if the date come ftom the user*/

void updateNameOfBranch(char** branchName);
void updateBranchId(int* branchId  , int tmpBranchId , int isInput );
void updateNumberOfBranchClients(int* numberOfBranchClients , int temp , int isInput );
void updateSumOfAllBranchClients(double* sumOfAllBranchClients , double temp , int isInput);
void updateBranchProfitOfLastYear(double* branchProfitOfLastYear , double temp , int isInput);
void updateNumberOfBranchLoans(int* numberOfBranchLoans , int temp , int isInput);
void updateOpenHour(int* openHour);
void updateCloseHour(int* closeHour);

/*updates the client parameters.
amountOfMoney means adding or subtract mony depend on sign.*/
void updateFirstNameOfClient(char** firstNameOfClient);
void updateLastNameOfClient(char** lastNameOfClient);
void updateClientId(int* clientId);
void updateAccountNumber(int* accountNumber);
void updateAuthorizedException(double* authorizedException );
void updateAccountBalance(double* acountBalance , double amountOfMoney  , int isInput );
void updateLoanBalance(double* loanBalance, double amountOfMoney , int isInput);
void updateSaveBalance(double* saveBlance , double amountOfMoney , int isInput);

#endif
