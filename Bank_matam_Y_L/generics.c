#include "generics.h"

/* create new tree*/
void create_tree( Tree* head ){
    head = NULL;
}

void* add_new_node(){
    
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
        head->right = add_new_node(head->right , key);
    } else if ( (*cmp)(key , head->key) == -1 ) {
        head->left = add_new_node( head->left , key);
    }
    return head;
}
///////////////////////////////
/////////////////////////////
////////////////////////////
/////////////////////////

/*******************************************************/
/* deleting all the wanted nodes in the bank/branch  */
Tree* remove_All_nodes(Tree* node , void (*free_t)(Tree*) ){
    Tree* temp;
    if(!node) return NULL;
    temp = remove_All_nodes(node->left);
    temp = remove_All_nodes(node->right);
    free_t(node);
    return temp;
}


/* delete spesific element in the tree */
Tree* delete_node_tree(Tree* t , void* element , int (*cmp)(void* , void*) , void (*free_t)(Tree*)){
    Tree *node , *node_2 , *parent;
    void* tempNode;
    parent = NULL;
    node = find_delete_node( t , element , &parent , cmp );/* searching */
    if(!node){
        printf("Branch not found\n");
        return t;
    }
    if(IS_LEAF(node)){
        if(parent){
            if(parent->left == node) parent->left = NULL;
            else parent->right = NULL;
            (*free_t)(node);/* free the deleted space */
            return t;
        }
        else{
            (*free_t)(node);
            return NULL;
        }
    }
    else{
        if(node->left){
            node_2 = find_max(node->left);
            SWAP(node->key , node_2->key , tempNode);
            node->left = delete_node_tree(node->left , element , cmp);
        }
        else{
            node_2 = find_min(node->right);
            SWAP(node->key , node_2->key , tempNode );
            node->right = delete_node_tree(node->right , element , cmp );
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
        return find_delete_node(t->left , key , parent);
    }
    if(parent) *parent = t;
    return find_delete_node(t->right , key , parent);
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



///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void tree_to_array( Tree array[] , Tree* treeHead ){
    if(!treeHead) return;
    tree_to_array( array , treeHead->left );
    array[i] = treeHead;
    tree_to_array( array , treeHead->right );
}
