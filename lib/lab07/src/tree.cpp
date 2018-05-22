//    #include <iostream>
//    #include "../inc/tree.h"
//    #include <sstream>
//    namespace lab7 {
//        void Rstring(node *top, std::string &built_string);
//
//        void clear(node *to_clear);
//
//        std::string to_string();
//
//        void Printnode(node *top);
//
//        void Rinsert(node *top, int value);
//
//        int Rlevel(node *top, int key);
//
//        bool Rintree(node *top, int key);
//
//        unsigned Rsize(node *top);
//
//        int Rfrequancy(node *top, int key);
//
//        unsigned Rdepth(node *top);
//
//        void Rprint(node *top);
//
//        bool childrenif(node *to_check);
//
//        node *get_swap(node *top);
//
//        node *get_node(node *top, int key);
//
//        node *get_parent(node *top, node *child);
//
//        node *Rnodecopy(node *top);
//
//        // Construct an empty tree
//        tree::tree() {
//            root = nullptr;
//        }
//
//        // Deconstruct tree
//        tree::~tree() {
//            clear(root);
//        }
//
//        // Insert
//        void tree::insert(int value) {
//            if (root == nullptr) {
//                root = new node(value);
//            } else {
//                Rinsert(root, value);
//            }
//        }
//
//        // What level is key on?
//        int tree::level(int key) {
//            if (in_tree(key)) return Rlevel(root, key);
//            else return -1;
//        }
//
//        // Print the path to the key, starting with root
//        void tree::path_to(int key) {
//
//        }
//
//        // Number of items in the tree
//        unsigned tree::size() {
//            if (root == nullptr) return 0;
//            else return Rsize(root);
//        }
//
//        // Calculate the depth of the tree, longest string of connections
//        unsigned tree::depth() {
//            if (size() <= 1) return 0;
//            else return Rdepth(root) - 1;
//        }
//
//        // Determine whether the given key is in the tree
//        bool tree::in_tree(int key) {
//            return Rintree(root, key);
//        }
//
//        // Return the number of times that value is in the tree
//        int tree::get_frequency(int key) {
//            return Rfrequancy(root, key);
//        }
//
//        // Print the tree least to greatest, Include duplicates
//        void tree::print() {
//            Rprint(root);
//            std::cout << std::endl;
//        }
//
//        void tree::print_gtl() {
//            Printnode(root);
//            std::cout << std::endl;
//        }
//
//        void node_print_gtl(node *top) {
//            if (top == nullptr) return;
//            node_print_gtl(top->right);
//            for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
//            node_print_gtl(top->left);
//        }
//
//        void clear(node *to_clear) {
//            if (to_clear == nullptr) return;
//            if (to_clear->left != nullptr) clear(to_clear->left);
//            if (to_clear->right != nullptr) clear(to_clear->right);
//            delete to_clear;
//        }
//
//        void Rinsert(node *top, int value) {
//            if (value > top->data) {
//                if (top->right == nullptr) top->right = new node(value);
//                else Rinsert(top->right, value);
//            } else if (value < top->data) {
//                if (top->left == nullptr) top->left = new node(value);
//                else Rinsert(top->left, value);
//            } else if (value == top->data) top->frequency++;
//        }
//
//        int Rlevel(node *top, int key) {
//            if (top->data == key) return 0;
//            else if (key < top->data) return 1 + Rlevel(top->left, key);
//            else if (key > top->data) return 1 + Rlevel(top->right, key);
//        }
//
//        bool Rintree(node *top, int key) {
//            if (top == nullptr) return false;
//            else if (top->data == key) return true;
//            else if (key < top->data) return Rintree(top->left, key);
//            else if (key > top->data) return Rintree(top->right, key);
//        }
//
//        unsigned Rsize(node *top) {
//            if (top == nullptr) return 0;
//            else return top->frequency + Rsize(top->left) + Rsize(top->right);
//        }
//
//        int Rfrequancy(node *top, int key) {
//            if (top == nullptr) return 0;
//            else if (top->data == key) return top->frequency;
//            else if (key < top->data) return Rfrequancy(top->left, key);
//            else if (key > top->data) return Rfrequancy(top->right, key);
//        }
//
//        unsigned depth_recursively(node *top) {
//            if (top == nullptr) return 0;
//            unsigned left = 0, right = 0;
//            left = 1 + depth_recursively(top->left);
//            right = 1 + depth_recursively(top->right);
//            if (left > right) return left;
//            else return right;
//        }
//
//        void Rprint(node *top) {
//            if (top == nullptr) return;
//            Rprint(top->left);
//            for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
//            Rprint(top->right);
//        }
//
//        // Remove key
//        bool tree::remove(int key) {
//            if (in_tree(key)) {
//                node *to_remove = get_node(root, key);
//                if (to_remove->frequency > 1) {
//                    to_remove->frequency--;
//                    return true;
//                }
//                node *to_remove_parent = get_parent(root, to_remove);
//                if (childrenif(to_remove)) {
//                    node *to_swap = get_swap(to_remove);
//                    node *to_swap_parent = get_parent(root, to_swap);
//
//                    if (childrenif(to_swap)) to_swap_parent->right = to_swap->left;
//                    else to_swap_parent->right = nullptr;
//
//                    to_swap->left = to_remove->left;
//                    to_swap->right = to_remove->right;
//                    if (to_remove_parent != nullptr) {
//                        if (to_remove_parent->left == to_remove) to_remove_parent->left = to_swap;
//                        else to_remove_parent->right = to_swap;
//                    } else root = to_swap;
//                } else {
//                    if (to_remove_parent != nullptr) {
//                        if (to_remove_parent->left == to_remove) to_remove_parent->left = nullptr;
//                        else to_remove_parent->right = nullptr;
//                    } else root = nullptr;
//                }
//                delete to_remove;
//                return true;
//            } else return false;
//        }
//    }
