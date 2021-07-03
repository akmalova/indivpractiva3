#include "Header.h"
//конструктор копирования
List::List(const List& l) {
    head = nullptr; tail = nullptr;
    node* q = l.head;
    while (q) {
        inTail(q->data);
        q = q->next;
    }
}
//удаление по позиции итатора
void delel(listIterator el);
//деструктор
List::~List()
{
    while (head) {
        node* cur = head;
        head = head->next;
        delete cur;
    }
    tail = head = nullptr;
}
//проверка списка на пустоту
bool List::isEmpty() const {
    return (head == nullptr);
}
//добавляем в голову
void List::inHead(int val) {
    node* t = new node(val, head, nullptr);
    if (!head)
        tail = t;
    else
        head->prev = t;
    head = t;
}
//добавляем в хвост
void List::inTail(int val) {
    node* t = new node(val, nullptr, tail);
    if (head) {
        tail->next = t;
        tail = t;
    }
    else {
        head = tail = t;
    }
}
//получаем 1ый элемент
int List::getFirst() const {
    if (head)
        return head->data;
    else
        throw 1;//список пуст
}
//получаем последний
int List::getLast()const {
    if (head)
        return tail->data;
    else
        throw 1;//список пуст
}
//удаляем первый
void List::delFirst() {
    if (head) {
        node* t = head;
        head = head->next;
        head->prev = nullptr;
        delete t;
    }
    else
        throw 1;//список пуст
}
//удаляем последний
void List::delLast() {
    if (head) {
        if (head == tail) { delete tail; head = nullptr; }
        else {
            node* t = head;
            while (t->next != tail)
                t = t->next;
            delete tail;
            tail = t;
            t->next = nullptr;
        }
    }
    else
        throw 1;//список пуст
}
int List::counter() {
    node* p = head;
    int k = 0;
    while (p) {
        k++;
        p = p->next;
    }
    return k;
}
ostream& operator<<(ostream& os, const List& l) {
    node* p = l.head;
    while (p) {
        os << p->data << " ";
        p = p->next;
    }
    os << endl;
    return os;
}
istream& operator>>(istream& in, List& l) {
    cout << "Enter number of elements= ";
    int n, elem;
    cin >> n;
    while (n) {
        cout << "Enter element= ";
        in >> elem;
        l.inTail(elem);
        n--;
    }
    return in;
}
listIterator List::begin() const {
    return listIterator(this, head);
}
listIterator List::end() const {
    listIterator iter(this, nullptr);
    return iter;
}


listIterator listIterator:: operator++() {
    if (cur) {
        cur = cur->next;
        return *this;
    }
    else
        throw 2;//итератор пуст
}
listIterator listIterator:: operator--() {
    if (cur) {
        cur = cur->prev;
        return *this;
    }
    else
        throw 2;//итератор пуст
}
int listIterator:: operator==(const listIterator& ri) const {
    return ((collection == ri.collection) && (cur == ri.cur));
}
int listIterator:: operator!=(const listIterator& ri) const {
    return !(*this == ri);
}
bool listIterator::isEmptyiter() const {
    return collection->isEmpty();
}
void List::delel(listIterator el) {
    listIterator b = this->begin();
    if (b == el)
        delFirst();

    else {
        if ((++el).getter() == nullptr)
            delLast();
        else {
            --el;//из-за того что проверили не  последниий ли это элемент
            --el;
            node* p = head;
            while (b != el) {
                p = p->next;
                ++b;
            }
            node* pp = p->next;
            pp = pp->next;
            delete p->next;
            pp->prev = p;
            p->next = pp;
        }
    }
}
listIterator List::poiskel(int el) {
    listIterator b = this->begin();
    while (b.getter() != nullptr && b.getter()->data != el)
        ++b;
    return b;
}
bool isNum(string& s) {
    /*int i = 0,  flag;
    while(s[i]){
        if(isalpha(s[i]) || s[i]){
            flag = 0;
            break;
        }
        else flag = 1;
        i++;
    }
    if (flag == 1) return true;
    else return false;*/
    try {
        stoi(s);
        return true;
    }
    catch (std::invalid_argument e) {
        return false;
    }
}
void List::Sort()
{
    node* temp = head;
    while (temp->next)
    {
        if (temp->data > temp->next->data)
        {
            swap(temp->data, temp->next->data);
            temp = temp->next;
            Sort();
        }
        else
            temp = temp->next;
    }
}
void enterseq(List& l) {
    int n;

    string s;
    cout << "To stop eter anysymbol!\n";
    cout << "enter number= ";
    cin >> s;
    while (isNum(s)) {

        n = stoi(s);
        if (!l.poiskel(n).getter()) {
            l.inTail(n);

        }
        cout << "enter number= ";
        cin >> s;
    }
    if (!l.isEmpty()) {
        l.Sort();
        cout << l;
    }

}
void List::insertelbefore(listIterator  el, int elem) {
    node* a = head;
    listIterator b = this->begin();

    if (b == el)
        inHead(elem);

    else {
        --el;
        while (b != el) {
            a = a->next;
            ++b;

        }
        a = a->next;

        node* p = new node(elem, a, a->prev);
        a->prev->next = p;
        a->prev = p;

    }
}
void List::insertelafter(listIterator  el, int elem) {
    node* a = head;
    listIterator b = this->begin();

    if (b == el)
        inHead(elem);

    else {
        --el;
        while (b != el) {
            a = a->next;
            ++b;

        }
        a = a->next;
        node* p = new node(elem, a->next, a);
        a->next->prev = p;
        a->next = p;

    }
}
