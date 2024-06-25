#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct node { int data; struct node * left; struct node * right;} Node;

Node* createNode(int d){
    Node * t = malloc(sizeof(Node));
    t->right = t->left = NULL;
    t->data = d;
    return t;
}

int nodeType(Node* s){
    if(s->right && s->left) return 1;   // Full node
    if(s->right) return 2;              // Right node
    if(s->left) return 3;               // left node
    return 0;                           // leaf
}

void traverseBT(Node * root){
    if(root){
        printf("%5d (L",root->data);
        traverseBT(root->left);
        printf(",");
        traverseBT(root->right);
        printf("R)");
    }
}

int H(Node* t){
    if(!t || !t->right && !t->left) return 0;
    return MAX(H(t->left),H(t->right)) +1 ;
}
int N(Node* t){
    if(!t) return 0;
    if( !t->right && !t->left) return 1;
    return N(t->left)+N(t->right) + 1;
}
int FN(Node* t){
    if(!t) return 0;
    if( !t->right && !t->left) return 0;
    return FN(t->left)+FN(t->right)  + (t->left && t->right);
}
int L(Node* t){
    if(!t) return 0; 
    if(!t->right && !t->left) return 1;
    return L(t->left) + L(t->right);
}
int I(Node* t){
    if(!t) return 0; 
    if(!t->right && !t->left) return 0;
    return L(t->left) + L(t->right) + 1;
}

void preorder(Node * t){
    if(t){
        printf("%3d",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(Node * t){
    if(t){
        inorder(t->left);
        printf("%3d",t->data);
        inorder(t->right);
    }
}
void postorder(Node * t){
    if(t){
        postorder(t->left);
        postorder(t->right);
        printf("%3d",t->data);
    }
}

void HeightOfAllNodes(Node * root){
    if(root){
        printf("%3d : Heighted -> %4d\n",root->data, H(root));
        HeightOfAllNodes(root->left);
        HeightOfAllNodes(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Node * root = createNode(10);
    int  n = 7;
    for(int i = 1; i < n ; i++){
        Node * t = createNode(i*(rand()%19)),*q = root;
        while(q){
            if((rand()/10)%2){
            // if(i%2){
                if(!q->left){
                    q->left = t;
                    break;
                } else q = q->left;
            }else {
                if(!q->right){
                    q->right = t;
                    break;
                }
                else q = q->right;
            }
        }
    }
    traverseBT(root);
    LOGsx("\nHeight of the Tree" , H(root));
    HeightOfAllNodes(root);
    LOGsx("\nNo of Nodes of the Tree" , N(root));
    LOGsx("No of Leaf Nodes in the Tree" , L(root));
    LOGsx("No of Internal Nodes in the Tree" , I(root));
    LOGsx("No of FULL Nodes in the Tree" , FN(root));
    printf("PreOrder : "); 
    preorder(root);
    printf("\nInOrder : "); 
    inorder(root);
    printf("\nPostOrder : "); 
    postorder(root);

    return 0;
}