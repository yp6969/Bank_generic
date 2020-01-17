#ifndef BRANCH_H
#define BRANCH_H

#include "client.h"
#define BANK_AMALIM 

/***************************************/
/*  functions that handle the tree data*/

void create_Branch_Tree(Tree* branchHead);
void add_New_Branch_t();
Branch* create_New_Branch();
int is_Branch_Empty(Client_tree* clientHead);
int is_Branch_Full(int numberOfBranchClients);


/************************************/
/*          delete branch          */
Tree* delete_All_Branchs(Tree* branchTree);
Tree* delete_Branch(Tree* branchTree , Branch* branch);
void free_Branch(Branch_tree *branchTree);


/************************************/
/*          search and compare          */
Branch* search_Branch_By_Id( Tree* branchHead );
int cmp_branchs_id(Branch* b1 , Branch* b2);

/*******************************************/
/* function's is manage all branch changes*/
void updateBranchParameters(Branch* branch);/*general*/
double calculateBranchProfitOfLastYear(Branch* branch);
int clientNumberWithGivenBalance(Tree *clientHead , double Balance);
int clientNumberWithBiggerLoansThenBalance(Tree *clientHead);
void print_all_Branch_Details(Tree* branchTree);
void print_all_Client_Id(Tree* branchTree);
void print_Branch_Details(Branch* branch);
void print_Branch_Id(Branch* b);

#endif