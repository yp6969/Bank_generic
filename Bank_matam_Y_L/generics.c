#include "generics.h"


/***********************************************************************************/
/*****                           ADD FUNCTIONS                              *****/

/* create new tree*/
void create_tree( Tree* head ){
    head = NULL;
}

/*  adding node */
Tree * add_new_node( Tree* head ,  void* key , int (*cmp)(void* , void*)) {
    if (!head) {
        Tree *newNode = ALLOC( Tree , 1 );    
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    /*if the branch id is alredy exsist do not add nothing and return the current tree */
    if ((*cmp)(key , head->key) == 0 ){
        printf("\n\tThis is already exsist try again/t/n");
        return head;
    }
    else if ( (*cmp)(key , head->key) == 1 ) {
        head->right = add_new_node(head->right , key , cmp);
    } else if ( (*cmp)(key , head->key) == -1 ) {
        head->left = add_new_node( head->left , key , cmp);
    }
    return head;
}

/***********************************************************************************/
/*****                           DELETE FUNCTION                              *****/

/* deleting all the wanted nodes in the bank/branch  */
/* used ass free list!!!!!!!!!!!!!!!!!  */
Tree* remove_All_nodes(Tree* node , void (*free_t)(void*) ){
    Tree* temp;
    if(!node) return NULL;
    temp = remove_All_nodes(node->left , free_t);
    temp = remove_All_nodes(node->right , free_t);
    free_t(node);
    return temp;
}


/* delete spesific key in the tree */
Tree* delete_node_tree(Tree* t , void* key , int (*cmp)(void* , void*) , void (*free_key)(void*)){
    Tree *node , *node_2 , *parent;
    void* tempNode;
    parent = NULL;
    node = find_delete_node( t , key , &parent , cmp );/* searching */
    if(!node){
        printf("Branch not found\n");
        return t;
    }
    if(IS_LEAF(node)){
        if(parent){
            if(parent->left == node) parent->left = NULL;
            else parent->right = NULL;
            (*free_key)(node->key);/* free the tree key */ 
            FREE(node);
            return t;
        }
        else{
            (*free_key)(node->key); /* free the tree key */ 
            FREE(node);
            return NULL;
        }
    }
    else{
        if(node->left){
            node_2 = find_max(node->left);
            SWAP(node->key , node_2->key , tempNode);
            node->left = delete_node_tree(node->left , key , cmp , free_key);
        }
        else{
            node_2 = find_min(node->right);
            SWAP(node->key , node_2->key , tempNode );
            node->right = delete_node_tree(node->right , key , cmp , free_key);
        }
    }
    return t;
}

/*** find the wanted node tree to delete ***/
/* using the compare function (generic) */
Tree* find_delete_node(Tree* t , void* key , Tree** parent , int (*cmp)(void* , void*) ){
    if(!t) return NULL;
    if((*cmp)(t->key , key ) == 0 ){
        return t;
    }
    if( (*cmp)(t->key , key ) == 1 ){
        if(parent) *parent = t;
        return find_delete_node(t->left , key , parent , cmp);
    }
    if(parent) *parent = t;
    return find_delete_node(t->right , key , parent , cmp);
}

/*  finds the bigest ID in the tree*/
Tree* find_max(Tree* node){
    if(!node) return NULL;
    if(node->right){
        return find_min(node->right);
    }
    return node;
}


/*  finds the lowest ID in the tree*/
Tree* find_min(Tree* node){
    if(!node) return NULL;
    if(node->left){
        return find_max(node->left);
    }
    return node;
}




/***********************************************************************************/
/*****                           FIND FUNCTION                              *****/


/* find client in the bank By any value*/
void find_Client_In_Bank_By_Any(D_Llinked_List* list ,Tree* branchHead ,  void* key , int(*cmp)(void* , void*) , int (*cmp_id)(void* , void*) , Tree* (*head)(void*)){
    if(!branchHead) return;
    find_Client_In_Bank_By_Any(list , branchHead->left , key , cmp , cmp_id , head);
    find_node_key(list , (*head)(branchHead->key) , key , cmp , cmp_id );
    find_Client_In_Bank_By_Any(list , branchHead->right , key , cmp , cmp_id , head);
}


/* find element By any value and insert to linked list*/
/* not sorted key */
void find_node_key(D_Llinked_List* list , Tree* head , void* key , int(*cmp)(void* , void*) , int (*cmp_id)(void* , void*)){
    if(!head) return;
    find_node_key(list , head->left , key , cmp , cmp_id);
    if((*cmp)(head->key , key ) == 0 )
        add_Node_to_list(list , head->key , cmp_id );
    find_node_key(list , head->right , key , cmp , cmp_id);
}



/* find element By int number */
/* sorted  */
void* sorted_find( Tree* head , void* key , int (*cmp)( void* , void* ))
{
    void* temp;
    if( !head) return NULL;
    if((*cmp)(head->key , key ) == 1){
        temp = sorted_find(head->left , key , cmp );
    }
    else if((*cmp)(head->key , key ) == -1){
        temp = sorted_find(head->right , key , cmp );
    }
    else return head->key;
    
    return temp;
}

/*******************************************************************************/
/*******                          tree to list                           *******/

void tree_to_array(D_Llinked_List* list , Tree* treeHead , int (*cmp)(void* , void*) ){
    if(!treeHead) return;
    tree_to_array( list , treeHead->left , cmp);
    add_Node_to_list( list , treeHead->key , cmp);
    tree_to_array( list , treeHead->right , cmp);
}



/*******************************************************************************/
/*******                       add node to list                        *******/

/* adding new client to Linked list and sort by ID */
void add_Node_to_list(D_Llinked_List* list , void* key , int (*cmp)(void*, void*)){
    Node* node = ALLOC( Node , 1 );
    Node* head = list->head;
    node->key = key;

    while((*cmp)(head->key , key ) <= 0 || !head->next  )
    {
        head = head->next;
    }
    if( (*cmp)(head->key , key ) == 1 )
    {
        node->prev = head->prev;
        head->prev = node;
        node->next = head;
        if(!node->prev){
            head->prev->next = node;
            list->head = node;
        }
    }
    else {
        head->next = node;
        node->prev = head;
    }
}

/***********************************************************************************/
/*****                           Avereg FUNCTION                              *****/

double avarage_Key(Tree* t , int* numOfNodes , double (*getKey)(void*)){
    
    int num_l , num_r;
    double avg_l , avg_r;
    
    if( !t ){
        *numOfNodes = 0;
        return 0;
    }
    
    avg_l = avarage_Key( t -> left , &num_l , getKey);
    avg_r = avarage_Key( t -> right , &num_r  , getKey);
    
    *numOfNodes = num_l + num_r + 1;
    return ( (avg_l * num_l) + (avg_r * num_r) + getKey(t->key) ) / *numOfNodes;
}

/***********************************************************************************/
/*****                           print FUNCTION                              *****/

/*print all the keys */
void print_keys(Tree* head , void (*print)(void*)){
    if(!head) return ;
    print_keys(head->left , print);
    (*print)(head->key);
    print_keys(head->right , print);
}
