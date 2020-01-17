#ifndef CLIENT_H
#define CLIENT_H

#include "generics.h"

#define FOREVER while(1)
#define IS_LEAF(t) (!(t)->left && !(t)->right)
#define SWAP( a , b , c) c = a , a = b, b = c;

#define TRUE 1
#define FALSE 0


/*  functions that handle the client tree data*/

/* adding client */
void create_Branch_Client_Tree(Tree* clientHead);
Client* create_New_Client( int branchId) ;
void add_Client_To_Branch_t(Branch* branch);


/* searching clients */
void findClient(D_Llinked_List* list );
Client* search_Client_By_Id_In_Bank(Tree* branchHead );
Client* search_Client_By_Id_in_branch( Tree* clientHead );
void find_Client_In_Bank_By_Acount_Balance(D_Llinked_List* list ,Tree* branchHead );


/*  deleting clients */
Tree* delete_All_Branch_Clients(Tree* clientHead  );
Tree* delete_Client( Tree* clientHead , Client* client );
void free_Client(Tree* clientNode);

/* compare clients */
int cmp_clients_id(Client* c1 , Client* c2);
int cmp_clients_accountBalance(Client* c1 , Client* c2 );


/*function's manage all client changes*/
void updateClientParameters(Client** client , int banchId);
void update_Delete_Client(Client* client );
void update_New_Client_To_Branch( Branch *branch  , Client* tempClient );
void depositeMoneyToClientAccount(Client* client);
void depositeMoneyToSave(Client* client);
void loanToClient(Client* client , Branch* branch);
void repayClientLoans(Client* client , Branch* branch );
int chekLoanRequest(double authorizedException , double deposite , double loanBalance);

/* print client deatails  */
void print_all_Client_Details(Tree* clientTree);
void print_all_Client_Id(Tree* clientTree);
void print_all_Client_Acount_Number_And_Balance(Tree* clientTree);
void print_Client_Details(Client* client);
void print_Client_Id(Client* c );
void print_Client_account_number_balance(Client* c );



#endif
