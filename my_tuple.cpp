// Казаков Александр 335гр, 2022


#include<iostream>
#include<string>
#include<tuple>

using namespace std;

template<size_t index, typename T>
class Value {
    T value;
public:
    Value(const T& v) {
        value = v;
    }
    Value(T&& v) {
        value = move(v);
    }
    T& get() {
        return value;
    }
};

template<size_t index, typename... Types>
class Indexer {};

template<size_t index, typename T, typename... Types>
class Indexer<index, T, Types...> : public Value<index, typename remove_reference<T>::type>,
    public Indexer<index+1, Types...>{
public:
    template<typename CT, typename... CTypes>
    Indexer(CT&& arg, CTypes&&... args) :
        Value<index, typename remove_reference<CT>::type>(forward<CT>(arg)),
        Indexer<index+1, Types...>(forward<CTypes>(args)...) {}
};

template<size_t index, typename T, typename... Types>
struct ExtractTypeAt {
    using type = typename ExtractTypeAt<index-1, Types...>::type;
};

template <typename T, typename... Types>
struct ExtractTypeAt<0, T, Types...> {
    using type = T;
};

template<typename T, typename... Types>
class MyTuple : public Indexer<0, T, Types...>{
public:
    template<typename... CTypes>
    MyTuple(CTypes&&... args) : Indexer<0, T, Types...>(forward<CTypes>(args)...) {}
};

template<size_t index, typename... Types>
auto& get(MyTuple<Types...>& mt) {
    return (static_cast<Value<index, typename ExtractTypeAt<index, Types...>::type>&>(mt)).get();
}

template<size_t index, typename... Types>
bool compare_my_tuples(const MyTuple<Types...>& mt1, const MyTuple<Types...>& mt2) {
    if constexpr (index == 0) {
        return get<0>(mt1) == get<0>(mt2);
    } else {
        return get<index>(mt1) == get<index>(mt2) && compare_my_tuples<index-1>(mt1, mt2);
    }
}

template<typename... Types>
bool operator==(const MyTuple<Types...>& mt1, const MyTuple<Types...>& mt2) {
    return compare_my_tuples<sizeof...(Types)-1>(mt2, mt2);
}

int main() {

    //Indexer mt(1, 2.3);
    MyTuple<int, double, string> l(1, 3.5, (string)"abc");
    cout << get<0>(l) << " " << get<1>(l) << " " << get<2>(l) << endl;

    return 0;
}
