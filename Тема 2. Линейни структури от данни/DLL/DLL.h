#include <ostream>
#include "Node.h"


template <class T>
class DLL
{
    private:
    //data members/fields
    
    Node<T> *first,*last;

    void copy(const DLL<T>&);
    void destroy();
    
    //public part
    public:
    //constructors
    DLL();
    DLL(const DLL<T>&);
    DLL<T>& operator=(const DLL<T>&);
    ~DLL();

    void print();
    //add/remove element
    DLL<T>& push(const T&);
    DLL<T>& push_back(const T&);
    DLL<T>& pop();
    DLL<T>& pop_back();
    DLL<T>& clear();
    DLL<T>& insertAfter(size_t,const T&);
    DLL<T>& deleteAt(size_t);
    //access
    size_t size() const;
    T& front() const;
    T& back() const;
    bool empty();

    //normal iterator
    class Iterator
    {
        private:
        Node<T>* current;
        
        public:
        Iterator(Node<T>*);
        bool operator!=(const Iterator&);
        Iterator& operator++();
        T& operator*();       
    };

    Iterator begin();
    Iterator end();

    //reverse iterator
    class ReverseIterator
    {
        private:
        Node<T>* current;

        public:
        ReverseIterator(Node<T>*);
        bool operator!=(const ReverseIterator&);
        ReverseIterator& operator++();
        T& operator*();
    };

    ReverseIterator rbegin();
    ReverseIterator rend();
};

template<typename T>
std::ostream& operator<<(std::ostream&, const DLL<T>&);

#include "DLL.cpp"



