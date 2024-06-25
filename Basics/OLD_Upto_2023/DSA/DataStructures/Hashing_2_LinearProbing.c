#include <stdio.h>
#include <stdlib.h>

#define SIZE 19

// Define a structure for a hash table
struct HashTable {
    int keys[SIZE];
    int values[SIZE];
};

// Function to create a hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < SIZE; i++) {
        hashTable->keys[i] = -1; // -1 represents an empty slot
    }
    return hashTable;
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hashFunction(key);

    while (hashTable->keys[index] != -1) {
        index = (index + 1) % SIZE; // Linear probing
    }

    hashTable->keys[index] = key;
    hashTable->values[index] = value;
}

// Function to search for a value in the hash table
int search(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);

    while (hashTable->keys[index] != -1) {
        if (hashTable->keys[index] == key) {
            return hashTable->values[index]; // Found
        }
        index = (index + 1) % SIZE; // Linear probing
    }

    return -1; // Not found
}

// Function to delete a key-value pair from the hash table
void delete(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);

    while (hashTable->keys[index] != -1) {
        if (hashTable->keys[index] == key) {
            hashTable->keys[index] = -1;
            hashTable->values[index] = 0; // Mark as deleted
            return;
        }
        index = (index + 1) % SIZE; // Linear probing
    }
}

// Function to print the hash table
void printHashTable(struct HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable->keys[i] != -1) {
            printf("[%d] -> %d\n", hashTable->keys[i], hashTable->values[i]);
        }
    }
}

int main() {
    struct HashTable* hashTable = createHashTable();

    insert(hashTable, 5, 25);
    insert(hashTable, 15, 225);
    insert(hashTable, 25, 625);
    insert(hashTable, 7, 49);
    insert(hashTable, 17, 289);

    printf("Initial Hash Table:\n");
    printHashTable(hashTable);

    int searchKey = 15;
    int foundValue = search(hashTable, searchKey);
    if (foundValue != -1) {
        printf("%d is found in the hash table with value %d.\n", searchKey, foundValue);
    } else {
        printf("%d is not found in the hash table.\n", searchKey);
    }

    delete(hashTable, 25);
    printf("\nHash Table after deleting key 25:\n");
    printHashTable(hashTable);

    free(hashTable);

    return 0;
}
