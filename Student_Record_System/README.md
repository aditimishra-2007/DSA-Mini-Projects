# Student Record Search System Using Trees

## Project overview
This C++ mini project stores student records in a Binary Search Tree (BST). Each record contains a unique enrolment ID, student name, and department. The enrolment ID is the BST key.

## Requirements covered
- Student record structure with enrolment ID, name, and department
- BST insertion with duplicate-ID rejection
- Search by enrolment ID
- Deletion of leaf, one-child, and two-child nodes
- Inorder, preorder, and postorder traversals
- Inorder displays records in ascending enrolment-ID order
- Menu-driven interface
- Option to load 10 sample records
- Average and worst-case complexity explanation

## How to compile and run
Using g++:

```bash
g++ main.cpp -o student_records
./student_records
```

On Windows:

```bash
g++ main.cpp -o student_records.exe
student_records.exe
```

## How to use
1. Run the program.
2. Choose option 7 to load the 10 sample records.
3. Choose option 4 to display records in sorted ID order.
4. Use option 1 to insert a new record.
5. Use option 2 to search by enrolment ID.
6. Use option 3 to delete a record.
7. Use options 4, 5, and 6 for inorder, preorder, and postorder traversals.
8. Choose option 0 to exit.

Choose option 7 only once for the sample dataset; loading it again will correctly report duplicate IDs.

## Sample test cases

### Test 1: Successful search
- Load sample records (option 7).
- Search ID: `50`
- Expected: Student found; Aarav, Computer Science.

### Test 2: Duplicate enrolment ID
- Load sample records.
- Insert ID: `50`, Name: `New Student`, Department: `Computer Science`.
- Expected: `Duplicate enrolment ID rejected. No record inserted.`

### Test 3: Delete a leaf node
- Load sample records.
- Delete ID: `10`.
- Expected: Record deleted; inorder traversal no longer contains ID 10.

### Test 4: Delete a node with one child
- Load sample records.
- Delete ID: `20` (after ID 10 has been deleted).
- Expected: Record deleted; the BST reconnects the remaining child correctly.

### Test 5: Delete a node with two children
- Load sample records.
- Delete ID: `30` (from the original sample tree, before deleting 20 or 40).
- Expected: Record deleted; its inorder successor replaces it and inorder remains sorted.

### Test 6: Unsuccessful search
- Load sample records.
- Search ID: `999`
- Expected: `Student record not found.`

## BST properties
For every node:
- All keys in its left subtree are smaller than the node's key.
- All keys in its right subtree are greater than the node's key.
- This project rejects duplicate enrolment IDs.

## Time and space complexity

Let n be the number of student records and h be the height of the BST.

| Operation | Average case (balanced-looking tree) | Worst case (skewed tree) |
|---|---:|---:|
| Insertion | O(log n) | O(n) |
| Search | O(log n) | O(n) |
| Deletion | O(log n) | O(n) |
| Traversal | O(n) | O(n) |

The recursive call stack for search, insertion, deletion, and traversal uses O(h) auxiliary space. The BST itself stores O(n) nodes.

A regular BST can become skewed when keys are inserted in sorted order. In that case, its height can become n and operations can take O(n). A self-balancing tree such as an AVL tree performs rotations to keep its height O(log n), so search, insertion, and deletion remain O(log n).

## Balanced-looking vs sorted insertion order
- Balanced-looking order example: `50, 30, 70, 20, 40, 60, 80`
- Sorted order example: `10, 20, 30, 40, 50, 60, 70`

The balanced-looking order creates a shorter tree. Sorted insertion creates a chain-like, skewed tree. The number of comparisons for operations is related to the tree height.

## Files
- `main.cpp` — complete source code
- `README.md` — project explanation, instructions, test cases, and complexity

## GitHub upload
Create a new public repository named `Student-Record-Search-BST`, then upload `main.cpp` and `README.md`.
