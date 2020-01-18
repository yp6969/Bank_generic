#include "bank.h"

/*creating the branch list with the maximum optional size*/
void inituilize_Bank(){
    create_Branch_Tree();
    update_Bank_Parameters();
}


/*update all the bank parameters.*/
void update_Bank_Parameters(){
    updateNameOfBank( &bank.nameOfBank ,  ADD );
    updateNumberOfBranch( &bank.numberOfBranch , NON , NON );
    updateNumberOfBankClients( &(bank.numberOfBankClients) , NON , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , NON , NON );
    updateBankProfitOfLastYear( &(bank.profitOfLastYear) , NON , NON );
    updateNumberOfBankActiveLoan( &(bank.numberOfActiveLoans) , NON , NON );
    return;
}

/* return the number of clients of bank  */
int client_in_bank()
{
 return bank.numberOfBankClients;
}


/********************************************************************/
/*******                   averege branches                 ********/

/*avg num of client*/
/* return the averge of number of clients in branch */
double average_Number_Of_Accounts_In_Branches(Tree* branchTree)
{
    int num;
    return avarage_Key(branchTree , &num , &client_in_Branch);
}


/********************************************************************/
/*******                      print bank                     ********/


void print_Bank_Parameters()
{
    printf("\nname Of Bank: %s \n", bank.nameOfBank );
    printf("Number of branches: %d \n" , bank.numberOfBranch );
    printf("Number of bank client: %d \n" , bank.numberOfBankClients);
    printf("Sum of all bank clients: %g\n " , bank.sumOfAllBankClients);
    printf("Profit of last year: %g \n" , bank.profitOfLastYear);
    printf("Number of active loans: %d \n" , bank.numberOfActiveLoans);
    return;
}


void calculate_Profit_Of_Last_Year()
{
    updateBankProfitOfLastYear( &(bank.profitOfLastYear) , NON , NON);
    return;
}