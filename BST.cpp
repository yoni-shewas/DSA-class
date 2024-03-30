#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int element){
        data = element;
        left = NULL;
        right = NULL;
    }
};

class BST{
private:
    node *root;

    node* insert(node* current, int element){
        if(current == NULL){
            return new node(element);
        }
        else if(element < current->data){
            current->left = insert(current->left, element);
        }
        else if(element > current->data){
            current->right = insert(current->right, element);
        }
        return current;
    }

    void inorderTraversal(node* current){
        if(current != NULL){
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }
       void postorderTraversal(node* current) {
        if (current != NULL) {
            postorderTraversal(current->left);
            postorderTraversal(current->right);
            cout << current->data << " ";
        }
    }
void preorderTraversal(node* current) {
        if (current != NULL) {
            cout << current->data << " ";
            preorderTraversal(current->left);
            preorderTraversal(current->right);
        }
    }
public:
    BST(){
        root = NULL;
    }

    void insert(int element){
        root = insert(root, element);
    }

    void inorder(){
        inorderTraversal(root);
    }
    void postorderTraversal(){
        postorderTraversal(root);
    }
    void preorderTraversal(){
        preorderTraversal(root);
    }
    
};

int main(){
    // Create a BST object
    BST myBST;

    // Insert elements into the BST
    myBST.insert(5);
    myBST.insert(3);
    myBST.insert(7);
    myBST.insert(2);
    myBST.insert(4);

    // Perform inorder traversal and print the elements
    cout << "Inorder Traversal: ";
    myBST.inorder();
    cout<<endl;
    cout << "postorder Traversal: ";
    myBST.postorderTraversal();
    cout<<endl;
    cout << "preorder Traversal: ";
    myBST.preorderTraversal();

    return 0;
}
