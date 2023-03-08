#ifndef ISSQUARE_H
#define ISSQUARE_H
#include <functional>
#include <cmath>

template <typename T>
class IsSquare : public std::unary_function<T, bool>
{
public:
    IsSquare();

    bool operator()( const T & t );
    int getCount();
private:
    int m_count;
};

template <typename T>
IsSquare < T >::IsSquare() : m_count(0) {}

template <typename T>
bool IsSquare < T >::operator()( const T & t )
{
    int temp = ( int )std::sqrt( double( t ) );

    if( temp * temp == t || ( temp - 1 ) * ( temp - 1 ) == t || ( temp + 1 ) * ( temp + 1 ) == t )
    {
        m_count++;
        return true;
    }
    else
        return false;
}

template <typename T>
int IsSquare < T >::getCount()
{
    return m_count;
}

#endif // ISSQUARE_H
