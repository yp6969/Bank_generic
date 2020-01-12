#ifndef INPUT_H
#define INPUT_H

#include "check_input.h"

#define ALLOC(typ,no) ((typ *) checked_malloc(sizeof(typ)*(no)))
#define FREE(ptr) checked_free(ptr)


/* doing malloc and chek if it allocat correctly*/
void *checked_malloc(unsigned int size);
void checked_free(void *);
void check_for_exit();
/*Bank.*/
/*this function's are responsibility of geting the bank parameters*/
void getNameOfBank( char** nameOfBank , int isInput);
int getNumberOfBankClients();
int getNumberOfBranch();
int getNumberOfBankClients();
double getSumOfAllBankClients();
double getProfitOfLastYear();
int getNumberOfActiveLoans();

/*Branch.*/
/*this function's are responsibility of geting the branch parameters*/
void getNameOfBranch(char** nameOfBranch);
int getNumberOfBranchClients();
int getBranchId();
double getSumOfAllBranchClients();
double getBranchProfitOfLastYear();
int getNumberOfBranchLoans();
int getOpenHour();
int getCloseHour();

/*Client.*/
/*this function's are responsibility of geting the client parameters*/
void getFirstNameOfClient(char** firstNameOfClient);
void getLastNameOfClient(char** lastNameOfClient);
int getClientId();
int getAccountNumber();
double getAuthorizedException();
double getAcountBalance();
double getLoanBalance();
double getSaveBlance();
double getDpositeMoney();

#endif
