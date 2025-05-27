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




int findPreOrderR(BSTnode *now,int val) {
    if (now == NULL) {
        return -1;
    }
    if (now->val == val) {
        return val;
    }


    int leftRes = findPreOrderR(now->left,val); 
    if (leftRes != -1) return leftRes;
    
    return findPreOrderR(now->right,val);




}
int findPostOrderR(BSTnode *now,int val) {
    
    
    int leftRes = findPreOrderR(now->left,val); 
    if (leftRes != -1) return leftRes;
    
    
    int rightRes = findPreOrderR(now->right,val); 
    if (rightRes != -1) return rightRes;

    if (now->val == val) return val;
    return -1;


}
int findInOrderR(BSTnode *now,int val) {
    int leftRes = findPreOrderR(now->left,val); 
    if (leftRes != -1) return leftRes;
    
    if (now == NULL) return -1;
    if (now->val == val) return val;
    
    int rightRes = findPreOrderR(now->right,val); 
    if (rightRes != -1) return rightRes;



}

int findPreOrder(BST*bst,int val) {
    return findPreOrderR(bst->root,val);
}
int findPostOrder(BST*bst,int val) {
    return findPostOrderR(bst->root,val);
}
int findInOrder(BST*bst,int val) {
    return findInOrderR(bst->root,val);
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
    
    

    printf("\n%d",findPreOrder(bst,45));
    printf("\n%d",findInOrder(bst,45));
    printf("\n%d",findPostOrder(bst,45));
    printf("\n%d",findPreOrder(bst,4));
    printf("\n%d",findInOrder(bst,4));
    printf("\n%d",findPostOrder(bst,0));
}