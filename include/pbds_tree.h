#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using PbdsTree = __gnu_pbds::tree<
        int,
        __gnu_pbds::null_type,
        std::less<int>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;

// __gnu_pbds::tree <Key, T>
/*
与std::map用法基本相同, 包括 begin(), end(), size(), empty(),
clear(), find(const Key), lower bound(const Key),
upper bound(const Key), erase(iterator), erase(const Key),
insert(const pair<Key, T>), operator[](const Key)

template <
    typename Key , typename Mapped ,
    typename Cmp_Fn = std :: less < Key >,
    typename Tag = rb_tree_tag ,
    template <
        typename Const_Node_Iterator ,
        typename Node_Iterator ,
        typename Cmp_Fn_ , typename Allocator_ >
    class Node_Update = null_tree_node_update ,
    typename Allocator = std :: allocator <char > >
class tree ;

Tag是指tree的类型: rb_tree_tag/splay_tree_tag/ov_tree_tag
    ov_tree_tag: O(n^2)
Node_Update: null_tree_node_update/tree_order_statistics_node_update
tree_order_statistics_node_update: find_by_order()⁄order_of_key()
iterator find_by_order(size_type order)
    找第order+1小的元素的迭代器
size_type order_of_key(const_key_reference r_key)
    询问这个tree中有多少个比r_key小的元素
*/
