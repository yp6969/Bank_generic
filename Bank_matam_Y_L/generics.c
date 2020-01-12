#include "generics.h"

/* create new tree*/
void create_tree( Tree* head ){
    head = NULL;
}

/*  adding node */
Tree * add_new_node( Tree* head ,  void* key ) {
    if (!head) {
        Tree *newNode = ALLOC( Tree , 1 );    
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    /*if the branch id is alredy exsist do not add nothing and return the current tree */
    if (key.Id == head->key->Id){
        printf("\n\tThis is already exsist try again/t/n");
        return head;
    }
    else if (key->Id > head->key->Id) {
        head->right = add_new_node(head->right , key); 
    } else if ( key->Id < head->key->Id ) {
        head->left = add_new_node( head->left , key);
    }
    return head;
}


/* deleting all the wanted nodes in the bank/branch  */
Tree* remove_All_nodes(Tree* node){
    Tree* temp;
    if(!node) return NULL;
    temp = remove_All_nodes(node->left);
    temp = remove_All_nodes(node->right);
    free_t(node);
    return temp;
}




void tree_to_array( D_Llinked_List* list, Tree* treeHead ){
    Node* head = list->head;
    if(treeHead == NULL ) return;
    tree_to_array( list , treeHead->left );
    Node* node = ALLOC( Node , 1 );
    node->next = head;
    head->prev = node;
    node->key = treeHead->key;
    list->head = node;
    tree_to_array( list , treeHead->right );

}




/* delete spesific branch by id*/
Tree* delete_node_tree(Tree* t , int id ){
    Tree *node , *node_2 , *parent;
    void* tempNode;
    parent = NULL;
    node = find_delete_node( t , id , &parent);/* searching */
    if(!node){
        printf("Branch not found\n");
        return t;
    }
    if(IS_LEAF(node)){
        if(parent){
            if(parent->left == node) parent->left = NULL;
            else parent->right = NULL;
            free_t(node);/* free the deleted space */
            return t;
        }
        else{
            free_t(node);
            return NULL;
        }
    }
    else{
        if(node->left){
            node_2 = find_Max_Branch(node->left);
            SWAP(node->key , node_2->key , tempNode);
            node->left = delete_node_tree(node->left , id );
        }
        else{
            node_2 = find_Min_Branch(node->right);
            SWAP(node->key , node_2->key , tempNode );
            node->right = delete_node_tree(node->right , id );
        }
    }
    return t;
}


Tree* findDeleteClient(Tree* clientNode , int clientId , Tree** parent){
    if(!clientNode) return NULL;
    if(clientNode->client.clientId == clientId){
        return clientNode;
    }
    if(clientNode->client.clientId > clientId){
        if(parent) *parent = clientNode;
        return findDeleteClient(clientNode->left , clientId , parent);
    }
    if(parent) *parent = clientNode;
    return findDeleteClient(clientNode->right , clientId , parent);
}

/*  finds the bigest client ID in the tree*/
Tree* find_max_client(Tree* clientNode){
    if(!clientNode) return NULL;
    if(clientNode->right){
        return find_max_client(clientNode->right);
    }
    return clientNode;
}

/*  finds the lowest client ID in the tree*/
Tree* find_min_client(Tree* clientNode){
    if(!clientNode) return NULL;
    if(clientNode->left){
        return find_max_client(clientNode->left);
    }
    return clientNode;
}