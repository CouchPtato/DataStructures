// Binary Search Tree
#include <iostream>
#include <queue>

using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            return new Node(data);
        }

        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    void preorder(Node *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node *node)
    {
        if (node != NULL)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void inorder(Node *node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void bfs_traversal(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *current = q.front();
            cout << current->data << " ";
            q.pop();
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }

    void preorder_traversal()
    {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorder_traversal()
    {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }

    void inorder_traversal()
    {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void bfs_traversal()
    {
        cout << "Breadth-First traversal: ";
        bfs_traversal(root);
        cout << endl;
    }
};

int main()
{
    BST bst;
    int choice, data;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. BFS Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            bst.insert(data);
            break;
        case 2:
            bst.preorder_traversal();
            break;
        case 3:
            bst.postorder_traversal();
            break;
        case 4:
            bst.inorder_traversal();
            break;
        case 5:
            bst.bfs_traversal();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
