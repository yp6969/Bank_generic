#ifndef BRANCH_H
#define BRANCH_H

#include "client.h"
#define BANK_AMALIM 

/***************************************/
/*  functions that handle the tree data*/

void addNewBranch_t();
void createBranchTree();
Branch* createNewBranch();
Branch_tree * addNewBranchToTree(Branch_tree* branchHead , Branch branch );
int isBranchEmpty(Client_tree* clientHead);
int isBranchFull(int numberOfBranchClients);


/************************************/
/*          delete branch          */
Branch_tree* deleteAllBranchs(Branch_tree* branchTree);
Branch_tree* deleteBranch(Branch_tree* branchTree , int branchId );
Branch_tree* findDeletedBranch(Branch_tree* branchTree , int branchId , Branch_tree** parent);
Branch_tree* find_Max_Branch(Branch_tree *branchNode);
Branch_tree* find_Min_Branch(Branch_tree *branchNode);
void freeBranch(Branch_tree *branchTree);


/*******************************************/
/* function's is manage all branch changes*/
void updateBranchParameters(Branch* branch);/*general*/
double calculateBranchProfitOfLastYear(Branch* branch);
void printBranchDetails(Branch* branch);
void printClientAcountNumberAndBalance(Client_tree* clientHead);
void printBranchsId(Branch_tree* branchHead);
int clientNumberWithGivenBalance(Client_tree *clientHead , double Balance);
int clientNumberWithBiggerLoansThenBalance( Client_tree *clientHead );

#endif
