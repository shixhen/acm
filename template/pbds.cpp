#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

// 定义一个支持名次树特性的 set
typedef tree<int, null_type, std::less<int>, rb_tree_tag,
             tree_order_statistics_node_update> indexed_set;

int main() {
    indexed_set s;
    s.insert(10);
    s.insert(20);
    s.insert(30);

    // 查询第 K 小 (从 0 开始计数)
    // find_by_order(1) 返回指向 20 的迭代器
    auto it = s.find_by_order(1); 
    
    // 查询某个值的排名
    // order_of_key(20) 返回 1 (表示有 1 个元素比它小)
    int rank = s.order_of_key(20); 
}