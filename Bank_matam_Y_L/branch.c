#include "branch.h"


/*********************************************************/
/*****               adding branch Tree             ******/

/*creating the branch list*/
void create_Branch_Tree()
{
    create_tree(bank.branchHead);
    return;
}

/*adding new branch to the branch tree*/
void add_New_Branch_t()
{
    Branch *tmpBranch = create_New_Branch();
    /* if the branch is full do nothing*/
    if(is_Bank_Full())
    {
        printf("The branch is full!!!!!\n\n");
        return;
    }
    
    bank.branchHead = add_new_node( bank.branchHead , tmpBranch , &cmp_branchs_id );
    updateNumberOfBranch( &(bank.numberOfBranch) , ADD , NON );
    printf("\nBranch number %d is created\n\n", tmpBranch->branchId);
}

/* creat new branch */
Branch* create_New_Branch()
{
    Branch* newBranch = ALLOC (Branch,1);
    update_Branch_Parameters( newBranch );
    return newBranch;
}

/* quest if the list is empty*/
int is_Bank_Empty(){
    if(!bank.branchHead) return TRUE;
    return FALSE;
}

/* quest if the branch list is full*/
int is_Bank_Full(){
    if(bank.numberOfBranch >= MAX_BRANCHS) return TRUE;
    return FALSE;
}

/**********************************************************/
/*******             delete branches               ********/


Tree* delete_All_Branchs(Tree* branchTree )
{
    return remove_All_nodes(branchTree , &free_Branch );
}

/* delete spesific branch by id*/
Tree* delete_Branch( Tree* branchTree , int branchId )
{
    Branch* tmp = ALLOC(Branch , 1);
    tmp->branchId = branchId;
    return delete_node_tree( branchTree , tmp , &cmp_branchs_id , &free_Branch);
}

/* free all the allocated blockes*/
void free_Branch(void *branch)
{
    updateNumberOfBranch( &bank.numberOfBranch , DELETE , NON);
    ((Branch*)branch)->clientHead = delete_All_Branch_Clients(((Branch*)branch)->clientHead);
    FREE(((Branch*)branch)->nameOfBank);
    FREE(((Branch*)branch)->branchName);
}


/****************************************************************/
/*                       getters branch                        */

double client_in_Branch(void* b)
{
 return (double)((Branch*)b)->numberOfBranchClients;
}


/********************************************************************/
/*  *********            branch data                     ***********/

/*updates all the branches parameters
flag means NON for 1 delete for -1.*/
void update_Branch_Parameters(Branch* branch){
    updateNameOfBank(&branch->nameOfBank , NON );
    updateNameOfBranch(&branch->branchName);
    updateBranchId( &branch->branchId , NON , ADD );
    updateNumberOfBranchClients( &(branch->numberOfBranchClients) , NON , NON );
    updateSumOfAllBranchClients( &(branch->sumOfAllBranchClients) , NON , NON);
    updateBranchProfitOfLastYear( &(branch->branchProfitOfLastYear) , NON , NON );
    updateNumberOfBranchLoans( &(branch->numberOfBranchLoans) , NON , NON);
    updateOpenHour( &(branch->openHour) );
    updateCloseHour( &(branch->closeHour) );
    return;
}

double get_num_of_client(Branch* b){
    return b->numberOfBranchClients;
}

/*calculate the branch profit of the last year*/
double calculateBranchProfitOfLastYear(Branch* branch){
    return NON;
}

/*recursive method to find number of appearance of client with account balance that bigger then given balance*/
int client_Number_With_Given_Balance(Tree *clientHead , double balance , double (*get_balance)(void*))
{
    int count = 0 ;
    if(!clientHead) {
        return 0;
    }
    count += client_Number_With_Given_Balance( clientHead->left , balance , get_balance);
    if( (*get_balance)(clientHead->key) > balance ) {
        count++;
    }
    count += client_Number_With_Given_Balance( clientHead->right , balance , get_balance);
    return count;
}

/*recursive method to find number of appearance of client with account balance that lower then given loan balance*/
int client_Number_With_Bigger_Loans_Then_Balance( Tree *clientHead , int (*cmp_balance_loan)(void*))
{
    int count = 0 ;
    if(!clientHead) {
        return 0;
    }
    count += client_Number_With_Bigger_Loans_Then_Balance( clientHead -> left , cmp_balance_loan);
    if((*cmp_balance_loan)(clientHead->key) == 1 ) {
        count++;
    }
    count += client_Number_With_Bigger_Loans_Then_Balance( clientHead -> right , cmp_balance_loan);
    return count;

}



/****************************************************************/
/*                   print branch ditails                       */

void print_all_Branch_Details(Tree* branchTree)
{
    print_keys(branchTree , &print_Branch_Details);
    return;
}

void print_all_Branch_Id(Tree* branchTree)
{
    print_keys(branchTree , &print_Branch_Id);
    return;
}

/**********************************************/
/*           print client pointers            */
/*print all the branch parameters*/
void print_Branch_Details(void* branch)
{
    printf("\nBeanch ID: %d\n", ((Branch*)branch)->branchId);
    printf("Number of branch clients: %d \n" ,((Branch*)branch) -> numberOfBranchClients);
    printf("Sum of all branch clients: %g \n" ,((Branch*)branch) -> sumOfAllBranchClients);
    printf("profit of last year : %g\n " , ((Branch*)branch) -> branchProfitOfLastYear);
    printf("Number of branch loans: %d \n" ,((Branch*)branch) -> numberOfBranchLoans);
    printf("Open hour: %d \n" , ((Branch*)branch) -> openHour);
    printf("Close hour: %d \n" , ((Branch*)branch) -> closeHour);
    return;
}

/*print all the branchs ID */
void print_Branch_Id(void* b )
{
    printf("Branch [%d]\n" , ((Branch*)b)->branchId);
}
