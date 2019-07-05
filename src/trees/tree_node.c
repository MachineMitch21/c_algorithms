#include "tree_node.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct _TreeNode {
  unsigned char*  data;
  unsigned int    dataSize;
  TreeNode*       leftChild;
  TreeNode*       rightChild;
};

TreeNode* tree_node_create(void* data, unsigned int data_size) {
  assert(data_size > 0 && "tree_node_create :: Newly created TreeNode's must have a specified size greater than 0");

  TreeNode* t_node = malloc(sizeof(TreeNode));
  memset(t_node, 0, sizeof(TreeNode));
  
  t_node->data = malloc(data_size);
  memcpy(t_node->data, data, data_size);
  
  t_node->dataSize = data_size;
  return t_node;
}

TreeNode* tree_node_clone(TreeNode* t_node) {
  if (t_node == NULL) return NULL;

  TreeNode* t_node_clone = malloc(sizeof(TreeNode));
  memset(t_node_clone, 0, sizeof(TreeNode));

  t_node_clone->data = malloc(t_node->dataSize);
  memcpy(t_node_clone->data, t_node->data, t_node->dataSize);
  t_node_clone->leftChild = t_node->leftChild;
  t_node_clone->rightChild = t_node->rightChild;
}

void tree_node_free(TreeNode* t_node) {
  if (t_node == NULL) return;

  free(t_node->data);
  tree_node_free(t_node->leftChild);
  tree_node_free(t_node->rightChild);
  free(t_node);
}

int tree_node_num_children(TreeNode* t_node) {
  if (t_node == NULL) return 0;
  return tree_node_num_children(t_node->leftChild) + tree_node_num_children(t_node->rightChild);
}

void tree_node_insert(TreeNode* t_node, void* data, unsigned int data_size) {
  if (t_node == NULL) {
    t_node = tree_node_create(data, data_size);
    return;
  }

  int cmp_result = memcmp(data, t_node->data, t_node->dataSize);

  if (cmp_result < 0 || cmp_result == 0) {
    tree_node_insert(t_node->leftChild, data, data_size);
  } else {
    tree_node_insert(t_node->rightChild, data, data_size);
  }
}

void tree_node_set(TreeNode* t_node, void* data) {
  if (t_node->data == NULL) {
    t_node->data = malloc(t_node->dataSize);
  }

  memcpy(t_node->data, data, t_node->dataSize);
}

void* tree_node_get(TreeNode* t_node) {
  return t_node->data;
}
