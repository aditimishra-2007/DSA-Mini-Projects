#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int enrolmentID;
    string name;
    string department;
    Student* left;
    Student* right;

    Student(int id, const string& studentName, const string& studentDepartment)
        : enrolmentID(id), name(studentName), department(studentDepartment),
          left(nullptr), right(nullptr) {}
};

class StudentBST {
private:
    Student* root;

    Student* insertNode(Student* node, int id, const string& name,
                        const string& department, bool& inserted) {
        if (node == nullptr) {
            inserted = true;
            return new Student(id, name, department);
        }
        if (id < node->enrolmentID)
            node->left = insertNode(node->left, id, name, department, inserted);
        else if (id > node->enrolmentID)
            node->right = insertNode(node->right, id, name, department, inserted);
        // Equal IDs are rejected; no duplicate node is created.
        return node;
    }

    Student* searchNode(Student* node, int id) const {
        if (node == nullptr || node->enrolmentID == id) return node;
        if (id < node->enrolmentID) return searchNode(node->left, id);
        return searchNode(node->right, id);
    }

    Student* findMinimum(Student* node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    Student* deleteNode(Student* node, int id, bool& deleted) {
        if (node == nullptr) return nullptr;

        if (id < node->enrolmentID) {
            node->left = deleteNode(node->left, id, deleted);
        } else if (id > node->enrolmentID) {
            node->right = deleteNode(node->right, id, deleted);
        } else {
            deleted = true;

            // Case 1: leaf node (no child).
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: node has exactly one child.
            if (node->left == nullptr) {
                Student* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Student* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: node has two children.
            // Replace it with its inorder successor (smallest right-subtree key).
            Student* successor = findMinimum(node->right);
            node->enrolmentID = successor->enrolmentID;
            node->name = successor->name;
            node->department = successor->department;
            bool successorDeleted = false;
            node->right = deleteNode(node->right, successor->enrolmentID, successorDeleted);
        }
        return node;
    }

    void inorderNode(Student* node) const {
        if (!node) return;
        inorderNode(node->left);
        displayStudent(node);
        inorderNode(node->right);
    }

    void preorderNode(Student* node) const {
        if (!node) return;
        displayStudent(node);
        preorderNode(node->left);
        preorderNode(node->right);
    }

    void postorderNode(Student* node) const {
        if (!node) return;
        postorderNode(node->left);
        postorderNode(node->right);
        displayStudent(node);
    }

    void destroyTree(Student* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    void displayStudent(Student* student) const {
        cout << "ID: " << student->enrolmentID
             << " | Name: " << student->name
             << " | Department: " << student->department << '\n';
    }

public:
    StudentBST() : root(nullptr) {}
    ~StudentBST() { destroyTree(root); }

    void insert(int id, const string& name, const string& department) {
        bool inserted = false;
        root = insertNode(root, id, name, department, inserted);
        if (inserted) cout << "Student record inserted successfully.\n";
        else cout << "Duplicate enrolment ID rejected. No record inserted.\n";
    }

    void search(int id) const {
        Student* result = searchNode(root, id);
        if (result) {
            cout << "Student found:\n";
            displayStudent(result);
        } else {
            cout << "Student record not found.\n";
        }
    }

    void remove(int id) {
        bool deleted = false;
        root = deleteNode(root, id, deleted);
        if (deleted) cout << "Student record deleted successfully.\n";
        else cout << "Student record not found. Nothing was deleted.\n";
    }

    void inorder() const {
        cout << "\nInorder traversal (records in ascending ID order):\n";
        if (!root) cout << "No records available.\n";
        else inorderNode(root);
    }

    void preorder() const {
        cout << "\nPreorder traversal:\n";
        if (!root) cout << "No records available.\n";
        else preorderNode(root);
    }

    void postorder() const {
        cout << "\nPostorder traversal:\n";
        if (!root) cout << "No records available.\n";
        else postorderNode(root);
    }

    void loadSampleRecords() {
        // Ten sample records, inserted in a balanced-looking order.
        insert(50, "Aarav", "Computer Science");
        insert(30, "Diya", "Information Technology");
        insert(70, "Kabir", "Electronics");
        insert(20, "Meera", "Computer Science");
        insert(40, "Rohan", "Mechanical");
        insert(60, "Anaya", "Civil");
        insert(80, "Ishaan", "Information Technology");
        insert(10, "Sana", "Electronics");
        insert(35, "Vivaan", "Computer Science");
        insert(65, "Tara", "Civil");
    }
};

int main() {
    StudentBST bst;
    int choice, id;
    string name, department;

    do {
        cout << "\n===== STUDENT RECORD SEARCH SYSTEM (BST) =====\n";
        cout << "1. Insert student record\n";
        cout << "2. Search student by enrolment ID\n";
        cout << "3. Delete student record\n";
        cout << "4. Inorder traversal (sorted records)\n";
        cout << "5. Preorder traversal\n";
        cout << "6. Postorder traversal\n";
        cout << "7. Load 10 sample student records\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter enrolment ID: ";
                if (!(cin >> id)) { cout << "Invalid ID.\n"; return 0; }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter department: ";
                getline(cin, department);
                bst.insert(id, name, department);
                break;
            case 2:
                cout << "Enter enrolment ID to search: ";
                cin >> id;
                bst.search(id);
                break;
            case 3:
                cout << "Enter enrolment ID to delete: ";
                cin >> id;
                bst.remove(id);
                break;
            case 4:
                bst.inorder();
                break;
            case 5:
                bst.preorder();
                break;
            case 6:
                bst.postorder();
                break;
            case 7:
                bst.loadSampleRecords();
                break;
            case 0:
                cout << "Thank you for using Student Record Search System!\n";
                break;
            default:
                cout << "Please enter a valid menu choice.\n";
        }
    } while (choice != 0);

    return 0;
}
