#include <stdlib.h>
#include <stdio.h>
#include "STDTYPES.h"
#ifndef A1_LINKED_LIST_H
#define A1_LINKED_LIST_H

typedef struct node{
    u16 data;
    struct node* next;
}node;

node* head = NULL;

void Add_At_Beginning(u16 data){
    node* temp = (node*) malloc(sizeof(node));
    temp -> data = data;
    temp -> next = head;
    head = temp;
}

void Add_At_End(u16 data){
    node* new = (node*) malloc(sizeof(node));
    node* temp = head;
    new -> data = data;
    new -> next = NULL;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = new;

}

void Add_Specific_Pos(u16 data, u8 pos){
    node* new = (node*) malloc(sizeof(node));
    new -> data = data;
    if(head == NULL){
        new -> next = head;
        head = new;
    }
    else{
        node *temp = head;
        int i = 1;
        while(i < pos - 1 && temp -> next != NULL){
            temp = temp -> next;
            i++;
        }
        new -> next = temp -> next;
        temp -> next = new;
    }
}

void Delete(u16 data){
    if(head == NULL){
        printf("The list is empty...");
    }
    else if(head -> data == data){ // You can't free(head);
        node* temp = head;
        head = temp -> next;
        free(temp);
        printf("Node has been deleted");
        return;
    }
    else{
        node* toDelete;
        for(node* temp = head ; temp -> data != data && temp != NULL ; temp = temp -> next){
            if(temp -> next == NULL){
                printf("The Node you want to delete doesn't exist...");
                return;
            }
            else if(temp -> next -> data == data){
                node *temp2 = temp -> next;
                toDelete = temp -> next;
                temp -> next = temp2 -> next;
                free(toDelete);
                printf("Node has been deleted");
                return;
            }
        }
    }
}

void Delete_Beginning(){
    Delete(head -> data);
}

void Delete_End(){
    if(head == NULL){
        printf("The List is empty...");
        return;
    }
    for(node* temp = head ; temp != NULL ; temp = temp -> next){
        if(temp -> next == NULL){
            Delete(temp -> data);

        }
    }
}

void View_List(){
    if(head != NULL){
        node* temp = head;
        do {
            printf("%hu\n", temp -> data);
            temp = temp -> next;
        } while (temp != NULL);
    }
}

void View_Specific(u16 data){
    node* temp = head;
    u8 i = 1;
    u8 flag = 1;
    do {
        if(temp -> data == data){

            printf("Result:\nData = %i\nNode number = %i",data, i);
            flag = 0;
            break;
        }
        else{
            i += 1;
            temp = temp -> next;
        }
    }while(temp != NULL);
    if(flag){
        printf("Not Found...");
    }
}

int Get_List_Size(){
    int size = 0;
    node* temp = head;
    do {
        size++;
        temp = temp -> next;
    }while(temp != NULL);
    return size;
}

void Free_List(){
    node* temp = head;
    do {
        Delete(temp -> data);
        temp = temp -> next;
    }while(temp != NULL);
}


#endif //A1_LINKED_LIST_H
