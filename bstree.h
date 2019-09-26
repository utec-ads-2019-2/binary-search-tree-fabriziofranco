#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
    int tamano;

    public:
        BSTree() : root(nullptr),tamano(0) {};

        bool find(T data){
            auto temp = root;
            while (temp) {
                if (data == temp->data)
                    return true;
                else{
                    if (data <= temp->data)
                        temp = temp->left;
                    else
                        temp = temp->right;
                }
            }
            return false;
        }

        Node<T> *Izquierdo(Node<T> * node) {
            while (node->left)
                node = node->left;
            return node;
        }

        void insert(T data) {
            auto nuevo = new Node<T>(data);
            if (!root)
                root = nuevo;
            else {
                Node<T> * actual=root, *prev = root;
                while(actual) {
                    prev = actual;
                    if (data <= actual->data)
                        actual = actual->left;
                    else
                        actual = actual->right;
                }
                if (data <= prev->data)
                    prev->left = nuevo;
                else
                    prev->right = nuevo;
            }
            tamano++;
        }

        Node<T> *Pre_Remove_and_order(Node<T> * node, T data) {
            if (!node)
                return node;
            else if (data < node->data)
                node->left = Pre_Remove_and_order(node->left, data);

            else if (data > node->data)
                node->right = Pre_Remove_and_order(node->right, data);

            else { //Data igual a la que se desea remover
                if (!node->right) {
                    auto temp = node->left;
                    delete node;
                    return temp;
                }
                else if (!node->left) {
                    auto temp = node->right;
                    delete node;
                    return temp;
                }
                auto minDataNode = Izquierdo(node->right);
                node->data = minDataNode->data;
                node->right = Pre_Remove_and_order(node->right, minDataNode->data);
            }
            return node;
        }

        bool remove(T data) {
            if(!find(data)||!root)
                return false;
            else{
                root = Pre_Remove_and_order(root, data);
                --tamano;
                return true;
                }
        }

        size_t size() {
            return tamano;
        }

        int altura(Node<T>* node){
            if (!node)
                return -1;
            return 1 + max(altura(node->left), altura(node->right));
        }

        int height() {
            return altura(root);
        }

        Node<T>* getroot(){
            return root;
        }

        void traversepreOrder(Node<T> * nodo) {
            if (!nodo) return;
            cout << nodo->data << " ";
            traversepreOrder(nodo->left);
            traversepreOrder(nodo->right);
        }

        void traverseinOrder(Node<T> * nodo) {
            if (!nodo) return;
            traverseinOrder(nodo->left);
            cout << nodo->data << " ";
            traverseinOrder(nodo->right);
        }

        void traversepostOrder(Node<T> * nodo) {
            if (!nodo) return;
            traversepostOrder(nodo->left);
            traversepostOrder(nodo->right);
            cout << nodo->data << " ";
        }

        void traversePreOrder(){
            traversepreOrder(root);
        }

        void traverseInOrder(){
            traverseinOrder(root);
        }

        void traversePostOrder(){
            traversepostOrder(root);
        }


        Iterator<T> begin() {
            return Iterator<T>(root);
        }

        Iterator<T> end() {
            return Iterator<T>(nullptr);
        }

        ~BSTree() {
            root->Destroy();
        }
};

#endif
