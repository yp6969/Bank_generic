#include "client.h"


/******************************************************/
/*  *********    adding client tree     ***************/

/*creating the branch list*/
void create_Branch_Client_Tree(Tree* clientHead){
    create_tree(clientHead);
    return;
}

/* creating allocat client */
Client* create_New_Client( int branchId ){
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
    Client* tempClient  = create_new_client(branch->branchId);
    branch-> clientHead = add_new_node(branch->clientHead , tempClient , &cmp_clients_id );
    updateNewClientToBranch( branch  , *tempClient );
    printf("\nBranch number %d is created\n\n", tmpBranch->branchId);
}


/********************************************************************/
/*                       searching clients                          */


/* handle the finding options */
void findClient(D_Llinked_List* list ){
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
        client = search_Client_By_Id_In_Bank( bank.branchHead );
        break;
    case 2:
        find_Client_In_Bank_By_Acount_Balance( list , bank.branchHead );
        break;
    case 3:
        return;
    default:
            printf("wrong choise try again\n");
    
    }
}


/* searching client by ID in the Bank !!!! */
 Client* search_Client_By_Id_In_Bank(Tree* branchHead ){
    Client* client;
    if(!branchHead) return NULL;
    client = search_Client_By_Id_In_Bank( branchHead->left ;
    if(client) return client;
    client = search_Client_By_Id_in_branch(branchHead->branch->clientHead );
    if(client) return client;
    client = search_Client_By_Id_In_Bank(branchHead->right );
    return client;
 }


/* searching client by ID in spesific branch */
Client* search_Client_By_Id_in_branch( Tree* clientHead )
{
    Client* tmp = ALLOC(Client , 1);
    tmp->clientId = getClientId();
    Client* client = (Client*)sorted_find(clientHead , tmp , &cmp_clients_id );
    FREE(tmp);
    return client;
}

/* find Client In the bank By Acount Balance and insert to linked list*/
void find_Client_In_Bank_By_Acount_Balance(D_Llinked_List* list ,Tree* branchHead )
{
    Client* tmp = ALLOC(Client , 1);
    tmp->acountBalance = getAcountBalance();
    find_Client_In_Bank_By_Any(list , branchHead , tmp , &cmp_clients_accountBalance , &cmp_clients_id);
    FREE(tmp);
    return ;
}

/********************************************************/
/******              delete clients                ******/

/*  delete all the branch clients*/
Tree* delete_All_Branch_Clients(Tree* clientHead  )
{
    return remove_All_nodes(clientHead , &free_Client );
}

/* delete specific client */
Tree* delete_Client( Tree* clientHead , Client* client )
{
    return delete_node_tree( clientHead , client , &cmp_clients_id , &free_Client);
}

/* free all the allocated blockes in the client*/
void free_Client(Tree* clientNode){
    update_Delete_Client(clientNode->client);
    FREE(clientNode->client->nameOfBank);
    FREE(clientNode->client->firstNameOfClient);
    FREE(clientNode->client->lastNameOfClient);
    FREE(clientNode);
    return;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

/* compare client by id */
int cmp_clients_id(Client* c1 , Client* c2)
{
    if(c1->clientId > c2->clientId) return 1;
    if(c1->clientId < c2->clientId) return -1;
    return 0;
}

/* compare client by id */
int cmp_clients_accountBalance(Client* c1 , Client* c2 )
{
    if(c1->accountBalance > c2->accountBalance ) return 1;
    if(c1->accountBalance < c2->accountBalance ) return -1;
    return 0;
}

/*************************************************/
/*  *********     client data     ***************/

/*updates all the client parameters.*/
void updateClientParameters(Client** client , int banchId){
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


void update_Delete_Client(Client* client ){
    Branch* branch = searchBranchById(bank.branchHead , client->branchId );
    /* bank updates */
    updateNumberOfBankClients( &bank.numberOfBankClients , DELETE , NON );
    updateSumOfAllBankClients(&bank.sumOfAllBankClients , -(client->acountBalance - client->loanBalance) , NON );
    /* branch updates */
    updateNumberOfBranchClients( &branch->numberOfBranchClients , DELETE , NON);
    updateSumOfAllBranchClients(&branch->sumOfAllBranchClients , -(client->acountBalance - client->loanBalance) , NON);
    return;
}

/*update the branch with the new client in the bank*/
void update_New_Client_To_Branch( Branch *branch  , Client* tempClient ){
    updateNumberOfBranchClients( &(branch->numberOfBranchClients) , ADD , NON );
    updateSumOfAllBranchClients( &(branch->sumOfAllBranchClients) , (tempClient->acountBalance) , NON);
    updateNumberOfBankClients( &(bank.numberOfBankClients) , ADD , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , (tempClient->acountBalance) , NON);
    printf("\nClient number %d is created!!!!!!\n\n",tempClient->accountNumber);
    return;
}

/*deposit money to client account*/
void depositeMoneyToClientAccount(Client* client){
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
}

void print_all_Client_Id(Tree* clientTree)
{
    print_keys(clientTree , &print_Client_Id);
    return;
}

void printClientAcountNumberAndBalance(Tree* clientTree){
    print_keys(clientTree , &print_Client_account_number_balance);
    return;
}




/**********************************************/
/*           print client pointers            */

/*Print the parameters of the client*/
void print_Client_Details(Client* client){
    printf("\nname Of Client: %s %s\n", client -> firstNameOfClient , client -> lastNameOfClient );
    printf("client Id: %d \n" ,(int)client -> clientId );
    printf("branch Id: %d \n" , client -> branchId);
    printf("account Number: %d\n " , client -> accountNumber);
    printf("authorized Exception: %g \n" , client -> authorizedException);
    printf("acount Balance: %g \n" , client -> acountBalance);
    printf("loan Balance: %g \n" , client -> loanBalance);
    printf("save Blance: %g \n" , client -> saveBlance);
    return;
}

void print_Client_Id(Client* c {
    printf("Client [%d]\n" , c->clientId);
}


void print_Client_account_number_balance(Client* c {
    printf("\nClient account: %d \t Balance: %g \n", client->accountNumber , client->acountBalance );
    
}