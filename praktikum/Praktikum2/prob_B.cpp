/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C++
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int count;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    BSTNode * findd(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return NULL;
        
        if (temp->key == value)
            return temp;
        else
            return NULL;
    }

    void insert(int value) {
        // if (!find(value)) {
            
        BSTNode * finddd = findd(value);
        if (finddd == NULL) {
            _root = __insert(_root, value);
            _size++;
        }else {
            finddd->count+=1;
        }
    }

    void remove(int value) {
        BSTNode * finddd = findd(value);

        if (finddd->count == 1) {
            _root = __remove(_root, value);
            _size++;
        } else {
            finddd->count--;
        }
        // if (find(value)) {
        //     _root = __remove(_root, value);
        //     _size++;
        // }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

private:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->count = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d(%d) ", root->key,root->count);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d(%d) ", root->key,root->count);
            
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d(%d) ", root->key,root->count);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    int comNum;
    scanf("%d", &comNum);

    char command[100];
    int num;
    // while (true) {
    for (int i = 0; i < comNum; i++) {
        scanf("%s %d",&command,&num);
        if (strcmp(command,"insert") == 0) {
            // printf("%s %d",command,num);
            set.insert(num);
        }
        if (strcmp(command,"remove") == 0) {
            set.remove(num);
        }
        if (strcmp(command,"inorder") == 0) {
            set.traverseInorder();
        }
        if (strcmp(command,"preorder") == 0) {
            set.traversePreorder();
        }
        if (strcmp(command,"postorder") == 0) {
            set.traversePostorder();
        }
        // printf("%s\n",command);


    }

    // set.insert(6);
    // set.insert(1);
    // set.insert(8);
    // set.insert(12);
    // set.insert(1);
    // set.insert(3);
    // set.insert(7);

    // set.traverseInorder();
    // puts("");

    // set.remove(1);
    // set.remove(6);
    // set.remove(8);
    // set.traverseInorder();
    // puts("");
    // return 0;
}