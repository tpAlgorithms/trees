#include <iostream>


struct node_t {
  int data;
  node_t *left;
  node_t *right;
};

struct tree_t {
  node_t *root;
};


/*
node_t* tree_find(node_t* node, int data) {
  node_t *current_node = node;
  
  if (current_node != NULL) {
    if (current_node->data > data) {
      return tree_find(current_node->left, data);
    } else if (current_node->data < data) {
      return tree_find(current_node->right, data);
    } else {
      return current_node;
    }
  } else {
    return NULL;
  }
}
*/

node_t* tree_find_impl(node_t* node, int data) {
  node_t *current_node = node;
  
  while (current_node != NULL) {
    if (current_node->data > data) {
      if (current_node->left != NULL) {
        current_node = current_node->left;
      } else {
        return current_node;
      }
    } else if (current_node->data < data) {
      if (current_node->right != NULL) {
        current_node = current_node->right;
      } else {
        return current_node;
      }
    } else {
      return current_node;
    }
  }
  
  return NULL;
}

node_t* tree_find(tree_t &tree, int data) {
  node_t *node = tree_find_impl(tree.root, data);
  if (node != NULL && node->data == data) {
    return node;
  }
  return NULL;
}

void init_node(node_t &node, int data) {
  node.data = data;
  node.left = NULL;
  node.right = NULL;
}

void tree_add(tree_t &tree, int data) {
  node_t *node = tree_find_impl(tree.root, data);
  if (node == NULL) {
    tree.root = new node_t;
    init_node(*tree.root, data);
  } else if (node->data >= data) {
    node->left = new node_t;
    init_node(*node->left, data);
  } else { // node->data < data
    node->right = new node_t;
    init_node(*node->right, data);
  }
}

template <typename func_t>
void tree_traverse(node_t *node, func_t foo) {
  if (node == NULL) return;

  // inorder
  tree_traverse(node->left, foo);
  foo(node->data);
  tree_traverse(node->right, foo);
/*
  // preorder
  foo(node->data);
  traverse(node->left);
  traverse(node->right);

  // postorder
  traverse(node->left);
  foo(node->data);
  traverse(node->right);
*/
}

int main() {


};




















