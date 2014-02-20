#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    set<int> myset;
    pair<set<int>::iterator,bool> it;
    set<int>::iterator it2;

    it = myset.insert(3);
    cout << it.second << endl;
    it = myset.insert(6);
    it = myset.insert(7);
    it = myset.insert(1);


    it2 = myset.find(8);
    cout << *it2 << endl;
}
