#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std ;
/*class Node {     // Queue Using Linked List
public :
    int data ;
    Node * next ;
    Node ( int val ) { data = val ; next = NULL ; }
};
class Queue {
    Node * head ;
    Node * tail ;
    int Size ;
public :
    Queue () {
        this -> head = NULL ;
        this -> tail = NULL ;
        this -> Size = 0 ;
    }
    void Enqueue ( int data ) {
        Node * new_node = new Node ( data ) ;
        if ( this -> head == NULL ) { this -> head = this -> tail = new_node ; }
        else {
            this -> tail -> next = new_node ;
            this -> tail = new_node ;
        } this -> Size ++ ;
    }
    void Dequeue ( ) {
        if ( this -> head == NULL ) { return ; }
        else {
            Node * OldHead = this -> head ;
            Node * NewHead = this -> head -> next ;
            this -> head = NewHead ;
            if ( this -> head == NULL ) this -> tail = NULL ;
            OldHead -> next = NULL ;
            delete ( OldHead ) ;
        } this -> Size -- ;
    }
    int Get_Size () { return this -> Size ; }
    bool Empty () { return this -> head == NULL ; }
    int Front () {
        if ( this -> head == NULL ) return - 1 ;
        return this -> head -> data ;
    }
};*/
/*class Queue {
    int Front ;
    int Back ;
    vector < int > v ;
public :
    Queue () {
        this -> Front = - 1 ;
        this -> Back = - 1 ;
    }
    void Enqueue ( int data ) {
        this -> v.push_back ( data ) ;
        this -> Back ++ ;
        if ( this -> Back == 0 ) this -> Front = 0 ;
    }
    void Dequeue () {
        if ( this -> Front == this -> Back ) {
            this -> Front = - 1 ;
            this -> Back = - 1 ;
            this -> v.clear () ;
        } else { this -> Front ++ ; cout << this -> Front << " \n " ; }
    }
    int Front_Element () {
        if ( this -> Front == - 1 ) return - 1 ;
        return this -> v [ this -> Front ] ;
    }
    bool Empty () {
        return this -> Front = - 1 ;
    }
};*/
int main () {
    queue < int > qu ;
    qu.push ( 10 ) ;
    qu.push ( 20 ) ;
    qu.push ( 30 ) ;
    qu.push ( 40 ) ;
    qu.pop () ;
    while ( ! qu.empty () ) {
        cout << " " << qu.front () ;
        qu.pop () ;
    }
    cout << " \n \n " ;
    return 0 ;
}
