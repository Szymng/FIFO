#include <stdio.h>
#include <stdlib.h>

struct Element{
    struct Element *next;
    struct Element *previous;
    int data;
};

struct FIFO{
    struct Element *first;
    struct Element *last;
    unsigned size;
};

void Add(struct FIFO *kolejka, struct Element *element){
    if(kolejka->size == 0){
        kolejka->size++;
        kolejka->first = element;
        kolejka->last = element;
    }
    else{
        kolejka->size++;
        element->previous = kolejka->last;
        kolejka->last->next = element;
        kolejka->last = element;
    }
    printf("Added element\n");
}

void Pop(struct FIFO *kolejka){
    if(kolejka->size == 0){
        printf("No elements in FIFO\n");
    }
    else{
        kolejka->first = kolejka->first->next;
        kolejka->size--;
        printf("Removed element\n");
    }
}

void Show(struct FIFO kolejka){
    struct Element *temp;
    if(temp != NULL){
        temp = NULL;
    }
    if(kolejka.size == 0){
        printf("No elements in queue\n");
    }
    else{
        printf("%d elements in queue:\n", kolejka.size);
    }
    for(int i = 0; i<kolejka.size; i++){
        temp = kolejka.first;
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct FIFO queue;
    queue.size = 0;
    struct Element element;
    element.data = 5;

    Add(&queue, &element);
    Add(&queue, &element);
    Show(queue);
    Add(&queue, &element);
    Pop(&queue);
    Show(queue);
}