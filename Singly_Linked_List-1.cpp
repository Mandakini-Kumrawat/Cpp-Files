#include <iostream>
//#include <vector>
//#include <cstring>
//#include <math.h>
using namespace std ;
class node {
    public :
    int val ;
    node * next ;
    node ( int data ) {
        val = data ;
        next = NULL ;
    }
};
void insertatstart ( node * &head , int val ) {
    node * newnode = new node ( val ) ;
    newnode -> next = head ;
    head = newnode ;
}
void insertatend ( node * &head , int val ) {
    node * newnode = new node ( val ) ;
    node * temp = head ;
    while ( temp -> next != NULL ) {
        temp = temp -> next ;
    }
    temp -> next = newnode ;
}
void insertatpos ( node * &head , int val , int pos ) {
    if ( pos == 0 ) {
    insertatstart ( head , val ) ;
    return ; }
    node * newnode = new node ( val ) ;
    node * temp = head ;
    int curr = 0 ;
    while ( curr != pos - 1 ) {
        temp = temp -> next ;
        curr ++ ;
    }
    newnode -> next = temp -> next ;
    temp -> next = newnode ;
}
void updateatpos ( node * &head , int val , int pos ) {
    node * temp = head ;
    int curr = 0 ;
    while ( curr != pos ) {
        temp = temp -> next ;
        curr ++ ;
    }
    temp -> val = val ;
}
void deleteatstart ( node * &head ) {
    node * temp = head ;
    head = head -> next ;
    free ( temp ) ;
}
void deleteatend ( node * &head ) {
    node * seclast = head ;
    while ( seclast -> next -> next != NULL ) {
        seclast = seclast -> next ;
    }
    node * temp = seclast -> next ;
    seclast -> next = NULL ;
    free ( temp ) ;
}
void deleteatpos ( node * &head , int pos ) {
    if ( pos == 0 ) {
        deleteatstart ( head ) ;
        return ;
    }
    node * prev = head ;
    int curr = 0 ;
    while ( curr != pos - 1 ) {
        prev = prev -> next ;
        curr ++ ;
    }
    node * temp = prev -> next ;
    prev -> next = prev -> next -> next ;
    free ( temp ) ;
}
void display ( node * head ) {
    node * temp = head ;
    while ( temp != NULL ) {
        cout << temp -> val << " " << temp -> next << " -> " ;
        temp = temp -> next ;
    }
    cout << " NULL \n \n " ;
}
int main () {
    node * head = NULL ;
    insertatstart ( head , 2 ) ;
    display ( head ) ;
    insertatstart ( head , 1 ) ;
    display ( head ) ;
    insertatend ( head , 4 ) ;
    display ( head ) ;
    insertatpos ( head , 3 , 2 ) ;
    display ( head ) ;
    updateatpos ( head , 10 , 3 ) ;
    display ( head ) ;
    //deleteatstart ( head ) ;
    //display ( head ) ;
    //deleteatend ( head ) ;
    //display ( head ) ;
    insertatstart ( head , 5 ) ;
    insertatstart ( head , 8 ) ;
    display ( head ) ;
    deleteatpos ( head , 3 ) ;
    display ( head ) ;
    return 0 ;
}
