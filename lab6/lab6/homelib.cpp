#include "homelib.h"

HomeLib::HomeLib()
{}

void HomeLib::deleteBook( const Book & b )
{
    if( !m_books.empty() )
    {
        auto it = std::find( m_books.begin(), m_books.end(), std::make_shared< Book >( b ) );
        m_books.erase( it );
    }
}

void HomeLib::addBook( const Book & b )
{
    m_books.push_back( std::make_shared< Book >( b ) );
}

void HomeLib::sort()
{
    std::sort( m_books.begin(), m_books.end() );
}

std::list< std::shared_ptr < Book > > HomeLib::getBy( std::function < bool( std::shared_ptr< Book > bPtr ) > f )
{
    std::list< std::shared_ptr < Book > > list;

    std::vector< std::shared_ptr < Book > > vec = m_books;//implemented to get all possible books

    std::vector< std::shared_ptr < Book > >::iterator it;

    while( ( it = std::find_if( vec.begin(), vec.end(), f ) ) != vec.end() )
    {
        list.push_back( *it ); // get pointer from itarator and push it
        vec.erase( it ); //erase to go further
    }

    return list;
}

std::list< std::shared_ptr < Book > > HomeLib::getByAuthor( std::string author )
{
    return getBy( [ author ]( std::shared_ptr< Book > bPtr ) { return ( *bPtr ).m_author == author; } );
}

std::list< std::shared_ptr < Book > > HomeLib::getByDate( int date )
{
    return getBy( [ date ]( std::shared_ptr< Book > bPtr ) { return ( *bPtr ).m_date == date; } );
}



