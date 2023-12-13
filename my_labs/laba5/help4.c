// claude ai

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Price {
  char Tovar[50];
  char Mag[50];
  int Stoim;
  struct Price *next;
};

typedef struct Price PRICE;

struct Node {
  PRICE info;
  struct Node *next;  
};

typedef struct Node NODE;

// Проверка корректности введенного индекса
int validate_index(int index, NODE* head) {
  if (index < 0) return 0;
  
  NODE* current = head;
  int i = 0;
  
  while (current != NULL) {
    if (i == index) return 1; 
    current = current->next;
    i++;
  }
  
  return 0;
}

// Добавление в начало списка
NODE* add_to_start(NODE* head, PRICE newtowar) {
  NODE* tmp = (NODE*) malloc(sizeof(NODE));
  tmp->info = newtowar;
  tmp->next = head;
  return tmp;
}

// Добавление в конец списка  
NODE* add_to_end(NODE *head, PRICE newtowar) {

    NODE* tmp = (NODE*) malloc(sizeof(NODE));
    tmp->info = newtowar;
    tmp->next = NULL;

    if(!head) {
        return tmp;
    }
    
    NODE* current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = tmp;  
    return head;
}

// Добавление на заданную позицию
NODE* add_anywhere(NODE* head, PRICE newtowar, int index) {

  // Проверка корректности индекса
  if(!validate_index(index, head)) {
    printf("Incorrect index");
    return head;  
  }
  
  NODE* tmp = (NODE*) malloc(sizeof(NODE));
  tmp->info = newtowar;
  
  if (index == 0) {
    tmp->next = head; 
    return tmp;
  }
  
  NODE* current = head;

  for(int i = 0; i < index - 1; i++) {
    current = current->next;
  }  

  tmp->next = current->next;  
  current->next = tmp;
  
  return head;
}

// Удаление с начала списка
NODE* delete_from_start(NODE* head) {
  
  if(!head) {
    return NULL;
  }
  
  NODE* temp = head;
  head = head->next;
  free(temp);
  
  return head;
}

// Остальные функции
void free_memory(NODE* head) {

  NODE* current = head;
  
  while(current) {
    NODE* temp = current;
    current = current->next;
    free(temp); 
  }

}

int main() {

  // Код программы
  
  return 0;
}