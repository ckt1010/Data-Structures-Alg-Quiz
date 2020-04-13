#pragma once

template <typename T> class list_signly {
  public:
    typedef struct node_t {
        node_t *next;
        T data;
    } node, *pNode;

  private:
    node _head;
    pNode _sentry;
    uint32_t _size;

  public:
    pNode begin() { return _head.next; };
    pNode end() { return _sentry; };
    uint32_t size() { return _size; }
    list_signly() : _size(0) { _sentry = &_head; }
    ~list_signly() {
        pNode prevTmp, tmp = _head.next;
        for (uint32_t i = 0; tmp != nullptr && i < _size; i++) {
            prevTmp = tmp;
            tmp = tmp->next;
            delete prevTmp;
        }
    }
    void push_back(pNode n) {
        _sentry->next = n;
        _sentry = _sentry->next;
        _size++;
    }

    void push_back(T c) {
        pNode _tail = new node;
        _tail->data = c;
        _sentry->next = _tail;
        _sentry = _sentry->next;
        _tail->next = nullptr;
        _size++;
    }

    void push_front(T c) {
        pNode tmp, newNode = new node;
        newNode->data = c;
        insert(newNode, 0);
    }

    void insert(pNode newNode, uint32_t pos) {
        if (pos > _size) {
            return;
        }
        
        pNode cur = &_head;
        for (uint32_t i = 0; i < pos; i++) {
            cur = cur->next;
        }
        pNode tmp = cur->next;
        cur->next = newNode;
        newNode->next = tmp;
        _size++;
    }

    void printAll() {
        pNode cur = _head.next;
        for (; cur != nullptr; cur = cur->next) {
            cout << cur->data << ", ";
                }
        cout << endl;
    }
};

typedef list_signly<char> listChar;
typedef list_signly<char>::pNode pNode;
typedef list_signly<char>::node nodeC;