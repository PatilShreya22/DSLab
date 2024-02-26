1. Hacker Rank Challenge: (linked list)
Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

 int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int hLeft = 0, hRight = 0;
    struct TreeNode* currLeft = root->left;
    struct TreeNode* currRight = root->right;
    while (currLeft != NULL) {
        hLeft++;
        currLeft = currLeft->left;
    }
    while (currRight != NULL) {
        hRight++;
        currRight = currRight->right;
    }

    if (hLeft == hRight) {
        return (1 << (hLeft + 1)) - 1;
    } else {
        return (1 << (hLeft + 1)) - 1 + countNodes(root->left) - (1 << hLeft);
    }
}

2. Hacker Rank Challenge: (Trees)
  You’re given the pointer to the head nodes of two linked lists. Compare the data in the nodes of the linked lists to check if they are equal. If all data attributes are equal and the lists are the same length, return . Otherwise, return .
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 != NULL || temp2 != NULL) {
        return 0;
    }

    return 1;
}
