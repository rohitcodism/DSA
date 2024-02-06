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

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

Node* searchNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}

Node* findSmallestElement(Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findSmallestElement(root->left);
}

Node* findLargestElement(Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findLargestElement(root->right);
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
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
    return countInternalNodes(root->left) + countInternalNodes(root->right) + 1;
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
    Node* temp;

    while (1) {
        cout << "1. Insert a node\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Preorder traversal\n";
        cout << "4. Search a key\n";
        cout << "5. Find the smallest element\n";
        cout << "6. Find the largest element\n";
        cout << "7. Count the total number of nodes\n";
        cout << "8. Count the total number of external nodes\n";
        cout << "9. Count the total number of internal nodes\n";
        cout << "10. Determine the height of the tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Enter the key to be searched: ";
                cin >> value;
                temp = searchNode(root, value);
                if (temp == NULL) {
                    cout << "Key not found\n";
                } else {
                    cout << "Key found\n";
                }
                break;
            case 5:
                temp = findSmallestElement(root);
                if (temp == NULL) {
                    cout << "Tree is empty\n";
                } else {
                    cout << "Smallest element: " << temp->data << endl;
                }
                break;
            case 6:
                temp = findLargestElement(root);
                if (temp == NULL) {
                    cout << "Tree is empty\n";
                } else {
                    cout << "Largest element: " << temp->data << endl;
                }
                break;
            case 7:
                cout << "Total number of nodes: " << countNodes(root) << endl;
                break;
            case 8:
                cout << "Total number of external nodes: " << countExternalNodes(root) << endl;
                break;
            case 9:
                cout << "Total number of internal nodes: " << countInternalNodes(root) << endl;
                break;
            case 10:
                cout << "Height of the tree: " << getHeight(root) << endl;
                break;
            default:
                cout << "Invalid choice\n";
        }
        cout << endl;
    }

    return 0;
}