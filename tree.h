//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


//changed string to int and class to struct for node implementation
template <typename T>
struct Node {
    int id;
    T data;
    vector<Node<T>*> children;
    //added parent nodes
    vector<Node<T>*> parents;

    // TODO: Write constructor
    //node is a int
    Node(int nodeID, const T &value);
};

template <typename T>
class Tree {
private:
    Node<T>* root;
    //store nodes
    unordered_map<int, Node<T>*> nodes;

public:
    Tree();
    // TODO: Initialize root pointer to nullptr

    void createRoot(int id, const T &value);
    // TODO: Allocate memory, assign id, assign data, set as root

    void addNode(int parentID, int childID, const T &value);
    // TODO: Find parent, create child, link parent to child
    // TODO: Support repeated children under multiple parents


    Node<T>* findNode(int id);
    // TODO: Use DFS or BFS to search tree

    Node<T>* dfs(Node<T>* current, int id, unordered_set<int> &visited);
    // TODO: implement helper

    void printAll();
    // TODO: Print entire structure in readable form

    ~Tree();
    // TODO: Free all allocated memory
};
//Setting root pntr to null
template <typename T>
Tree<T>::Tree() {
    root = nullptr;
}

//making first node in tree the root and storing
template<typename T>
void Tree<T>::createRoot(int id, const T &value) {
    Node<T>* node = new Node<T>(id, value);
    root = node;
    nodes[id] = node;
}
//creating node by allocating memory, assigning id and data
template<typename T>
Node<T>::Node(int nodeID, const T &value) {
    id = nodeID;
    data = value;
}
//direct node
template<typename T>
Node<T>* Tree<T>::findNode(int id) {
    if (!root) {
        return nullptr;
    }
    unordered_set<int> visited;
    return dfs(root, id, visited);
}
template<typename T>
Node<T> *Tree<T>::dfs(Node<T> *current, int id, unordered_set<int> &visited) {
    if (!current) {
        return nullptr; // nothing
    }

    if (visited.count(current->id)) {
        return nullptr; //visited
    }
    visited.insert(current->id);
}





#endif //FA25EC3_TREE_H
