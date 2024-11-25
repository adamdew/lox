#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* node_create(int data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

Node* node_insert(int data, Node* prev, Node* next)
{
    Node* new_node = node_create(data);

    if(prev == NULL) {
        next->prev = new_node;
    }

    new_node->next = next;
    new_node->prev = prev;

    if(next != NULL){
        next->prev = new_node;
    }

    if(prev != NULL){
        prev->next = new_node;
    }

    return new_node;
}

Node* node_search(Node* head, int value_data)
{
    Node* found_node = NULL;
    for (Node* temp = head; temp != NULL; temp = temp->next) 
    {
        if(temp->data == value_data)
        {
            found_node = temp;
        } 
    }
    return found_node;
}

void node_print_list(Node* first_node)
{
    for (Node* temp = first_node; temp != NULL; temp = temp->next) {
        printf("%d <-> ", temp->data); 
    }
}

int main()
{
    Node* head = node_create(10);
    node_insert(11, head, NULL);
    node_insert(12, head->next, NULL);
    node_insert(13, head->next->next, NULL);
    head = node_insert(9, NULL, head);

    //node_print_list(head);
    int search_query = 15;
    Node* node_search_result = node_search(head, search_query); 
    printf("Search for a node with data value: %d\n",  search_query);
    printf("Data found at memory address: %p\n",  node_search_result);
    return 0;
}

