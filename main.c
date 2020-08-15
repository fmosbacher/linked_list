#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "linked_list.h"

int main(int argc, char *argv[]) {
	char input[201];
  LinkedList *linked_list = init_list();

	while(1) {
		printf("prompt > ");

		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
    }

    if (strncmp(input, "put", 3) == 0) {
      put(linked_list, atoi(&input[4]));
      printf("%d\n", linked_list->last->data);
		} else if (strncmp(input, "get", 3) == 0) {
      int data = get(linked_list, atoi(&input[4]));
      printf("%d\n", data);
		} else if (strncmp(input, "list\n", 5) == 0) {
			list(linked_list);
		} else if (strncmp(input, "remove", 6) == 0) {
			int data = remove_node(linked_list, atoi(&input[7]));
      printf("%d\n", data);
		} else if (strncmp(input, "clear\n", 6) == 0) {
			clear(linked_list);
		} else if (strncmp(input, "first\n", 6) == 0) {
			int first = get_first(linked_list);
      if (first != INT_MIN) printf("%d\n", first);
		} else if (strncmp(input, "last\n", 5) == 0) {
      int last = get_last(linked_list);
      if (last != INT_MIN) printf("%d\n", last);
		}
	}

	return EXIT_SUCCESS;
}