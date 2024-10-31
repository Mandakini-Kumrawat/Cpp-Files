#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
using namespace std ;
/*bool check_Alphabets ( string s ) {
    if ( s.size () < 26 ) return false ;
    transform ( s.begin () , s.end () , s.begin () , :: tolower ) ;
    set < char > alphabets ;
    for ( auto ch : s ) {
        alphabets.insert ( ch ) ;
    }
    return ( alphabets.size () == 26 ) ;
}*/
int main () {
    cout << " \n \n " ;
    //int n ; cout << " 1st Vector : " ; cin >> n ;
    //string input ; cout << " Input String : " ; cin >> input ;
    /*unordered_set < int > set1 ;
    set1.insert ( 23 ) ;
    set1.insert ( 44 ) ;
    set1.insert ( 20 ) ;
    set1.insert ( 67 ) ;
    for ( auto value : set1 ) {
        cout << " " << value ;
    }*/
    /*multiset < int > ms ;
    ms.insert ( 1 ) ;
    ms.insert ( 1 ) ;
    ms.insert ( 4 ) ;
    ms.insert ( 2 ) ;
    for ( auto ele : ms ) {
        cout << " " << ele ;
    }*/
    /*unordered_multiset < int > ums ;
    ums.insert ( 5 ) ;
    ums.insert ( 2 ) ;
    ums.insert ( 3 ) ;
    ums.insert ( 4 ) ;*/
    /*multiset < string > ms ;
    ms.insert ( "Apple" ) ;
    ms.insert ( "Ball" ) ;
    ms.insert ( "Collage Wallah" ) ;
    ms.insert ( "Collage" ) ;
    ms.insert ( "Collage" ) ;
    ms.insert ( "Cat" ) ;
    ms.erase ( ms.find ( "Collage" ) , ms.end () ) ;*/
    //int n ; cout << " Size : " ; cin >> n ;
    int n , p , q ;
    cout << " Questions : " ; cin >> n ; // n = 2
    cout << " \n Attended : " ; cin >> p ; // p = 1
    cout << " \n Unattended : " ; cin >> q ; // q = -1
    unordered_set < int > set1 ; // set1 = 0 , -1 , -2 , 1 , 0 , 2
    for ( int i = 0 ; i <= n ; i ++ ) { // i = 0 , 1 , 2
        for ( int j = 0 ; j <= n ; j ++ ) { // j = 0 , 1 , 2
            int c = i ; // c = 2
            int in = j ; // in = 0 , 1 , 2
            int un = n - ( i + j ) ; // un = 2 , 1 , 0 , 1 , 0 , - 1 , 0 , -1 , -2
            if ( un >= 0 ) { int score = c * p + in * q ; set1.insert ( score ) ; } // score = 0 , -1 , -2 , 1 , 0 , 2 ,
            else break ;
        }
    }
    for ( auto score : set1 ) {
        cout << " " << score ;
    }
    cout << " \n \n " ;
    /*set < string > Invite_List ;
    while ( n -- ) {
        string name ;
        cin >> name ;
        Invite_List.insert ( name ) ;
    }*/
    //int m ; cout << " 2nd Vector : " ; cin >> m ;
    /*if ( check_Alphabets ( input ) ) cout << " Yes " ;
    else cout << " No " ;*/
    /*vector < int > v ( n ) ;
    cout << " Enter Elements : " ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v [ i ] ;
    }*/
    cout << " Answer : " << set1.size () ;
    cout << " \n \n " ;
    //set < int > :: iterator itr ;
    /*for ( auto name : Invite_List ) {
        cout << "  " << name ;
    }*/
    /*vector < int > v1 ( n ) ;
    vector < int > v2 ( m ) ;
    cout << " 1st Vector elements : " ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v1 [ i ] ;
    }*/
    /*for ( int i = 0 ; i < n ; i ++ ) {
        cout << " " << v [ i ] ;
    }
    set < int > s ;
    for ( auto val : v ) {
        s.insert ( val ) ;
    }*/
    cout << " \n \n " ;
    //set1.erase ( 4 ) ;
    /*auto itr = set1.begin () ;
    advance ( itr , 3 ) ;
    set1.erase ( itr ) ;
    for ( itr = set1.begin () ; itr != set1.end () ; itr ++ ) {
        cout << " " << *itr ;
    }*/
    /*cout << " 2nd Vector elements : " ;
    for ( int i = 0 ; i < m ; i ++ ) {
        cin >> v2 [ i ] ;
    }*/
    /*auto itr = s.begin () ;
    itr ++ ;
    cout << " Answer : " << *itr ;*/
    cout << " \n \n " ;
    /*auto start_itr = set1.begin () ;
    start_itr ++ ;
    auto end_itr = set1.begin () ;
    advance ( end_itr , 4 ) ;
    set1.erase ( start_itr , end_itr ) ;
    for ( itr = set1.begin () ; itr != set1.end () ; itr ++ ) {
        cout << " " << *itr ;
    }*/
    /*int ans_sum = 0 ;
    set < int > set1 ;
    for ( auto ele : v1 ) {
        set1.insert ( ele ) ;
    }
    for ( auto ele : v2 ) {
        if ( set1.find ( ele ) != set1.end () ) {
            ans_sum += ele ;
        }
    }*/
    cout << " \n \n " ;
    //cout << " Answer : " << ans_sum ;
    cout << " \n \n " ;
    return 0 ;
}
