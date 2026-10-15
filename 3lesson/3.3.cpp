#include <iostream>
#include <memory>

using namespace std;

int main() {
    shared_ptr<int> sp1 = make_shared<int>(100);
    weak_ptr<int> wp = sp1;

    cout << "Alive? " << (!wp.expired() ? "Yes" : "No") << endl;

    sp1.reset(); 

    if (wp.expired()) {
        cout << "Memory clean, no dangling pointers!" << endl;
    }

    return 0;
}