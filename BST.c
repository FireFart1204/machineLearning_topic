#include<stdio.h>
#include<stdlib.h>
#include<conio.h.>

struct node{
    int data;
    struct node*left;
    struct node*right;

};

struct node* creatNode(int data){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;newnode->right = NULL;
    return newnode;
    
}

struct node* insert(struct node *root,int data){
    if (root == NULL){

        return creatNode(data);
    }

    if (data < root->data){
        root->left = insert(root->left,data);
    }
    else if(data> root->data){
        root->right = insert(root->right,data);
    }

    return root;
}

struct node*search(struct node* root,int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(key < root->data){
        return search(root->left,key);

    }
    return search(root->right,key);
}

void inOrderTraversal(struct node* root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d->",root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    int key = 40;
    struct node* result = search(root, key);

    if (result) {
        printf("%d found in the BST.\n", key);
    } else {
        printf("%d not found in the BST.\n", key);
    }

    return 0;
}