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
/*class Hashing {
    vector < list < int > > hashtable ;
    int buckets ;
public :
    Hashing ( int Size ) {
        buckets = Size ;
        hashtable.resize ( Size ) ;
    }
    int Hashvalue ( int key ) {
        return key % buckets ;
    }
    int Add ( int key ) {
        int index = Hashvalue ( key ) ;
        hashtable [ index ].push_back ( key ) ;
    }
    list < int > :: iterator Search ( int key ) {
        int index = Hashvalue ( key ) ;
        return find ( hashtable [ index ].begin () , hashtable [ index ].end () , key ) ;
    }
    void Delete ( int key ) {
        int index = Hashvalue ( key ) ;
        if ( Search ( key ) != hashvalue [ index ].end () ) {
        hashtable [ index ].erase ( Search ( key ) ) ;
        cout << " \n \n Deleted : " << key ; }
        else { cout << " \n \n Not Present ! " ; }
    }
};
int main () {
    Hashing H ( 10 ) ;
    H.Add ( 5 ) ;
    H.Add ( 9 ) ;
    H.Add ( 3 ) ;
    H.Delete ( 3 ) ;
    return 0 ;
}*/
int main () {
    cout << " \n \n " ;
    //int n ;
    /*map < string , int > directory ;
    directory [ "Naman" ] = 2376 ;
    directory [ "Neel" ] = 2316 ;
    directory [ "Aman" ] = 4376 ;
    directory [ "Tiya" ] = 4376 ;
    for ( auto ele : directory ) {
        cout << " Name : " << ele.first << " =  Phone Number : " << ele.second << " \n " ;
    }
    map < string , int > :: iterator itr ;
    for ( itr = directory.begin () ; itr != directory.end () ; itr ++ ) {
        cout << " Name : " << itr -> first << " = " << " Phone Number : " << itr -> second << " \n " ;
    }*/ // cout << " Size : " ; cin >> n ;
   /* unordered_map < int , string > record ;
    record.insert ( make_pair ( 1 , "Ria" ) ) ;
    record [ 2 ] = "Bali" ;
    record [ 3 ] = "Lali" ;
    record.insert ( make_pair ( 3 , "Harry" ) ) ;*/
    /*multimap < string , int > directory ;
    directory.insert ( make_pair ( "Urvi" , 5438 ) ) ;
    directory.insert ( make_pair ( "Hulk" , 2845 ) ) ;
    directory.insert ( make_pair ( "Hulk" , 7564 ) ) ;
    for ( auto ele : directory ) {
        cout << " Name : " << ele.first << " " << " Phone Numbers : " << ele.second << " \n " ;
    }*/
    unordered_multimap < string , int > Fruit_Count ;
    Fruit_Count.insert ( make_pair ( "Apple" , 6 ) ) ;
    Fruit_Count.insert ( make_pair ( "Banana" , 3 ) ) ;
    Fruit_Count.insert ( make_pair ( "Apple" , 4 ) ) ;
    for ( auto ele : Fruit_Count ) {
        cout << " Fruite Name : " << ele.first << " Count : " << ele.second << " \n " ;
    }
    cout << " \n \n " ;
    /*map < string , int > :: reverse_iterator itr ;
    for ( itr = directory.rbegin () ; itr != directory.rend () ; itr ++ ) {
        cout << " Name : " << itr -> first << " = " << " Phone Number : " << itr -> second << " \n " ;
    }*/
    /*vector < int > input ( n ) ;
    cout << " Enter Vector : " ;*/
    /*for ( auto p : record ) {
        cout << " Roll No . : " << p.first << " -> " << " Name : " << p.second << " \n " ;
    }*/
    //cout << " Count : " << directory.count ( "Hulk" ) ;
    cout << " \n \n " ;
    /*for ( int i = 0 ; i < n ; i ++ ) {
        cin >> input [ i ] ;
    }
    map < int , int > m ;
    for ( int i = 0 ; i < n ; i ++ ) {
        m [ input [ i ] ] ++ ;
    }
    int sum = 0 ;
    for ( auto ele : m ) {
        if ( ele.second > 1 ) sum += ele.first ;
    }*/
    cout << " \n \n " ;
    //cout << " Answer : " << sum ;
    cout << " \n \n " ;
    return 0 ;
}
