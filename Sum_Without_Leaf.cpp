#include <bits/stdc++.h>
using namespace std;

class binary_tree_node
{
public:
    int value;
    binary_tree_node *left;
    binary_tree_node *right;

    binary_tree_node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

binary_tree_node *buildTree(vector<int> &node)
{
    if (node.empty() || node[0] == -1)
        return NULL;

    binary_tree_node *root = new binary_tree_node(node[0]);
    queue<binary_tree_node *> q;
    q.push(root);
    int i = 1, n = node.size();

    while (!q.empty() && i < n)
    {
        binary_tree_node *current = q.front();
        q.pop();

        if (node[i] != -1)
        {
            current->left = new binary_tree_node(node[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && node[i] != -1)
        {
            current->right = new binary_tree_node(node[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int sum_of_non_leaf_nodes(binary_tree_node *root)
{
    if (!root)
        return 0;

    queue<binary_tree_node *> q;
    q.push(root);
    int sum = 0;

    while (!q.empty())
    {
        binary_tree_node *current = q.front();
        q.pop();

        if (current->left || current->right)
        {
            sum += current->value;
        }

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }

    return sum;
}

int main()
{
    vector<int> node;
    int num;
    while (cin >> num)
    {
        node.push_back(num);
    }

    binary_tree_node *root = buildTree(node);
    cout << sum_of_non_leaf_nodes(root) << endl;
    return 0;
}
