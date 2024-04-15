#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename T, typename C = less<T>>
using indexed_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V, typename C = less<K>>
using indexed_map = tree<K, V, C, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename H = detail::default_hash_fn<T>::type>
using hash_set = gp_hash_table<T, null_type, H>;

template <typename K, typename V, typename H = detail::default_hash_fn<K>::type>
using hash_map = gp_hash_table<K, V, H>;
