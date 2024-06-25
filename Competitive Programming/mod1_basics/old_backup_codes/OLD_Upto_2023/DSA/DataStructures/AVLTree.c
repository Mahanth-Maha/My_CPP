#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height  = 0;
    return newNode;
}

#define MAX(a,b) ((a) > (b)) ? (a) : (b) ;

int balanceFactor(Node *s){
    if(s->left && s->right) return (s->right->height - s->left->height);
    if(s->left) return s->left->height + 1;
    if(s->right) return -1*(s->right->height + 1);
    return 0;
}

int updateHeight(Node *s){
    if(s->left && s->right) 
        return ( (s->left->height > s->right->height)?(s->left->height ) :( s->right->height)) + 1;
    if(s->left) return s->left->height + 1;
    if(s->right) return s->right->height + 1;
    return 0;
}

Node * LL_rotation(Node *x){
    Node * y = x->left;
    x->left  = y->right;
    y->right = x;
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    return y;
}

Node * RR_rotation(Node *x){
    Node * y = x->right;
    x->right  = y->left;
    y->left = x;
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    return y;
}

Node * LR_rotation(Node *x){
    if(x->left)
        x->left = RR_rotation(x->left);
    return LL_rotation(x);
}

Node * RL_rotation(Node *x){
    if(x->right)
        x->right = LL_rotation(x->right);
    return RR_rotation(x);
}

Node* insert(Node* root, int data) {
    if (root == NULL) 
        return createNode(data);
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    int bf = balanceFactor(root);
    if(!( bf == 1 || bf == -1 || bf == 0)){
        if(root->left && data < root->data ) {
            if(data > root->left->data ){
                // printf("LR Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->left->data, root->left->right->data);
                root = LR_rotation(root);
            } else{
                // printf("LL Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->left->data, root->left->left->data);
                root = LL_rotation(root);
            }
        } else if(root->right && data > root->data) {
            if(data > root->right->data ){
                // printf("RR Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->right->data, root->right->right->data);
                root = RR_rotation(root);
            } else {
                // printf("RL Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->right->data, root->right->left->data);
                root = RL_rotation(root);
            }
        }
    }
    root->height = updateHeight(root);
    return root;
}




Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    int bf = balanceFactor(root);
    if(!( bf == 1 || bf == -1 || bf == 0)){
        if((root->left && root->right &&  root->left->height > root->right->height) || (root->left && !root->right) ) {
            if((root->left->left && root->left->right &&  root->left->left->height >= root->left->right->height ) || (root->left->left && !(root->left->right ) ) ){
                printf("LL Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->left->data, root->left->left->data);
                root = LL_rotation(root);
            }else if((root->left->left && root->left->right &&  root->left->left->height < root->left->right->height ) || (root->left->right && !(root->left->left ) )) {
                printf("LR Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->left->data, root->left->right->data);
                root = LR_rotation(root);
            } 
        } else if((root->left && root->right &&  root->left->height < root->right->height) || (!root->left && root->right)) {
            if((root->right->left && root->right->right &&  root->right->left->height > root->right->right->height ) || (root->right->left && !(root->right->right ) ) ){
                printf("RL Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->right->data, root->right->left->data);
                root = RL_rotation(root);
            }else if((root->right->left && root->right->right &&  root->right->left->height <= root->right->right->height ) || (root->right->right && !(root->right->left ) )) {
                printf("RR Rotating -> (x,y,z) : (%3d,%3d,%3d)\n",root->data,root->right->data, root->right->right->data);
                root = RR_rotation(root);
            } 
        }
    }
    root->height = updateHeight(root);

    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%3d (%2d) ", root->data,root->height);
        inorderTraversal(root->right);
    }
}

void example2(){
    Node* root = NULL;
    int ins[] = { 14,17,11,7,53,4,13,12,8, -1};
    int del[] = { 53,11,8, -1};
    int *p = ins;
    while(p<0, *p != -1){
        root = insert(root, *p);
        p++;
    }
    printf("Inorder traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");
    p = del;
    while(*p != -1){
        root = deleteNode(root, *p);
        p++;
    }

    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");
}

int main() {
    // Node* root = NULL;
    // int arr[] = { 10,85,15,70,20,60,30,50,65,80,90,40,5,55, -1};
    // int *p = arr;
    // while(*p != -1){
    //     printf("inserted : %d \n", *p );
    //     root = insert(root, *p);
    //     p++;
    //     // printf("Inorder : ");
    //     // inorderTraversal(root);
    //     // printf("\n");
    // }
    // printf("Inorder traversal before deletion: ");
    // inorderTraversal(root);
    // printf("\n");

    // // root = deleteNode(root, 40);
    // root = deleteNode(root, 60);

    // printf("Inorder traversal after deletion: ");
    // inorderTraversal(root);
    // printf("\n");

    example2();

    return 0;
}
