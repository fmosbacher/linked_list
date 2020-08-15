#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "linked_list.h"

LinkedList *init_list() {
  LinkedList *linked_list = malloc(sizeof(LinkedList));

  linked_list->first = NULL;
  linked_list->last = NULL;
  linked_list->size = 0;

  return linked_list;
}

void put(LinkedList *linked_list, int data) {
  if (linked_list->first == NULL) {
    linked_list->first = linked_list->last = malloc(sizeof(Node));
  } else {
    linked_list->last->next = malloc(sizeof(Node));
    linked_list->last = linked_list->last->next;
  }

  linked_list->last->data = data;
  linked_list->last->next = NULL;
  linked_list->size += 1;
}

int get(LinkedList *linked_list, int index) {
  if (linked_list->size < index || index < 1) {
    return INT_MIN;
  }

  int counter = 1;
  Node *current_node = linked_list->first;

  while (counter < index) {
    counter += 1;
    current_node = current_node->next;
  }

  return current_node->data;
}

void list(LinkedList *linked_list) {
  if (linked_list->first == NULL) printf("Empty list\n");

  Node *current_node = linked_list->first;

  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }

  printf("\n");
}

int remove_node(LinkedList *linked_list, int index) {
  if (linked_list->size < index || index < 1) {
    return INT_MIN;
  }

  int counter = 1;
  int removed_data;
  Node *to_be_removed;
  Node *current_node = linked_list->first;

  while (counter < index - 1) {
    counter += 1;
    current_node = current_node->next;
  }

  to_be_removed = current_node->next;
  removed_data = current_node->next->data;
  current_node->next = current_node->next->next;
  free(to_be_removed);

  return removed_data;
}

void clear(LinkedList *linked_list) {
  if (linked_list->first == NULL) return;

  while (linked_list->first != linked_list->last) {
    Node *to_be_removed = linked_list->first;

    linked_list->first = linked_list->first->next;
    free(to_be_removed);
  }

  free(linked_list->first);
  linked_list->first = linked_list->last = NULL;
  linked_list->size = 0;
}

int get_first(LinkedList *linked_list) {
  if (linked_list->first == NULL) return INT_MIN;
  return linked_list->first->data;
}

int get_last(LinkedList *linked_list) {
  if (linked_list->first == NULL) return INT_MIN;
  return linked_list->last->data;
}