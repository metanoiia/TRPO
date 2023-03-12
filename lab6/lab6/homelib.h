#ifndef HOMELIB_H
#define HOMELIB_H
#include <string>
#include <vector>
#include <memory>
#include <list>
#include <algorithm>
#include <functional>

struct Book
{
    Book( std::string aut, int d) : m_author( aut ), m_date( d ){}
    Book( const Book & other ) : m_author( other.m_author ), m_date( other.m_date ){}

    std::string m_author;
    int m_date;

    bool operator ==( const Book & other ) const
    {
        if( this == &other )
            return true;
        return ( m_author == other.m_author ) && ( m_date == other.m_date );
    }

     bool operator !=( const Book &other ) const { return !operator ==( other ); }

     bool operator <( const Book & other ) const
     {
         return m_date < other.m_date;
     }

     bool operator >( const Book & other ) const
     {
         return m_date > other.m_date;
     }
};

class HomeLib
{
public:
    HomeLib();
    void deleteBook( const Book & b );
    void addBook( const Book & b );
    void sort();

    std::list< std::shared_ptr < Book > > getByAuthor( std::string author );
    std::list< std::shared_ptr < Book > > getByDate( int date );

private:
    std::list< std::shared_ptr < Book > > getBy( std::function < bool( std::shared_ptr< Book > bPtr ) > f );
    std::vector< std::shared_ptr < Book > > m_books;
};

#endif // HOMELIB_H
