#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std ;
bool Equal_String ( vector < string > &v ) {
    unordered_map < char , int > uno ;
    for ( auto str : v ) {
        for ( char c : str ) {
            uno [ c ] ++ ;
        }
    }
    int n = v.size () ;
    for ( auto ele : uno ) {
        if ( ele.second % n != 0 ) return false ;
    } return true ;
}
bool Anagram ( string s1 , string s2 ) {
    if ( s1.size () != s2.size () ) return false ;
    unordered_map < char , int > m ;
    for ( auto c1 : s1 ) {
        m [ c1 ] ++ ;
    }
    for ( auto c2 : s2 ) {
        if ( m.find ( c2 ) == m.end () ) return false ;
        else m [ c2 ] -- ;
    }
    for ( auto c : m ) {
        if ( c.second != 0 ) return false ;
    }
    return true ;
}
bool Isomorphic ( string s1 , string s2 ) {
    if ( s1.size () != s2.size () ) return false ;
    unordered_map < char , char > m ;
    for ( int i = 0 ; i < s1.size () ; i ++ ) {
        if ( m.find ( s1 [ i ] ) != m.end () ) {
            if ( m [ s1 [ i ] ] != s2 [ i ] ) return false ;
        } else {
            m [ s1 [ i ] ] = s2 [ i ] ;
        }
    }
    m.clear () ;
    for ( int i = 0 ; i < s2.size () ; i ++ ) {
        if ( m.find ( s2 [ i ] ) != m.end () ) {
            if ( m [ s2 [ i ] ] != s1 [ i ] ) return false ;
        } else {
            m [ s2 [ i ] ] = s1 [ i ] ;
        }
    }
    return true ;
}
vector < int > Target_Sum ( vector < int > &v , int x ) {
    unordered_map < int , int > m ;
    vector < int > ans ( 2 , - 1 ) ;
    for ( int i = 0 ; i < v.size () ; i ++ ) {
        if ( m.find ( x - v [ i ] ) != m.end () ) {
            ans [ 0 ] = m [ x - v [ i ] ] ;
            ans [ 1 ] = i ;
            return ans ;
        } else {
            m [ v [ i ] ] = i ;
        }
    } return ans ;
}
int Target_Zero_Sum ( vector < int > &v ) {
    unordered_map < int , int > m ;
    int pre = 0 ;
    int ml = INT_MIN ;
    for ( int  i = 0 ; i < v.size () ; i ++ ) {
        pre += v [ i ] ;
        if ( pre == 0 ) ml ++ ;
        if ( m.find ( pre ) != m.end () ) {
            ml = max ( ml , i - m [ pre ] ) ;
        } else {
            m [ pre ] = i ;
        }
    }
    return ml ;
}
int main () {
    cout << " \n \n " ;
    int n ; cout << " Size : " ; cin >> n ;
    vector < int > v ( n ) ;
    /*string s1 , s2 ;
    cout << " String 1 : " ; cin >> s1 ;
    cout << " \n \n " ;
    cout << " String 2 : " ; cin >> s2 ;*/
    cout << " \n \n " ;
    cout << " Enter Elements : " ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v [ i ] ;
    }
    /*if ( Equal_String ( v ) ) cout << " \n \n Yes. " ;
    else cout << " \n \n No. " ;*/
    //cout << ( Anagram ( s1 , s2 ) ? " Yes. " : " No. " ) << endl ;
    //cout << ( Isomorphic ( s1 , s2 ) ? " Yes. " : " No. " ) << endl ;
    /*int target ;
    cout << " \n \n  Taget = " ;
    cin >> target ;
    vector < int > ans = Target_Sum ( v , target ) ;
    cout << " Answer = " << ans [ 0 ] << " , " << ans [ 1 ] ;*/
    cout << " \n \n Answer : " << Target_Zero_Sum ( v ) ;
    cout << " \n \n " ;
    return 0 ;
}
