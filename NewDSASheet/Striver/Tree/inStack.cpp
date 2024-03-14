#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
    treeNode(int val)
    {
        this->data = val;
        this->left = this->right = nullptr;
    }
    treeNode()
    {
        this->data = 0;
        this->left = this->right = nullptr;
    }

    treeNode(int val, treeNode *lc, treeNode *rc)
    {
        this->data = val;
        this->left = lc;
        this->right = rc;
    }
};

class Tree
{
private:
    treeNode *root;

public:
    Tree()
    {
        this->root = nullptr;
    }
    Tree(int data)
    {
        this->root->data = data;
        this->root->left = root->right = nullptr;
    }

    treeNode *getRoot()
    {
        return root;
    }

    void display(treeNode *root)
    {
        if (root)
        {
            display(root->left);
            cout << root->data << " ";
            display(root->right);
        }
        else
        {
            cout << "NULL: There is no root!!! " << endl;
        }
    }

    void insert(treeNode *root, int data)
    {
        if (root == nullptr)
        {
            root = new treeNode(data);
            display(root);
            return;
        }
        if (root->data > data)
        {
            if (root->left == nullptr)
            {
                root->left = new treeNode(data);
            }
            else
            {
                insert(root->left, data);
            }
        }
        else if (root->data < data)
        {
            if (!root->right)
            {
                root->right = new treeNode(data);
            }
            else
            {
                insert(root->right, data);
            }
        }
        display(root);
    }

    void displayTraversalVector(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    vector<int> inOrder(treeNode *root)
    {
        stack<treeNode *> st;
        treeNode *Node = root;
        vector<int> inOrder;
        while (true)
        {
            if (Node)
            {
                st.push(Node);
                Node = Node->left;
            }
            else
            {
                if (st.empty())
                    break;
                Node = st.top();
                st.pop();
                inOrder.push_back(Node->data);
                Node = Node->right;
            }
        }
        displayTraversalVector(inOrder);
        return inOrder;
    }
    vector<int> postOrder(treeNode *root)
    {
        vector<int> postOrder;
        stack<treeNode *> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left)
                st1.push(root->left);
            if (root->right)
                st1.push(root->right);
        }
        while (!st2.empty())
        {
            postOrder.push_back(st2.top()->data);
            st2.pop();
        }
        displayTraversalVector(postOrder);
        return postOrder;
    }

    vector<int> postOrder2(treeNode *root)
    {
        vector<int> postOrder;
        stack<treeNode *> st;
        treeNode *temp;
        treeNode *curr = root;
        st.push(root);

        while (curr && !st.empty())
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                temp = st.top()->right;
                if (!temp)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->data);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        displayTraversalVector(postOrder);
        return postOrder;
    }

    void allTraversal(treeNode *root)
    {
        stack<pair<treeNode *, int>> st;
        int num = 1;

        // traversals
        vector<int> preOrder;  // 1
        vector<int> inOrder;   // 2
        vector<int> postOrder; // 3

        st.push(make_pair(root, num));

        while (!st.empty())
        {
            if (st.top().second == 1)
            {
                preOrder.push_back(st.top().first->data);
                st.top().second++;
                if (st.top().first->left)
                {
                    st.push(make_pair(st.top().first->left, 1));
                }
            }
            if (st.top().second == 2)
            {
                inOrder.push_back(st.top().first->data);
                st.top().second++;
                if (st.top().first->right)
                {
                    st.push(make_pair(st.top().first->left, 1));
                }
            }
            if (st.top().second == 3)
            {
                postOrder.push_back(st.top().first->data);
                st.pop();
            }
        }

        // print traversals
        cout << "Preorder: ";
        displayTraversalVector(preOrder);
        cout << "Inorder: ";
        displayTraversalVector(inOrder);
        cout << "Postorder: ";
        displayTraversalVector(postOrder);
    }

    int height(treeNode *root)
    {
        if (!root)
            return 0;

        int x = height(root->left);
        int y = height(root->right);
        return max(x, y) + 1;
    }

    int checkBalance(treeNode *root)
    {
        if (!root)
            return 0;

        int x = height(root->left);
        int y = height(root->right);

        if(x == -1 || y == -1) return -1;
        if(x-y > 1) return -1;

        return max(x, y) + 1;
    }

    int maxPathSum(treeNode* node, int maxi){
        if(!node)
            return 0;
        
        int leftSum = max(0, maxPathSum(node->left, maxi));
        int rightSum = max(0, maxPathSum(node->right, maxi));

        maxi = max(maxi, node->data+leftSum+rightSum);

        return node->data+max(leftSum,rightSum);
        
    }
};

int main()
{
    Tree tree;
    int choice, data;
    do
    {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4.All at once traversal\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            tree.insert(tree.getRoot(), data);
            tree.display(tree.getRoot());
            break;
        case 2:
            cout << "Inorder Traversal: ";
            tree.inOrder(tree.getRoot());
            cout << endl;
            break;
        case 3:
            cout << "Postorder Traversal: ";
            tree.postOrder(tree.getRoot());
            cout << endl;
            break;
        case 4:
            cout << "All Traversals: ";
            tree.allTraversal(tree.getRoot());
            break;
        case 5:
            cout << "Display: ";
            tree.display(tree.getRoot());
            cout << endl;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice);

    return 0;
}