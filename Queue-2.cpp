#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque> //                      7
using namespace std ; // 1 3 -1 -3 5 3 6 7 , k = 3 , Result = 3 3 5 5 6 7
class Circular_Queue {
    int Front ;
    int Back ;
    int cs ;
    int ts ;
    vector < int > v ;
public :
    Circular_Queue ( int n ) {
        v.resize ( n ) ;
        this -> Front = n - 1 ;
        this -> Back = 0 ;
        this -> cs = 0 ;
        this -> ts = n ;
    }
    void Enqueue ( int data ) {
        if ( Fool () ) return ;
        this -> Back = ( this -> Back + 1 ) % this -> ts ;
        this -> v [ this -> Back ] = data ;
        this -> cs ++ ;
    }
    void Dequeue () {
        if ( Empty () ) return ;
        this -> Front = ( this -> Front + 1 ) % this -> ts ;
        this -> cs -- ;
    }
    int get_Front () {
        if ( this -> Front = -1 ) return - 1 ;
        return this -> v [ this -> Front ] ;
    }
    bool Empty () { return this -> cs = 0 ; }
    bool Fool () { return this -> cs = ts ; }
};
/*class Queue {
    stack < int > st ;
public :
    Queue () {}
    void Push ( int x ) {
        if ( st.empty () ) { st.push ( x ) ; }
        else {
            stack < int > temp ;
            while ( ! this -> st.empty () ) {
                temp.push ( this -> st.top () ) ;
                this -> st.pop () ;
            } this -> st.push ( x ) ;
            while ( ! temp.empty () ) {
                this -> st.push ( temp.top () ) ;
                temp.pop () ;
            }
        }
    }
    void pop () {
        if ( this -> st.empty () ) return ;
        this -> st.pop () ;
    }
    bool empty () { return this -> st.empty () ; }
    int Front () {
        if ( this -> st.empty () ) return - 1 ;
        return this -> st.top () ;
    }
};*/
/*class Queue {
    stack < int > st ;
public :
    Queue () {}
    void Push ( int x ) { this -> st.push ( x ) ; }
    void Pop () {
        if ( st.empty () ) return ;
        stack < int > temp ;
        while ( st.size () > 1 ) {
            temp.push ( st.top () ) ;
            st.pop () ;
        }
        this -> st.pop () ;
        while ( ! temp.empty () ) {
            st.push ( temp.top () ) ;
            temp.pop () ;
        }
    }
    bool empty () { return this -> st.empty () ; }
    int Front () {
        if ( st.empty () ) return - 1 ;
        stack < int > temp ;
        while ( st.size () > 1 ) {
            temp.push ( st.top () ) ;
            st.pop () ;
        }
        int result = this -> st.top () ;
        while ( ! temp.empty () ) {
            st.push ( temp.top () ) ;
            temp.pop () ;
        }
        return result ;
    }
};*/
/*vector < int > Max_Window ( vector < int > &arr , int k ) {
    deque < int > dq ;
    vector < int > res ;
    for ( int i = 0 ; i < k ; i ++ ) { // i = 0 , 1 , 2
        while ( ! dq.empty () && arr [ dq.back () ] < arr [ i ] ) {
            dq.pop_back () ;
        } dq.push_back ( i ) ;
    }
    res.push_back ( arr [ dq.front () ] ) ;
    for ( int i = k ; i < arr.size () ; i ++ ) { // i = 3 , 4 , 5 , 6 , 7
            int curr = arr [ i ] ; // curr = -3 , 5 , 3 , 6 , 7
        if ( dq.front () = ( i - k ) ) dq.pop_front () ; // 6 =
        while ( ! dq.empty () && arr [ dq.back () ] < arr [ i ] ) {// 6 < 7
            dq.pop_back () ;
        } dq.push_back ( i ) ; res.push_back ( arr [ dq.front () ] ) ;
    }
    return res ;
}*/
int main () {
    cout << " \n \n " ;
    Circular_Queue cqu ( 4 ) ;
    cqu.Enqueue ( 10 ) ;
    cqu.Enqueue ( 20 ) ;
    cqu.Enqueue ( 30 ) ;
    cqu.Enqueue ( 40 ) ;
    //input.pop () ;
    //input.pop () ;
    cout << " \n \n " ;
    /*stack < int > st ;
    while ( ! input.empty () ) {
        st.push ( input.front () ) ;
        input.pop () ;
    }
    while ( ! st.empty () ) {
        input.push ( st.top () ) ;
        st.pop () ;
    } */
    while ( ! cqu.Empty () ) {
        cout << " " << cqu.get_Front () ;
        cqu.Dequeue () ;
    }
    cout << " \n \n " ;
    return 0 ;
}
