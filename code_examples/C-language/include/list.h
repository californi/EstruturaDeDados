#ifndef LIST_H
#define LIST_H

#include "common.h"

// Estrutura da Lista Sequencial (Array)
typedef struct {
    DataType data[MAX_SIZE];
    int size;
} ListArray;

// Estrutura da Lista Simplesmente Ligada
typedef struct ListNode {
    DataType data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
    int size;
} ListLinked;

// Estrutura da Lista Duplamente Ligada
typedef struct DListNode {
    DataType data;
    struct DListNode* next;
    struct DListNode* prev;
} DListNode;

typedef struct {
    DListNode* head;
    DListNode* tail;
    int size;
} DoublyLinkedList;

// Estrutura da Lista Circular
typedef struct CListNode {
    DataType data;
    struct CListNode* next;
} CListNode;

typedef struct {
    CListNode* head;
    int size;
} CircularList;

// Operações da Lista Sequencial
void list_array_init(ListArray* list);
bool list_array_is_empty(ListArray* list);
bool list_array_is_full(ListArray* list);
int list_array_insert(ListArray* list, int position, DataType value);
int list_array_remove(ListArray* list, int position, DataType* value);
int list_array_get(ListArray* list, int position, DataType* value);
int list_array_set(ListArray* list, int position, DataType value);
int list_array_find(ListArray* list, DataType value);
int list_array_size(ListArray* list);
void list_array_print(ListArray* list);
void list_array_clear(ListArray* list);

// Operações da Lista Simplesmente Ligada
void list_linked_init(ListLinked* list);
bool list_linked_is_empty(ListLinked* list);
int list_linked_insert(ListLinked* list, int position, DataType value);
int list_linked_remove(ListLinked* list, int position, DataType* value);
int list_linked_get(ListLinked* list, int position, DataType* value);
int list_linked_set(ListLinked* list, int position, DataType value);
int list_linked_find(ListLinked* list, DataType value);
int list_linked_size(ListLinked* list);
void list_linked_print(ListLinked* list);
void list_linked_clear(ListLinked* list);

// Operações da Lista Duplamente Ligada
void dlist_init(DoublyLinkedList* list);
bool dlist_is_empty(DoublyLinkedList* list);
int dlist_insert(DoublyLinkedList* list, int position, DataType value);
int dlist_remove(DoublyLinkedList* list, int position, DataType* value);
int dlist_get(DoublyLinkedList* list, int position, DataType* value);
int dlist_set(DoublyLinkedList* list, int position, DataType value);
int dlist_find(DoublyLinkedList* list, DataType value);
int dlist_size(DoublyLinkedList* list);
void dlist_print(DoublyLinkedList* list);
void dlist_print_reverse(DoublyLinkedList* list);
void dlist_clear(DoublyLinkedList* list);

// Operações da Lista Circular
void clist_init(CircularList* list);
bool clist_is_empty(CircularList* list);
int clist_insert(CircularList* list, int position, DataType value);
int clist_remove(CircularList* list, int position, DataType* value);
int clist_get(CircularList* list, int position, DataType* value);
int clist_find(CircularList* list, DataType value);
int clist_size(CircularList* list);
void clist_print(CircularList* list);
void clist_clear(CircularList* list);

// Funções de demonstração
void demonstrate_list_array(void);
void demonstrate_list_linked(void);
void demonstrate_doubly_linked_list(void);
void demonstrate_circular_list(void);

#endif // LIST_H

