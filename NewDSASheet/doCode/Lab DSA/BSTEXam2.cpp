#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};



Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void display(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << "Data: " << root->data << endl;
    if (root->left) {
        cout << "Left Child: " << root->left->data << endl;
    } else {
        cout << "Left Child: NULL" << endl;
    }
    if (root->right) {
        cout << "Right Child: " << root->right->data << endl;
    } else {
        cout << "Right Child: NULL" << endl;
    }
    cout << endl;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int countExternalNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

int countInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    int choice, value;
    while (true) {
        cout << "1. Insert a node\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Count total number of external nodes\n";
        cout << "4. Count total number of internal nodes\n";
        cout << "5. Determine the height of the tree\n";
        cout << "6. Exit\n";
        cout<<"7. Display\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Total number of external nodes: " << countExternalNodes(root) << endl;
                break;
            case 4:
                cout << "Total number of internal nodes: " << countInternalNodes(root) << endl;
                break;
            case 5:
                cout << "Height of the tree: " << getHeight(root) << endl;
                break;
            case 7:
                display(root);
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Invalid choice\n";
        }
        cout << endl;
    }
    return 0;
}