#include <iostream>
#include <string>
using namespace std;

class AVLNode {
public:
    string keyword;
    string meaning;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(string keyword, string meaning) {
        this->keyword = keyword;
        this->meaning = meaning;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLDictionary {
private:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, string keyword, string meaning) {
        if (node == nullptr) {
            return new AVLNode(keyword, meaning);
        }

        if (keyword < node->keyword) {
            node->left = insert(node->left, keyword, meaning);
        } else if (keyword > node->keyword) {
            node->right = insert(node->right, keyword, meaning);
        } else {
            // Keyword already exists, update the meaning
            node->meaning = meaning;
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        // Perform rotations if the node becomes unbalanced
        if (balanceFactor > 1 && keyword < node->left->keyword) {
            return rotateRight(node);
        }
        if (balanceFactor < -1 && keyword > node->right->keyword) {
            return rotateLeft(node);
        }
        if (balanceFactor > 1 && keyword > node->left->keyword) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1 && keyword < node->right->keyword) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* remove(AVLNode* node, string keyword) {
        if (node == nullptr) {
            return nullptr;
        }

        if (keyword < node->keyword) {
            node->left = remove(node->left, keyword);
        } else if (keyword > node->keyword) {
            node->right = remove(node->right, keyword);
        } else {
            // Node to be deleted found

            // Node with only one child or no child
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = node->left ? node->left : node->right;

                // No child case
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    // One child case
                    *node = *temp;
                }

                delete temp;
            } else {
                // Node with two children
                AVLNode* temp = findMin(node->right);
                node->keyword = temp->keyword;
                node->meaning = temp->meaning;
                node->right = remove(node->right, temp->keyword);
            }
        }

        if (node == nullptr) {
            return nullptr;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        // Perform rotations if the node becomes unbalanced
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* findMin(AVLNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    int getHeight(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rotateRight(AVLNode* node) {
        AVLNode* newRoot = node->left;
        AVLNode* temp = newRoot->right;

        newRoot->right = node;
        node->left = temp;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    AVLNode* rotateLeft(AVLNode* node) {
        AVLNode* newRoot = node->right;
        AVLNode* temp = newRoot->left;

        newRoot->left = node;
        node->right = temp;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    void inorderTraversal(AVLNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->keyword << ": " << node->meaning << endl;
        inorderTraversal(node->right);
    }

public:
    AVLDictionary() {
        root = nullptr;
    }

    void addKeyword(string keyword, string meaning) {
        root = insert(root, keyword, meaning);
    }

    void deleteKeyword(string keyword) {
        root = remove(root, keyword);
    }

    void displayAscending() {
        inorderTraversal(root);
    }

    void displayDescending() {
        displayDescendingHelper(root);
    }

    void displayDescendingHelper(AVLNode* node) {
        if (node == nullptr) {
            return;
        }

        displayDescendingHelper(node->right);
        cout << node->keyword << ": " << node->meaning << endl;
        displayDescendingHelper(node->left);
    }
};

int main() {
    AVLDictionary dictionary;

    int choice;
    string keyword, meaning;

    while (true) {
        cout << "------ Menu ------" << endl;
        cout << "1. Add a keyword" << endl;
        cout << "2. Delete a keyword" << endl;
        cout << "3. Display data in ascending order" << endl;
        cout << "4. Display data in descending order" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dictionary.addKeyword(keyword, meaning);
                cout << "Keyword added successfully!" << endl;
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                dictionary.deleteKeyword(keyword);
                cout << "Keyword deleted successfully!" << endl;
                break;
            case 3:
                cout << "Data in ascending order:" << endl;
                dictionary.displayAscending();
                break;
            case 4:
                cout << "Data in descending order:" << endl;
                dictionary.displayDescending();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
