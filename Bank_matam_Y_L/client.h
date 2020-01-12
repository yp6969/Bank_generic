#ifndef CLIENT_H
#define CLIENT_H

#include "updates.h"

#define FOREVER while(1)
#define IS_LEAF(t) (!(t)->left && !(t)->right)
#define SWAP( a , b , c) c = a , a = b, b = c;

#define TRUE 1
#define FALSE 0


/*  functions that handle the client tree data*/
void addClientToBranch_t(Branch* branch);
void createBranchClientTree( Client_tree* clientHead );
Client_tree * addNewClientToBranch(Client_tree * clientHead , Client client ) ;
Client* createNewClient(int btanchId);


/* searching clients */
void findClient(D_Llinked_List* list );
void findClientInBankByAcountBalance(D_Llinked_List* list ,Branch_tree* branchHead ,  int acountBalance );
void findClientInBranchByAcountBalance(D_Llinked_List* list , Client_tree* clientHead , int acountBalance);
Client* searchClientByIdInBank(Branch_tree* branchHead ,  int clientId );
Client* searchClientById( Client_tree* clientHead , int clientId );
void addNode(D_Llinked_List* list , Client* newClient );


/*      searching branch       */
Branch* searchBranchById(Branch_tree* branchHead , int branchId );


/*  deleting clients */
Client_tree* deleteAllBranchClients(Client_tree* clientHead );
Client_tree* deleteClient(Client_tree* clientHead , int clientId );
Client_tree* findDeleteClient(Client_tree* clientNode , int clientId , Client_tree** parent);
Client_tree* find_max_client(Client_tree* clientNode);
Client_tree* find_min_client(Client_tree* clientNode);
void freeClient(Client_tree* clientNode);


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
void printClientId(Client_tree* clientHead );


#endif
