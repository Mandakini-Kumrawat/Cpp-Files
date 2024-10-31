#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <math.h>
using namespace std ;
class Node {
public :
    int val ;
    Node * next ;
    Node ( int data ) {
        val = data ;
        next = NULL ;
    }
};
class Circular {
public :
    Node * head ;
    Circular () {
        head = NULL ;
    }
    void CL () {
        Node * temp = head ;
        for ( int i = 0 ; i < 10 ; i ++ ) {
            cout << " " << temp -> val << " -> " ;
            temp = temp -> next ;
        }
        cout << " \n \n " ;
    }
    void Display () {
        cout << " \n \n " ;
        Node * temp = head ;
        do {
            cout << " " << temp -> val << " -> " ;
            temp = temp -> next ;
        } while ( temp != head ) ;
        cout << " NULL \n \n " ;
    }
    void Insert_At_Start ( int val ) {
    Node * new_node = new Node ( val ) ;
    if ( head == NULL ) { head = new_node ; new_node -> next = new_node ; return ; } // 1 -> 2 -> 3 -> 4
    Node * tail = head ;
    while ( tail -> next != head ) {
        tail = tail -> next ;
    }
    tail -> next = new_node ;
    new_node -> next = head ;
    new_node = head ;
    }
    void Insert_At_End ( int val ) {
        Node * new_node = new Node ( val ) ;
        if ( head == NULL ) { head = new_node ; new_node -> next = new_node ; return ; }
        Node * tail = head ;
        while ( tail -> next != head ) {
            tail = tail -> next ;
        }
        tail -> next = new_node ;
        new_node -> next = head ;
        tail = new_node ;
    }
     void Delete_At_Start () {
         if ( head == NULL ) return ;
         Node * temp = head ;
         Node * tail = head ;
         while ( tail -> next != head ) {
            tail = tail -> next ;
         }
         head = head -> next ;
         tail -> next = head ;
         free ( temp ) ;
     }
     void Delete_At_End ( ) {
         if ( head == NULL ) return ;
         Node * tail = head ;
         while ( tail -> next -> next != head ) { // 1 -> 2 -> 3 -> 4 -> 5
            tail = tail -> next ;
         }
         Node * temp = tail -> next ;
         tail -> next = head ;
         free ( temp ) ;
     }
};
int main () {
    Circular cl ;
    cl.Insert_At_Start ( 1 ) ;
    cl.Insert_At_Start ( 2 ) ;
    cl.Insert_At_Start ( 3 ) ;
    cl.Insert_At_End ( 4 ) ;
    cl.Insert_At_End ( 5 ) ;
    cl.Display () ;
    cl.Delete_At_Start () ;
    cl.Display () ;
    //cl.CL () ;
    cl.Delete_At_End () ;
    cl.Display () ;
    //cl.CL () ;
    return 0;
}
