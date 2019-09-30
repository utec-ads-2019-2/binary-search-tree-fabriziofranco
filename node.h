#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
    T data;
    Node<T> *left;
    Node<T> *right;

    template<class>
    friend class BSTree;

    template<class>
    friend class Iterator;

public:
    explicit Node(T data):data(data),left(nullptr),right(nullptr){};

    void Destroy(){
        if(this){ // Esto no es necesario porque this siempre va a existir. Esta revisión deberías hacerla fuera del nodo, en el árbol
            if(this->left)
                left->Destroy();
            if(this->right)
                right->Destroy();
            delete this;
        }
    }

};

#endif