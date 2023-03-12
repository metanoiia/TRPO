#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <vector>
#include <cmath>
#include <memory>

template <typename T>
class MyDeque
{
public:
    void pushBack ( const T & t );
    void pushFront( const T & t );
    void popBack  ();
    void popFront ();

    bool empty() const;
    size_t size() const;

    T front() const;
    T back() const;

private:
    void checkBack();
    void checkFront();

    std::vector < T > m_front;
    std::vector < T > m_back;
};

template < typename T >
void MyDeque< T >::pushBack( const T & t )
{
    m_back.push_back( t );
}

template < typename T >
void MyDeque< T >::pushFront( const T & t )
{
    m_front.push_back( t );
}

template < typename T >
size_t MyDeque< T >::size() const
{
     return m_front.size() + m_back.size();
}

template < typename T >
bool MyDeque< T >::empty() const
{
    return size() == 0;
}

template < typename T >
void MyDeque< T >::checkBack()
{
    if( !m_back.size() )
    {
        if( m_front.size() == 1 )
           m_back = std::move( m_front );
        else
        {
            auto newEndIt =  m_front.begin() +  m_front.size() / 2;
            auto newEndItR =  m_front.rbegin() + std::floor( float( m_front.size() + 1 ) / 2 );

            std::move( newEndItR, m_front.rend() ,
                       std::back_inserter( m_back ) );//copy a half into the m_back
            m_front.erase( m_front.begin(), newEndIt );
        }
    }
}

template < typename T >
void MyDeque< T >::checkFront()
{
    if( !m_front.size() )
    {
        if( m_back.size() == 1 )
           m_front = std::move( m_back );
        else
        {
            auto newEndIt =  m_back.begin() +  m_back.size() / 2;
            auto newEndItR =  m_back.rbegin() + std::floor( ( m_back.size() + 1 ) / 2 );

            std::move( newEndItR, m_back.rend() ,
                       std::back_inserter( m_front ) );//copy a half into the m_back
            m_back.erase( m_back.begin(), newEndIt );
        }
    }
}

template < typename T >
void MyDeque< T >::popBack()
{
    if( !empty() )
    {
        checkBack();

        m_back.pop_back();

        checkBack();
    }
}

template < typename T >
void MyDeque< T >::popFront()
{
    if( !empty() )
    {
        checkFront();

        m_front.pop_back();

        checkFront();
    }
}

template < typename T >
T MyDeque< T >::front() const
{
    if( m_front.size() )
        return m_front.back();
    else
        return T();
}

template < typename T >
T MyDeque< T >::back() const
{
    if( m_back.size() )
        return m_back.back();
    else
        return T();
}


#endif // MYDEQUE_H

