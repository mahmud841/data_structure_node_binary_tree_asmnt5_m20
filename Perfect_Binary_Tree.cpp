#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree() : root(NULL) {}

    void buildTree(const vector<int> &nodes)
    {
        if (nodes.empty() || nodes[0] == -1)
            return;

        root = new TreeNode(nodes[0]);
        queue<TreeNode *> q;
        q.push(root);
        size_t index = 1;

        while (!q.empty() && index < nodes.size())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (index < nodes.size() && nodes[index] != -1)
            {
                curr->left = new TreeNode(nodes[index]);
                q.push(curr->left);
            }
            index++;

            if (index < nodes.size() && nodes[index] != -1)
            {
                curr->right = new TreeNode(nodes[index]);
                q.push(curr->right);
            }
            index++;
        }
    }

    int calculateDepthOfNode(TreeNode *node)
    {
        if (!node)
            return 0;
        int leftDepth = calculateDepthOfNode(node->left);
        int rightDepth = calculateDepthOfNode(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    bool isPerfectBinaryTree(TreeNode *node, int depth, int level = 0)
    {
        if (!node)
            return true;

        if (!node->left && !node->right)
            return depth == level + 1;

        if (!node->left || !node->right)
            return false;

        return isPerfectBinaryTree(node->left, depth, level + 1) && isPerfectBinaryTree(node->right, depth, level + 1);
    }

    bool isPerfectBinaryTree()
    {
        int depth = calculateDepthOfNode(root);
        return isPerfectBinaryTree(root, depth);
    }
};

int main()
{
    vector<int> nodes;
    int value;

    while (cin >> value)
    {
        nodes.push_back(value);
    }

    BinaryTree tree;
    tree.buildTree(nodes);
    if (tree.isPerfectBinaryTree())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// bool isPerfectBinaryTreeBinaryTree(vector<int> &tree)
// {
//     int n = tree.size();
//     if (n == 0)
//         return false;

//     int countNodes = 0;
//     for (int val : tree)
//     {
//         if (val != -1)
//             countNodes++;
//     }

//     int h = 0;
//     while ((1 << h) <= countNodes)
//         h++;
//     h--;

//     int expectPerfectNodes = (1 << (h + 1)) - 1;
//     if (countNodes != expectPerfectNodes)
//         return false;

//     bool ifNullNodeSeen = false;
//     for (int val : tree)
//     {
//         if (val == -1)
//         {
//             ifNullNodeSeen = true;
//         }
//         else if (ifNullNodeSeen)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     string input;
//     getline(cin, input);
//     stringstream ss(input);
//     vector<int> tree;
//     int val;

//     while (ss >> val)
//     {
//         tree.push_back(val);
//     }

//     if (isPerfectBinaryTreeBinaryTree(tree))
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // bool isPerfectBinaryTreeBinaryTree(vector<int> &tree)
// // {
// //     vector<int> valid_node;
// //     for (int val : tree)
// //     {
// //         if (val != -1)
// //         {
// //             valid_node.push_back(val);
// //         }
// //     }
// //     int vnCount = valid_node.size();
// //     int height = log2(vnCount + 1);
// //     int expectPerfectNode = pow(2, height) - 1;
// //     return vnCount == expectPerfectNode;
// // }
// // //
// // int main()
// // {
// //     string input;
// //     getline(cin, input);
// //     stringstream ss(input);
// //     vector<int> trees;
// //     int val;

// //     while (ss >> val)
// //     {
// //         trees.push_back(val);
// //     }

// //     if (isPerfectBinaryTreeBinaryTree(trees))
// //     {
// //         cout << "YES" << endl;
// //     }
// //     else
// //     {
// //         cout << "NO" << endl;
// //     }

// //     return 0;
// // }

// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // class Node
// // // {
// // // public:
// // //     int val;
// // //     Node *left;
// // //     Node *right;
// // //     Node(int val) : val(val), left(NULL), right(NULL) {}
// // // };

// // // class TreeNode
// // // {
// // // public:
// // //     Node *root;
// // //     TreeNode() : root(NULL) {}
// // //     void myBuildTree(const vector<int> &node)
// // //     {
// // //         if (node.empty() || node[0] == -1)
// // //             return;

// // //         root = new Node(node[0]);
// // //         queue<Node *> q;
// // //         q.push(root);
// // //         size_t index = 1;

// // //         while (!q.empty() && index < node.size())
// // //         {
// // //             Node *running = q.front();
// // //             q.pop();

// // //             if (index < node.size() && node[index] != -1)
// // //             {
// // //                 running->left = new Node(node[index]);
// // //                 q.push(running->left);
// // //             }
// // //             index++;
// // //             if (index < node.size() && node[index] != -1)
// // //             {
// // //                 running->right = new Node(node[index]);
// // //                 q.push(running->right);
// // //             }
// // //             index++;
// // //         }
// // //     }

// // //     bool isPerfectBinaryTreeTree()
// // //     {
// // //         if (!root)
// // //             return true;
// // //         queue<Node *> q;
// // //         q.push(root);
// // //         int countNode = 0;

// // //         while (!q.empty())
// // //         {
// // //             Node *running = q.front();
// // //             q.pop();
// // //             countNode++;
// // //             if (running->left)
// // //                 q.push(running->left);
// // //             if (running->right)
// // //                 q.push(running->right);
// // //         }
// // //         // maximum depth
// // //         int maxNodeDepth = 0;
// // //         Node *runningNode = root;
// // //         while (runningNode)
// // //         {
// // //             maxNodeDepth++;
// // //             runningNode = runningNode->left;
// // //         }
// // //         int perfectTree = pow(2, maxNodeDepth) - 1;
// // //         return countNode == perfectTree;
// // //     }
// // // };

// // // int main()
// // // {
// // //     vector<int> node;
// // //     int val;
// // //     while (cin >> val)
// // //     {
// // //         node.push_back(val);
// // //     }
// // //     TreeNode tree;
// // //     tree.myBuildTree(node);
// // //     if (tree.isPerfectBinaryTreeTree())
// // //     {
// // //         cout << "YES" << endl;
// // //     }
// // //     else
// // //     {
// // //         cout << "NO" << endl;
// // //     }
// // //     return 0;
// // // }

// // // // #include <bits/stdc++.h>
// // // // using namespace std;

// // // // int main()
// // // // {
// // // //     vector<int> level_order;
// // // //     int val;
// // // //     while (cin >> val)
// // // //     {
// // // //         level_order.push_back(val);
// // // //     }
// // // //     vector<int> valid_node;
// // // //     for (int node : level_order)
// // // //     {
// // // //         if (node != -1)
// // // //         {
// // // //             valid_node.push_back(node);
// // // //         }
// // // //     }

// // // //     int total_node = valid_node.size();

// // // //     int depths = 0;
// // // //     while ((1 << depths) - 1 <= total_node)
// // // //     {
// // // //         depths++;
// // // //     }

// // // //     int perfectTreeNode = (1 << (depths - 1)) - 1;

// // // //     if (total_node == perfectTreeNode)
// // // //     {
// // // //         cout << "YES" << endl;
// // // //     }
// // // //     else
// // // //     {
// // // //         cout << "NO" << endl;
// // // //     }

// // // //     return 0;
// // // // }

// // // // #include <bits/stdc++.h>
// // // // using namespace std;

// // // // int main()
// // // // {
// // // //     vector<int> level_order;
// // // //     int val;

// // // //     while (cin >> val)
// // // //     {
// // // //         level_order.push_back(val);
// // // //     }

// // // //     int n = level_order.size();
// // // //     int depthss = 0;
// // // //     while ((1 << depthss) - 1 <= n)
// // // //     {
// // // //         depthss++;
// // // //     }

// // // //     int total_node = (1 << (depthss - 1)) - 1;

// // // //     if (total_node == n)
// // // //     {
// // // //         cout << "YES" << endl;
// // // //     }
// // // //     else
// // // //     {
// // // //         cout << "NO" << endl;
// // // //     }
// // // //     return 0;
// // // // }

// // // // // #include <bits/stdc++.h>
// // // // // using namespace std;
// // // // // bool myPerfectTreeNode(vector<int> &level_order)
// // // // // {
// // // // //     int n = level_order.size();
// // // // //     int depthsss = 0;
// // // // //     int total_node = 0;

// // // // //     while ((1 << depthsss) - 1 <= n)
// // // // //     {
// // // // //         total_node = (1 << depthsss) - 1;
// // // // //         depthsss++;
// // // // //     }
// // // // //     return total_node == n;
// // // // // }

// // // // // int main()
// // // // // {
// // // // //     string input;
// // // // //     getline(cin, input);
// // // // //     vector<int> level_order;
// // // // //     stringstream ss(input);
// // // // //     string temp;
// // // // //     while (ss >> temp)
// // // // //     {
// // // // //         int val = 0;
// // // // //         for (char c : temp)
// // // // //         {
// // // // //             if (c >= '0' && c <= '9')
// // // // //             {
// // // // //                 val = val * 10 + (c - '0');
// // // // //             }
// // // // //         }
// // // // //         level_order.push_back(val);
// // // // //     }

// // // // //     if (myPerfectTreeNode(level_order))
// // // // //     {
// // // // //         cout << "YES" << endl;
// // // // //     }
// // // // //     else
// // // // //     {
// // // // //         cout << "NO" << endl;
// // // // //     }

// // // // //     return 0;
// // // // // }
