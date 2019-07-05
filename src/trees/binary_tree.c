#include "binary_tree.h"
#include "tree_node.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct _BinaryTree {
  unsigned int            dataSize;
  TreeNode*               root;
};

BinaryTree* binary_tree_create(unsigned int data_size) {
  assert(data_size > 0 && "binary_tree_create :: data_size should be greater than zero");

  BinaryTree* b_tree = malloc(sizeof(BinaryTree));
  b_tree->dataSize = data_size;
  b_tree->root = NULL;
  return b_tree;
}

void binary_tree_free(BinaryTree* b_tree) {
  tree_node_free(b_tree->root);
  free(b_tree);
}

int binary_tree_num_elements(BinaryTree* b_tree) {
  return tree_node_num_children(b_tree->root);
}

void binary_tree_insert(BinaryTree* b_tree, void* data) {
  tree_node_insert(b_tree->root, data, b_tree->dataSize);
}