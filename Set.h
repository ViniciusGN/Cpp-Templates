#ifndef SET_H
#define SET_H
#include <iostream>

template <typename T>
class Set {
public:
    Set();
    Set(T param);
    void clear();
    ~Set();
    bool isEmpty() const;
    std::ostream & flush(std::ostream & out) const;
    bool contains(T param) const;
    bool isSubsetOf(const Set & param) const;
    void insert(T param);
    void remove(T param);
    void insertInto(Set & other) const;
    void removeFrom(Set & other) const;
    Set & operator=(const Set & other);
    Set(const Set & other);
    friend Set image(const Set & set, double (*function)(T));
    
private:
    class Node {
    public:
        Node(T value, Node * next = nullptr);
        ~Node() = default;
        T getValue() const;
        Node * getNext() const;
        void setNext(Node * next);
    private:
        T value;
        Node * next;
};

    Node * list;
    static Node * remove(Node * list, T param);
};

    template <typename T>
    std::ostream & operator<<(std::ostream & out, const Set<T> & s);

    template <typename T>
    Set<T> singleton(T params);

    template <typename T>
    Set<T> emptySet();

    template <typename T>
    bool operator==(const Set<T> &a, const Set<T> &b);

    template <typename T>
    bool operator<(const Set<T> & a, const Set<T> & b);

    template <typename T>
    bool operator>(const Set<T> & a, const Set<T> & b);

    template <typename T>
    Set<T> operator|(const Set<T> & a, const Set<T> & b);

    template <typename T>
    Set<T> operator-(const Set<T> & a, const Set<T> & b);

    template <typename T>
    Set<T> operator^(const Set<T> & a, const Set<T> & b);
    
    template <typename T>
    Set<T> operator&(const Set<T> & a, const Set<T> & b);

#endif //SET_H