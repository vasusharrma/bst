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
  cout << "Enter the value : " << endl;
  cin >> data;
  if (data == -1) {
    return nullptr;
  }

  // Step 1

  Node *root = new Node(data);

  // Create left subtree
  root->left = createTree();

  // Create right subtree
  root->right = createTree();

  return root;

  //
}

int main() {

  Node *root = createTree();
  cout << "root data is : " << root->data;

  return 0;
}
