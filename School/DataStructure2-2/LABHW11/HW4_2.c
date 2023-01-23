#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define min(i, j) (((i) < (j)) ? (i) : (j))
#define max(i, j) (((i) > (j)) ? (i) : (j))

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode * new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) 
		return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return NULL;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
	 		TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void preorder(TreeNode* root)
{
	if (root != NULL) { //if(root)
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int get_minimum(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;
	return current->key;
}

int get_maximum(TreeNode* node)
{
	TreeNode* current = node;

	while (current->right != NULL)
		current = current->right;
	return current->key;
}

int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

int get_height(TreeNode* node)
{
	int height = 0; 
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int main(void)
{
	TreeNode * root = NULL;
	char key;
	int num;

	do {
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>, c<ount>, m<ax>, n<min>, q<uit> : ");
		scanf(" %c", &key);

		switch (key)
		{
			case 'i' :
				printf("������ key�� �Է�:");
				scanf("%d", &num);
				root = insert_node(root, num);
				break;
			case 'd' :
				printf("������ key�� �Է�:");
				scanf("%d", &num);
				root = delete_node(root, num);
				break;
			case 's' :
				printf("Ž���� key�� �Է�:");
				scanf("%d", &num);
				if (search(root, num))
					printf("����\n");
				else
					printf("����\n");
				break;
			case 'p':
				preorder(root);
				printf("\n");
				break;
			case 'h' :
				printf("Ʈ���� ���̴� %d\n", get_height(root));
				break;
			case 'c' :
				printf("����� ������ %d\n", get_node_count(root));
				break;
			case 'm' :
				printf("���� ū ���� %d\n", get_maximum(root));
				break;
			case 'n' :
				printf("���� ���� ���� %d\n", get_minimum(root));
				break;
			default:
				break;
		}
	} while (key != 'q');

	return 0;
}


