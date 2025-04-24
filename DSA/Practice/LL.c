// ============================insertion=================================

// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node* next;
// };

// struct node* createNode(int data){
//     struct node* temp = (struct node*)malloc(sizeof(struct node));
//     temp -> data = data;
//     temp -> next = NULL;
//     return temp;
// }

// struct node* insertBegin(struct node* head, int data){
//     struct node* temp = createNode(data);
//     temp->next = head;
//     return temp;
// }

// struct node* insertAfter(struct node* head, int key, int data){
//     struct node* curr = head;
//     if(key == 0) return insertBegin(head, data);
//     int i = 0;
//     while(i < key-1){
//         curr = curr -> next;
//         i++;
//     }


//     struct node* temp = createNode(data);
//     temp -> next = curr -> next;
//     curr -> next = temp;
//     return head;

// }

// struct node* insertEnd(struct node* head, int data){
//     struct node* curr = head;
//     while(curr -> next != NULL){
//         curr = curr -> next;
//     }
//     struct node* temp = createNode(data);
//     temp -> next = NULL;
//     curr -> next = temp;
//     return head;
// }

// void display(struct node* head){
//     struct node* curr = head;
//     while(curr != NULL){
//         printf("%d ", curr->data);
//         curr = curr -> next;
//     }
//     printf("\n");
// }


// // int main() {
  
// //     // Create the linked list 2->3->4->5
// //     struct node* head = createNode(2);
// //     head->next = createNode(3);
// //     head->next->next = createNode(4);
// //     head->next->next->next = createNode(5);

// //     int data = 1;
// //     head = insertBegin(head, data);
// //     display(head);

// //     return 0;
// // }

// // int main() {
  
// //     // Create the linked list 2->3->5->6
// //     struct node* head = createNode(2);
// //     head->next = createNode(3);
// //     head->next->next = createNode(5);
// //     head->next->next->next = createNode(6);

// //     int key = 2, newData = 4;

// //     // Insert a new node with data 4 after the node having
// //     // data 3
// //     head = insertAfter(head, key, newData);

// //     display(head);

// //     return 0;
// // }
// int main()
// {
//     // Create a linked list:
//     // 2 -> 3 -> 4 -> 5 -> 6
//     struct node* head = createNode(2);
//     head->next = createNode(3);
//     head->next->next = createNode(4);
//     head->next->next->next = createNode(5);
//     head->next->next->next->next = createNode(6);

//     head = insertEnd(head, 1);

//     display(head);

//     return 0;
// }

// ========================deletion==============================


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

struct node* deleteHead(struct node* head){

    if(head == NULL) return NULL;
    struct node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}

struct node* deleteEnd(struct node* head){

    if(head == NULL) return NULL;
    if(head -> next == NULL){
        free(head);
        return NULL;
    }
    struct node* seclast = head;
    while(seclast -> next -> next != NULL){
        seclast = seclast -> next;
    }
    free(seclast -> next);
    seclast -> next = NULL;
    return head;
    
}

void display(struct node* head){
    struct node* curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr -> next;
    }
    printf("\n");
}

int main()
{
    // Creating a linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: ");
    display(head);

    // Deleting the head node
    head = deleteHead(head);

    printf("List after deleting the head: ");
    display(head);

    return 0;
}