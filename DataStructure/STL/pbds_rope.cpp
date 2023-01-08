#include <bits/extc++.h>
using namespace std;

using namespace __gnu_pbds;
using namespace __gnu_cxx; //for rope

template<typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag> 
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;

template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;

template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main() {
    _heap<int> hp; // priority_queue
    _hash<int, int> hs; // hash table, replace unordered_map
    _hash<int> set;// set
    _tree<int, int> tr; // map
    
    rope<char> r; // a "heavy" string
    crope r2; //same as "rope<char>"
    return 0;
}