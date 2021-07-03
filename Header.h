#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
using namespace std;
struct node {
    int data;
    node* next;
    node* prev;
    node(int data, node* next, node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
class listIterator; //предварительное объявление класса итератора

//Класс список
class List {

private:
    node* head;
    node* tail;
public:
    void insertelbefore(listIterator  el, int elem);
    void insertelafter(listIterator  el, int elem);
    void Sort();
    listIterator poiskel(int el);
    List() { head = nullptr; tail = nullptr; }
    List(const List& l);
    ~List();

    bool isEmpty() const;
    void inHead(int val);
    void inTail(int val);
    int getFirst()const;
    int getLast()const;
    void delFirst();
    void delLast();
    int counter();
    listIterator begin() const;
    void delel(listIterator el);
    listIterator end() const;
    friend ostream& operator<<(ostream& os, const List& l);
    friend istream& operator>>(istream& in, List& l);
    friend void enterseq(List& l);
};


//Класс итератор
class listIterator
{
private:
    const List* collection;
    node* cur;
public:
    node* getter() {
        return cur;
    }
    bool isEmptyiter() const;
    listIterator(const List* s, node* e) :collection(s), cur(e) {}
    const int operator *()
    {
        return cur->data;
    }
    listIterator operator++(); //префиксный ++
    listIterator operator--(); //префиксный --
    int operator == (const listIterator& ri) const;
    int operator != (const listIterator& ri) const;
};
void enterseq(List& l);
#endif // HEADER_H
