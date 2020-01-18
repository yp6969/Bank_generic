#ifndef CLIENT_H
#define CLIENT_H

#include "generics.h"




/*  functions that handle the client tree data*/

/* adding client */
void create_Branch_Client_Tree(Tree* clientHead);
Client* create_New_Client( int branchId) ;
void add_Client_To_Branch_t(Branch* branch);
int is_Branch_Empty(Tree* clientHead);
int is_Branch_Full(int numberOfBranchClients);


/* searching clients */
void find_Client(D_Llinked_List* list );
Client* search_Client_By_Id_In_Bank(Tree* branchHead , int clientId , Tree* (*get_tree)(void*) );
Client* search_Client_By_Id_in_branch( Tree* clientHead , int clientId);
void find_Client_In_Bank_By_Acount_Balance(D_Llinked_List* list ,Tree* branchHead , double acountBalance);
Branch* search_Branch_By_Id( Tree* branchHead , int branchId);


/*  deleting clients */
Tree* delete_All_Branch_Clients(Tree* clientHead  );
Tree* delete_Client( Tree* clientHead , int clientId );
void free_Client(void* client);

/* compare clients */
int cmp_clients_id(void* c1 , void* c2);
int cmp_clients_accountBalance(void* c1 , void* c2 );
int cmp_balance_loan(void* client);
int cmp_branchs_id(void* b1 , void* b2);
double get_balance(void* client);
Tree* get_client_head(void* branch);



/* update the deatails of the client */
void updateClientParameters(Client** client , int banchId);
void update_Delete_Client(Client* client );
void update_New_Client_To_Branch( Branch *branch  , Client* tempClient );


/*function's manage all client changes*/
void depositeMoneyToClientAccount(Client* client);
void depositeMoneyToSave(Client* client);
void loanToClient(Client* client , Branch* branch);
void repayClientLoans(Client* client , Branch* branch );
int chekLoanRequest(double authorizedException , double deposite , double loanBalance);

/* print client deatails  */
void print_all_Client_Details(Tree* clientTree);
void print_all_Client_Id(Tree* clientTree);
void print_all_Client_Acount_Number_And_Balance(Tree* clientTree);
void print_Client_Details(void* client);
void print_Client_Id(void* c );
void print_Client_account_number_balance(void* c );



#endif
