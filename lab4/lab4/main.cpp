#include <iostream>
#include <typeinfo>
#include <list>
#include <algorithm>

template <class T>
class CaseChanger
{
public:
    T operator()( T& t )
    {
        if(typeid ( t ) != typeid (char) )
            throw std::exception();
        else
        {
            if( islower( t ) )
                return std::toupper( t );
            else
                return std::tolower( t );
        }
    }
};


int main()
{
    std::list < char > charList = {'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e'};
    CaseChanger < char > cc;

    for( const char & c : charList )
        std::cout << c;
    std::cout << std::endl;

    try
    {
        std::transform( charList.begin(), charList.end(),
                        charList.begin(), cc );
    }
    catch ( std::exception & ex )
    {
        std::cout <<"Cathced "<< ex.what() <<". Case change is available only for 'char' type\n";
    }

    for( const char & c : charList )
        std::cout << c;
    std::cout << std::endl;

    return 0;
}
