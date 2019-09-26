#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();

    auto arbol=new BSTree<int>;
    arbol->insert(8);
    arbol->insert(3);
    arbol->insert(10);
    arbol->insert(1);
    arbol->insert(6);
    arbol->insert(14);
    arbol->insert(4);
    arbol->insert(7);
    arbol->insert(13);
    arbol->traversePreOrder();
    cout<<endl;
    arbol->traverseInOrder();
    cout<<endl;
    arbol->traversePostOrder();
    arbol->remove(4);
    cout<<endl;
    arbol->traverseInOrder();
    delete arbol;
    return EXIT_SUCCESS;
}
