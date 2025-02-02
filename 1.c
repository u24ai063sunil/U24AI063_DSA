//Write a program in C to create and display a Singly link list.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void print_singly_list(struct node *head){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    second->data=20;
    third->data=30;
    head->next=second;
    second->next=third;
    third->next=NULL;
    print_singly_list(head);
    return 0;
}
