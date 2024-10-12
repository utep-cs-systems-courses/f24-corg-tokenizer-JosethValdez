#ifndef _HISTORY_
#define _HISTORY_

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history() {
    Item* head = (Item*)malloc(sizeof(Item));
    
    if (head == NULL) {
        printf("ERROR WITH MEMORY");
    }
    
    head->id = 0;
    head->str = "";
    head->next = NULL;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
    Item* current = list->root;
    
    if (current->str == ""){
        current->str = str;
        return;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    Item* new_node = (Item*)malloc(sizeof(Item));
    if (new_node == NULL) {
        printf("ERROR WITH MEMORY");
    }
    new_node->id = current->id+1;
    new_node->str = str;
    current->next = new_node;
    new_node->next = NULL;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/*Print the entire contents of the list. */
void print_history(List *list){
    Item* current = list->root;
    
    while (current != NULL) {
        printf("%d\t", current->id);
        printf("%d\n", current->str);
        current = current->next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list);

#endif
