#include <stdio.h>

#include <stdlib.h>

#include <string.h> // For strcmp and strdup
#include <stdlib.h> // For malloc and free

typedef struct s_env {
    char *name;
    char *value;
    struct s_env *next;
} t_env;

// Function to swap the contents of two nodes
void swap_nodes(t_env *a, t_env *b) {
    char *temp_name = a->name;
    char *temp_value = a->value;

    a->name = b->name;
    a->value = b->value;

    b->name = temp_name;
    b->value = temp_value;
}

// Function to sort the linked list of environment variables by name
void sort_env(t_env *env) {
    if (!env) return;

    int is_swap;
    t_env *curr;

    while (1) {
        is_swap = 0;
        curr = env;

        while (curr->next != NULL) {
            // Compare current node's name with the next node's name
            if (strcmp(curr->name, curr->next->name) > 0) {
                // Swap the nodes if they are out of order
                swap_nodes(curr, curr->next);
                is_swap = 1;
            }
            curr = curr->next;
        }

        // If no swaps were made, the list is sorted
        if (!is_swap) {
            break;
        }
    }
}


int main()
{
	printf("%d\n", atoi(NULL));
}
