

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};


struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}


struct node* insertion(struct node**node, int value) {
    if (!*node){
        *node=createNode(value); }
    else if(value<(*node)->data){
        insertion(&(*node)->left,value);}
    else if(value>(*node)->data){
        insertion(&(*node)->right,value);}
}



void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->data);
  inorderTraversal(root->right);
}


void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->data);
}

int main() {
  int data,ch;
  struct node *root;
  do{
    printf("\n1.Insertion\n2.Inorder\n3,Preorder\n4,Postorder\5.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",ch);
    switch(ch){
        case 1:
        printf("Enter data");
        scanf("%d",&data);
        insertion(&root,data);
        break;

        case 2:
        printf("Inorder traversal \n");
        inorderTraversal(root);
        break;

        case 3:
        printf("\nPreorder traversal \n");
        preorderTraversal(root);
        break;

        case 4:
        printf("\nPostorder traversal \n");
        postorderTraversal(root);
        break;

        case 5:
        printf("Thank You");
        break;  
    }
  }while (ch!=5);
}