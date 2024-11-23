#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree()
    {
        root = NULL;
    }

    Node *buildTree(const vector<int> &arr)
    {
        if (arr.empty() || arr[0] == -1)
            return NULL;
        root = new Node(arr[0]);
        queue<Node *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size())
        {
            Node *curr = q.front();
            q.pop();

            if (arr[i] != -1)
            {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;

            if (i < arr.size() && arr[i] != -1)
            {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }

    void collectLeftBoundaryNodes(Node *node, vector<int> &boundary)
    {
        Node *curr = node->left;
        while (curr)
        {
            if (curr->left || curr->right)
                boundary.push_back(curr->val);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void collectLeafs(Node *node, vector<int> &boundary)
    {
        if (!node)
            return;
        if (!node->left && !node->right)
        {
            boundary.push_back(node->val);
            return;
        }

        collectLeafs(node->left, boundary);
        collectLeafs(node->right, boundary);
    }

    void collectRightBoundaryNodes(Node *node, vector<int> &boundary)
    {
        Node *curr = node->right;
        vector<int> temp;
        while (curr)
        {
            if (curr->left || curr->right)
                temp.push_back(curr->val);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        boundary.insert(boundary.end(), temp.begin(), temp.end());
    }

    void printBoundaryNodes(Node *node)
    {
        if (!node)
            return;

        vector<int> boundary;
        boundary.push_back(node->val);

        collectLeftBoundaryNodes(node, boundary);
        collectLeafs(node, boundary);
        collectRightBoundaryNodes(node, boundary);

        for (int val : boundary)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> arr;
    int val;

    while (ss >> val)
    {
        arr.push_back(val);
    }

    BinaryTree tree;
    tree.buildTree(arr);
    tree.printBoundaryNodes(tree.root);
    return 0;
}
