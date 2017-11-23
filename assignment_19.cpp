#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Node {
    std::string value;
    Node *left, *right;
};

Node *root;

bool insert_node(Node n, const std::string &str, int direction);
Node *find_node(const std::string &s, Node *p);

bool
insert_node(Node n, const std::string &str, int direction) 
{
    auto it = find_node(str, root);
    if (it != nullptr) {
        if (direction == 0) {
            if (it->left == nullptr) {
                it->left = new Node(n);
            }
            else return 1;
        }

        if (direction == 1) {
            if (it->right == nullptr)
                it->right = new Node(n);
            else return 1;
        }
        return 0;
    }
    return 1;
}

Node *
find_node(const std::string &s, Node *p) {
    if (p == NULL)
        return NULL;
    if (p->value.compare(s) == 0)
        return p;
    auto left = find_node(s, p->left);
    if (left != NULL) return left;
    auto right = find_node(s, p->right);
    if (right != NULL) return right;
    return NULL;
}

int
n_nodes(Node *p) 
{
    if (p == NULL)
        return 0;
    else return 1 + (n_nodes(p->left) + n_nodes(p->right));
}

bool
complete(Node *p, int in)
{
    if (!p)
        return true;

    if (in > n_nodes(root))
        return false;

    return (complete(p->left, 2 * in + 1) && (complete(p->left, 2 * in + 2)));
}

int
full(Node *p) {
    if (p == NULL)
        return true;

    if ((p->left && p->right == NULL)|| (p->left == NULL && p->right)) 
        return false;

    return full(p->left) && full(p->right);
}

int 
depth(Node *p)
{
    int left = 0, right = 0;
    if (p == NULL) 
        return 0;
    if (p->left)
        left =  1 + depth(p->left);
    if (p->right)
        right = 1 + depth(p->right);

    return std::max(left, right);
}

void
preorder(Node *p)
{
    if (p == nullptr)
        return;
    std::cout << p->value << ' ';
    preorder(p->left);
    preorder(p->right);
}

void
inorder(Node *p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    std::cout << p->value << ' ';
    inorder(p->right);
}

void
postorder(Node *p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    inorder(p->right);
    std::cout << p->value << ' ';
}

int
main(void)
{
    int c;
    std::string buf, buf2;
    bool boolin;
    std::cout << "Creating a new tree." << std::endl;
    std::cout << "node name? ";
    getline(std::cin, buf);
    root = new Node{buf, NULL, NULL};
    
    do {
        std::cout << "Nodes: " << n_nodes(root) << std::endl;
        std::cout << "Depth: " << depth(root) << std::endl;
        std::cout << "Complete: " << complete(root, 0) << std::endl;
        std::cout << "Full: " << full(root) << std::endl;
        std::cout << "Preorder: ";
        preorder(root);
        std::cout << std::endl;
        std::cout << "In-order: ";
        inorder(root);
        std::cout << std::endl;
        std::cout << "Post-order: ";
        postorder(root);
        std::cout << std::endl;

        std::cout << "1. Add a left child" << std::endl;
        std::cout << "2. Add a right child" << std::endl;
        std::cout << "3. get out of here" << std::endl;
        std::cin >> c;
        if (c == 3)
            break;
        if (c < 1 || c > 2)
            continue;

        std::cout << "node name? ";
        getline(std::cin, buf);
        std::cin.ignore();

        std::cout << "location? ";
        getline(std::cin, buf2);
        std::cin.ignore();


        switch (c) {
            case 1:
                if (find_node(buf, root) != NULL) {
                    boolin = insert_node(Node{buf, NULL, NULL}, buf2, 0);
                    std::cout << (boolin ? "location doesn't exist" : "inserted") << std::endl;
                }

                break;
            case 2:
                if (find_node(buf, root) != NULL) {
                    insert_node(Node{buf, NULL, NULL}, buf2, 1);
                    std::cout << (boolin ? "location doesn't exist" : "inserted") << std::endl;
                }
                break;
            case 3:
                break;
            default:
                std::cout << "????" << std::endl;
                break;
        }
        std::cin.ignore();

    } while (1);
}
