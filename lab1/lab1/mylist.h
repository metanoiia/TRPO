#ifndef MYLIST_H
#define MYLIST_H

#include <uchar.h>

template < typename T >
class MyList
{
private:
    struct Node;
public:
    class Iterator
    {
    public:
        Iterator( Node * node ) : m_node( node ){}
        bool operator ==( const Iterator & other ) const
        {
            if( this == &other )
                return true;
            else
                return m_node == other.m_node;
        }

        bool operator !=( const Iterator &other ) const { return !operator ==( other ); }

        T operator *() const
        {
            if( m_node != nullptr )
                return m_node->m_t;
            else
                return T();
        }

        void operator ++()
        {
            if( m_node )
                m_node = m_node->m_next;
        }
    private:
        Node * m_node;
    };
public:
    MyList();
    ~MyList();

    void append( const T &t );
    void pop();

    T head() const;

    Iterator begin() const;
    Iterator end() const;

    size_t size() const;

    void clear();
private:
    struct Node
    {
        Node * m_next;
        T m_t;

        Node() : m_next( nullptr ){}
        Node( const T & t ) : m_next( nullptr ), m_t( t ) {}
    };

    Node * m_head;
};

template < typename T >
MyList< T >::MyList() : m_head( nullptr ){}

template < typename T >
MyList< T >::~MyList() { clear(); }

template < typename T >
void MyList< T >::append( const T &t )
{
    Node * node = new Node( t );

    node->m_next = m_head;

    m_head = node;
}

template < typename T >
void MyList< T >::pop()
{
    if( m_head )
    {
        Node * newHead = m_head->m_next;

        delete m_head;

        m_head = newHead;
    }
}

template < typename T >
T MyList< T >::head() const { return m_head->m_t; }

template < typename T >
typename MyList< T >::Iterator MyList< T >::begin() const
{
    return Iterator( m_head );
}

template < typename T >
typename MyList< T >::Iterator MyList< T >::end() const
{
    return Iterator( nullptr );
}

template < typename T >
size_t MyList< T >::size() const
{
    size_t size = 0;
    for( Iterator it = begin(); it != end(); ++it )
        size++;
    return size;
}

template < typename T >
void MyList< T >::clear()
{
    while( m_head )
        pop();
}

#endif // MYLIST_H
