//
// Created by 이지호 on 21. 3. 14..
//

#include <cstdlib>
#include <cstdio>

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* root = NULL;

Tree* search(Tree* node, int value) {
    if(node == NULL) {
        return NULL;
    }
    if(node->data == value) {
        return node;
    }
    Tree* result = search(node->left, value);
    if(result != NULL) {
        return result;
    } else {
        return search(node->right, value);
    }
}

void insert(Tree* parent, int value) {
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->left = NULL;
    node->right = NULL;
    node->data = value;
    if(parent->left == NULL) {
        parent->left = node;
    } else if(parent->right == NULL) {
        parent->right = node;
    }
}

void preorder(Tree* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Tree* node) {
    if(node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(Tree* node) {
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main() {
    root = (Tree*)malloc(sizeof(Tree));
    root->left = NULL;
    root->right = NULL;
    root->data = 1;

    insert(root, 2);
    insert(root, 3);
    insert(root->left, 4);
    insert(root->left, 5);
    insert(root->right, 6);
    insert(root->right, 7);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}