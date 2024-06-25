#include <stdio.h>

#define MAX_NODES 10

int binaryTree[MAX_NODES] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

int getParent(int i) {
    return (i - 1) / 2;
}

int getLeftChild(int i) {
    return 2 * i + 1;
}

int getRightChild(int i) {
    return 2 * i + 2;
}

int main() {
    int nodeIndex = 1;  // Index of the node we're interested in
    
    printf("Node: %d, Value: %d\n", nodeIndex, binaryTree[nodeIndex]);
    
    int parentIndex = getParent(nodeIndex);
    int leftChildIndex = getLeftChild(nodeIndex);
    int rightChildIndex = getRightChild(nodeIndex);
    
    printf("Parent of node %d at index %d: %d\n", nodeIndex, parentIndex,binaryTree[parentIndex]);
    printf("Left child of node %d at index %d: %d\n", nodeIndex, leftChildIndex, binaryTree[leftChildIndex]);
    printf("Right child of node %d at index %d: %d\n", nodeIndex, rightChildIndex, binaryTree[rightChildIndex]);
    
    return 0;
}
