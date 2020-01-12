#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H

#include "struct_declaration.h"

#define MAX_EXEPTION 200000
#define MIN_EXEPTION 1000
#define MAX_ID 999999999
#define MAX_BRANCH_LOANS 100
#define MAX_OF_ACTIVE_LOANS 100
#define SUCCESS 1
#define FAILD 0
#define MAX_BRANCHS 500
#define MAX_CLIENT_OF_BANK 500000
#define MAX_CLIENT_OF_BRANCH 1000
#define MAX_NAME 100
#define NON 0
#define OPEN_HOUR 8
#define CLOSE_HOUR 4

/*Bank.*/
/*this function's are responsibility of cheking the bank parameters*/
int checkNumberOfBankClients(int input);
int checkNameOfBank(char* input);
int checkNumberOfBranch(int input);
int checkNumberOfBankClients(int input);
int checkSumOfAllBankClients(double input);
int checkProfitOfLastYear(double input);
int checkNumberOfActiveLoans(int input);

/*Branch.*/
/*this function's are responsibility of cheking the branch parameters*/
int checkBranchId(int input);
int checkNumberOfBranchClients(int input);
int checkSumOfAllBranchClients(double input);
int checkBranchProfitOfLastYear(double input);
int checkNumberOfBranchLoans(int input);
int checkOpenHour(int input);
int checkCloseHour(int input);

/*Client.*/
/*this function's are responsibility of cheking the client parameters*/
int checkNameOfClient(char* input);
int checkClientId(int input);
int checkAccountNumber(int input);
int checkAuthorizedException(double input);
int checkAcountBalance(double input);
int checkLoanBalance(double input);
int checkSaveBlance(double input);
int checkDepositeMoney(double input);

#endif
