typedef struct node
{
    char data[10];
    struct node *pNext;
} Node;
int isEmpty(Node *head);
Node *addToEnd(Node *head, char str[]);
Node *addToBeginning(Node *head, char str[]);
int size(Node *head);
Node *tail(Node *head);
Node *get_node(Node *head, int pos);
Node *deleteFirst(Node *head);
Node *deleteLast(Node *head);
int find(Node *head, char *str);
void print(Node *head);
char *toString(Node *head);
Node *reverse(Node *head);