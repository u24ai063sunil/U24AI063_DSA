// Write a program in C to copy the elements of the array to a singly
// linked list
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
int* copy(struct node *head,int *arr){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int i=0;
    while(temp!=NULL){
        temp->data=*(arr+i);
        temp=temp->next; 
        i++;
        }
    return head;
 }       
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    head->next=second;
    second->next=third;
    third->next=NULL;
    int arr[3]={40,10,20};
    head=copy(head,arr);
    print_singly_list(head);
    return 0;
}
