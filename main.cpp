#include <QCoreApplication>
#include "Header.h"
int main()
{
    List p, p1, p2;
    for (int i = 0; i < 7; i++)
        p.inHead(i);
    cout << "List: " << p << endl;
    listIterator iter = p.begin();
    listIterator iter1 = p1.begin();
    cout << "Is iter empty? " << iter.isEmptyiter() << endl;
    cout << "Is iter1 empty? " << iter1.isEmptyiter() << endl;
    while (*(iter) != 3) {
        ++(iter);
    }
    p.delel(iter);
    cout << "List after delete: " << p << endl;
    cout << "Number elements of list=" << p.counter() << endl;
    cin >> p1;
    cout << "List p1= " << p1 << endl;
    enterseq(p2);
    listIterator iter2 = p2.begin();
    while (*(iter2) != 2) {
        ++(iter2);
    }
    p2.insertelbefore(iter2, 5);
    cout << "Insertel before " << p2 << endl;
    iter2 = p2.begin();
    while (*(iter2) != 2) {
        ++(iter2);
    }
    p2.insertelafter(iter2,1);
    cout << "Insertel after " << p2 << endl;
    return 0;
}
