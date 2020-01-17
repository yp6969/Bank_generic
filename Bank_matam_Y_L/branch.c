#include "branch.h"


/*********************************************************/
/*****               adding branch Tree             ******/

/*creating the branch list*/
void create_Branch_Tree(Tree* branchHead)
{
    create_tree(branchHead);
    return;
}

/*adding new branch to the branch tree*/
void add_New_Branch_t()
{
    Branch *tmpBranch = create_New_Branch();
    branch-> clientHead = add_new_node(branch->clientHead , tmpBranch , &cmp_branchs_id );
    update_Number_Of_Branch( &(bank.numberOfBranch) , ADD , NON );
    printf("\nBranch number %d is created\n\n", tmpBranch->branchId);
}

/* creat new branch */
Branch* create_New_Branch()
{
    Branch* newBranch = ALLOC (Branch,1);
    update_Branch_Parameters( newBranch );
    return newBranch;
}

/* check is the client list is empty*/
int is_Branch_Empty( Tree* clientHead )
{
    if(!clientHead) return TRUE;
    return FALSE;
}
/* check is the client list is full*/
int is_Branch_Full(int numberOfBranchClients)
{
    if(numberOfBranchClients >= MAX_CLIENT_OF_BRANCH) return TRUE;
    return FALSE;
}

/**********************************************************/
/*******             delete branches               ********/


Tree* delete_All_Branchs(Tree* branchTree )
{
    return remove_All_nodes(branchTree , &free_Branch );
}

/* delete spesific branch by id*/
Tree* delete_Branch( Tree* branchTree , Branch* branch )
{
    return delete_node_tree( branchTree , branch , &cmp_branchs_id , &free_Branch);
}

/* free all the allocated blockes*/
void free_Branch(Tree *branchTree)
{
    update_Number_Of_Branch( &bank.numberOfBranch , DELETE , NON);
    branchTree->branch->clientHead = delete_All_Branch_Clients(branchTree->branch.clientHead);
    FREE(branchTree->branch.nameOfBank);
    FREE(branchTree->branch.branchName);
    FREE(branchTree);
}


/****************************************************************/
/*                         search branch                        */

Branch* search_Branch_By_Id( Tree* branchHead )
{
    Branch* tmp = ALLOC(Branch , 1);
    tmp->clientId = getBranchId();
    Branch* branch = (Branch*)sorted_find(branchHead , tmp , &cmp_branchs_id );
    FREE(tmp);
    return branch;
}

/****************************************************************/
/*                         compare branch                        */

int cmp_branchs_id(Branch* b1 , Branch* b2)
{
    if(b1->branchId > b2->branchId) return 1
    if(b1->branchId < b2->branchId) return -1
    return 0;
}

/********************************************************************/
/*  *********            branch data                     ***********/

/*updates all the branches parameters
flag means NON for 1 delete for -1.*/
void updateBranchParameters(Branch* branch){
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


/*calculate the branch profit of the last year*/
double calculateBranchProfitOfLastYear(Branch* branch){
    return NON;
}

/*recursive method to find number of appearance of client with account balance that bigger then given balance*/
int clientNumberWithGivenBalance(Tree *clientHead , double Balance) {
    int count = 0 ;
    if(!clientHead) {
        return 0;
    }
    count += clientNumberWithGivenBalance( clientHead->left , Balance );
    if( clientHead -> client->acountBalance > Balance ) {
        count++;
    }
    count += clientNumberWithGivenBalance( clientHead->right , Balance );
    return count;
}

/*recursive method to find number of appearance of client with account balance that lower then given loan balance*/
int clientNumberWithBiggerLoansThenBalance( Tree *clientHead , int(*cmp)(void* , void*)) {
    int count = 0 ;
    if(!clientHead) {
        return 0;
    }
    count += clientNumberWithBiggerLoansThenBalance( clientHead -> left );
    if(clientHead -> client->loanBalance > clientHead->client.acountBalance) {
        count++;
    }
    count += clientNumberWithBiggerLoansThenBalance( clientHead -> right );
    return count;

}



/****************************************************************/
/*                   print branch ditails                       */

void print_all_Branch_Details(Tree* branchTree)
{
    print_keys(branchTree , &print_Branch_Details);
    return;
}

void print_all_Client_Id(Tree* branchTree)
{
    print_keys(branchTree , &print_Branch_Id);
    return;
}

/**********************************************/
/*           print client pointers            */
/*print all the branch parameters*/
void print_Branch_Details(Branch* branch){
    printf("\nBeanch ID: %d\n", branch -> branchId);
    printf("Number of branch clients: %d \n" ,branch -> numberOfBranchClients);
    printf("Sum of all branch clients: %g \n" ,branch -> sumOfAllBranchClients);
    printf("profit of last year : %g\n " , branch -> branchProfitOfLastYear);
    printf("Number of branch loans: %d \n" ,branch -> numberOfBranchLoans);
    printf("Open hour: %d \n" , branch -> openHour);
    printf("Close hour: %d \n" , branch -> closeHour);
    return;
}

/*print all the branchs ID */
void print_Branch_Id(Branch* b {
    printf("Branch [%d]\n" , b->branchId);
}