#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(NULL), right(NULL) {}
};

class BinaryNode
{
public:
    Node *root;
    BinaryNode() : root(NULL) {}

    void buildTree(const vector<int> &levelNodes)
    {
        if (levelNodes.empty() || levelNodes[0] == -1)
            return;

        root = new Node(levelNodes[0]);
        queue<Node *> q;
        q.push(root);
        size_t index = 1;

        while (!q.empty() && index < levelNodes.size())
        {
            Node *curr = q.front();
            q.pop();

            if (index < levelNodes.size() && levelNodes[index] != -1)
            {
                curr->left = new Node(levelNodes[index]);
                q.push(curr->left);
            }
            index++;

            if (index < levelNodes.size() && levelNodes[index] != -1)
            {
                curr->right = new Node(levelNodes[index]);
                q.push(curr->right);
            }
            index++;
        }
    }

    void printLevelNodes(Node *node, int level)
    {
        if (!node)
            return;
        if (level == 0)
        {
            cout << node->value << " ";
            return;
        }

        printLevelNodes(node->left, level - 1);
        printLevelNodes(node->right, level - 1);
    }

    int depthCalculation(Node *node)
    {
        if (!node)
            return 0;
        return max(depthCalculation(node->left), depthCalculation(node->right)) + 1;
    }

    void printLevelNodess(int level)
    {
        int depth = depthCalculation(root);
        if (level < 0 || level >= depth)
        {
            cout << "Invalid" << endl;
            return;
        }
        printLevelNodes(root, level);
        cout << endl;
    }
};

int main()
{
    vector<int> levelNodes;
    int value, level;

    while (cin >> value)
    {
        levelNodes.push_back(value);
    }
    level = levelNodes.back();
    levelNodes.pop_back();

    BinaryNode tree;
    tree.buildTree(levelNodes);
    tree.printLevelNodess(level);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void levelLeftToRightTree(vector<int> &l_order, int level_2_print, int n)
// {

//     int start = (1 << level_2_print) - 1;
//     int end = (1 << (level_2_print + 1)) - 1;

//     if (start >= n)
//     {
//         cout << "Invalid" << endl;
//         return;
//     }

//     bool isPrintedLevel = false;
//     for (int i = start; i < end && i < n; i++)
//     {
//         if (l_order[i] != -1)
//         {
//             cout << l_order[i] << " ";
//             isPrintedLevel = true;
//         }
//     }

//     if (!isPrintedLevel)
//     {
//         cout << "Invalid" << endl;
//     }
// }

// int main()
// {

//     vector<int> l_order;
//     int val;

//     while (cin >> val)
//     {
//         l_order.push_back(val);
//     }

//     int level_2_print = l_order.back();
//     l_order.pop_back();

//     int n = l_order.size();
//     levelLeftToRightTree(l_order, level_2_print, n);

//     return 0;
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // int main()
// // {
// //     vector<int> level_order;
// //     int val, my_print_level;

// //     while (cin >> val)
// //     {
// //         level_order.push_back(val);
// //     }

// //     my_print_level = level_order.back();
// //     level_order.pop_back();

// //     if (level_order.empty())
// //     {
// //         cout << "Invalid" << endl;
// //         return 0;
// //     }

// //     int n = level_order.size();
// //     int depths = 0;
// //     while ((1 << depths) - 1 < n)
// //     {
// //         depths++;
// //     }

// //     if (my_print_level >= depths)
// //     {
// //         cout << "Invalid" << endl;
// //         return 0;
// //     }

// //     int print_start = (1 << my_print_level) - 1;
// //     int print_end = (1 << (my_print_level + 1)) - 1;

// //     if (print_start >= n)
// //     {
// //         cout << "Invalid" << endl;
// //         return 0;
// //     }

// //     bool isPrintedLevel_left_to_right_level = false;
// //     for (int i = print_start; i < print_end && i < n; i++)
// //     {
// //         if (level_order[i] != -1)
// //         {
// //             cout << level_order[i] << " ";
// //             isPrintedLevel_left_to_right_level = true;
// //         }
// //     }

// //     if (!isPrintedLevel_left_to_right_level)
// //     {
// //         cout << "Invalid" << endl;
// //     }

// //     return 0;
// // }
