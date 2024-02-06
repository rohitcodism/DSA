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

        void Search(Node *root, int key){
            if(root!=nullptr){
                if(key == root->data){
                    cout<<"Key was found"<<endl;
                }
                else if(key<root->data){
                    Search(root->left, key);
                }
                else if(key>root->data){
                    Search(root->right, key);
                }
            }
            else {
                cout<<"Key wasn't found in the tree."<<endl;
            }
        }

        void searchTree(int key){
            Search(root, key);
        }

        void Insert(Node *p, int value, Node *follower){
            Node *r = NULL, *t;
            while(p != NULL){
                follower = p;
                if(p->data == value)
                    return;
                else if(p->data<value)
                    p = p->right;
                else if(p->data>value)
                    p = p->left;
            }
            t = new Node(value);
            if(follower->data>t->data){follower->left = t;cout<<"Node inserted successfully !!"; display();}
            else{follower->right = t;cout<<"Node inserted successfully !!"; display();}
        }

        void Insertion(int value){
            Node *r;
            Insert(root, value, r);
        }

        Node *RInsert(Node *p, int value){
            Node *t;
            if(p == NULL){
                t = new Node(value);
                cout<<"Node Inserted Successfully !!"<<endl;
                return t;
            }
            else
            {
                if(value<p->data){
                    p->left = RInsert(p->left, value);
                }
                else if(value>p->data)
                    p->right = RInsert(p->right, value);
                return p;
            }
        }

        void FastInsert(int value){
            root = RInsert(root, value);
        }

        int Height(Node *p){
            int x,y;
            if(!p)
                return 0;
            x = Height(p->left);
            y = Height(p->right);
            return x>y?x+1:y+1;
        }

        Node *inPre(struct Node *p){
            while(p && p->right)
                p = p->right;
            return p;
        }

        Node *inSucc(struct Node *p){
            while(p && p->left)
                p = p->left;
            return p;
        }

        Node *Delete(Node *p, int key){

            struct Node *q;
            if(!p)
                return NULL;
            if(!p->left && !p->right){
                if(p == root)
                {
                    root = NULL;
                    free(p);
                    return NULL;
                }
            }


            if(key<p->data){
                p->left = Delete(p->left, key);
            }
            else if(key>p->data){
                p->right = Delete(p->right, key);
            }
            else
            {
                if(Height(p->left)>Height(p->right))
                {
                    q = inPre(p->left);
                    p->data = q->data;
                    Delete(p->left, q->data);
                }
                else
                {
                    q = inSucc(p->right);
                    p->data = q->data;
                    Delete(p->right, q->data);
                }
            }
            return p;
        }

        void keyDelete(int value){
            Node *q = Delete(root, value);
        }

        int findLargestElement(Node *root) {
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
                return -1;
            }
            while (root->right != nullptr) {
                root = root->right;
            }
            return root->data;
        }

        int findSmallestElement(Node *root) {
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
                return -1;
            }
            while (root->left != nullptr) {
                root = root->left;
            }
            return root->data;
        }
        int countExternalNodes(Node *root) {
            if (root == nullptr) {
                return 0;
            }
            if (root->left == nullptr && root->right == nullptr) {
                return 1;
            }
            return countExternalNodes(root->left) + countExternalNodes(root->right);
        }

        int countInternalNodes(Node *root) {
            if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
                return 0;
            }
            return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
        }

        int countNodes(Node *root) {
            if (root == nullptr) {
                return 0;
            }
            return 1 + countNodes(root->left) + countNodes(root->right);
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
        cout<<"7. Search Operation \n";
        cout<<"8. Insertion Operation \n";
        cout<<"9. Fast Insert \n";
        cout<<"10. Deletion \n";
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
            case 7:
                int key;
                cout<<"Enter the value you want to found : ";
                cin>>key;
                cout<<endl;
                tree.searchTree(key);
                break; 
            case 8:
                cout<<"Enter the value you want to insert : ";
                cin>>value;
                cout<<endl;
                tree.Insertion(value);
                break;
            case 9:
                int Ivalue;
                cout<<"Enter the value you want to insert : ";
                cin>>Ivalue;
                cout<<endl;
                tree.FastInsert(Ivalue);
                break;
            case 10:
                int dValue;
                cout<<"Enter the key to delete : ";
                cin>>dValue;
                cout<<endl;
                tree.keyDelete(dValue);
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);


    return 0;
}