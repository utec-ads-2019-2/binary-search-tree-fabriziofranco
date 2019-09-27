#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        stack<Node<T>*> stack_de_avance;
        stack<Node<T>*> stack_de_retroceso;

    public:
        Iterator():current(nullptr){}

        explicit Iterator(Node<T> *node){
            if(node){
                while(node){
                    stack_de_avance.push(node);
                    node=node->left;
                }
                current=stack_de_avance.top();
            }
            else
                current= nullptr;
        }


        Iterator<T>& operator=(const Iterator<T> &other) {
            this->current=other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current!=other.current;
        }

        Iterator<T>& operator++() {
            if(current && !stack_de_avance.empty()){
                stack_de_retroceso.push(stack_de_avance.top());
                if(current->right){
                    auto temp=current->right;
                    stack_de_avance.pop();
                    while(temp){
                        stack_de_avance.push(temp);
                        temp=temp->left;
                        }
                }
                else{
                    stack_de_avance.pop();
                }
                if(!stack_de_avance.empty())
                    current=stack_de_avance.top();
                else
                    current= nullptr;
                return *this;
            }
            throw out_of_range("Current is empty");
        }

        Iterator<T>& operator--() {
                if(stack_de_retroceso.empty())
                    throw out_of_range("There's not prev element");
                current=stack_de_retroceso.top();
                stack_de_retroceso.pop();
                return *this;
                    }

        T operator*() {
            if(current)
                return this->current->data;
            throw out_of_range("Empty node");
        }
};

#endif
