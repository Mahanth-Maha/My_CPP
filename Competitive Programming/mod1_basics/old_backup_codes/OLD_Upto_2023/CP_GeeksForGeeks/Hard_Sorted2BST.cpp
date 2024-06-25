//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct LNode
{
    int data;
    struct LNode *next;

    LNode(int x)
    {
        data = x;
        next = NULL;
    }
};

struct TNode
{

    int data;
    struct TNode *left;
    struct TNode *right;
    TNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void preOrder(TNode *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

/*
//Linked List
struct LNode
{
    int data;
    struct LNode* next;

    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode
{

    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution
{
public:
    TNode *binInsert(vector<int> &v, int l, int r)
    {
        int mid;
        if (l > r)
            return NULL;
        if (l == r)
        {
            TNode *newNode = new TNode(v[r]);
            return newNode;
        }
        if ((l + r) % 2)
            mid = (l + r + 1) / 2;
        else
            mid = (l + r) / 2;
        TNode *newNode = new TNode(v[mid]);
        newNode->left = binInsert(v, l, mid - 1);
        newNode->right = binInsert(v, mid + 1, r);
        return newNode;
    }
    TNode *sortedListToBST(LNode *head)
    {
        vector<int> v;
        LNode *temp = head;
        while (temp != NULL)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        return binInsert(v, 0, v.size() - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode *Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
