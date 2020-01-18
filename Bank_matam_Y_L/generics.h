#ifndef GENERICS_H
#define GENERICS_H

#include "updates.h"


#define FOREVER while(1)
#define IS_LEAF(t) (!(t)->left && !(t)->right)
#define SWAP( a , b , c) c = a , a = b, b = c;

#define TRUE 1
#define FALSE 0

/********************************************************************************/
/*****                           generic function                          *****/

/*          adding nodes        */
void create_tree( Tree* head );
Tree * add_new_node( Tree* head ,  void* key , int (*cmp)(void* , void*)) ;

/*          delete nodes        */
Tree* remove_All_nodes(Tree* node , void (*free_t)(void*) );
Tree* delete_node_tree(Tree* t , void* key , int (*cmp)(void* , void*) , void (*free_t)(void*));
Tree* find_delete_node(Tree* t , void* key , Tree** parent , int (*cmp)(void* , void*) );


/*          sreaching nodes        */
void find_Client_In_Bank_By_Any(D_Llinked_List* list ,Tree* branchHead ,  void* key , int(*cmp)(void* , void*) , int (*cmp_id)(void* , void*) , Tree* (*head)(void*));
void find_node_key(D_Llinked_List* list , Tree* head , void* key , int(*cmp)(void* , void*) , int (*cmp_id)(void* , void*));
Tree* find_max(Tree* node);
Tree* find_min(Tree* node);
void* sorted_find( Tree* head , void* key , int (*cmp)( void* , void* ));


/*          convertng rtee to list        */
void tree_to_array(D_Llinked_List* list , Tree* treeHead , int (*cmp)(void* , void*) );
void add_Node_to_list(D_Llinked_List* list , void* key , int (*cmp)(void*, void*));


/*          averege nodes key       */
double avarage_Key(Tree* t , int* numOfNodes , double (*getKey)(void*));


/*          prins nodes keys        */
void print_keys(Tree* head , void (*print)(void*));



#endif