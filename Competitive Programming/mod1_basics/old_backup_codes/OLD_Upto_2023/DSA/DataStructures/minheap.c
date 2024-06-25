#include <stdio.h>
#include <stdlib.h>

struct MinHeap {
    int *array;
    int capacity;
    int size;
};

// Function to create a new min heap
struct MinHeap *createMinHeap(int capacity) {
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    heap->array = (int *)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Utility function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Heapify a subtree rooted at given index
void heapify(struct MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;
    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Function to insert a new element into the heap
void insert(struct MinHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    int index = heap->size;
    heap->array[index] = value;
    heap->size++;

    int parent = (index - 1) / 2;
    while (index > 0 && heap->array[parent] > heap->array[index]) {
        swap(&heap->array[parent], &heap->array[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to delete the minimum element from the heap
int deleteMin(struct MinHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot delete.\n");
        return -1;
    }

    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to find the minimum element in the heap
int findMin(struct MinHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }
    return heap->array[0];
}

// Function to find the maximum element in the heap
int findMax(struct MinHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int max = heap->array[0];
    for (int i = 1; i < heap->size; i++) {
        if (heap->array[i] > max) {
            max = heap->array[i];
        }
    }
    return max;
}

// Function to print the elements of the heap
void printHeap(struct MinHeap *heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// Function to build a heap from an array
void buildHeap(struct MinHeap *heap, int *array, int n) {
    if (n > heap->capacity) {
        printf("Array size is greater than heap capacity.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        heap->array[i] = array[i];
    }
    heap->size = n;

    for (int i = (n - 2) / 2; i >= 0; i--) {
        heapify(heap, i);
    }
}

int main() {
    struct MinHeap *heap = createMinHeap(10);

    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 6);

    printHeap(heap);

    printf("Minimum element: %d\n", findMin(heap));
    printf("Maximum element: %d\n", findMax(heap));

    deleteMin(heap);
    printHeap(heap);

    int array[] = {9, 2, 7, 4};
    int n = sizeof(array) / sizeof(array[0]);
    buildHeap(heap, array, n);
    printHeap(heap);

    free(heap->array);
    free(heap);

    return 0;
}
