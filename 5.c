// Write a C program that converts a singly linked list into an array and
// returns it.
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
int* copy_to_array(struct node *head){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int i=0;
    int *array;
    while(temp!=NULL){
        *(array+i)=temp->data;
        temp=temp->next; 
        i++;
        }
    return array;
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
    int *arr;
    arr=copy_to_array(head);
    for(int i=0;i<3;i++){
         printf("%d\t",*(arr+i));
         }
    return 0;
}
