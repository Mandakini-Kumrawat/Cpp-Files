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
    Node * next ;
    Node ( int data ) { val = data ; next = NULL ; }
};
class LinkedList {
public :
    Node * head ;
    LinkedList () { head = NULL ; }
    void insertattail ( int value ) {
        Node * new_node = new Node ( value ) ;
        if ( head == NULL ) {
            head = new_node ;
            return ;
        }
        Node * temp = head ;
        while ( temp -> next != NULL ) {
            temp  = temp -> next ;
        }
        temp -> next = new_node ;
    }
    void display () {
        Node * temp = head ;
        while ( temp != NULL ) {
            cout << " " << temp -> val << " -> " ;
            temp = temp -> next ;
        }
        cout << " NULL \n\n " ;
    }
};
void Delete_Alter_Node ( Node * &head ) {
    Node * curr_node = head ;
    while ( curr_node != NULL and curr_node -> next != NULL ) {
        Node * temp = curr_node -> next ;
        curr_node -> next = curr_node -> next -> next ;
        free ( temp ) ;
        curr_node = curr_node -> next ;
    }
}
void Delete_Duplicate_Node ( Node * &head ) {
    Node * curr_node = head ;
    while ( curr_node != NULL ) {
        while ( curr_node -> next != NULL and curr_node -> val == curr_node -> next -> val ) {
            Node * temp = curr_node -> next ;
            curr_node -> next = curr_node -> next -> next ;
            free ( temp ) ;
        } curr_node = curr_node -> next ;
    }
}
void Reverse_Traversing ( Node * &head ) {
    if ( head == NULL ) return ;
    else Reverse_Traversing ( head -> next )  ;
    cout << " <- " << head -> val << " " ;
}
Node * Reversing_List ( Node * &head ) {
    Node * prev = NULL ;
    Node * current = head ;
    while ( current != NULL ) {
        Node * next = current -> next ;
        current -> next = prev ;
        prev = current ;
        current = next ;
    }
    Node * new_head = prev ;
    return new_head ;
}
Node * Reversing_List_Recurrsion ( Node * &head ) {
    if ( head == NULL || head -> next == NULL ) return head ;
    Node * new_head = Reversing_List_Recurrsion ( head -> next ) ;
    head -> next -> next = head ;
    head -> next = NULL ;
    return new_head ;
}
Node * K_Node_Reversing ( Node * &head , int k ) {
    Node * prev = NULL ;
    Node * current = head ;
    int counter = 0 ;
    while ( current != NULL && counter < k ) {
        Node * next = current -> next ;
        current -> next = prev ;
        prev = current ;
        current = next ;
        counter ++ ;
    }
    if ( current != NULL ) {
    Node * new_head = K_Node_Reversing ( current , k ) ;
    head -> next = new_head ; }
    return prev ;
}
bool Same_List ( Node * h1 , Node * h2 ) {
    Node * ptr1 = h1 ;
    Node * ptr2 = h2 ;
    while ( ptr1 != NULL and ptr2 != NULL ) {
        if ( ptr1 -> val != ptr2 -> val ) return false ;
        ptr1 = ptr1 -> next ; ptr2 = ptr2 -> next ;
    }
    if ( ptr1 == NULL and ptr2 == NULL ) return true ;
}
int Get_Length ( Node * h ) {
    int len = 0 ;
    Node * temp = h ;
    while ( temp != NULL ) {
        len ++ ;
        temp = temp -> next ;
    }
    return len ;
}
Node * Move_K_Ahead ( Node * h , int n ) {
    Node * p = h ;
    while ( n -- ) p = p -> next ;
    return p ;
}
Node * Intersection ( Node * head1 , Node * head2 ) {
    int len1 = Get_Length ( head1 ) ;
    int len2 = Get_Length ( head2 ) ;
    Node* ptr1 ;
    Node* ptr2 ;
    if ( len1 > len2 ) {
        int k = len1 - len2 ;
        ptr1 = Move_K_Ahead ( head1 , k ) ;
        ptr2 = head2 ;
    } else {
        int k = len2 - len1 ;
        ptr1 = head1 ;
        ptr2 = Move_K_Ahead ( head2 , k ) ;
    }
    while ( ptr1 ) {
        if ( ptr1 == ptr2 ) return ptr1 ;
        ptr1 = ptr1 -> next ; ptr2 = ptr2 -> next ;
    }
    return NULL ;
}
void Remove_From_End ( Node * &head , int k ) { // 12 -> 13 -> 14 -> 15 -> 16 -> 17 -> 18 -> 19
    Node * ptr1 = head ;
    Node * ptr2 = head ;
    int c = k ;
    while ( c -- ) {
        ptr2 = ptr2 -> next ;
    }
    while ( ptr2 -> next != NULL ) {
        ptr1 = ptr1 -> next ;
        ptr2 = ptr2 -> next ;
    }
    if ( ptr2 == NULL ) {
        Node * temp = head ;
        head = head -> next ;
        free ( temp ) ;
        return ;
    }
    Node * temp = ptr1 -> next ;
    ptr1 -> next = ptr1 -> next -> next ;
    free ( temp ) ;
}
Node * Merge_List ( Node * & head1 , Node * &head2 ) {
    Node * DummyHeadNode = new Node ( -1 ) ;
    Node * ptr1 = head1 ;
    Node * ptr2 = head2 ;
    Node * ptr3 = DummyHeadNode ;
    while ( ptr1 and ptr2 ) {
        if ( ptr1 -> val < ptr2 -> val ) {
            ptr3 -> next = ptr1 ;
            ptr1 = ptr1 -> next ;
        } else {
            ptr3 -> next = ptr2 ;
            ptr2 = ptr2 -> next ;
        }
        ptr3 = ptr3 -> next ;
    }
    if ( ptr1 ) ptr3 -> next = ptr1 ;
    else ptr3 -> next = ptr2 ;
    return DummyHeadNode -> next ;
}
Node * Merge_Multiple_Lists ( vector < Node * > &lists ) {
    if ( lists.size () == 0 ) return NULL ;
    while ( lists.size () > 1 ) {
        Node * MergeHead = Merge_List ( lists [ 0 ] , lists [ 1 ] ) ;
        lists.push_back ( MergeHead ) ;
        lists.erase ( lists.begin () ) ;
        lists.erase ( lists.begin () ) ;
    }
    return lists [ 0 ] ;
}
Node * Middle_Node ( Node * &head ) {
    Node * slow = head ;
    Node * fast = head ;
    while ( fast and fast -> next ) {
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    return slow ;
}
bool Cycle_List ( Node * &head ) {
    Node * slow = head ;
    Node * fast = head ;
    while ( fast and fast -> next ) {
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if ( slow == fast ) {
        cout << slow -> val ; return true ; }
    }
    return false ;
}
void Remove_Cycle ( Node * &head ) {
    Node * slow = head ;
    Node * fast = head ;
    while ( fast and fast -> next ) {
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if ( slow == fast ) break ;
    }
    fast = head ;
    while ( fast -> next != slow -> next ) {
        slow = slow -> next ;
        fast = fast -> next ;
    }
    slow -> next = NULL ;
}
bool Palindrome ( Node * &head ) {
    Node * slow = head ;
    Node * fast = head ;
    while ( fast && fast -> next ) {
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    Node * curr = slow -> next ;
    slow -> next = NULL ;
    while ( curr ) {
    Node * next = curr -> next ;
    curr -> next = slow ;
    slow = curr ;
    curr = next ; }
    Node * head1 = head ;
    Node * head2 = slow ;
    while ( head2 ) {
        if ( head1 -> val != head2 -> val ) {
            return false ;
        }
        head1 = head1 -> next ;
        head2 = head2 -> next ;
    }
    return true ;
}
Node * Rotate_List_K ( Node * &head , int k ) { // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL n = 1 2 3 4 5 6 , i = 1 , 2
    int n = 0 ;
    Node * tail = head ;
    while ( tail -> next ) {
        n ++ ;
        tail = tail -> next ;
    } n ++ ;
    k = k % n ;
    if ( k == 0 ) return head ;
    tail -> next = head ;
    Node * temp = head ;
    for ( int i = 1 ; i < n - k ; i ++ ) {
        temp = temp -> next ;
    }
    Node * NewHead = temp -> next ;
    temp -> next = NULL ;
    return NewHead ;
}
Node * Odd_Even_List ( Node * &head ) {
    Node * EvenHead = head -> next ;
    Node * oddptr = head ;
    Node * evenptr = EvenHead ;
    while ( evenptr and evenptr -> next ) {
        oddptr -> next = oddptr -> next -> next ;
        evenptr -> next = evenptr -> next -> next ;
        oddptr = oddptr -> next ;
        evenptr = evenptr -> next ;
    }
    oddptr -> next = EvenHead ;
    return head ;
}
Node * Second_Last_Question ( Node * &head ) {
    Node * slow = head ;
    Node * fast = head ;
    while ( fast && fast -> next ) {
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    Node * curr = slow -> next ;
    slow -> next = NULL ;
    while ( curr ) {
        Node * next = curr -> next ;
        curr -> next = slow ;
        slow = curr ;
        curr = next ;
    }
    Node * ptr1 = head ;
    Node * ptr2 = slow ;
    while ( ptr1 != ptr2 ) {
        Node * temp = ptr1 -> next ;
        ptr1 -> next = ptr2 ;
        ptr1 = ptr2 ;
        ptr2 = temp ;
    }
    return head ;
}
Node * Swap_Adjacent_Node ( Node * &head ) {
    if ( head == NULL || head -> next == NULL ) return head ;
    Node * SecondNode = head -> next ;
    head -> next = Swap_Adjacent_Node ( SecondNode -> next ) ;
    SecondNode -> next = head ;
    return SecondNode ;
}
int main () {
    LinkedList li ;
    li.insertattail ( 1 ) ;
    li.insertattail ( 2 ) ;
    li.insertattail ( 3 ) ;
    li.insertattail ( 4 ) ;
    li.insertattail ( 5 ) ;
    li.insertattail ( 6 ) ;
    //li.insertattail ( 2 ) ;
    //li.insertattail ( 1 ) ;
    //li.head -> next -> next -> next -> next -> next -> next -> next -> next = li.head -> next -> next ;
    //li.insertattail ( 6 ) ;
    //li.display () ;
    cout << " \n \n " ;
    //Delete_Alter_Node ( li.head ) ;
    //Delete_Duplicate_Node ( li.head ) ;
    //Reverse_Traversing ( li.head ) ;
    //li.head = Reversing_List ( li.head ) ;
    //li.head = Reversing_List_Recurrsion ( li.head ) ;
    //li.head = K_Node_Reversing ( li.head , 2 ) ;
    //LinkedList li1 , li2 , li3 , li4 , li5 ;
    //cout << " 1st List -----------> \n \n " ;
    //li1.insertattail ( 1 ) ;
    //li1.insertattail ( 4 ) ;
    //li1.insertattail ( 5 ) ;
    //li1.display () ;
    //cout << "  2nd List -----------> \n \n " ;
    //li2.insertattail ( 11 ) ;
    //li2.insertattail ( 12 ) ;
    //li2.insertattail ( 13 ) ;
    //li2.insertattail ( 14 ) ;
    //li2.display () ;
    //cout << "  3rd List -----------> \n \n " ;
    //li3.insertattail ( 2 ) ;
    //li3.insertattail ( 3 ) ;
    //li3.display () ;
    //cout << "  4th List -----------> \n \n " ;
    //li4.insertattail ( 8 ) ;
    //li4.insertattail ( 9 ) ;
    //li4.display () ;
    //li2.head -> next -> next -> next = li1.head -> next -> next -> next ;
    //Remove_From_End ( li. head , 5 ) ;
    //li3.head = Merge_List ( li1.head , li2.head ) ;
    //cout << " Result List -----------> \n \n " ;
    //vector < Node * > v ;
    //v.push_back ( li1.head ) ;
    //v.push_back ( li2.head ) ;
    //v.push_back ( li3.head ) ;
    //v.push_back ( li4.head ) ;
    //li5.head = Merge_Multiple_Lists ( v ) ;
    //li5.display () ;
    //Node * lis = Middle_Node ( li.head ) ;
    //cout << " Middle Node = " << lis -> val ;
    //if ( Cycle_List ( li.head ) ) cout << " Yes " ;
    //else cout << " No " ;
    cout << " \n \n " ;
    li.display () ;
    //Remove_Cycle ( li.head ) ;
    cout << " \n \n " ;
    //if ( Palindrome ( li.head ) ) cout << " YES " ;
    //else cout << " NO " ;
    //li.head = Rotate_List_K ( li.head , 5 ) ;
    //li.display () ;
    //li.head = Odd_Even_List ( li.head ) ;
    //li.display () ;
    //li.head = Second_Last_Question ( li.head ) ;
    //li.display () ;
    li.head = Swap_Adjacent_Node ( li.head ) ;
    li.display () ;
    cout << " \n \n " ;
 return 0 ;
 }
