// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left, * right;
    };
    int s;
    Node* root;
    Node* addNode(Node* root, const T& value) {
        if (!root) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addNode(root->left, value);
        } else if (root->value < value) {
            root->right = addNode(root->right, value);
        } else {
            root->count++;
        }
        return root;
    }
    int mymax(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }
    int depthTree(Node* root) {
        if (!root)
            return 0;
        return mymax(depthTree(root->left), depthTree(root->right)) + 1;
    }

 public:
    BST() :root(nullptr), s(0) {}
    void add(const T& value) {
        root = addNode(root, value);
    }
    int depth() {
        int d = depthTree(root);
        return d - 1;
    }

    int search(const T& value) {
        searchTree(root, value);
        return s;
    }
    void searchTree(Node* root, const T& value) {
        if (!root)
            s = 0;
        else if (root->value > value)
            searchTree(root->left, value);
        else if (root->value < value)
            searchTree(root->right, value);
        else
            s = root->count;
    }
};

BST<std::string> makeTree(const char* filename);
std::string get_corr_word(std::string str);
#endif  // INCLUDE_BST_H_
