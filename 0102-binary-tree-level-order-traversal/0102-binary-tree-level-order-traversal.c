
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {

    *returnSize = 0;

    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = malloc(2000 * sizeof(int*));
    *returnColumnSizes = malloc(2000 * sizeof(int));

    struct TreeNode* queue[2000];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        int levelSize = rear - front;

        result[*returnSize] = malloc(levelSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {

            struct TreeNode* current = queue[front++];

            result[*returnSize][i] = current->val;

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        (*returnSize)++;
    }

    return result;
}
