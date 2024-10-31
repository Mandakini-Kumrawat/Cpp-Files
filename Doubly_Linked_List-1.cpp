#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
//#include <math.h>
using namespace std ;
class Node {
public :
    int val ;
    Node * prev ;
    Node * next ;
    Node ( int data ) {
        val = data ;
        prev = NULL ;
        next = NULL ;
    }
};
class DoublyList {
public :
    Node * head ;
    Node * tail ;
    DoublyList () {
        head = NULL ;
        tail = NULL ;
    }
    void Display () {
        cout << " \n \n " ;
        Node * temp = head ;
        while ( temp ) {
            cout << " " << temp -> val << " " << " <--> " ;
            temp = temp -> next ;
        }
        cout << " NULL \n " ;
    }
    void Insert_At_Start ( int val ) {
        Node * new_node = new Node ( val ) ;
        if ( head == NULL ) { head = new_node ; tail = new_node ; return ; }
        new_node -> next = head ;
        head -> prev = new_node ;
        head = new_node ;
        return ;
    }
    void Insert_At_End ( int val ) {
        Node * new_node = new Node ( val ) ;
        if ( tail == NULL ) { head = new_node ; tail = new_node ; }
        tail -> next = new_node ;
        new_node -> prev = tail ;
        tail = tail -> next ;
    }
    void Insert_At_K ( int val , int k ) {
        Node * new_node = new Node ( val ) ;
        Node * temp = head ;
        int c = 1 ;
        while ( c < ( k - 1 ) ) {
            temp = temp -> next ;
            c ++ ;
        }
        new_node -> next = temp -> next ;
        temp -> next = new_node ;
        new_node -> next -> prev = new_node ;
        new_node -> prev = temp ;
    }
    void Delete_At_Start () {
        if ( head == NULL ) return ;
        Node * temp = head ;
        head = head -> next ;
        if ( head == NULL ) tail = NULL ;
        else head -> prev = NULL ;
        free ( temp ) ;
        return ;
    }
    void Delete_At_End () {
        if ( tail == NULL ) return ;
        Node * temp = tail ;
        tail = tail -> prev ;
        if ( tail == NULL ) head = NULL ;
        else tail -> next = NULL ;
        free ( temp ) ;
        return ;
    }
    void Delete_At_K ( int k ) { // 1 <-> 5 <-> 2 <-> 1 <-> 7
        Node * temp = head ;
        int c = 1 ;
        while ( c < k ) { temp = temp -> next ; c ++ ; }
        temp -> prev -> next = temp -> next ;
        temp -> next -> prev = temp -> prev ;
        free ( temp ) ;
        return ;
    }
};
int main () {
    DoublyList dl ;
    dl.Insert_At_Start ( 2 ) ;
    dl.Display () ;
    dl.Insert_At_Start ( 1 ) ;
    dl.Display () ;
    dl.Insert_At_Start ( 3 ) ;
    dl.Display () ;
    dl.Insert_At_End ( 0 ) ;
    dl.Display () ;
    dl.Insert_At_K ( 5 , 3 ) ;
    dl.Display () ;
    dl.Delete_At_Start () ;
    dl.Display () ;
    dl.Delete_At_End () ;
    dl.Display () ;
    dl.Insert_At_End ( 1 ) ;
    dl.Display () ;
    dl.Insert_At_End ( 7 ) ;
    dl.Display () ;
    dl.Delete_At_K ( 4 ) ;
     dl.Display () ;
    return 0 ;
}
