#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

Node *createTree() {

  int data;
  cout << "vaule enter : " << endl;
  cin >> data;

  if (data == -1)
    return nullptr;

  Node *root = new Node(data);

  cout << root->data << " left : " << " ";
  root->left = createTree();
  cout << root->data << " right : " << " ";
  root->right = createTree();

  return root;
};

void inOrderTraversal(Node *root) {

  if (root == nullptr) {
    return;
  }

  inOrderTraversal(root->left);

  cout << root->data << " ";

  inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root) {

  if (root == nullptr) {
    return;
  }

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

int main() {

  Node *root = createTree();

  cout << endl << "preOrderTraversal" << endl;
  preOrderTraversal(root);
  cout << endl << "inOrderTraversal" << endl;
  inOrderTraversal(root);
  cout << endl << "postOrderTraversal" << endl;
  postOrderTraversal(root);

  return 0;
}
