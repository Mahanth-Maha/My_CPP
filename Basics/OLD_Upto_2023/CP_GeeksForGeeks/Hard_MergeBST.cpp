#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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
    Node *root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    void traverseBst(Node *node, multiset<int> &s)
    {
        if (node != NULL)
        {
            traverseBst(node->left, s);
            s.insert(node->data);
            traverseBst(node->right, s);
        }
    }

    void traverseBstVec(Node *node, vector<int> &s)
    {
        if (node != NULL)
        {
            traverseBstVec(node->left, s);
            s.push_back(node->data);
            traverseBstVec(node->right, s);
        }
    }
    void traverseBstPrint(Node *node)
    {
        if (node != NULL)
        {
            traverseBstPrint(node->left);
            cout << node->data << ' ';
            traverseBstPrint(node->right);
        }
    }
    Node *traverseInsert(Node *node, Node *rootOfSecondTree)
    {
        if (node != NULL)
        {
            traverseInsert(node->left, rootOfSecondTree);
            insertNode(rootOfSecondTree, node->data);
            traverseInsert(node->right, rootOfSecondTree);
        }
        return rootOfSecondTree;
    }

    Node *insertNode(Node *root, int data)
    {
        Node *temp = new Node(data);
        if (root == NULL)
        {
            root = temp;
        }
        else if (root->left == NULL && root->data >= data)
        {
            root->left = temp;
        }
        else if (root->right == NULL && data > root->data)
        {
            root->right = temp;
        }
        else
        {
            if (root->data >= data)
            {
                return insertNode(root->left, data);
            }
            else if (root->data < data)
            {
                return insertNode(root->right, data);
            }
        }

        return root;
    }

    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        // version 1
        // vector<int> ans;
        // multiset<int> s;
        // traverseBst(root1, s);
        // traverseBst(root2, s);
        // for (auto &i : s)
        // {
        //     ans.push_back(i);
        // }
        // return ans;
        // 25/26 "TLE"

        // // version 2
        // vector<int> res;
        // Node *newRoot = traverseInsert(root1, root2);
        // traverseBstVec(newRoot, res);
        // return res;
        // 24/26 "TLE"

        // version 3
        vector<int> v1;
        traverseBstVec(root1, v1);
        vector<int> v2;
        traverseBstVec(root2, v2);
        vector<int> ans;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] <= v2[j])
            {
                ans.push_back(v1[i++]);
            }
            else
            {
                ans.push_back(v2[j++]);
            }
        }
        while (i < v1.size())
        {
            ans.push_back(v1[i++]);
        }
        while (j < v2.size())
        {
            ans.push_back(v2[j++]);
        }
        return ans;
    }
};

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
