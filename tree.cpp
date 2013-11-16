#include <iostream>


struct node_t {
  int data;
  node_t *left;
  node_t *right;
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
      if (current_node->right != NULL)
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

node_t* tree_find(node_t* node, int data) {
  node = tree_find_impl(node, data);
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

void tree_add(node_t* node, int data) {
  node = tree_find_impl(node, data);
  if (node == NULL) {
    // error
  } else if (node->data >= data) {
    node->left = new node_t;
    init_node(*node->left, data);
  } else { // node->data < data
    node->right = new node_t;
    init_node(*node->right, data);
  }
  
  return NULL;
}

template <typename func_t>
void tree_traverse(node_t *node, func_t foo) {
  if (node == NULL) return;

  // inorder
  traverse(node->left);
  foo(node->data);
  traverse(node->right);
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




















