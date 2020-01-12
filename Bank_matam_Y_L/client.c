#include "client.h"


/******************************************************/
/*  *********    adding client tree     ***************/

void addClientToBranch_t(Branch* branch){
    Client* tempClient  = createNewClient(branch->branchId);
    branch->clientHead = addNewClientToBranch(branch->clientHead , *tempClient );
    updateNewClientToBranch( branch  , *tempClient );
    FREE(tempClient);
}

/*creating the branch list*/
void createBranchClientTree(Client_tree* clientHead){
    clientHead = NULL;
    return;
}

Client* createNewClient( int branchId ){
    Client* newClient = ALLOC (Client , 1 );
    newClient->acountBalance = 0;
    updateClientParameters( &newClient , branchId );
    return newClient;
} 

/*adding new branch to the branch tree*/
Client_tree * addNewClientToBranch(Client_tree * clientHead , Client client  ) {
    if (!clientHead) {
        Client_tree *newClientNode = ALLOC( Client_tree , 1 );    
        newClientNode->client = client;
        newClientNode->left = newClientNode->right = NULL;
        return newClientNode;
    }
    /*if the branch id is alredy exsist do not add nothing and return the current tree */
    if (client.clientId == clientHead->client.clientId){
        printf("\n\tThis client is already exsist try again/t/n");
        return clientHead;
    }
    else if (client.clientId > clientHead->client.clientId) {
        clientHead->right = addNewClientToBranch(clientHead->right, client); 
    } else if ( client.clientId < clientHead->client.clientId ) {
        clientHead->left = addNewClientToBranch(clientHead->left, client);
    } 
    return clientHead;
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
Client_tree* deleteAllBranchClients(Client_tree* clientHead ){
    Client_tree* tempClient;
    if(!clientHead) return NULL;
    tempClient = deleteAllBranchClients(clientHead->left);
    tempClient = deleteAllBranchClients(clientHead->right);
    freeClient(clientHead);
    return NULL;
}

/*  delete specific client by id*/
Client_tree* deleteClient(Client_tree* clientHead , int clientId ){
    Client_tree *clientNode , *clientNode_2 , *parent;
    Client tempClient;
    parent = NULL;
    clientNode = findDeleteClient( clientHead , clientId , &parent);
    if(!clientNode) return clientHead;
    if(IS_LEAF(clientNode)){
        if(parent){
            if(parent->left = clientNode) parent->left = NULL;
            else parent->right = NULL;
            freeClient(clientNode); 
        }
        else {
            freeClient(clientNode);
            return NULL;
        }
    }
    else{
        if(clientNode->left){
            clientNode_2 = find_max_client(clientNode->left);
            SWAP(clientNode->client , clientNode_2->client , tempClient );
            clientNode->left = deleteClient(clientNode->left , clientId );
        }
        else{
            clientNode_2 = find_min_client(clientNode->right);
            SWAP(clientNode->client , clientNode_2->client , tempClient );
            clientNode->right = deleteClient(clientNode->right , clientId );
        }
    }
    return clientHead;
}

/* finds the wanted client for deletion*/
Client_tree* findDeleteClient(Client_tree* clientNode , int clientId , Client_tree** parent){
    if(!clientNode) return NULL;
    if(clientNode->client.clientId == clientId){
        return clientNode;
    }
    if(clientNode->client.clientId > clientId){
        if(parent) *parent = clientNode;
        return findDeleteClient(clientNode->left , clientId , parent);
    }
    if(parent) *parent = clientNode;
    return findDeleteClient(clientNode->right , clientId , parent);
}

/*  finds the bigest client ID in the tree*/
Client_tree* find_max_client(Client_tree* clientNode){
    if(!clientNode) return NULL;
    if(clientNode->right){
        return find_max_client(clientNode->right);
    }
    return clientNode;
}

/*  finds the lowest client ID in the tree*/
Client_tree* find_min_client(Client_tree* clientNode){
    if(!clientNode) return NULL;
    if(clientNode->left){
        return find_max_client(clientNode->left);
    }
    return clientNode;
}


/* free all the allocated blockes in the client*/
void freeClient(Client_tree* clientNode){
    updateDeleteClient(clientNode->client);
    FREE(clientNode->client.nameOfBank);
    FREE(clientNode->client.firstNameOfClient);
    FREE(clientNode->client.lastNameOfClient);
    FREE(clientNode);
    return;
}


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
    Branch* branch = searchBranchById(branchHead , client.branchId );
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
int chekLoanRequest(double authorizedException , double deposite , double loanBalance){
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

void printClientId(Client_tree* clientHead ){
    if(!clientHead) return;
    printClientId(clientHead->left);
    printf("Client ID : [%d]\n" , clientHead->client.clientId);
    printClientId(clientHead->right);
    return;
}
