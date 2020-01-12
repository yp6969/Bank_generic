/*updates all the varlible*/
#include "updates.h"

/******************************************************
*****                    Bank                     ****/


/*this function updating the name of the bank*/
void updateNameOfBank(char** nameOfBank , int isInput ){
    getNameOfBank( nameOfBank , isInput );
    return;
}

/*this function updating the number of a branch*/
void updateNumberOfBranch(int* numberOfBranch , int temp , int isInput){
    if( isInput ) *numberOfBranch = getNumberOfBranch();
    else (*numberOfBranch)+=temp;
    return;
}

/*this function updating the account balance of a client*/
void updateNumberOfBankClients(int* numberOfBankClient , int temp , int isInput){
    if( isInput ) *numberOfBankClient = getNumberOfBankClients();
    else (*numberOfBankClient)+=temp;
    return;
}

/*this function updating of all bank clients*/
void updateSumOfAllBankClients(double* sumOfAllBankClients , double temp , int isInput){
    if( isInput ) *sumOfAllBankClients = getSumOfAllBankClients();
    else (*sumOfAllBankClients)+=temp;
    return;
}

/*this function update the bank sum of the profit of last year*/
void updateBankProfitOfLastYear(double* profitOfLastYear , double temp , int isInput){
    if( isInput ) *profitOfLastYear = getProfitOfLastYear();
    else (*profitOfLastYear)+=temp;
    return;
}

/*this function update the number of bank loans*/
void updateNumberOfBankActiveLoan(int* numberOfActiveLoans , int temp , int isInput){
    if( isInput ) *numberOfActiveLoans = getNumberOfActiveLoans();
    else if (*numberOfActiveLoans <= 0 ){
        return;
    }
    else (*numberOfActiveLoans)+=temp;
    return;
}

/******************************************************
********                  branch              ********/

void updateNameOfBranch(char** branchName){
    getNameOfBranch(branchName);
    return;
}

/*this function update the Id of a branch*/
void updateBranchId(int* branchId  , int tmpBranchId , int isInput ){
    if(!isInput) *branchId = tmpBranchId;
    else *branchId = getBranchId();
    return;
}

/*this function update the number of branch clients*/
void updateNumberOfBranchClients(int* numberOfBranchClients ,  int temp , int isInput ){
    if( isInput ) *numberOfBranchClients = getNumberOfBranchClients();
    else (*numberOfBranchClients)+=temp;
    return;
}

/*this function update the sum of all branch clients*/
void updateSumOfAllBranchClients(double* sumOfAllBranchClients , double temp , int isInput){
    if( isInput ) *sumOfAllBranchClients = getSumOfAllBranchClients();
    else (*sumOfAllBranchClients)+=temp;
    return;
}

/*this function update the branch sum of the profit of last year*/
void updateBranchProfitOfLastYear(double* branchProfitOfLastYear , double temp , int isInput){
    if( isInput ) *branchProfitOfLastYear = getBranchProfitOfLastYear();
    else (*branchProfitOfLastYear)+=temp;
    return;
}

/*this function update the number of branch loans*/
void updateNumberOfBranchLoans(int* numberOfBranchLoans , int temp , int isInput ){
    if( isInput ) *numberOfBranchLoans = getNumberOfBranchLoans();
    else (*numberOfBranchLoans)+=temp;
    return;
}

/*this function update the opening time of a branch*/
void updateOpenHour(int* openHour){
    *openHour = OPEN_HOUR ;
    return;
}

/*this function update the closing time of a branch*/
void updateCloseHour(int* closeHour){
    *closeHour = CLOSE_HOUR ;
    return;
}

/********************************************************
********                 client                *********/


/*the static parameters.*/

/*this function updating the name of client*/
void updateFirstNameOfClient(char** firstNameOfClient){
    getFirstNameOfClient(firstNameOfClient);
    return;
}

void updateLastNameOfClient(char** lastNameOfClient){
    getLastNameOfClient(lastNameOfClient);
    return;
}

/*this function updating the client Id number*/
void updateClientId(int* clientId){
    *clientId = getClientId();
    return;
}

/*this function updating the account number*/
void updateAccountNumber(int* accountNumber){
    *accountNumber = getAccountNumber();
    return;
}

/*the dinamic parameters.
amountOfMoney means adding or subtract money depend on sign*/
void updateAuthorizedException(double* authorizedException ){
    *authorizedException = MIN_EXEPTION;
    return;
}

/*this function updating the account balance of a client*/
void updateAccountBalance(double* acountBalance , double amountOfMoney  , int isInput ){
    if(isInput) *acountBalance = getAcountBalance();
    else *acountBalance += amountOfMoney;
    return;
}

/*this function updating the loan balance of a client*/
void updateLoanBalance(double* loanBalance, double amountOfMoney , int isInput){
    if(isInput) *loanBalance = getLoanBalance();
    else *loanBalance += amountOfMoney;
    return;
}

/*this function updating the saving balance of a client*/
void updateSaveBalance(double* saveBlance , double amountOfMoney , int isInput){
    if(isInput) *saveBlance = getSaveBlance();
    else *saveBlance += amountOfMoney;
    return;
}
