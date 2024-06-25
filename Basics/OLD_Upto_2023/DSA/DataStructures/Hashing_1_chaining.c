#include <stdio.h>
#include <stdlib.h>

#define SIZE 19

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for a hash table
struct HashTable {
    struct Node* table[SIZE];
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Function to insert a value into the hash table
void insert(struct HashTable* hashTable, int data) {
    int index = hashFunction(data);
    struct Node* newNode = createNode(data);

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct Node* current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for a value in the hash table
int search(struct HashTable* hashTable, int data) {
    int index = hashFunction(data);
    struct Node* current = hashTable->table[index];

    while (current != NULL) {
        if (current->data == data) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Function to print the hash table
void printHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* current = hashTable->table[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable* hashTable = createHashTable();
    // int arr[] = { 10,85,15,70,20,60,30,50,65,80,90,40,5,55, -1};
    // int *p = arr;
    // while(*p != -1){
    //     insert(hashTable, *p);
    //     p++;
    // }
    int i = 36;
    while(i--){
        insert(hashTable, rand()%2345);
    }
    // insert(hashTable, 15);
    // insert(hashTable, 25);
    // insert(hashTable, 7);
    // insert(hashTable, 17);

    printHashTable(hashTable);

    int searchValue = 15;
    if (search(hashTable, searchValue)) {
        printf("%d is found in the hash table.\n", searchValue);
    } else {
        printf("%d is not found in the hash table.\n", searchValue);
    }

    free(hashTable);
    
    return 0;
}
