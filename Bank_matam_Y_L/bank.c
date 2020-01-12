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


/* return the averge of number of clients in branch */
double averageNumberOfAccountsInBranches(Branch_tree* branchHead , int* cnt_clients) {
    int numOfBranchLeft , numOfBranchRight;
    double averageLeft , averageRight;
    if( !branchHead ) {
        *cnt_clients = 0;
        return 0;
    }
    /* ask for the averege of the left right childs */
    averageLeft = averageNumberOfAccountsInBranches( branchHead -> left , &numOfBranchLeft );
    averageRight = averageNumberOfAccountsInBranches( branchHead -> right , &numOfBranchRight );
    /* update the number of clients */
    *cnt_clients = numOfBranchLeft + numOfBranchRight + 1;
    /* mathematical expretion of avereg */
    return ( averageLeft * numOfBranchLeft + averageRight * numOfBranchRight + branchHead -> branch.numberOfBranchClients ) / *cnt_clients;

}