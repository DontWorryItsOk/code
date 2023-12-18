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

struct Node { // данные о товаре + указатель на следующий узел списка
  PRICE info;
  struct Node *next;  
};

typedef struct Node NODE;

// Проверка введенного индекса (используется в add_anywhere)
int check_index(int index, NODE *head) {
  if (index <= 0)
  return 0;
  
  NODE *current = head;
  int i = 1;
  
  while (current != NULL) {
    if (i == index) return 1; 
    current = current->next;
    i++;
  }
  
  return 0;
}

// Добавление в начало списка
NODE *add_to_start(NODE *head, PRICE newtowar) {
  NODE *tmp = (NODE*) malloc(sizeof(NODE)); // адрес выделенного блока памяти сохраняется в указателе tmp
  tmp->info = newtowar; //  копируем информацию о товаре newtowar в поле info нового узла tmp.
  tmp->next = head; // указываем на следующий элемент списка, т.к. до выполнения функции head был на первом элементе
  return tmp; // возвращаем значение, чтобы после выполнения функции указать на начало списка - head = add_to_start (т.е. head = tmp)
}

// Добавление в конец списка  
NODE *add_to_end(NODE *head, PRICE newtowar) {

    NODE *tmp = (NODE*) malloc(sizeof(NODE));
    tmp->info = newtowar;
    tmp->next = NULL;

    if(!head) { // проверка, является ли список пустым (если *head == NULL)
        return tmp;
    }
    
    NODE *current = head; // создаем указатель current для движения по списку сверху вниз, присваиваем ему head (это копия указателя, изменение current не влияет на head)

    while(current->next != NULL) { // до тех пор, пока следующий элемент списка будет существовать
        current = current->next; // переходим на следующий элемент
    }

    current->next = tmp; // устанавливаем указатель next последнего узла (current) так, чтобы он указывал на наш новый узел (tmp)
    return head; // возвращаем head для последующего обновления, без обновления новый элемент списка не появляется
}

// Добавление в любое место списка
NODE *add_anywhere(NODE *head, PRICE newtowar, int index) {

  if(!check_index(index, head)) { // проверка  индекса (чтобы нельзя было добавить на несуществующую позицию), т.е. функция вернула 0 - индекс неправильный
    printf("Введен неправильный индекс!");
    return head;
  }
  
  NODE *tmp = (NODE*) malloc(sizeof(NODE));
  tmp->info = newtowar;
  
  if (index == 1) { 
    tmp->next = head; // следующий элемент становится head
    return tmp; // возвращаем tmp для обновления head
  }
  
  NODE *current = head; // создаем указатель current для движения по списку сверху вниз, присваиваем ему head

  for(int i = 0; i < index - 2; ++i) { // элемент вставляется точно по индексу
    current = current->next; // обновление текущего элемента списка (если остановились на 2, укажет на 3)
  }  

  tmp->next = current->next; // устанавливаем указатель next узла tmp на элемент, который изначально находился на позиции index.
  current->next = tmp; // устанавливаем указатель next предыдущего узла current на новый узел tmp
  
  return head;
}


// Удаление с начала списка
NODE *delete_from_start(NODE *head) {
  
  if(head == NULL) { // если head указывает на пустое место
    printf("Список пуст.\n");
    return NULL;
  }
  
  NODE *tmp = head;
  head = head->next; // перемещаем head на следующий элемент списка
  free(tmp);
  
  return head;
}


// Удаление с конца списка
NODE *delete_from_end(NODE *head) {
    
    if (head == NULL) { // если head указывает на пустое место
        printf("Список пуст.\n");
        return NULL;
    }

    if (head->next == NULL) { // если единственный элемент списка
        free(head); // освобождаем память выделенную под head
        return NULL;
    }

    NODE *current = head; // создаем указатель current для движения по списку сверху вниз, присваиваем ему head
    NODE *prev = NULL; //  создаем пустой указатель

    while (current->next != NULL) { // пока следующий элемент после current не перестанет существовать
        prev = current;
        current = current->next; // двигаемся вниз по списку
    }

    free(current); // освобождаем память выделенную для последнего элемента списка

    if (prev != NULL) { // если элемент перед удаляемым current существует
        prev->next = NULL; // next указывает на пустое место списка
        return head;
    } 
    
    else { // если элемента перед current не существует(был единственный элемент в списке)
        return NULL;
    }
}


// Удалить из любого места списка
NODE *delete_anywhere(NODE *head, int index) {
   if (head == NULL) {
      printf("Список пуст.\n");
      return NULL;
    }

    if (index == 1) { // удаление первого элемента
      NODE *new_head = head->next; // создаем новый указатель на голову, который указывает на следующий элемент после текущей головы
      free(head); // освобождаем память под элемент текущей головы
      return new_head;
    }

    NODE *current = head;
    NODE *prev = NULL;

    for (int i = 0; i < index - 1 && current != NULL; ++i) { // цикл для движения по списку, пока не дойдем до предыдущего элемента за тем, который надо удалить
      prev = current;
      current = current->next;
    }

    if (current == NULL || index == 0) { // если индекс 0 или такого в списке не существует
      printf("Неверный индекс для удаления.\n");
      return head;
    }

    prev->next = current->next; // обновление prev
    free(current); // освобождение памяти под элемент
    return head;
}


// Вывести список на экран
void show(NODE *head) {
    printf("Список:\n");
    NODE *current = head;
    int index = 1; // элементы в списке начинаем с единицы

    while (current != NULL) { // пока не дойдем до пустого места
        printf("%d. %s, %s, %d\n", index, current->info.Tovar, current->info.Mag, current->info.Stoim);
        current = current->next;
        index++;
    }
}


// Освобождение памяти при завершении программы
void free_memory(NODE *head) {
  NODE *current = head;
  
    while(current != NULL) {
        NODE *tmp = current;
        current = current->next;
        free(tmp); 
    }
}


// Вывод информации о товаре по названию
void search_tovar(NODE *head, const char *name) {
    NODE *current = head;

    while (current != NULL) {
        
        if (strcmp(current->info.Tovar, name) == 0) {
            printf("Информация о товаре:\nНазвание: %s\nМагазин: %s\nЦена: %d\n", current->info.Tovar, current->info.Mag, current->info.Stoim);
            return;
        }

        current = current->next;
    }
    printf("Ошибка! Товар с таким названием не найден.\n");
}


int main() {
  NODE *head = NULL;
  int answer; // переменная для ответа пользователя
  PRICE newtowar;

  do {
      printf("\nМеню:\n");
      printf("1. Добавить элемент в начало списка\n");
      printf("2. Добавить элемент в конец списка\n");
      printf("3. Добавить элемент в выбранное место в списке\n");
      printf("4. Удалить элемент из начала списка\n");
      printf("5. Удалить элемент из конца списка\n");
      printf("6. Удалить элемент с выбранного места в списке\n");
      printf("7. Вывести список\n");
      printf("8. Вывести информацию о товаре по названию\n");
      printf("9. Выход\n");

      printf("Выберите действие (1-9): ");

      // Проверка вводимого значения(в случае введения напр. буквы): 
      if (scanf("%d", &answer) != 1) {
         printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
         while (getchar() != '\n'); // Очистка входного буфера
         continue;
        }

      switch (answer) {
        case 1:
          printf("Введите данные товара (Название, Магазин и Стоимость): ");
          scanf("%s %s %d", newtowar.Tovar, newtowar.Mag, &newtowar.Stoim);
          head = add_to_start(head, newtowar);
          break;

        case 2:
          printf("Введите данные товара (Название, Магазин и Стоимость): ");
          scanf("%s %s %d", newtowar.Tovar, newtowar.Mag, &newtowar.Stoim);
          head = add_to_end(head, newtowar);
          break;

        case 3:
          printf("Введите данные товара (Название, Магазин и Стоимость): ");
          scanf("%s %s %d", newtowar.Tovar, newtowar.Mag, &newtowar.Stoim);
          int index;
          printf("Введите индекс для вставки: ");
          scanf("%d", &index);
          head = add_anywhere(head, newtowar, index);
          break;

        case 4:
          head = delete_from_start(head);
          break;

        case 5:
          head = delete_from_end(head);
          break;

        case 6:
          int delete_index;
          printf("Введите индекс для удаления: ");
          scanf("%d", &delete_index);
          head = delete_anywhere(head, delete_index);
          break;

        case 7:
          show(head);
          break;

        case 8:
          char search[50];
          printf("Введите название товара: ");
          scanf("%s", search);
          search_tovar(head, search);
          break;

        case 9:
          free_memory(head);
          printf("Программа завершена.\n");
          break;

        default:
          printf("Неверный выбор. Попробуйте снова.\n");
          break;

        }

    } while (answer != 9);

 return 0;
}

// решил проблему с бесконечным выполнением программы в случае введения буквы
// проблема с освобождением памяти решена
// решил проблему с индексом в add_anywhere

// добавить возможность вводить название товара через пробелы?
// при вводе d d d выводит ошибку ввода, но в список добавляет (вместо стоимости пишет не то) 
// при этом если удалить 2, то удалится 2 (при вводе 0 ошибка), 
// при добавлении в любое место списка сделать возможность добавить элемент в конец списка(новый элемент)


// в версии me_help5 внёс изменения в индексацию add_anywhere и check_index