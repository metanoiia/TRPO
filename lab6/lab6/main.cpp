#include <iostream>
#include "mydeque.h"
#include <algorithm>
#include <vector>
#include <homelib.h>

void usageExample( HomeLib & library );

int main()
{
    MyDeque< int > deq;

    for( int i = -1; i > -11; i-- )
        deq.pushFront( i );

    for( int i = 0; i < 9; i++ )
        deq.pushBack( i );

    for( int i = 0; i < 19; i++ )
    {
        std::cout << deq.front() << " ";
        deq.popFront();
    }

    HomeLib hl;

    Book book1( "Bulgakov", 1925 );
    Book book2( "Sapkowski", 1997 );
    Book book3( "Tolkien", 1937 );

    hl.addBook( book1 );
    hl.addBook( book2 );
    hl.addBook( book3 );

    std::list< std::shared_ptr< Book > > list = hl.getByDate( 1997 );

    //anyway this is an example too
    if( !list.empty() )
        list.back().get()->m_author = "Konev";

    usageExample( hl );

    return 0;
}

void usageExample( HomeLib & library )
{
    MyDeque < std::shared_ptr< Book > > bookDeque;

    std::list< std::shared_ptr< Book > > bookList = library.getByDate( 1997 );

    if( !bookList.empty() )
        for( auto & book : bookList  )
        {
            bookDeque.pushBack( book );
            bookDeque.back().get()->m_date = 2000;
        }

}
