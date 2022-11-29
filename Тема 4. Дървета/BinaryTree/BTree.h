#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

template<typename T>
class BTree
{
    private:
    struct Node
    {
        T data;
        Node *left, *right;
    };

    Node *root;

    //helper methods
    void pushAtHelper(const T&, const char*, Node*&);
    Node* getAt(const char*, Node*);

    void copy(Node*&, Node*);
    void clear(Node*);
    void printHelper(Node*,size_t);
    size_t countHelper(Node*);
    size_t countEvensHelper(Node*);
    size_t searchCountHelper (bool (*pred)(const T&), Node*);
    size_t heightHelper(Node*);
    size_t countLeavesHelper(Node*);
    Node* maxLeafHelper(Node*);
    public:
    BTree();
    BTree(const BTree&);
    BTree<T>& operator=(const BTree<T>&);
    ~BTree();    

    //access
    T& get(const char*);
    void print();
    size_t count();
    size_t height();
    size_t countEvens();
    size_t searchCount (bool (*pred)(const T&));
    size_t countLeaves();
    const T& maxLeaf();
    //add/remove element
    void pushAt(const T&, const char*);
};

template<typename T>
BTree<T>::BTree(): root(nullptr) {}

template<typename T>
const T& BTree<T>::maxLeaf()
{
    maxLeafHelper(root)->data;
}

template<typename T>
typename BTree<T>::Node* BTree<T>::maxLeafHelper(Node* current)
{
    if(current == nullptr)
    {
        return nullptr;
    }
    if(current->left == nullptr && current->right == nullptr)
    {
        return current;
    }
    
    Node* maxLeft = maxLeafHelper(current->left);
    Node* maxRight = maxLeafHelper(current->right);
    if(maxRight == nullptr || maxLeft->data > maxRight->data)
    {
        return maxLeft;
    }
    else
    {
        return maxRight;
    }
    
}

template<typename T>
size_t BTree<T>::countLeaves()
{
    countLeavesHelper(root);
}

template<typename T>
size_t BTree<T>::countLeavesHelper(Node* current)
{
    if(current == nullptr)
    {
        return 0;
    }
    if(current->left == nullptr && current->right == nullptr)
    {
        return 1;
    }
    return 0 + countLeavesHelper(current->left) + countLeavesHelper(current->right);
}

template<typename T>
size_t BTree<T>::height()
{
    heightHelper(root);
}

template<typename T>
size_t BTree<T>::heightHelper(Node* current)
{  
    if(current == nullptr)
    {
        return 0;
    }

    return 1 + std::max(heightHelper(current->left), heightHelper(current->right));
}

template<typename T>
void BTree<T>::pushAt(const T& element, const char* way)
{
    pushAtHelper(element, way, root);
}

template<typename T>    
void BTree<T>::pushAtHelper(const T& element, const char* way, Node*& current)
{
    if(current == nullptr && way[0] != '\0')
    {
        assert(false);
    }
    if(current != nullptr && way[0] == '\0')
    {
        assert(false);
    }
    if(current == nullptr && way[0] == '\0')
    {
        current = new Node{element, nullptr, nullptr};
        return;
    }

    switch(way[0])
    {
        case 'L': pushAtHelper(element, ++way, current->left); return;
        case 'R': pushAtHelper(element, ++way, current->right); return;
        default: assert(false);
    }
}

template<typename T>
T& BTree<T>::get(const char* way)
{
    if(getAt(way,root) == nullptr)
    {
        assert(false);
    }
    return getAt(way, root)->data;
}

template<typename T>
typename BTree<T>::Node* BTree<T>::getAt(const char* way, Node* current)
{
    if(current == nullptr && way[0] != '\0')
    {
        return nullptr;
    }
    if(current != nullptr && way[0] == '\0')
    {
        return current;
    }

    switch(way[0])
    {
        case 'L': return getAt(++way, current->left);
        case 'R': return getAt(++way, current->right);
        default: assert(false);
    }
}

template<typename T>
void BTree<T>::copy(Node*& destination, Node* source)
{
    if(source == nullptr)
    {
        destination = nullptr;
        return;
    }
    destination = new Node{source->data, nullptr, nullptr};
    copy(destination->left, source->left);
    copy(destination->right, source->right);
}

template<typename T>
BTree<T>::BTree(const BTree<T>& other)
{
    copy(root, other.root);
}

template<typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>& other)
{
    if(this != &other)
    {
        clear(root);
        copy(root, other.root);
    }
    return *this;
}


template<typename T>
void BTree<T>::clear(Node* current)
{
    if(current == nullptr)
    {
        return;
    }

    clear(current->left);
    clear(current->right);
    delete current;
}

template<typename T>
BTree<T>::~BTree()
{
    clear(root);
}

template<typename T>
void BTree<T>::print()
{
    printHelper(root, 0);
}

template<typename T>
size_t BTree<T>::count()
{
    countHelper(root);
}

template<typename T>
size_t BTree<T>::countHelper(Node* current)
{
    if(current == nullptr)
    {
        return 0;
    }
    return 1 + countHelper(current->right) + countHelper(current->left);
}

template<typename T>
size_t BTree<T>::countEvens()
{
    countEvensHelper(root);
}

template<typename T>
size_t BTree<T>::countEvensHelper(Node* current)
{
    if(current == nullptr)
    {
        return 0;
    }

    return !(current->data % 2) + countEvensHelper(current->left) + countEvensHelper(current->right);
}


template<typename T>
size_t BTree<T>::searchCount (bool (*pred)(const T&))
{
    searchCountHelper(pred, root);
}

template<typename T>
size_t BTree<T>::searchCountHelper (bool (*pred)(const T&), Node* current)
{
    if(current == nullptr)
    {
        return 0;
    }

    return pred(current->data) + searchCountHelper(pred,current->left) + searchCountHelper(pred, current->right);
}



template<typename T>
void BTree<T>::printHelper(Node* current, size_t space)
{
    if(current == nullptr)
    {
        std::cout << "()" << std::endl;
        return;
    }
    std::cout  << current->data << std::endl;
    for(int i = 0; i <= space; ++i) { std::cout << ' ';};
    printHelper(current->left, space+1);
    for(int i = 0; i <= space; ++i) { std::cout << ' ';};
    printHelper(current->right, space+1);
}

