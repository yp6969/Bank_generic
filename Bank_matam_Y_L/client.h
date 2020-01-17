#ifndef CLIENT_H
#define CLIENT_H

#include "generics.h"

#define FOREVER while(1)
#define IS_LEAF(t) (!(t)->left && !(t)->right)
#define SWAP( a , b , c) c = a , a = b, b = c;

#define TRUE 1
#define FALSE 0


/*  functions that handle the client tree data*/
void addClientToBranch_t(Branch* branch);
void createBranchClientTree( Tree* clientHead );
Tree * addNewClientToBranch(Tree * clientHead , Client client ) ;
Client* createNewClient(int btanchId);


/* searching clients */
void findClient(D_Llinked_List* list );
void findClientInBankByAcountBalance(D_Llinked_List* list ,Tree* branchHead ,  int acountBalance );
void findClientInBranchByAcountBalance(D_Llinked_List* list , Tree* clientHead , int acountBalance);
Client* searchClientByIdInBank(Tree* branchHead ,  int clientId );
Client* searchClientById( Tree* clientHead , int clientId );
void addNode(D_Llinked_List* list , Client* newClient );


/*      searching branch       */
Branch* searchBranchById(Tree* branchHead , int branchId );


/*  deleting clients */
Tree* deleteAllBranchClients(Tree* clientHead );
Tree* deleteClient(Tree* clientHead , int clientId );
Tree* findDeleteClient(Tree* clientNode , int clientId , Tree** parent);
Tree* find_max_client(Tree* clientNode);
Tree* find_min_client(Tree* clientNode);
void freeClient(Tree* clientNode);


/*function's manage all client changes*/
void updateClientParameters(Client** client , int branchId);/*general*/
void updateNewClientToBranch( Branch *branch  , Client tempClient );
void updateDeleteClient(Client client );
void depositeMoneyToClientAccount(Client* client);
void depositeMoneyToSave(Client* client);
void loanToClient(Client* client , Branch* branch);
void repayClientLoans(Client* client , Branch* branch);
int chekLoanRequest(double authorizedException , double deposit , double loanBalance);
void printClientDetails(Client* client);
void printClientId(Tree* clientHead );


#endif
