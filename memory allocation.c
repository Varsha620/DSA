#include<stdio.h>
#include<stdlib.h>
struct node{
    int m;
    struct node *next;
};
struct node*head=NULL;
struct node*temp=NULL;

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->m);
        temp=temp->next;
    }
}
void ffit(){
    int f=0, req;
    printf("Enter required memory:");
    scanf("%d",&req);
    temp=head;
    while(temp!=NULL){
    if (req<=temp->m){
        f=1;
        temp->m=temp->m-req;
        break;
    }
    else{
        temp=temp->next;
    }}
    if (f==1){
        printf("MEMORY ALLOCATED.");
        printf("MEMORY LEFT:\n");
        display();
    }
    else{
        printf("MEMORY ALLOCATION FAILED.");
    }
}
void bfit(){
    struct node *best=NULL;
    int req;
    printf("Enter required memory:");
    scanf("%d", &req);
    temp=head;
    while (temp!=NULL){
        if (req<=temp->m){
        if(best==NULL || temp->m < best->m){
            best=temp;
        }
            temp=temp->next;
        }
    }
    if(best!=NULL){
        best->m=best->m-req;
        printf("MEMEORY ALLOCATED.");
        printf("MEMORY LEFT:\n");
        display();
    }
    else{
        printf("Memory alloction failed");
    }
}
void wfit(){
    struct node*worst=NULL;
    int req;
    printf("Enter required memory:");
    scanf("%d", &req);
    temp=head;
    while (temp!=NULL){
        if (req<=temp->m){
        if(worst==NULL || temp->m > worst->m){
            worst=temp;
        }
            temp=temp->next;
        }
    }
    if(worst!=NULL){
        worst->m=worst->m-req;
        printf("MEMEORY ALLOCATED.");
        printf("MEMORY LEFT:\n");
        display();
    }
    else{
        printf("Memory alloction failed");
    }
}
void main(){
    int size,ch,req;
    printf("Enter no of memory spaces reqd:");
    scanf("%d", &size);
    for (int i=0;i<size;i++){
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter memory:");
        scanf("%d",&newnode->m);
        if (head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    do{
        printf("\n1.First fit\n2.Best Fit\n3.Worst Fit\n4.Exit");
        printf("\nEnter a choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            ffit();
            break;
            case 2:
            bfit();
            break;
            case 3:
            wfit();
            break;
            case 4:
            printf("THANK YOU");
            break;
        }
    }while(ch!=4);
}