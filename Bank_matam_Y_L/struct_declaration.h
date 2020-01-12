#ifndef SRTUCT_DECLARATION_H
#define SRTUCT_DECLARATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*declatation of all the struct*/

/*********************************************/
/*                Generic Tree               */

typedef struct Tree_t{
    void* key;
    struct Tree_t* left;
    struct Tree_t* right;
}Tree;

/************************************************/
/*     ********    client data      *********   */

typedef struct {
    char *firstNameOfClient;
    char *lastNameOfClient;
    char *nameOfBank;
    int clientId;
    int branchId;
    int accountNumber;
    double authorizedException;
    double acountBalance;
    double loanBalance;
    double saveBlance;
}Client;

/*************************************************/
/*    ******       branch data        *******   */

typedef struct Branch_t{
    char* nameOfBank;
    char* branchName;
    int branchId;
    int numberOfBranchClients;
    double sumOfAllBranchClients;
    double branchProfitOfLastYear;
    int numberOfBranchLoans;
    int openHour;
    int closeHour;
    Tree* clientHead;
} Branch;

 /* branch head to the top of the tree */


/*******************************************/
/*   ******     Bank data     ********    */

typedef struct Bank_t{
    char* nameOfBank;
    int numberOfBranch;
    int numberOfBankClients;
    double sumOfAllBankClients;
    double profitOfLastYear;
    int numberOfActiveLoans;
    Tree* branchHead;
} Bank;

 Bank bank;

/*******************************************/
/*   linked list for other information     */

typedef struct Node_t{
    Client client;
    struct Node_t* prev;
    struct Node_t* next;
}Node;


typedef struct {
    Node* head;
}D_Llinked_List;


#endif