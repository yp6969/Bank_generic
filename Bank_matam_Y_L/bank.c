#include "bank.h"

/*update all the bank parameters.*/
void updateBankParameters(){
    updateNameOfBank( &bank.nameOfBank ,  ADD );
    updateNumberOfBranch( &bank.numberOfBranch , NON , NON );
    updateNumberOfBankClients( &(bank.numberOfBankClients) , NON , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , NON , NON );
    updateBankProfitOfLastYear( &(bank.profitOfLastYear) , NON , NON );
    updateNumberOfBankActiveLoan( &(bank.numberOfActiveLoans) , NON , NON );
    return;
}
/*creating the branch list with the maximum optional size*/
void inituilizeBank(){
    createBranchTree();
    updateBankParameters();
}

int clientNuberOfBank(){
    return bank.numberOfBankClients;
}

void calculateProfitOfLastYear(){
    updateBankProfitOfLastYear( &(bank.profitOfLastYear) , NON , NON);
    return;
}

void printBankParameters(){
    printf("\nname Of Bank: %s \n", bank.nameOfBank );
    printf("Number of branches: %d \n" , bank.numberOfBranch );
    printf("Number of bank client: %d \n" , bank.numberOfBankClients);
    printf("Sum of all bank clients: %g\n " , bank.sumOfAllBankClients);
    printf("Profit of last year: %g \n" , bank.profitOfLastYear);
    printf("Number of active loans: %d \n" , bank.numberOfActiveLoans);
    return;
}

/* quest if the list is empty*/
int isBankEmpty(){
    if(!branchHead) return TRUE;
    return FALSE;
}

/* quest if the branch list is full*/
int isBankFull(){
    if(bank.numberOfBranch >= MAX_BRANCHS) return TRUE;
    return FALSE;
}


/********************************************************************/
/*******                   averege branches                 ********/

/*avg num of client*/
/* return the averge of number of clients in branch */
double average_Number_Of_Accounts_In_Branches(Tree* branchTree){
    int num;
    return avarageKey(branchTree , &num , &get_num_of_client);
}


double get_num_of_client(Branch* b){
    return b->numberOfBranchClients;
}