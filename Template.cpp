#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <math.h>
#include <list>
using namespace std ;
int main () {
    list < int > l1 = { 1 , 2 , 3 , 4 , 5 } ;
    auto itr = l1.begin () ;
    cout << " " << *itr << " \n \n " ;
    return 0 ;
}
