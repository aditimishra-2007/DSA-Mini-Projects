# Project Report: Student Record Search System Using Trees

## Objective
To develop a menu-driven student record system using a Binary Search Tree (BST), with enrolment ID as the unique key.

## Student record
Each node stores:
- Enrolment ID
- Student name
- Department
- Left child pointer
- Right child pointer

## BST property
For each node, keys in the left subtree are smaller and keys in the right subtree are greater. Duplicate enrolment IDs are rejected.

## Operations
- **Insertion:** Adds a student record at the correct BST position.
- **Searching:** Finds a record using enrolment ID.
- **Deletion:** Handles leaf nodes, nodes with one child, and nodes with two children. For two children, the inorder successor is used.
- **Inorder:** Displays records in ascending enrolment-ID order.
- **Preorder and postorder:** Display the tree in their respective traversal orders.

## Test cases
1. Load the sample records and search for ID 50: expected to find Aarav.
2. Insert an existing ID 50: expected to reject the duplicate.
3. Delete leaf ID 10: expected to remove the leaf.
4. Delete ID 20 after deleting ID 10: expected to handle a one-child node.
5. Delete ID 30 from the original sample tree: expected to handle a two-child node.
6. Search for ID 999: expected to report that the record was not found.

## Complexity
Let n be the number of records and h be the BST height.
- Search, insertion, and deletion: O(log n) average for a balanced-looking tree; O(n) worst case for a skewed tree.
- Traversal: O(n).
- Recursive auxiliary stack space: O(h).

A regular BST can become skewed when keys are inserted in sorted order. A self-balancing tree such as an AVL tree uses rotations to keep its height O(log n).

## Conclusion
The project demonstrates BST operations, traversal methods, duplicate handling, deletion cases, and the effect of tree height on operation efficiency.
