#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} nd;

nd* createnode(int value) {
    nd* p = (nd*)malloc(sizeof(nd));
    if (p == NULL) {
        return NULL;
    }
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

nd* insert(nd *root, int value) {
    if (root == NULL) {
        return createnode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(nd* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(nd *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(nd* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    nd* root = NULL;
    int n;
    printf("enter number of nodes : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("enter data : ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\ninorder : ");
    inorder(root);
    printf("\npreorder : ");
    preorder(root);
    printf("\npostorder : ");
    postorder(root);
    printf("\n");

    return 0;
}
