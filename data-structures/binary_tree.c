#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} Tree;


Tree* createNode(int value) {
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* insert(Tree* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }

    if(value < root->data) {
        root->left = insert(root->left, value);
    } else if((value) > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Tree* root) {
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Tree* root) {
    if(root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree* root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

Tree* search(Tree* root, int value) {
    if(root == NULL) return NULL;

    if(value < root->data) {
        return search(root->left, value);
    } else if(value > root->data) {
        return search(root->right, value);
    } else if (value == root->data) {
        return root;
    }
    return NULL;
}


int main() {
    Tree* root = NULL;
    root = insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 45);
    insert(root, 80);
    insert(root, 100);

    printf("In Order:\n");
    inorder(root);
    printf("\n");

    printf("Pre Order:\n");
    preorder(root);
    printf("\n");

    printf("Post Order:\n");
    postorder(root);
    printf("\n");

    Tree* s = search(root, 45);
    if(s!=NULL) {
        printf("Value found: %d\n", s->data);
    } else {
        printf("Value not found\n");
    }
}