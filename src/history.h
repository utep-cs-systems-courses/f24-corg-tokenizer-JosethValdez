#ifndef _HISTORY_
#define _HISTORY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id_number = 0;

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
    List* linked_list = (List *) malloc(sizeof(List));
    if (linked_list == NULL) {
        printf("Error with Memory");
    }
    
    linked_list->root = NULL;
    return linked_list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
    Item* node = (Item *) malloc(sizeof(Item));
    if (node == NULL) {
        printf("Error with Memory");
        return;
    }
    
    id_number += 1;
    node->id = id_number;
    node->str = str;
    node->next = list->root;
    list->root = node;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item* current = list->root;
    
    while (current != NULL) {
        if(current->id == id){
            return current->str;
        }
        current = current->next;
    }
    return NULL;
}

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
void free_history(List *list){
    Item* current;
    
    while (current != NULL) {
        current = list->root;
        list->root = list->root->next;
        free(current);
    }
}

#endif
