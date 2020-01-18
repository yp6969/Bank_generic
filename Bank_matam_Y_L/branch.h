#ifndef BRANCH_H
#define BRANCH_H

#include "client.h"
#define BANK_AMALIM 

/***************************************/
/*  functions that handle the tree data*/

void create_Branch_Tree();
void add_New_Branch_t();
Branch* create_New_Branch();
int is_Bank_Empty();
int is_Bank_Full();


/************************************/
/*          delete branch          */
Tree* delete_All_Branchs(Tree* branchTree);
Tree* delete_Branch(Tree* branchTree , int branchId);
void free_Branch(void *branch);


/************************************/
/*             compare              */
double client_in_Branch(void* b);


/*******************************************/
/* function's is manage all branch changes*/
void update_Branch_Parameters(Branch* branch);/*general*/
double calculateBranchProfitOfLastYear(Branch* branch);


int client_Number_With_Given_Balance(Tree *clientHead , double Balance , double (*get_balance)(void*));
int client_Number_With_Bigger_Loans_Then_Balance(Tree *clientHead , int (*cmp_balance_loan)(void*));

/* print branch deatails */
void print_all_Branch_Details(Tree* branchTree);
void print_all_Branch_Id(Tree* branchTree);
void print_Branch_Details(void* branch);
void print_Branch_Id(void* b);

#endif