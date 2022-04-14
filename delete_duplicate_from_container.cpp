#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void delete_duplicate(T& v) {
    T v_unique;
    bool is_inside = 0;
    for (auto elem : v) {
        for (auto elem_unique : v_unique) {
            if (elem == elem_unique) is_inside = 1;
        }
        if (!is_inside) { v_unique.push_back(elem); }
        else  { is_inside = 0; }
    }

    v.erase(begin(v), end(v));
    v = v_unique;

    for (auto i : v) {
        cout << i << "; ";
    }
    cout << "\n";
}

class VecString : vector<char> {
public:
    VecString(initializer_list<char> l) {
        for (auto i : l) {
            this->push_back(i);
        }
    }

    bool operator==(const VecString& v) const {
        if (this->size() != v.size()) return false;
        for (int i = 0; i < min(this->size(), v.size()); ++i) {
            if (this->at(i) != v.at(i)) { return false; }
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, VecString& vs);
};

ostream& operator<<(ostream& os, VecString& vs) {
    for (auto i : vs) {
        os << i << " ";
    };
    return os;
}

int main() {

    vector<char> v{'s', 'a', 'a', 's', 's', 'h', 'a', 's', 's'};
    list<float> l{1.0, 1.0, 3.3, 5.7, 5.7};
    deque<int> d{1, 1, 45, 45, 56, 77, 77};

    vector<VecString> vs;
    VecString vc1{'s', 'a', 's', 'h', 'a'};
    VecString vc2{'s', 'a', 's', 'h', 'a'};
    VecString vc3{'i', 'g', 'o', 'r'};
    vs.push_back(vc1);
    vs.push_back(vc2);
    vs.push_back(vc3);

    delete_duplicate(v);
    delete_duplicate(l);
    delete_duplicate(d);
    delete_duplicate(vs);

    return 0;
}
