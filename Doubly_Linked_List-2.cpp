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
void Reverse_Doubly_List ( Node * &head , Node * &tail ) {
    Node * curr = head ;
    while ( curr ) {
        Node * next = curr -> next ;
        curr -> next = curr -> prev ;
        curr -> prev = next ;
        curr = next ;
    }
    Node * new_head = tail ;
    tail = head ;
    head = new_head ;
}
bool Palindrome_Check ( Node * head , Node * tail ) {
    while ( head != tail and head -> prev != tail ) {
        if ( head -> val != tail -> val ) return false ;
        head = head -> next ;
        tail = tail -> prev ;
    }
    return true ;
}
void Delete_Same_Node ( Node * &head , Node * &tail ) {
    Node * curr = tail -> prev ;
    while ( curr != head ) {
        Node * prevNode = curr -> prev ;
        Node * nextNode = curr -> next ;
        if ( prevNode -> val == nextNode -> val ) {
            prevNode -> next = nextNode ;
            nextNode -> prev = prevNode ;
            free ( curr ) ;
        } curr = prevNode ;
    }
}
bool is_Critical_Point ( Node * &curr ) {
    if ( curr -> prev -> val < curr -> val && curr -> next -> val < curr -> val ) return true ;
    if ( curr -> prev -> val > curr -> val && curr -> next -> val > curr -> val ) return true ;
    return false ;
}
vector < int > Critical_Point ( Node * head , Node * tail ) {
    vector < int > ans ( 2 , INT_MAX ) ;
    int firstCP = -1 , lastCP = -1 ;
    Node * curr = tail -> prev ;
    if ( curr == NULL ) { ans [ 0 ] = ans [ 1 ] = -1 ; return ans ; }
    int pos = 0 ;
    while ( curr -> prev != NULL ) {
        if ( is_Critical_Point ( curr ) ) {
            if ( firstCP == -1 ) { firstCP = lastCP = pos ; }
            else {
                ans [ 0 ] = min( ans [ 0 ] , pos - lastCP ) ;
                ans [ 1 ] = pos - firstCP ;
                lastCP = pos ;
            }
        }
        pos ++ ;
        curr = curr -> prev ;
    }
    if ( ans [ 0 ] == INT_MAX ) ans [ 0 ] = ans [ 1 ] = -1 ;
    return ans ;
}
vector < int > Pair_Of_Sum ( Node * head , Node * tail , int x ) {
    vector < int > ans ( 2 , -1 ) ;
    while ( head != tail ) {
        int sum = head -> val + tail -> val ;
        if ( sum == x ) {
            ans [ 0 ] = head -> val ;
            ans [ 1 ] = tail -> val ;
            return ans ;
        }
        if ( sum > x ) tail = tail -> prev ;
        else head = head -> next ;
    }
    return ans ;
}
int main () {
    DoublyList dl ;
    dl.Insert_At_End ( 2 ) ;
    dl.Insert_At_End ( 4 ) ;
    dl.Insert_At_End ( 6 ) ;
    dl.Insert_At_End ( 8 ) ;
    dl.Insert_At_End ( 10 ) ;
    dl.Display () ;
    //Reverse_Doubly_List ( dl.head , dl.tail ) ;
    //if ( Palindrome_Check ( dl.head , dl.tail ) ) cout << " \n \n  Yes. \n \n " ;
    //else cout << " \n \n No. \n \n " ;
    //Delete_Same_Node ( dl.head , dl.tail ) ;
    //vector < int > ans = Critical_Point ( dl.head , dl.tail ) ;
    //cout << " " << ans [ 0 ] << " " << ans [ 1 ] ;
    vector < int > ans = Pair_Of_Sum ( dl.head , dl.tail , 11 ) ;
    cout << "  " << ans [ 0 ] << "  " << ans [ 1 ] ;
    //dl.Display () ;
    return 0 ; }
