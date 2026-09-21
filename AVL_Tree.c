#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *root) {
    if (root == NULL)
        return 0;
    return root->height;
}

struct Node* createNode(int data) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void updateHeight(struct Node *root) {
    if (root != NULL) {
        root->height = 1 +
            max(height(root->left), height(root->right));
    }
}

int getBalance(struct Node *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct Node* LLRotation(struct Node *root) {
    struct Node *x = root->left;
    struct Node *T2 = x->right;
    x->right = root;
    root->left = T2;
    updateHeight(root);
    updateHeight(x);
    return x;
}

struct Node* RRRotation(struct Node *root) {
    struct Node *x = root->right;
    struct Node *T2 = x->left;
    x->left = root;
    root->right = T2;
    updateHeight(root);
    updateHeight(x);
    return x;
}

struct Node* LRRotation(struct Node *root) {
    root->left = RRRotation(root->left);
    return LLRotation(root);
}

struct Node* RLRotation(struct Node *root) {
    root->right = LLRotation(root->right);
    return RRRotation(root);
}

struct Node* balance(struct Node *root) {
    if (root == NULL)
        return root;
    updateHeight(root);
    int bf = getBalance(root);
    if (bf > 1) {
        if (getBalance(root->left) >= 0)
            return LLRotation(root);
        else
        return LRRotation(root);
    }
    if (bf < -1) {
        if (getBalance(root->right) <= 0)
            return RRRotation(root);
        else
            return RLRotation(root);
    }
    return root;
}

struct Node* insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;
    return balance(root);
}

struct Node* deleteNode(struct Node* root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct Node* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return balance(root);
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {

    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 28);
    root = insert(root, 40);
    root = insert(root, 50);
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    return 0;
}


