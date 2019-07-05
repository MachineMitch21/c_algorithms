#ifndef TREE_NODE_H
#define TREE_NODE_H

typedef struct _TreeNode TreeNode;

TreeNode* tree_node_create(void* data, unsigned int data_size);
TreeNode* tree_node_clone(TreeNode* t_node);
void      tree_node_free(TreeNode* t_node);

int       tree_node_num_children(TreeNode* t_node);

void      tree_node_insert(TreeNode* t_node, void* data, unsigned int data_size);

void      tree_node_set(TreeNode* t_node, void* data);
void*     tree_node_get(TreeNode* t_node);

#endif 