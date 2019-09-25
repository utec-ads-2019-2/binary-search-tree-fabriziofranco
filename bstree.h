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

        void insert(T data) {
            auto Nuevo_nodo= new Node<T>(data);
            if (!root)
                root = Nuevo_nodo;
            else {
                auto temp = root;
                while(temp->right and temp->left) {
                    if (data <= temp->data)
                        temp= temp->left;
                    else
                        temp = temp->right;
                }
                if (data <= temp->data)
                    temp->left = Nuevo_nodo;
                else
                    temp->right = Nuevo_nodo;
            }
            tamano++;
        }


        bool remove(T data) {
            if(find(data)){
                return true;
            }
            return false;
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

        void traversePreOrder(Node<T> * nodo) {
            if (!nodo) return;
            cout << nodo->data << " ";
            traversePreOrder(nodo->left);
            traversePreOrder(nodo->right);
        }

        void traverseInOrder(Node<T> * nodo) {
            if (!nodo) return;
            traverseInOrder(nodo->left);
            cout << nodo->data << " ";
            traverseInOrder(nodo->right);
        }

        void traversePostOrder(Node<T> * nodo) {
            if (!nodo) return;
            traversePostOrder(nodo->left);
            traversePostOrder(nodo->right);
            cout << nodo->data << " ";
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


//FALTA REMOVE E ITERADORES

#endif
