#include "client.h"


/******************************************************/
/*  *********    adding client tree     ***************/

/*creating the branch list*/
void create_Branch_Client_Tree(Tree* clientHead)
{
    create_tree(clientHead);
    return;
}

/* creating allocat client */
Client* create_New_Client( int branchId )
{
    Client* newClient = ALLOC (Client , 1 );
    //newClient->acountBalance = 0;
    updateClientParameters( &newClient , branchId );
    return newClient;
}

/* add the client to the sorted tree*/
void add_Client_To_Branch_t(Branch* branch)
{
    /* if the branch is full do nothing*/
    if(is_Branch_Full(branch->numberOfBranchClients))
    {
        printf("The branch is full!!!!!\n\n");
        return;
    }
    Client* tempClient  = create_New_Client(branch->branchId);
    branch-> clientHead = add_new_node(branch->clientHead , tempClient , &cmp_clients_id );
    update_New_Client_To_Branch( branch  , tempClient );
    printf("\nclient number %d is created\n\n", tempClient->accountNumber);
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


/********************************************************************/
/*                       searching clients                          */


/* handle the finding options */
void find_Client(D_Llinked_List* list ){
    int option;
    Client* client;
    printf("\nHow do you want to find\n");
    printf("[1] Client ID\n");
    printf("[2] Account balance\n");
    printf("[3] Go back\n");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        client = search_Client_By_Id_In_Bank( bank.branchHead , getClientId() , &get_client_head);
        if(!client) printf("client not found\n");
        else printf("succses\n");
        break;
    case 2:
        find_Client_In_Bank_By_Acount_Balance( list , bank.branchHead , getAcountBalance());
        if(!list) printf("clients not found\n");
        else printf("succses\n");
        break;
    case 3:
        return;
    default:
            printf("wrong choise try again\n");
    
    }
}

/* searching client by ID in the Bank !!!! */
Client* search_Client_By_Id_In_Bank(Tree* branchHead , int clientId , Tree* (*get_tree)(void*))
{
    Client* client;
    if(!branchHead) return NULL;
    client = search_Client_By_Id_In_Bank( branchHead->left , clientId , get_tree);
    if(client) return client;
    client = search_Client_By_Id_in_branch( (*get_tree)(branchHead->key) , clientId);
    if(client) return client;
    client = search_Client_By_Id_In_Bank(branchHead->right , clientId , get_tree);
    return client;
}


/* searching client by ID in spesific branch */
Client* search_Client_By_Id_in_branch( Tree* clientHead , int clientId )
{
    Client* tmp = ALLOC(Client , 1);
    tmp->clientId = clientId;
    Client* client = (Client*)sorted_find(clientHead , tmp , &cmp_clients_id );
    FREE(tmp);
    return client;
}

/* find Client In the bank By Acount Balance and insert to linked list*/
void find_Client_In_Bank_By_Acount_Balance(D_Llinked_List* list ,Tree* branchHead , double acountBalance )
{
    Client* tmp = ALLOC(Client , 1);
    tmp->acountBalance = acountBalance;
    find_Client_In_Bank_By_Any(list , branchHead , tmp , &cmp_clients_accountBalance , &cmp_clients_id , &get_client_head);
    FREE(tmp);
    return ;
}


/****************************************************************/
/*                         search branch                        */

Branch* search_Branch_By_Id( Tree* branchHead , int branchId)
{
    Branch* tmp = ALLOC(Branch , 1);
    tmp->branchId = branchId;
    Branch* branch = (Branch*)sorted_find(branchHead , tmp , &cmp_branchs_id );
    FREE(tmp);
    return branch;
}


/********************************************************/
/******              delete clients                ******/

/*  delete all the branch clients*/
Tree* delete_All_Branch_Clients(Tree* clientHead  )
{
    return remove_All_nodes(clientHead , &free_Client );
}

/* delete specific client */
Tree* delete_Client( Tree* clientHead , int clientId )
{
    Client* tmp = ALLOC(Client , 1);
    tmp->clientId = clientId;
    return delete_node_tree( clientHead , tmp , &cmp_clients_id , &free_Client);
    FREE(tmp);
}

/* free all the allocated blockes in the client*/
void free_Client(void* client)
{
    update_Delete_Client((Client*)client);
    FREE(((Client*)client)->nameOfBank);
    FREE(((Client*)client)->firstNameOfClient);
    FREE(((Client*)client)->lastNameOfClient);
    return;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

/* compare client by id */
int cmp_clients_id(void* c1 , void* c2)
{
    if(((Client*)c1)->clientId > ((Client*)c2)->clientId) return 1;
    if(((Client*)c1)->clientId < ((Client*)c2)->clientId) return -1;
    return 0;
}

/* compare client by id */
int cmp_clients_accountBalance(void* c1 , void* c2 )
{
    if(((Client*)c1)->acountBalance > ((Client*)c2)->acountBalance ) return 1;
    if(((Client*)c1)->acountBalance < ((Client*)c2)->acountBalance ) return -1;
    return 0;
}

int cmp_balance_loan(void* client)
{
    if(((Client*)client)->acountBalance > ((Client*)client)->loanBalance) return 1;
    if(((Client*)client)->acountBalance < ((Client*)client)->loanBalance) return -1;
    return 0;
}

int cmp_branchs_id(void* b1 , void* b2)
{
    if(((Branch*)b1)->branchId > ((Branch*)b2)->branchId) return 1;
    if(((Branch*)b1)->branchId < ((Branch*)b2)->branchId) return -1;
    return 0;
}

double get_balance(void* client)
{
    return ((Client*)client)->acountBalance;
}

/* get the client tree head of branch */
Tree* get_client_head(void* branch)
{
    return ((Branch*)branch)->clientHead;
}

/**********************************************************************************/
/**********                      client data                         **************/

/*updates all the client parameters.*/
void updateClientParameters(Client** client , int banchId)
{
    updateFirstNameOfClient( &(*client) -> firstNameOfClient);
    updateLastNameOfClient( &(*client) -> lastNameOfClient);
    updateNameOfBank( &(*client) -> nameOfBank , NON );
    updateClientId( &(*client) -> clientId);
    updateBranchId( &(*client) -> branchId , banchId , NON );
    updateAccountNumber( &((*client) -> accountNumber));
    updateAuthorizedException(&((*client) -> authorizedException ));
    updateAccountBalance( &((*client) -> acountBalance) , NON , NON);
    updateLoanBalance( &((*client) -> loanBalance) , NON , NON);
    updateSaveBalance( &((*client) -> saveBlance) , NON , NON);
    return;
}


void update_Delete_Client(Client* client )
{
    Branch* branch = search_Branch_By_Id(bank.branchHead , client->branchId );
    /* bank updates */
    updateNumberOfBankClients( &bank.numberOfBankClients , DELETE , NON );
    updateSumOfAllBankClients(&bank.sumOfAllBankClients , -(client->acountBalance - client->loanBalance) , NON );
    /* branch updates */
    updateNumberOfBranchClients( &branch->numberOfBranchClients , DELETE , NON);
    updateSumOfAllBranchClients(&branch->sumOfAllBranchClients , -(client->acountBalance - client->loanBalance) , NON);
    return;
}

/*update the branch with the new client in the bank*/
void update_New_Client_To_Branch( Branch *branch  , Client* tempClient )
{
    updateNumberOfBranchClients( &(branch->numberOfBranchClients) , ADD , NON );
    updateSumOfAllBranchClients( &(branch->sumOfAllBranchClients) , (tempClient->acountBalance) , NON);
    updateNumberOfBankClients( &(bank.numberOfBankClients) , ADD , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , (tempClient->acountBalance) , NON);
    printf("\nClient number %d is created!!!!!!\n\n",tempClient->accountNumber);
    return;
}

/*deposit money to client account*/
void depositeMoneyToClientAccount(Client* client)
{
    double deposit;
    printf("\nHow much do you want to deposite ? :\n" );
    deposit = getDpositeMoney();
    updateAccountBalance(&client->acountBalance , deposit , NON );
    return;
}

/*deposit money to client save*/
void depositeMoneyToSave(Client* client){
    double deposit;
    printf("\nHow much do you want to deposite to your save ? :\n" );
    deposit = getSaveBlance();
    updateSaveBalance(&client->saveBlance , deposit , NON );
    updateAccountBalance(&client->acountBalance , -deposit , NON);
    return;
}

/*gives loan to client*/
void loanToClient(Client* client , Branch* branch){
    int flag = 0;
    double deposit;
    do{
        if(flag) printf("\n\nyou pass the authorized Exception try again!\n\n");
        flag = 1;
        printf("\nHow much do you want to loan ? :\n" );
        deposit = getLoanBalance();
    }while ( !chekLoanRequest(client -> authorizedException , deposit , client -> loanBalance) );
    updateLoanBalance(&client->loanBalance , deposit , NON );
    updateNumberOfBranchLoans(&(branch -> numberOfBranchLoans) , ADD , NON);
    updateNumberOfBankActiveLoan(&(bank.numberOfActiveLoans) , ADD , NON);
    return;
}

/*repay client loans*/
void repayClientLoans(Client* client , Branch* branch )
{
    double deposit;
    if(client->loanBalance >= 0 )
    {
        printf("you dont have loans");
        bank.numberOfActiveLoans = 0;
        return;
    }
    printf("\nHow much do you want to repay your loan ? :\n\n" );
    deposit = getDpositeMoney();
    updateLoanBalance(&client->loanBalance , -deposit , NON );
    updateAccountBalance(&client->acountBalance , -deposit , NON);
    updateNumberOfBranchLoans(&(branch-> numberOfBranchLoans) , DELETE , NON);
    updateNumberOfBankActiveLoan(&bank.numberOfActiveLoans , DELETE , NON);
    return;
}

/*  checking the loane request for client */
int chekLoanRequest(double authorizedException , double deposite , double loanBalance)
{
    if( (loanBalance + deposite) > authorizedException ) return FAILD;
    return SUCCESS;
}



/***************************************************************************/
/*******                      print client                         *********/

void print_all_Client_Details(Tree* clientTree)
{
    print_keys(clientTree , &print_Client_Details);
    return;
}

void print_all_Client_Id(Tree* clientTree)
{
    print_keys(clientTree , &print_Client_Id);
    return;
}

void print_all_Client_Acount_Number_And_Balance(Tree* clientTree){
    print_keys(clientTree , &print_Client_account_number_balance);
    return;
}




/**********************************************/
/*           print client pointers            */

/*Print the parameters of the client*/
void print_Client_Details(void* client){
    printf("\nname Of Client: %s %s\n", ((Client*)client) -> firstNameOfClient , ((Client*)client) -> lastNameOfClient );
    printf("client Id: %d \n" ,(int)((Client*)client) -> clientId );
    printf("branch Id: %d \n" , ((Client*)client) -> branchId);
    printf("account Number: %d\n " , ((Client*)client)-> accountNumber);
    printf("authorized Exception: %g \n" , ((Client*)client) -> authorizedException);
    printf("acount Balance: %g \n" , ((Client*)client) -> acountBalance);
    printf("loan Balance: %g \n" , ((Client*)client) -> loanBalance);
    printf("save Blance: %g \n" , ((Client*)client) -> saveBlance);
    return;
}

void print_Client_Id(void* c ){
    printf("Client [%d]\n" , ((Client*)c)->clientId);
}


void print_Client_account_number_balance(void* c ){
    printf("\nClient account: %d \t Balance: %g \n", ((Client*)c)->accountNumber , ((Client*)c)->acountBalance );
    
}