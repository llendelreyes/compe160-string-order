//
//  main.c
//  Lab #9
//
//  Created by Llendel Reyes on 4/5/16.
//  Copyright © 2016 Llendel Reyes. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 80

struct link_node {
    char node_str[MAX_STR_LEN];
    struct link_node *next;
};

int compare_node(struct link_node *n1, struct link_node *n2) {
    return strcmp(n1->node_str, n2->node_str);
}

void bubble_sort(struct link_node *header) {
    
    int i, j, k, n = 0;
    char tempV[250];
    struct link_node *p, *r;
    struct link_node *pointer = header;
    while (pointer != NULL) {
        pointer = pointer->next;
        n++;
    }
    k = n;
    for (i = 0; i < n - 1; i++, k--) {
        p = header;
        r = p -> next;
        for (j = 1; j < k; j++) {
            if (strcmp(p->node_str, r->node_str) > 0) {
                strcpy(tempV, p -> node_str);
                strcpy(p -> node_str, r -> node_str);
                strcpy(r-> node_str, tempV);
            }
            p = p -> next;
            r = r -> next;
        }
    }
}
struct link_node* add_to_list(struct link_node *header, struct link_node *node) {
    if (NULL == header) {
        header = node;
        return header;
    } else {
        struct link_node *pointer = header;
        while (pointer->next != NULL) {
            pointer = pointer->next;
        }
        pointer->next = node;
        bubble_sort(header);
        return header;
    }
}
void print_list(struct link_node *header) {
    struct link_node *pointer = header;
    while (pointer != NULL) {
        printf("%s\n", pointer->node_str);
        pointer = pointer->next;
    }
    return;
}
int main(void) {
    struct link_node *header = NULL;
    char userName[250];
    printf("Please enter strings. When you are done, enter a blank line.\n");
    while (1) {
        printf("> ");
        gets(userName);
        struct link_node *pointer = (struct link_node*) malloc(sizeof(struct link_node));
        if (strcmp(userName, " ") == 0) {
            break;
        }
        strcpy(pointer->node_str, userName);
        pointer->next = NULL;
        header = add_to_list(header, pointer);
    }
    print_list(header);
    return 0;
}