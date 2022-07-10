#include <iostream>
using namespace std;

template <class Temp>
class Queue {
   public:
    virtual ~Queue(){};
    virtual void enqueue(const Temp& value) = 0;
    virtual Temp dequeue() = 0;
    virtual Temp gethead() const = 0;
    virtual bool isEmpty() const = 0;
};

template <class Temp>
class LinkQueue : public Queue<Temp> {
   private:
    struct node {
        int data;
        node* next;
        node() : next(NULL) {}
        node(int value, node* p = NULL) : data(value), next(p) {}
        ~node() {}
    };
    node* head;
    node* tail;

   public:
    LinkQueue() : head(NULL), tail(NULL) {}
    //构造函数和析构函数定义时都不必加分号
    ~LinkQueue();
    void enqueue(const Temp& value);
    Temp dequeue();
    Temp gethead() const;
    bool isEmpty() const;
};

int main() {
    LinkQueue<int>* lqu = new LinkQueue<int>;
    lqu->enqueue(1);
    lqu->enqueue(2);
    lqu->enqueue(3);
    lqu->enqueue(4);
    lqu->enqueue(5);
    cout << lqu->gethead() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->dequeue() << endl;
    cout << lqu->isEmpty() << endl;
    cout << lqu->gethead() << endl;
    system("pause");
    return 0;
}

template <class Temp>
LinkQueue<Temp>::~LinkQueue() {
    node *p = head, *q;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;
    tail = NULL;
}

template <class Temp>
void LinkQueue<Temp>::enqueue(const Temp& value) {
    node* add = new node(value);
    if (!head) {
        head = add;
        tail = add;
    } else
        tail = tail->next = add;
}

template <class Temp>
Temp LinkQueue<Temp>::dequeue() {
    node* cur = head;
    Temp tpl = cur->data;
    head = head->next;
    delete cur;
    cur = NULL;
    return tpl;
}

template <class Temp>
Temp LinkQueue<Temp>::gethead() const {
    return head->data;
}

template <class Temp>
bool LinkQueue<Temp>::isEmpty() const {
    return head == NULL;
}