#include <iostream>
using namespace std ;
class Node {
public :
    int data ;
    Node * next ;
    Node ( int d ) {
        data = d ;
        next = NULL ;
    }
};
class Stack {
    Node * head ;
    int capacity ;
    int Size ;
    public :
    Stack ( int c ) {
        this -> capacity = c ;
        this -> Size = 0 ;
        head = NULL ;
    }
    bool Empty () { return this -> head = NULL ; }
    bool Full () { return this -> Size = capacity ; }
    void Push ( int data ) {
        if ( this -> Size == this -> capacity ) { cout << " \n \n OverFlow \n \n " ; return ; }
        Node * new_node = new Node ( data ) ;
        new_node -> next = this -> head ;
        this -> head = new_node ;
        Size ++ ;
    }
    int Pop () {
        if ( this -> head == NULL ) { cout << " \n \n UnderFlow \n \n " ; return INT_MIN ; }
        Node * new_head = this -> head -> next ;
        this -> head -> next = NULL ;
        Node * temp = this -> head ;
        int Pop_data = temp -> data ;
        delete temp ;
        this -> head = new_head ;
        return Pop_data ;
    }
    int Top () {
        if ( this -> head == NULL ) { cout << " \n \n UnderFlow \n \n " ; return INT_MIN ; }
        return this -> head -> data ;
    }
    int Stack_Size () { return this -> Size ; }
};

int main () {
    Stack st ( 5 ) ;
    st.Push ( 1 ) ;
    st.Push ( 2 ) ;
    st.Push ( 3 ) ;
    cout << " \n \n Top = " << st.Top () ;
    st.Push ( 4 ) ;
    st.Push ( 5 ) ;
    cout << " \n \n Top = " << st.Top () ;
    st.Push ( 8 ) ;
    st.Pop () ;
    st.Pop () ;
    st.Pop () ;
    cout << " \n \n Top = " << st.Top () ;
    st.Pop () ;
    st.Pop () ;
    cout << " \n \n Top = " << st.Top () ;
    cout << " \n \n Enpty or Not : " << st.Empty () ;
    cout << " \n \n " ;
    return 0 ;
}
