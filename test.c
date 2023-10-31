#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define size 5 

int stack[size];
int top = -1;

int queue[size];
int cqueue[size];

int front = -1;
int rear = -1;


struct node{
    int data;
    struct node*next;
};
struct node *head,*newnode,*temp,*prev;



void push_stack(int x){
    if (top == (size-1)){
        printf("Stack is full");
    }
    else{
        top++;
        stack[top] = x;
    }

}

void pop_stack(){

    if (top == -1){
        printf("Stack is empty");
    }
    else{
        top--;
    }
}

void display_stack(){

    if(top ==-1){
        printf("Stack is empty");

    }
    else{
        for(int i = 0;i++;i<=top){
            printf('%d->',stack[i]);
        }
    }

}

void enqueue(int x){
    if (rear == (size-1)){
        printf("Queue is full");

    }
    else if (front == rear == -1){
        front = rear = 0;
        queue[front] = x;

    }
    else{

        rear++;
        queue[rear] = x;
    }

}


void dequeue(){
    if (front == rear == -1){
        printf("queue is empty");
    }
    else if (front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }



    
}

void c_enqueue(int x){

    if((rear-1)/size == front ){
        printf("queue is full");
    }
    else if (front == rear == -1){
        front = rear =  0;
        cqueue[front] = x;

    }
    else{
        rear = (rear-1)/size;
        cqueue[rear] = x;
    }




}

void c_dequeue(){
    if (front == rear == -1){
        printf("empty");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front-1)/size;
    }
}

void display_cqueue(){
    if(front == rear == -1){
        printf("empty");
        return;
    } 
    if (rear >= front){
        for (int i=front;i<=rear;i++){
            print('%d',cqueue[i]);
        }
    }
    else{
        for(int i =front;i<size;i++){
            printf('%d',cqueue[i]);
        }
        for(int i =rear;i<front;i++){
            printf('%d',cqueue[i]);
        }
    }
}


void insertAtBegin(int x){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}
void insertAtEnd(int x){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if (head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}

void deleteAtEnd(){
    temp = head;
    while(temp->next){
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;


}

void deleteAtStart(){
    temp = head;
    head = head->next;
    free(temp);

}

void insertAtPos(int x,int pos){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    temp = head;
    int i = 1;
    while(i!=pos){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}


