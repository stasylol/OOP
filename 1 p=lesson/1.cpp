#include "header.h"
#include <iostream>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    cout << SimpleAdd::add(a, b) << endl << RandomAdd::add(a, b) << endl;
    return 0;
};