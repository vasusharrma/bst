#include <iostream>
#include <queue>
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
  cout << "enter vaule : " << endl;
  cin >> data;

  if (data == -1)
    return nullptr;

  Node *root = new Node(data);

  root->left = createTree();
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

void levelOrderTraversal(Node *root) {
  queue<Node *> q;

  q.push(root);
  q.push(nullptr);

  while (q.size() > 1) {

    Node *temp = q.front();
    q.pop();

    if (temp != nullptr) {

      cout << temp->data << " ";
      if (temp->left != nullptr) {
        q.push(temp->left);
      }
      if (temp->right != nullptr) {

        q.push(temp->right);
      }
    } else {
      cout << endl;
      q.push(nullptr);
    }
  }
}

int main() {

  Node *root = createTree();

  cout << endl << "preOrderTraversal" << endl;
  preOrderTraversal(root);
  cout << endl << "inOrderTraversal" << endl;
  inOrderTraversal(root);
  cout << endl << "postOrderTraversal" << endl;
  postOrderTraversal(root);
  cout << endl << "levelOrderTraversal" << endl;
  levelOrderTraversal(root);
  return 0;
}
