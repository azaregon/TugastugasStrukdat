#include <stdio.h>
#include <stdlib.h>


typedef struct BSTNode {
    int val;
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

// BSTnode * preOrderFind(BSTnode * node,int val) {
//     if (node == val) {
//         return node;
//     }

//     preOrderFind(node->left);
//     preOrderFind(node->right);
// }

int workerOfDelete(BST * bst, int val) {
    // BSTnode * toDel = preOrderFind(bstnode);
    BSTnode * findNowParent = NULL;
    BSTnode * findNow = bst->root;


    while (1) {
        if (findNow == NULL) {
            return -1;
        }

        if (findNow->val == val){
            break;
        }

        if (val > findNow->val) {
            findNowParent = findNow;
            findNow = findNow->right;
        } else if (val < findNow->val) {
            findNowParent = findNow;
            findNow = findNow->left;
        }


    }

    BSTnode * foundParent = findNowParent;
    BSTnode * found = findNow;
    
    if (found == NULL) return -1; // val not found


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
                found->val = successorNow->val;
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

void insert(BST * bst, int val) {
    BSTnode * newnode = malloc(sizeof(BSTnode));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if (bst->root == NULL) {
        bst->root = newnode;
        return;

    } else {
        BSTnode * now = bst->root;
        while (1) {


            if (val < now->val)  {
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
    printf("%d ", now->val);
    if (now->left != NULL) {
        preOrderTraversalRecr(now->left);
    }
    if (now->right != NULL) {
        preOrderTraversalRecr(now->right);
    } 

}


int preOrderTraversal(BST * bst) {
    if (bst->root == NULL) {
        return 0;
    }

    preOrderTraversalRecr(bst->root);
}



int main() {
    BST * bst = init_bst();

    insert(bst,40);
    insert(bst,30);
    insert(bst,50);
    insert(bst,25);
    insert(bst,35);
    insert(bst,45);
    insert(bst,60);


    preOrderTraversal(bst);
    printf("\n");
    
    workerOfDelete(bst,40);
    preOrderTraversal(bst);
    printf("\n");


    printf("\n%d\n",findsmallest(bst->root)->val);
}