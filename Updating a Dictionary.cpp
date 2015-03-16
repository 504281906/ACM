#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
#include <map>
#include <set>
 
using namespace std;
 
#define MAX_LENGTH 200
 
int main ( )
{
    int test_cases;
    char line[MAX_LENGTH];
    string  key, value;
    map <string, string> dic;
    set <string> add, change;
    scanf( "%d", &test_cases );
    gets( line );
    while ( test_cases -- )
    {
        key = value = "";
        dic.clear( );
        gets( line );
        for ( int i = 1 ; line[i] != '\0' ; i ++ )
        {
            if ( isdigit(line[i]) )
                value += line[i];
            else if ( isalpha(line[i]) )
                key += line[i];
            else if ( line[i] == ',' )
            {
                dic.insert( make_pair<string, string>(key, value) );
                key = value = "";
            }
            else if ( line[i] == '}' )
            {
                if ( key != "" )
                    dic.insert( make_pair<string, string>(key, value) );
                key = value = "";
            }
        }
 
        add.clear( );
        change.clear( );
        gets( line );
        for ( int i = 1 ; line[i] != '\0' ; i ++ )
        {
            if ( isdigit(line[i]) )
                value += line[i];
            else if ( isalpha(line[i]) )
                key += line[i];
            else if ( line[i] == ',' )
            {
                map <string, string> :: iterator  it = dic.find( key );
                if ( it == dic.end( ) )
                    add.insert( key );
                else
                {
                    if ( it->second != value )
                        change.insert( key );
                    dic.erase( it );
                }
                key = value = "";
            }
            else if ( line[i] == '}' )
            {
                if ( key != "" )
                {
                    map <string, string> :: iterator  it = dic.find( key );
                    if ( it == dic.end( ) )
                        add.insert( key );
                    else
                    {
                        if ( it->second != value )
                            change.insert( key );
                        dic.erase( it );
                    }
                    key = value = "";
                }
            }
        }
 
        if ( dic.size( ) == 0 && add.size( ) == 0 && change.size( ) == 0 )
            puts( "No changes" );
        else
        {
            if ( add.size( ) != 0 )
            {
                set <string> :: const_iterator  it;
                it = add.begin( );
                printf( "+%s", it->c_str( ) );
                for ( ++ it ; it != add.end( ) ; ++ it )
                    printf( ",%s", it->c_str( ) );
                puts( "" );
            }
            if ( dic.size( ) != 0 )
            {
                map <string, string> :: const_iterator  it;
                it = dic.begin( );
                printf( "-%s", it->first.c_str( ) );
                for ( ++ it ; it != dic.end( ) ; ++ it )
                    printf( ",%s", it->first.c_str( ) );
                puts( "" );
            }
            if ( change.size( ) != 0 )
            {
                set <string> :: const_iterator  it;
                it = change.begin( );
                printf( "*%s", it->c_str( ) );
                for ( ++ it ; it != change.end( ) ; ++ it )
                    printf( ",%s", it->c_str( ) );
                puts( "" );
            }
        }
        puts( "" );
    }
    return 0;
}
