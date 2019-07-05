#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct _BinaryTree BinaryTree;

BinaryTree* binary_tree_create(unsigned int data_size);
void        binary_tree_free(BinaryTree* b_tree);

int         binary_tree_num_elements(BinaryTree* b_tree);

void        binary_tree_insert(BinaryTree* b_tree, void* data);

#endif