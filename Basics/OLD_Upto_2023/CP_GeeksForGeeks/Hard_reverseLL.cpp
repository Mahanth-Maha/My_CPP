//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
// User function Template for C++

/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
// #include "./../Logger.h"

class Solution
{
public:
    Node *reverseBetween(Node *head, int m, int n)
    {
        map<int, Node *> mp;
        Node *temp = head;
        int i = 1;
        mp[0] = NULL;
        while (temp)
        {
            mp[i++] = temp;
            temp = temp->next;
        }
        mp[i] = NULL;
        for (int p = m; p < (m + n) / 2; p++)
        {
            int q = n - (p - m);
            // swap node
            temp = mp[p];
            mp[p] = mp[q];
            mp[q] = temp;
        }
        for (int t = 1; t < mp.size() - 2; t++)
        {
            mp[t]->next = mp[t + 1];
        }
        mp[i - 1]->next = NULL;
        Node *root = mp[1];
        return root;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, m, n;
        cin >> N >> m >> n;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;

        Node *newhead = ob.reverseBetween(head, m, n);
        printList(newhead);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
