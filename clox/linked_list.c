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
    printf("Now printing node list: ");
    for (Node* temp = first_node; temp != NULL; temp = temp->next) {
        printf("%d:%p <-> ", temp->data, temp); 
    }
    printf("\n");
}

void node_destroy(Node* node)
{
    if(node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    if(node->next != NULL)
    {
        node->next->prev = node->prev;
    }
    free(node);
}

int main()
{
    Node* head = node_create(10);
    node_insert(11, head, NULL);
    Node* delete_this_node = node_insert(12, head->next, NULL);
    node_insert(13, head->next->next, NULL);
    head = node_insert(9, NULL, head);
    node_insert(69, head, head->next);

    node_print_list(head);
    int search_query = 11;
    Node* node_search_result = node_search(head, search_query); 
    printf("Search for a node with data value: %d\n",  search_query);
    printf("Data found at memory address: %p\n",  node_search_result);
    node_destroy(delete_this_node);
    printf("Deleted node with value 12, now showing new list\n");
    node_print_list(head);
    return 0;
}

