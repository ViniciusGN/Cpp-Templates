#ifndef SET_H
#define SET_H

#include <iostream>
#include <cmath>

template <typename T>
class Set
{
public:
    Set() : list(nullptr) {}                // Default constructor
    Set(T param) : list(new Node(param)) {} // Param constructor
    ~Set() { clear(); }                     // Destructor

    Set(const Set &other) : list(nullptr)
    { // Copy constructor
        for (auto current = other.list; current != nullptr; current = current->getNext())
        {
            insert(current->getValue());
        }
    }

    Set &operator=(const Set &other)
    { // Attribution operator
        if (this != &other)
        {
            clear();
            for (auto current = other.list; current != nullptr; current = current->getNext())
            {
                insert(current->getValue());
            }
        }
        return *this;
    }

    void clear()
    {
        while (list != nullptr)
        {
            Node *temp = list;
            list = list->getNext();
            delete temp;
        }
    }

    bool isEmpty() const { return list == nullptr; }

    bool contains(T param) const
    {
        for (Node *current = list; current != nullptr; current = current->getNext())
        {
            if (current->getValue() == param)
                return true;
        }
        return false;
    }

    void insert(T value)
    {
        if (!contains(value))
        {
            list = new Node(value, list);
        }
    }

    void remove(T value)
    {
        Node *current = list;
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->getValue() == value)
            {
                if (prev == nullptr)
                {
                    list = current->getNext();
                }
                else
                {
                    prev->setNext(current->getNext());
                }
                delete current;
                return;
            }
            prev = current;
            current = current->getNext();
        }
    }

    template <typename G>
    void insertInto(Set<G> &source, Set<G> &target) {
        for (auto current = source.list; current != nullptr; current = current->getNext()) {
            target.insert(current->getValue());
        }
    }

    template <typename G>
    void removeFrom(Set<G> &source, Set<G> &target) {
        for (auto current = source.list; current != nullptr; current = current->getNext()) {
            target.remove(current->getValue());
        }
    }

    template <typename G>
    bool isSubsetOf(const Set<G> &a, const Set<G> &b) {
        for (auto current = a.list; current != nullptr; current = current->getNext()) {
            if (!b.contains(current->getValue())) {
                return false;
            }
        }
        return true;
    }



    // I changed everything to type G, to avoid the overshadowing errors.
    // Union
    template <typename G>
    friend Set<G> operator|(const Set<G> &a, const Set<G> &b);

    // Intersection
    template <typename G>
    friend Set<G> operator&(const Set<G> &a, const Set<G> &b);

    // Difference
    template <typename G>
    friend Set<G> operator-(const Set<G> &a, const Set<G> &b);

    // Symetric Difference
    template <typename G>
    friend Set<G> operator^(const Set<G> &a, const Set<G> &b);

    // equality operator overload
    template <typename G>
    friend bool operator==(const Set<G> &a, const Set<G> &b);

    // minor operator overload
    template <typename G>
    friend bool operator<(const Set<G> &a, const Set<G> &b);

    // image function
    template <typename G>
    friend Set<G> image(const Set<G> &set, G (*function)(G));

    // singleton function
    template <typename G>
    friend Set<G> singleton(G param);

    // insertion operator overload
    template <typename G>
    friend std::ostream &operator<<(std::ostream &out, const Set<G> &s);

private:
    class Node
    {
    public:
        Node(T value, Node *next = nullptr) : value(value), next(next) {}
        T getValue() const { return value; }
        Node *getNext() const { return next; }
        void setNext(Node *nextNode) { next = nextNode; }
        ~Node(){}

    private:
        T value;
        Node *next;
    };

    Node *list;
};

// implementations
template <typename G>
Set<G> operator|(const Set<G> &a, const Set<G> &b)
{
    Set<G> result = a;
    for (auto current = b.list; current != nullptr; current = current->getNext())
    {
        if (!result.contains(current->getValue()))
        {

            result.insert(current->getValue());
        }
    }
    return result;
}

template <typename G>
Set<G> operator&(const Set<G> &a, const Set<G> &b) {
    Set<G> result;

    // Build the intersection (in reverse order due to insert at the beginning)
    for (auto current = a.list; current != nullptr; current = current->getNext()) {
        if (b.contains(current->getValue())) {
            result.insert(current->getValue());
        }
    }

    // Reverse the list to maintain the correct (descending) order
    Set<G> reversedResult;
    auto current = result.list;
    while (current != nullptr) {
        reversedResult.insert(current->getValue());
        current = current->getNext();
    }

    return reversedResult;
}

template <typename G>
Set<G> operator-(const Set<G> &a, const Set<G> &b)
{
    Set<G> result;
    for (auto current = a.list; current != nullptr; current = current->getNext())
    {
        if (!b.contains(current->getValue()))
        {
            result.insert(current->getValue());
        }
    }
    return result;
}

template <typename G>
Set<G> operator^(const Set<G> &a, const Set<G> &b)
{
    return (a - b) | (b - a);
}

template <typename G>
bool operator==(const Set<G> &a, const Set<G> &b)
{
    if (a.isEmpty() && b.isEmpty())
        return true;
    for (auto current = a.list; current != nullptr; current = current->getNext())
    {
        if (!b.contains(current->getValue()))
        {
            return false;
        }
    }
    for (auto current = b.list; current != nullptr; current = current->getNext())
    {
        if (!a.contains(current->getValue()))
        {
            return false;
        }
    }
    return true;
}

template <typename G>
bool operator<(const Set<G> &a, const Set<G> &b)
{
    if (a == b)
        return false;
    for (auto current = a.list; current != nullptr; current = current->getNext())
    {
        if (!b.contains(current->getValue()))
        {
            return false;
        }
    }
    return true;
}

template <typename G>
Set<G> singleton(G param)
{
    Set<G> result;
    result.insert(param);
    return result;
}

template <typename G>
Set<G> image(const Set<G>& set, G (*function)(G)) {
    Set<G> result;
    for (auto current = set.list; current != nullptr; current = current->getNext()) {
        result.insert(function(current->getValue()));
    }
    return result;
}

template <typename G>
std::ostream &operator<<(std::ostream &out, const Set<G> &s)
{
    out << "{";
    auto current = s.list;
    while (current != nullptr)
    {
        out << current->getValue();
        if (current->getNext() != nullptr)
            out << ",";
        current = current->getNext();
    }
    out << "}";
    return out;
}

template <typename G>
Set<G> emptySet() {
    return Set<G>();
}


#endif // SET_H
