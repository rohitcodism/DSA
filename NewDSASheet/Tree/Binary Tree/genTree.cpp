#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    Node *left;
    Node *right;
    int data;

    Node(){data = 0;left = right = nullptr;};
    Node( int value){
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
    public:
        Node *root;
        BinaryTree(){
            root = nullptr;
        }

        Node *insertRecursive(Node *root, int value){
            if(root == nullptr){
                return new Node(value);
            }

            if(value<root->data){
                root->left = insertRecursive(root->left, value);
            }else if(value>root->data){
                root->right = insertRecursive(root->right, value);
            }

            return root;
        }

        void insert(int value){
            root = insertRecursive(root, value);
        }

        void displayRecursive(Node *root){
            if(root != nullptr){
                displayRecursive(root->left);
                cout<<root->data<<endl;
                displayRecursive(root->right);
            }
        }

        void display(){
            displayRecursive(root);
        }

        void preOrder(Node *root)
        {
            if (root != nullptr)
            {
                cout << root->data << endl;
                preOrder(root->left);
                preOrder(root->right);
            }
        }

        void preOrderTraversal(){
            cout<<"Post Order Traversal of your tree : "<<endl;
            preOrder(root);
        }
        void postOrder(Node *root)
        {
            if (root != nullptr)
            {
                postOrder(root->left);
                postOrder(root->right);
                cout << root->data << endl;
            }
        }

        void postOrderTraversal(){
            cout<<"Post Order Traversal of your tree : "<<endl;
            postOrder(root);
        }
        void inOrder(Node *root){
            if (root != nullptr)
            {
                inOrder(root->left);
                cout << root->data << endl;
                inOrder(root->right);
            }
        }

        void inOrderTraversal(){
            inOrder(root);
        }

        void levelOrder(Node *root){

            if(root == nullptr)
                return;

            queue<Node *>  Q;
            Q.push(root);

            while(!Q.empty()){
                Node *current = Q.front();
                cout<<current->data<<endl;
                Q.pop();

                if(current->left)
                    Q.push(current->left);
                if(current->right)
                    Q.push(current->right);    
            }

            cout<<endl;
        }

        void levelOrderTraversal(){
            cout<<"Level Order Traversal : "<<endl;
            levelOrder(root);
        }

};

int main()
{
        BinaryTree tree;
    int choice, value;

    do {
        std::cout << "\nBinary Tree Menu:\n";
        std::cout << "1. Insert a node\n";
        std::cout << "2. Display the tree\n";
        cout<<"3. Pre Order Traversal\n";
        cout<<"4. In Order Traversal\n";
        cout<<"5. Post Order Traversal\n";
        cout<<"6. Level Order Traversal\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Binary Tree: ";
                tree.display();
                cout << endl;
                break;
            case 3:
                tree.preOrderTraversal();
                break;
            case 4:
                tree.inOrderTraversal();
                break;
            case 5:
                tree.postOrderTraversal();
                break;
            case 6:
                tree.levelOrderTraversal();
                break;            
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}