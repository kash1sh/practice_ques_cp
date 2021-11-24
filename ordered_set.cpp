// #include <bits/stdc++.h>
// using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// int main()
// {

//     ordered_set st;
//     st.insert(3);
//     st.insert(5);
//     st.insert(6);
//     st.insert(8);
//     st.insert(12);

//     cout << *(st.begin()) << endl;
//     cout << *(find_by_order(3)) << endl;
//     cout << order_of_key(6) << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//common file for PBDS
#include <ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;

//macro definition
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{

    //ordered set
    ordered_set st;
    //insert operation
    st.insert(5);
    st.insert(10);
    st.insert(1);
    st.insert(3);
    //st-> {1, 3, 5, 10}

    //find_by_order() return the iterator to the element at xth(0-based) position
    cout << *(st.find_by_order(2));
    cout << endl;

    //order_of_key() returns number of elements in set which are strictly less than x
    cout << st.order_of_key(6);
    cout << endl;
    st.insert(6);

    cout << st.order_of_key(6);
    cout << endl;

    return 0;
}
