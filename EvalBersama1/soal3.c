#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct BSTNode {
    int id;
    char nama[30];
    int harta;
    int isDed;

    struct BSTNode *left;
    struct BSTNode *right;
} BSTnode;


typedef struct BST {
    BSTnode *root;
} BST;



BST * init_bst() {
    BST * newBST = malloc(sizeof(BST));
    newBST->root = NULL;
    return newBST;
}

BSTnode * findsmallest(BSTnode * root) {
    BSTnode * now = root;
    while (1) {
        if (now->left == NULL) {
            return now;
        }


        now = now->left;
    }
}

// BSTnode * preOrderFind(BSTnode * node,int id) {
//     if (node == id) {
//         return node;
//     }

//     preOrderFind(node->left);
//     preOrderFind(node->right);
// }

int workerOfDelete(BST * bst, int id) {
    // BSTnode * toDel = preOrderFind(bstnode);
    BSTnode * findNowParent = NULL;
    BSTnode * findNow = bst->root;


    while (1) {
        if (findNow == NULL) {
            return -1;
        }

        if (findNow->id == id){
            break;
        }

        if (id > findNow->id) {
            findNowParent = findNow;
            findNow = findNow->right;
        } else if (id < findNow->id) {
            findNowParent = findNow;
            findNow = findNow->left;
        }


    }

    BSTnode * foundParent = findNowParent;
    BSTnode * found = findNow;
    
    if (found == NULL) return -1; // id not found


    if (found->left == NULL && found->right == NULL) {
        if (foundParent->left == found) {
            foundParent->left = NULL;
        }
        if (foundParent->right == found) {
            foundParent->right = NULL;
        }
        free(found);
        return 1;
    }

    else if  (found->left == NULL || found->right == NULL) {
        if (foundParent == NULL) {
            if (found->left != NULL) {
                bst->root = found->left;
            }
            if (found->right != NULL) {
                bst->root = found->right;
            }
        } 
        else if (found->left == found) {
            foundParent->left = found->left;
        } else {
            foundParent->right = found->right;
        }
        free(found);
        return 1;
    }

    else {
        BSTnode * successorParent =  found;
        BSTnode * successorNow = found->right;

        while (1) {
            if (successorNow->left == NULL) {
                found->id = successorNow->id;
                if (successorParent->left == successorNow) {
                    successorParent->left = successorNow->right;
                } else {
                    successorParent->right = successorNow->right;
                }
                free(successorNow);
                return 1;
            }
    
            successorParent = successorNow;
            successorNow = successorNow->left;
        }
    }

}

void insert(BST * bst, int id,char nama[], int harta) {
    BSTnode * newnode = malloc(sizeof(BSTnode));
    newnode->id = id;
    strcpy(newnode->nama,nama);
    newnode->harta  = harta;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->isDed = 0;

    if (bst->root == NULL) {
        bst->root = newnode;
        return;

    } else {
        BSTnode * now = bst->root;
        while (1) {


            if (id < now->id)  {
                if (now->left == NULL){
                    now->left = newnode;
                    return;
                }
                now = now->left;
            } else {
                if (now->right == NULL){
                    now->right = newnode;
                    return;
                }
                now = now->right;
            }
        }
    }
}


int preOrderTraversalRecr(BSTnode * now) { 
    printf("%d ", now->id);
    if (now->left != NULL) {
        preOrderTraversalRecr(now->left);
    }
    if (now->right != NULL) {
        preOrderTraversalRecr(now->right);
    } 



}

BSTnode * findPostOrderR(BSTnode *now,int id) {
    if (now == NULL) return NULL;
    
    BSTnode* leftRes = findPostOrderR(now->left,id); 
    if (leftRes != NULL) return leftRes;
    
    BSTnode* rightRes = findPostOrderR(now->right,id); 
    if (rightRes != NULL) return rightRes;

    if (now->id == id) return now;
    return NULL;
}
BSTnode * findPostOrder(BST*bst,int val) {
    return findPostOrderR(bst->root,val);
}

void bagi(BSTnode * node, int hasil_bagi) {
    if (node->isDed) {
        if (node->left == NULL && node->right == NULL) {

        } else if (node->left == NULL) {
            // node->right->harta += bank;
            bagi(node->left,hasil_bagi);
        } else if (node->right == NULL) {
            bagi(node->right,hasil_bagi);
            // node->left->harta += bank;
        } else {
            bagi(node->left,0.6*hasil_bagi);
            bagi(node->right,0.4*hasil_bagi);
            // node->left->harta += 0.6 * bank;
            // node->right->harta += 0.4 * bank;
        }
    } else {
        node->harta +=hasil_bagi;
    }

}


void unalive(BST * bst,int id ) {
    BSTnode * tounalive = findPostOrder(bst,id);
    if (tounalive->isDed) return;

    tounalive->isDed = 1;

    int bank = tounalive->harta;
    tounalive->harta = 0;

    bagi(tounalive, bank);
    // if (tounalive->left == NULL && tounalive->right == NULL) {

    // } else if (tounalive->left == NULL) {
    //     tounalive->right->harta += bank;
    // } else if (tounalive->right == NULL) {
    //     tounalive->left->harta += bank;
    // } else {
    //     tounalive->left->harta += 0.6 * bank;
    //     tounalive->right->harta += 0.4 * bank;
    // }
    
}


int preOrderTraversal(BST * bst) {
    if (bst->root == NULL) {
        return 0;
    }

    preOrderTraversalRecr(bst->root);
}

int inOrderTraversalR(BSTnode * node) {
    if (node->left != NULL) {
        inOrderTraversalR(node->left);
    }
    printf("id: %d\n",node->id);
    printf("nama: %s\n",node->nama);
    printf("isDed: %d\n",node->isDed);
    printf("harta: %d\n",node->harta);
    printf("\n |\n\\ /\n");

    if (node->right != NULL) {
        inOrderTraversalR(node->right);
    }
}
int inOrderTraversal(BST * bst) {
    if (bst->root == NULL) return 0;

    inOrderTraversalR(bst->root);

}



int main() {
    BST * bst = init_bst();

    insert(bst,40,"a",10000);
    insert(bst,30,"a",2000);
    insert(bst,50,"a",3000);
    insert(bst,25,"a",4000);
    insert(bst,35,"a",5000);
    insert(bst,45,"a",6000);
    insert(bst,60,"a",7000);


    preOrderTraversal(bst);
    printf("\n");
    
    // workerOfDelete(bst,40);
    // preOrderTraversal(bst);
    // printf("\n");

    unalive(bst, 50);
    unalive(bst, 40);
    inOrderTraversal(bst);

    


    // printf("%d",findPostOrder(bst,60)->id);
    // printf("\n%d\n",findsmallest(bst->root)->id);
}