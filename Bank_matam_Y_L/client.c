#include "client.h"


/******************************************************/
/*  *********    adding client tree     ***************/

/*creating the branch list*/
void create_Branch_Client_Tree(Tree* clientHead){
    create_tree(clientHead);
    return;
}

void add_Client_To_Branch_t(Branch* branch){
    Client* tempClient  = create_new_client(branch->branchId);
    branch->clientHead = addNewClientToBranch(branch->clientHead , *tempClient );
    updateNewClientToBranch( branch  , *tempClient );
    FREE(tempClient);
}


Client* create_New_Client( int branchId ){
    Client* newClient = ALLOC (Client , 1 );
    newClient->acountBalance = 0;
    updateClientParameters( &newClient , branchId );
    return newClient;
}

/*adding new branch to the branch tree*/
Tree * add_New_Client_To_Branch(Tree * clientHead , Client client )
{

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
        client = searchClientByIdInBank( branchHead , getClientId() );
        break;
    case 2:
        findClientInBankByAcountBalance( list , branchHead , getAcountBalance() );
        break;
    case 3:
        return;
    default:
            printf("wrong choise try again\n");
    
    }


}


/* find Client In the bank By Acount Balance and insert to linked list*/
void findClientInBankByAcountBalance(D_Llinked_List* list ,Branch_tree* branchHead ,  int acountBalance ){
    if(!branchHead) return;
    findClientInBankByAcountBalance(list , branchHead->left , acountBalance);
    findClientInBranchByAcountBalance(list , branchHead->branch.clientHead , acountBalance );
    findClientInBankByAcountBalance(list , branchHead->right , acountBalance );
}

/* find Client In Branch By Acount Balance and insert to linked list*/
void findClientInBranchByAcountBalance(D_Llinked_List* list , Client_tree* clientHead , int acountBalance){
    if(!clientHead) return;
    findClientInBranchByAcountBalance(list , clientHead->left , acountBalance );
    if(clientHead->client.acountBalance == acountBalance )
        addNode(list , &clientHead->client );
    findClientInBranchByAcountBalance(list , clientHead->right , acountBalance );
}


/* searching client by ID in the Bank !!!! */
 Client* searchClientByIdInBank(Branch_tree* branchHead ,  int clientId ){
    Client* client;
    if(!branchHead) return NULL;
    client = searchClientByIdInBank( branchHead->left , clientId);
    if(client) return client;
    client = searchClientById(branchHead->branch.clientHead , clientId );
    if(client) return client;
    client = searchClientByIdInBank(branchHead->right , clientId );
    return client;
}


/* searching client by ID in spesific branch */
Client* searchClientById( Client_tree* clientHead , int clientId ){
    Client* temp;
    if( !clientHead) return NULL;
    if(clientHead->client.clientId > clientId ){
        temp = searchClientById(clientHead->left , clientId );
    }
    else if(clientHead->client.clientId < clientId){
        temp = searchClientById(clientHead->right , clientId );
    }
    else return &clientHead->client;
    
    return temp;
}



/* adding new client to Linked list and sort bi ID */
void addNode(D_Llinked_List* list , Client* newClient ){
    Node* node = ALLOC( Node , 1 );
    Node* head = list->head;
    int clientId = newClient->clientId;
    node->client = *newClient;

    while( head->client.branchId  <= clientId || !head->next  ){
        head = head->next;
    }
    if(head->client.clientId > clientId){
        node->prev = head->prev;
        head->prev = node;
        node->next = head;
        if(!node->prev){
            head->prev->next = node;
            list->head = node;
        }
    }
    else {
        head->next = node;
        node->prev = head;
    }
}


/********************************************************/
/******              delete clients                ******/

/*  delete all the branch clients*/
Tree* deleteAllBranchClients(Tree* clientHead  )
{
    return remove_All_nodes(clientHead , &freeClient );
}

/* delete specific client */
Tree* deleteClient( Tree* clientHead , Client* client )
{
    return delete_node_tree( clientHead , client , &cmp_clients_id , &freeClient);
}

/* free all the allocated blockes in the client*/
void freeClient(Tree* clientNode){
    updateDeleteClient(clientNode->client);
    FREE(clientNode->client.nameOfBank);
    FREE(clientNode->client.firstNameOfClient);
    FREE(clientNode->client.lastNameOfClient);
    FREE(clientNode);
    return;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

/* compare client by id */
int cmp_clients_id(Client* c1 , Client* c2)
{
    if(c1->clientId > c2->clientId) return 1
    if(c1->clientId < c2->clientId) return -1
    return 0;
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


/****************************************************************/
/*                         search branch                        */

Branch* searchBranchById( Branch_tree* branchHead , int  branchId ){
    
    Branch* temp;
    
    if( !branchHead) return NULL;
    if(branchHead->branch.branchId > branchId ){
        temp = searchBranchById(branchHead->left , branchId );
    }
    else if(branchHead->branch.branchId < branchId){
        temp = searchBranchById(branchHead->right , branchId );
    }
    else return &branchHead->branch;
    
    return temp;
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

void updateDeleteClient(Client client ){
    Branch* branch = searchBranchById(bank.branchHead , client.branchId );
    updateNumberOfBankClients( &bank.numberOfBankClients , DELETE , NON );
    updateSumOfAllBankClients(&bank.sumOfAllBankClients , -(client.acountBalance - client.loanBalance) , NON );
    /* branch updates */
    updateNumberOfBranchClients( &branch->numberOfBranchClients , DELETE , NON);
    updateSumOfAllBranchClients(&branch->sumOfAllBranchClients , -(client.acountBalance - client.loanBalance) , NON);
    return;
}

/*update the branch with the new client in the bank*/
void updateNewClientToBranch( Branch *branch  , Client tempClient ){
    updateNumberOfBranchClients( &(branch -> numberOfBranchClients) , ADD , NON );
    updateSumOfAllBranchClients( &(branch -> sumOfAllBranchClients) , (tempClient.acountBalance) , NON);
    updateNumberOfBankClients( &(bank.numberOfBankClients) , ADD , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , (tempClient.acountBalance) , NON);
    printf("\nClient number %d is created!!!!!!\n\n",tempClient.accountNumber);
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
void repayClientLoans(Client* client , Branch* branch ){

    double deposit;
    
    if(client->loanBalance >= 0 ){
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

/*Print the parameters of the client*/
void printClientDetails(Client* client){
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


void printClientId(Tree* clientHead ){
    if(!clientHead) return;
    printClientId(clientHead->left);
    printf("Client ID : [%d]\n" , clientHead->client.clientId);
    printClientId(clientHead->right);
    return;
}
