#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;

    public:
        Iterator():current(nullptr){}
        explicit Iterator(Node<T> *node): current(node){}


        Iterator<T>& operator=(const Iterator<T> &other) {
            this->current=other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current!=other.current;
        }

        Iterator<T>& operator++() {
            // TODO
        }

        Iterator<T>& operator--() {
            // TODO
        }

        T operator*() {
            if(current)
                return this->current->data;
            throw out_of_range("Empty node");
        }
};

#endif
