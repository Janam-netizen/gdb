#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int element;


};

struct dll {
    struct node *head;
    struct node *tail;
    int ctr;


};

void add(struct dll *l, struct node *n) {
    if (l->ctr == 0) {
        l->head = n;
        l->tail = n;
        l->head->next = NULL;
        l->head->prev = NULL;

    } else {
        n->prev = l->tail;
        l->tail->next = n;
        l->tail = n;
        l->tail->next = NULL;


    }

    l->ctr = l->ctr + 1;


}

void delete(struct dll *l, int num) {

    if (l->ctr == 0) {
        printf("%s", "List empty\n");
    }
    struct node *start = l->head;

    struct node *current = start;
    while (current != NULL) {

        if (current->element == num) {
            printf("%s","Node found\n");


            if (current->next == NULL && current->prev == NULL) {
                free(current);
            } else if (current->next == NULL) {

                current->prev->next = NULL;
                free(current);
            } else if (current->prev == NULL) {
                l->head=current->next;

                current->next->prev = NULL;
                free(current);
            } else {
                struct node *prev = current->prev;
                struct node *next = current->next;
                prev->next = next;
                next->prev=prev;
                free(current);


            }

            break;
        }
        current=current->next;


    }

}
void display(struct dll *l){
struct node * current=l->head;
while (current !=NULL){
    printf("\n");

    printf("%d",current->element);
    current=current->next;
}

}
int main() {

    struct dll* l=malloc(sizeof(struct dll));
    struct node *n1=malloc(sizeof(struct node));
    struct node *n2=malloc(sizeof(struct node));
    struct node *n3=malloc(sizeof(struct node));
    l->ctr=0;
    n1->element=1;
    n2->element=2;
    n3->element=3;
    add(l,n1);
    add(l,n2);
    add(l,n3);
    delete(l,1);

    display(l);
    free(l);
    //free(n1);
    free(n2);
    free(n3);




    return 0;
}
