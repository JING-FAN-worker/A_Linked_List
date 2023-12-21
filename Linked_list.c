#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int isEmpty(Node *head)
{
    if (head == NULL)
    {
        return 1; 
        /*if the list is empty return 1*/
    }
    else
    {
        return 0; 
        /*otherwise 0*/
    }
}

Node *addToEnd(Node *head, char str[])
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, str);
    new_node->pNext = NULL;
    if (head == NULL) 
    /*if head is null then return new_node*/
    {
        return new_node;
    }
    Node *current_node = head;
    while (current_node->pNext != NULL) 
    /*add the new node to the end of string*/
    {
        current_node = current_node->pNext;
    }
    current_node->pNext = new_node;
    return head;
}

Node *addToBeginning(Node *head, char str[]) 
/*adds a new node containing the string
 str to the end of the list. The function returns a pointer to the first node in the list.
 */
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, str);
    new_node->pNext = head;
    return new_node;
}

int size(Node *head) 
/*returns the total number of nodes in the list.*/
{
    int count = 0;
    Node *current_node = head;
    while (current_node != NULL) 
    /*count the number of non-null place*/
    {
        count++;
        current_node = current_node->pNext;
    }
    return count;
}
Node *tail(Node *head)
{
    if (head == NULL) 
    /*which means there isn't any content*/
    {
        return NULL;
    }
    Node *current_node = head;
    while (current_node->pNext != NULL) 
    /*search deeply and find the last node*/
    {
        current_node = current_node->pNext;
    }
    return current_node;
}

Node *get_node(Node *head, int pos) 
/*returns the node at the given position. If
 pos is bigger than the number of elements in the list, then the function returns NULL. The value
 of the parameter pos is always at least 1.*/
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *current_node = head;
    int count = 1;
    while (current_node != NULL && count < pos)
    {
        current_node = current_node->pNext;
        count++;
    }
    if (current_node == NULL)
    {
        return NULL;
    }
    else
    {
        return current_node;
    }
}

Node *deleteFirst(Node *head) 
/*removes the first element of the list and returns a
 pointer to the new first element.  */
{
    if (head == NULL) 
    /*check the first element*/
    {
        return NULL;
    }
    Node *new_head = head->pNext; 
    /*free the head*/
    free(head);
    return new_head;
}

Node *deleteLast(Node *head) 
/*) removes the last element of the list and returns a
 pointer to the first element. The memory space of the deleted element is freed. If the first
 element is removed or the list was empty, the method returns NULL.*/
{
    if (head == NULL) 
    /*check if it is empty*/
    {
        return NULL;
    }
    Node *current_node = head;
    Node *prev_node = NULL;
    while (current_node->pNext != NULL)
    {
        prev_node = current_node;
        current_node = current_node->pNext;
    }
    if (prev_node == NULL)
    {
        free(current_node);
        return NULL;
    }
    else
    {
        prev_node->pNext = NULL; 
        /*find the last one and free*/
        free(current_node);
        return head;
    }
}

int find(Node *head, char *str) 
/*returns the position of the element containing
 the string str. If such an element is not found, then the method returns 0.*/
{
    int pos = 1;
    Node *current_node = head;
    while (current_node != NULL)
    {
        if (strcmp(current_node->data, str) == 0) 
        /*check if there is such a string*/
        {
            return pos;
        }
        current_node = current_node->pNext;
        pos++;
    }
    return 0;
}

void print(Node *head) 
/*prints the names stored in Nodes. For instance, the printing may
 look like this:
 Printing...
 Node position 1: Heikki.
 Node position 2: Matti.
 Node position 3: Sirkka.
 Node position 4: Pirkko.*/
{
    int pos = 1;
    Node *current_node = head;
    printf("Printing...\n");
    while (current_node != NULL)
    {
        printf("Node position %d: %s\n", pos, current_node->data); 
        /*print all the elements in it in while loop*/
        current_node = current_node->pNext;
        pos++;
    }
}

char *toString(Node *head) 
/*reverses the list The requirement is that the reversing must be done only by changing the pointers. */
{
    char *str = malloc(100 * sizeof(char));
    memset(str, 0, 100);
    Node *current_node = head;

    while (current_node != NULL)
    {
        strcat(str, "("); 
        /*use this method to connect string*/
        strcat(str, current_node->data);
        strcat(str, ") -> ");
        current_node = current_node->pNext;
    }
    strcat(str, "NULL");
    return str;
}

Node *reverse(Node *head) 
/*change the order by pointer*/
{
    Node *prev_node = NULL;
    Node *current_node = head;
    Node *next_node = NULL;
    while (current_node != NULL)
    {
        next_node = current_node->pNext;
        current_node->pNext = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    return prev_node;
}