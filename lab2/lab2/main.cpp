#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <list>

template < typename T >
class IsPalindrome
{
public:
    bool operator()( const T & t )
    {
        std::string strT;

        if constexpr( std::is_same< std::string, T >::value )
            strT = t;
        else
            strT  = std::to_string( t );

        std::string strCopy = strT;

        std::reverse( strT.begin(), strT.end() );

        return strCopy == strT;
    }
};


void task1()
{
    typedef  std::vector < int > vector;

    std::cout << "Task 1:" << std::endl;

    vector v = { 1, 2, 5, 12, 46, -2, -28, 256, 3, 28 };

    std::cout << "vector before: ";
    for( int n : v )
        std::cout << n << " ";
    std::cout << std::endl;

    int sumMax = 0;
    int sumMin = 0;

    vector::iterator itMax = std::max_element( v.begin(), v.end() );
    vector::iterator itMin = std::min_element( v.begin(), v.end() );

    if( itMax != v.end() )
       sumMax = std::accumulate( v.begin(), itMax,  0 );

    if( itMin != v.end() )
        sumMin = std::accumulate( itMin + 1, v.end(), 0 );

    *itMax = sumMax;
    *itMin = sumMin;

    std::cout << "vector after: ";
    for( int n : v )
        std::cout << n << " ";
    std::cout << std::endl ;
}

void task2( )
{
    std::cout << std::endl<< "Task 2:" << std::endl;

    std::string s = "One and two and three and four and five and abba and aaaa and heh and lol";
    std::string andStr = " and ";

    std::istringstream ss( s );
    std::string word;
    size_t num = 0;

    IsPalindrome< std::string > isPal;

    while( std::getline( ss, word, ' ' ) )
        if( isPal( word ) )
            num++;

    std::cout << "quantity of palindromes: " << num << std:: endl;

    int pos = -1;

    std::cout << "string before: " << s << std::endl;

    while( ( pos = s.find( andStr ) ) != -1 )
        s.replace( pos, andStr.length(), ", " );

    std::cout << "string after: " << s << std::endl;

}

int main()
{
    task1();
    task2();
    return 0;
}
