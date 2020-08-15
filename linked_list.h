#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct linked_list {
  Node *first;
  Node *last;
  int size;
} LinkedList;

LinkedList *init_list();
void put(LinkedList *linked_list, int data);
int get(LinkedList *linked_list, int index);
void list(LinkedList *linked_list);
int remove_node(LinkedList *linked_list, int index);
void clear(LinkedList *linked_list);
int get_first(LinkedList *linked_list);
int get_last(LinkedList *linked_list);

#endif