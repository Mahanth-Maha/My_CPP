//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void printBst(Node *node)
    {
        if (node != NULL)
        {
            printBst(node->left);
            cout << node->data << " ";
            printBst(node->right);
        }
    }
    void traverse(Node *node, map<int, set<int>> &dp, int level)
    {
        if (node != NULL)
        {
            if (node->left != NULL)
                traverse(node->left, dp, level + 1);
            dp[level].insert(node->data);
            if (node->right != NULL)
                traverse(node->right, dp, level + 1);
        }
    }
    bool areAnagrams(Node *root1, Node *root2)
    {
        map<int, set<int>> dp;
        // printBst(root1);
        // cout << "\n";
        // printBst(root2);
        // cout << "\n";
        traverse(root1, dp, 0);
        // for (auto &i : dp)
        // {
        //     cout << i.first << ":";
        //     for (auto &j : i.second)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        map<int, set<int>> dp2;
        traverse(root2, dp2, 0);
        // for (auto &i : dp2)
        // {
        //     cout << i.first << ":";
        //     for (auto &j : i.second)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        for (auto &i : dp)
        {
            if (dp[i.first] != dp2[i.first])
            {
                return false;
            }
            // cout << i.first << "OK\n";
        }
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends
