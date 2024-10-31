#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#define ll long long int
using namespace std ;
/*class MinStack {
public :
    stack < ll > st ;
    ll m ;
    MinSstack () {
        this -> m = INT_MAX ;
    }
    void Push ( int val ) {
        if ( st.empty () ) {
            this -> m = val ;
            this -> st.push ( val ) ;
        } else {
            this -> st.push ( val - this -> m ) ;
            if ( this -> m > val ) this -> m = val ;
        }
    }
    void Pop () {
        if ( ! this -> st.empty () ) {
            if ( this -> st.top () >= 0 ) {
                this -> st.pop () ;
            } else {
                this -> m = this -> m - this -> st.top () ;
                this -> st.top () ;
            }
        }
    }
    int Get_Min () {
        return this -> m ;
    }
    int Top () {
        if ( this -> st.size () == 1 ) return this -> st.top () ;
        else if ( this -> st.top () < 0 ) return this -> m ;
        else return this -> m + this -> st.top () ;
    }
};*/
stack < int > Copy_Stack ( stack < int > &input ) {
    stack < int > temp ;
    while ( ! input.empty () ) {
        int curr = input.top () ;
        input.pop () ;
        temp.push ( curr ) ;
    }
    stack < int > result ;
    while ( ! temp.empty () ) {
        int curr = temp.top () ;
        temp.pop () ;
        result.push ( curr ) ;
    }
    return result ;
}
void Recurssion_Copy_Stack ( stack < int > &st , stack < int > &result ) {
    if ( st.empty () ) return ;
    int curr = st.top () ;
    st.pop () ;
    Recurssion_Copy_Stack ( st , result ) ;
    result.push ( curr ) ;
}
void Insert_At_Bottom ( stack < int > &st , int x ) {
    stack < int > temp ;
    while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        temp.push ( curr ) ;
    }
    st.push ( x ) ;
    while ( ! temp.empty () ) {
        int curr = temp.top () ;
        temp.pop () ;
        st.push ( curr ) ;
    }
}
stack < int > Recursively_Insert_At_Bottom ( stack < int > &st , int x ) {
    if ( st.empty () ) { st.push ( x ) ; return st ; }
    int curr = st.top () ;
    st.pop () ;
    Recursively_Insert_At_Bottom ( st , x ) ;
    st.push ( curr ) ;
    return st ;
}
void Insert_At_Position ( stack < int > &st , int x , int pos ) {       // 4    4 <-
    stack < int > temp ;
    int n = st.size () ;                                                // 3    3 <-
    int c = 0 ; // c = 0 1 2 3                                               // 2    2 <-
    while ( c < n - pos ) { // (5-1=4)                                 // 1    1
        int curr = st.top () ;                                          // 100  0
        st.pop () ;
        temp.push ( curr ) ;
        c++ ;
    }
    st.push ( x ) ;
    while ( ! temp.empty () ) {
        int curr = temp.top () ;
        temp.pop () ;
        st.push ( curr ) ;
    }
    return ;
}
void Recursively_Remove_Bottom ( stack < int > st ) {
    if ( st.size () == 1 ) { st.pop () ; return ; }
    stack < int > temp ;
    int curr = st.top () ;
    st.pop () ;
    Recursively_Remove_Bottom ( st ) ;
    st.push ( curr ) ;
}
void Reverse_Stack ( stack < int > &st ) {
     stack < int > t1 , t2 ;
     while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        t1.push ( curr ) ;
     }
     while ( ! t1.empty () ) {
        int curr = t1.top () ;
        t1.pop () ;
        t2.push ( curr ) ;
     }
     while ( ! t2.empty () ) {
        int curr = t2.top () ;
        t2.pop () ;
        st.push ( curr ) ;
     }
}
void Reverse_Stack_Recursively ( stack < int > &st ) {
    if ( st.empty () ) return ;
    int curr = st.top () ;
    st.pop () ;
    Reverse_Stack_Recursively ( st ) ;
    Insert_At_Bottom ( st , curr ) ;
}
bool Balanced_String ( string str ) {
    stack < char > st ;
    int c = 0 ;
    for ( int i = 0 ; i < str.size () ; i ++ ) {
        char ch = str [ i ] ;
        if ( ch == '(' or ch == '{' or ch == '[' ) {
                st.push ( ch ) ;
                c ++ ;
            }
        else {
            if ( ch == ')' && !st.empty () && st.top () == '(' ) st.pop () ;
            else if ( ch == ']' && !st.empty () && st.top () == '[' ) st.pop () ;
            else if ( ch == '}' && !st.empty () && st.top () == '{' ) st.pop () ;
            else return false ;
        }
    }
    return st.empty () ;
}
vector < int > Next_Greater_Element ( vector < int > &arr ) {
    int n = arr.size () ;
    vector < int > output ( n , - 1 ) ;
    stack < int > st ;
    st.push ( 0 ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        while ( ! st.empty () && arr [ i ] > arr [ st.top () ] ) {
            output [ st.top () ] = arr [ i ] ;
            st.pop () ;
        }
        st.push ( i ) ;
    }
    while ( ! st.empty () ) {
        output [ st.top () ] = -1 ;
        st.pop () ;
    }
    return output ;
}
vector < int > Previous_Greater_Element ( vector < int > &arr ) {
    int n = arr.size () ;
    //reverse ( arr.begin () , arr.end () ) ;
    vector < int > output ( n , - 1 ) ;
    stack < int > st ;
    st.push ( 0 ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        while ( ! st.empty () && arr [ i ] > arr [ st.top () ] ) {
            output [ st.top () ] = arr [ i ] ;
            st.pop () ;
        }
        st.push ( i ) ;
    }
    while ( ! st.empty () ) {
        output [ st.top () ] = -1 ;
        st.pop () ;
    }
    //reverse ( arr.begin () , arr.end () ) ;
    //reverse ( output.begin () , output.end () ) ;
    return output ;
}
int Histogram ( vector < int > arr ) {
    int n = arr.size () ;
    stack < int > st ;
    st.push ( 0 ) ;
    int ans = INT_MIN ;
    for ( int i = 0 ; i < n ; i ++ ) {
        while ( ! st.empty () && arr [ i ] < arr [ st.top () ] ) {
            int el = arr [ st.top () ] ;
            st.pop () ;
            int nsi = i ;
            int psi = ( st.empty () ) ? ( - 1 ) : st.top () ;
            ans = max ( ans , el * ( nsi - psi - 1 ) ) ;
        }
        st.push ( i ) ;
    }
    while ( ! st.empty () ) {
        int el = arr [ st.top () ] ;
        st.pop () ;
        int nsi = n ;
        int psi = ( st.empty () ) ? ( - 1 ) : st.top () ;
        ans = max ( ans , el * ( nsi - psi - 1 ) ) ;
    }
    return ans ;
}
int Calculate ( int v1 , int v2 , char op ) {
    if ( op == '^' ) return pow ( v1 , v2 ) ;
    if ( op == '*' ) return v1 * v2 ;
    if ( op == '/' ) return v1 / v2 ;
    if ( op == '+' ) return v1 + v2 ;
    return v1 - v2 ;
}
int Eval ( string &str ) {
    stack < char > st ;
    for ( int i = st.size () - 1 ; i >= 0 ; i -- ) {
        char ch = str [ i ] ;
        if ( isdigit ( ch ) ) {
            st.push ( ch - '0' ) ;
        } else {
            int v2 = st.top () ;
            st.pop () ;
            int v1 = st.top () ;
            st.pop () ;
            st.push ( Calculate ( v1 , v2 , ch ) ) ;
        }
    }
    return st.top () ;
}
int Precedence ( char ch ) {
    if ( ch == '^' ) return 3 ;
    else if ( ch == '*' or ch == '/' ) return 2 ;
    else if ( ch == '+' or ch == '-' ) return 1 ;
    else return -1 ;
}
int Infix ( string &str ) {
    stack < int > numbers ;
    stack < char > ops ;
    for ( int i = 0 ; i < str.size () ; i ++ ) {
        if ( isdigit ( str [ i ] ) ) {
            numbers.push ( str [ i ] - '0' ) ;
        } else if ( str [ i ] == '(' ) {
            ops.push ( str [ i ] ) ;
        } else if ( str [ i ] == ')' ) {
            while ( !ops.empty () && ops.top () != '(' ) {
                char op = ops.top () ;
                ops.pop () ;
                int v2 = numbers.top () ;
                numbers.pop () ;
                int v1 = numbers.top () ;
                numbers.pop () ;
                numbers.push ( Calculate ( v1 , v2 , op ) ) ;
            }
            if ( ! ops.empty () ) ops.pop () ;
        } else {
            while ( ! ops.empty () && Precedence ( ops.top () ) >= Precedence ( str [ i ] ) ) {
                char op = ops.top () ;
                ops.pop () ;
                int v2 = numbers.top () ;
                numbers.pop () ;
                int v1 = numbers.top () ;
                numbers.pop () ;
                numbers.push ( Calculate ( v1 , v2 , op ) ) ;
            }
            ops.push ( str [ i ] ) ;
        }
    }
    while ( ! ops.empty () ) {
        char op = ops.top () ;
        ops.pop () ;
        int v2 = numbers.top () ;
        numbers.pop () ;
        int v1 = numbers.top () ;
        numbers.pop () ;
        numbers.push ( Calculate ( v1 , v2 , op ) ) ;
    }
    return numbers.top () ;
}
string Prefix_To_Postfix ( string &str ) {
    stack < string > st ;
    reverse ( str.begin () , str.end () ) ;
    for ( int i = 0 ; i < str.size () ; i ++ ) {
        if ( isdigit ( str [ i ] ) ) {
            st.push ( to_string ( str [ i ] ) ) ;
        } else {
            string v1 = st.top () ;
            st.pop () ;
            string v2 = st.top () ;
            st.pop () ;
            string newexp = v1 + v2 + str [ i ] ;
            st.push ( newexp ) ;
        }
    }
    return st.top () ;
}
int main () {
    cout << " \n \n " ;
    //string str = "(){})[()()])" ;
    string str = "*+32-15" ;
    /*stack < int > st ;
    st.push ( 100 ) ;
    st.push ( 1 ) ;
    st.push ( 2 ) ;
    st.push ( 3 ) ;
    st.push ( 4 ) ;*/
    /*while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        cout << " " << curr << " \n " ;
    } */cout << " \n \n " ;
    /*stack < int > res = Copy_Stack ( st ) ;
    while ( ! res.empty () ) {
        int curr = res.top () ;
        res.pop () ;
        cout << " " << curr << " \n " ;
    }*/
    /*stack < int > result ;
    Recurssion_Copy_Stack ( st , result ) ;
    while ( ! result.empty () ) {
        int curr = result.top () ;
        result.pop () ;
        cout << " " << curr << " \n " ;
    }*/
    /*Insert_At_Bottom ( st , 100 ) ;
    while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        cout << " " << curr << " \n " ;
    }*/
    /*Recursively_Insert_At_Bottom ( st , 100 ) ;
    while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        cout << " " << curr << " \n " ;
    }*/
    /*Insert_At_Position ( st , 12 , 1 ) ;
    while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        cout << " " << curr << " \n " ;
    }*/
    /*Recursively_Remove_Bottom ( st ) ;
    while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        cout << " " << curr << " \n " ;
    }*/
    //Reverse_Stack ( st ) ;
    /*Reverse_Stack_Recursively ( st ) ;
    while ( ! st.empty () ) {
        int curr = st.top () ;
        st.pop () ;
        cout << " " << curr << " \n " ;
    }*/
    //if ( Balanced_String ( str ) ) cout << " \n Balanced \n " ;
    //else cout << " \n Not Balanced \n " ;
    /*int n ; cout << " Enter Size = " ; cin >> n ;
    vector < int > v ; cout << " \n \n Enter Elements = " ;
    while ( n -- ) {
        int x ; cin >> x ; v.push_back ( x ) ;
    }*/
    cout << " \n \n Result = " ;
    cout << Prefix_To_Postfix ( str ) ;
    /*vector < int > Result = Next_Greater_Element ( v ) ;
    for ( int i = 0 ; i < Result.size () ; i ++ ) {
        cout << " " << i - Result [ i ] ;
    }*/
    /*int ans = Histogram ( v ) ;
    cout << "   " << ans ;*/
    cout << " \n \n " ;
    return 0 ;
}
