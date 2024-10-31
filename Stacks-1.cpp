#include <iostream>
#include <stack>
using namespace std ;
class Stack {
    int capacity ;
    int * arr ;
    int top ;
public :
    Stack ( int c ) {
        this -> capacity = c ;
        arr = new int [ c ] ;
        this -> top = -1 ;
    }
    void push ( int data ) {
        if ( this -> top == this -> capacity - 1 ) { cout << " \n \n Overflow \n \n " ; return ; }
        this -> top ++ ;
        this -> arr [ this -> top ] = data ;
    }
    int pop () {
        if ( this -> top == -1 ) { cout << " \n \n Underflow \n \n " ; return INT_MIN ; }
        this -> top -- ;
    }
    int Top_Element () {
        if ( this -> top == -1 ) { cout << " \n \n Underflow \n \n " ; return INT_MIN ; }
        return this -> arr [ this -> top ] ;
    }
    void Display () {
        for ( int i = 0 ; i < capacity ; i ++ ) {
            cout << " \n \n  " << arr [ i ] << " \n \n " ;
        }
    }
    bool Empty () { return this -> top = -1 ; }
    int Size () { return this -> top + 1 ; }
    bool Full () { return this -> top == this -> capacity - 1 ; }
};
int main () {
    Stack st ( 5 ) ;
    st.pop () ;
    st.push ( 0 ) ;
    st.push ( 1 ) ;
    st.push ( 2 ) ;
    //st.Display () ;
    cout << " \n \n Top = " << st.Top_Element () << " \n \n " ;
    st.push ( 3 ) ;
    st.push ( 4 ) ;
    cout << " \n \n Top = " << st.Top_Element () << " \n \n " ;
    st.push ( 8 ) ;
    st.pop () ;
    st.pop () ;
    cout << " \n \n Top = " << st.Top_Element () << " \n \n " ;
    cout << " \n \n Enpty or Not : " << st.Empty () ;
    return 0 ;
}
