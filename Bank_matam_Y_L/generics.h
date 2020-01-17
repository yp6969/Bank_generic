#ifndef GENERICS_H
#define GENERICS_H

#include "updates.h"

/********************************************************************************/
/*****                           generic function                          *****/

/*          adding nodes        */
void create_tree( Tree* head );
Tree * add_new_node( Tree* head ,  void* key , int (*cmp)(void* , void*)) ;

/*          delete nodes        */
Tree* remove_All_nodes(Tree* node , void (*free_t)(Tree*) );
Tree* delete_node_tree(Tree* t , void* key , int (*cmp)(void* , void*) , void (*free_t)(Tree*));
Tree* find_delete_node(Tree* t , void* key , Tree** parent , int (*cmp)(void* , void*) );


/*          sreaching nodes        */
void find_Client_In_Bank_By_Any(D_Llinked_List* list ,Tree* branchHead ,  void* key , int(*cmp)(void* , void*) , int (*cmp_id)(void* , void*) );
void find_node_key(D_Llinked_List* list , Tree* head , void* key , int(*cmp)(void* , void*) , int (*cmp_id)(void* , void*));
void* sorted_find( Tree* head , void* key , int (*cmp)( void* , void* ));


/*          convertng rtee to list        */
void tree_to_array(D_Llinked_List* list , Tree* treeHead , int (*cmp)(void* , void*) );
void add_Node_to_list(D_Llinked_List* list , void* key , int (*cmp)(void*, void*));


/*          averege nodes key       */
double avarage_Key(Node* t , int* numOfNodes , double (*getKey)(void*));


/*          prins nodes keys        */
void print_keys(Tree* head , void (*print)(void*));



#endif