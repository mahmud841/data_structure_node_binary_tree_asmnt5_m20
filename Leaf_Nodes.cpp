#include <bits/stdc++.h>
using namespace std;

class LeafNodeTreeDescendingOrder
{
public:
    int value;
    LeafNodeTreeDescendingOrder *left;
    LeafNodeTreeDescendingOrder *right;

    LeafNodeTreeDescendingOrder(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

LeafNodeTreeDescendingOrder *createTree(vector<int> &node)
{
    if (node.empty() || node[0] == -1)
        return NULL;

    LeafNodeTreeDescendingOrder *root = new LeafNodeTreeDescendingOrder(node[0]);
    queue<LeafNodeTreeDescendingOrder *> q;
    q.push(root);
    int i = 1, n = node.size();

    while (!q.empty() && i < n)
    {
        LeafNodeTreeDescendingOrder *running = q.front();
        q.pop();
        if (node[i] != -1)
        {
            running->left = new LeafNodeTreeDescendingOrder(node[i]);
            q.push(running->left);
        }
        i++;

        if (i < n && node[i] != -1)
        {
            running->right = new LeafNodeTreeDescendingOrder(node[i]);
            q.push(running->right);
        }
        i++;
    }
    return root;
}

void printToGetLeafNode(LeafNodeTreeDescendingOrder *root, vector<int> &leafNode)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        leafNode.push_back(root->value);
    }

    if (root->left)
        printToGetLeafNode(root->left, leafNode);
    if (root->right)
        printToGetLeafNode(root->right, leafNode);
}

int main()
{
    vector<int> node;
    int num;
    while (cin >> num)
    {
        node.push_back(num);
    }

    LeafNodeTreeDescendingOrder *root = createTree(node);
    vector<int> leafNode;

    printToGetLeafNode(root, leafNode);
    sort(leafNode.begin(), leafNode.end(), greater<int>());
    // Print leaf node
    for (int leaf : leafNode)
    {
        cout << leaf << " ";
    }
    cout << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> node, leafs;
//     int sum;
//     while (cin >> sum)
//         node.push_back(sum);

//     for (size_t i = 0; i < node.size(); i++)
//     {
//         if (node[i] == -1)
//             continue;

//         size_t left_node = 2 * i + 1, right_node = 2 * i + 2;
//         // set condition
//         if ((left_node >= node.size() || node[left_node] == -1) &&
//             (right_node >= node.size() || node[right_node] == -1))
//         {
//             leafs.push_back(node[i]);
//         }
//     }
//     sort(leafs.begin(), leafs.end(), greater<int>());
//     for (int leaf : leafs)
//         cout << leaf << " ";
//     cout << endl;

//     return 0;
// }
