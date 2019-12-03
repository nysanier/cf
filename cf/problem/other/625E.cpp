#include "bits/stdc++.h"

const int N = 1e5 + 9;
const int INF = 1e9;
int p[N];  // x的初始位置
int speed[N];  // x的当前速度
int pos[N];  // 当前这个位置是谁, pos[i]=y
int m, n;
int ri[N], le[N];  // x的后面和前面的frog

// key: round+id, 找到最小的x追上y的那一组, 且x最小, 因为x先去追的y, x追上y之后进行调整px和ny
std::set<std::pair<int, int>> event_queue;  // used as priority queue

// y多少轮可以追上z
int GetRound(int y, int z) {
    if (y == z) return INF;  // 自己永远追不上自己, 用于只有自己是特殊情况的处理
    int d = (p[z] - p[y] + m) % m;  // 当前x和y的距离
    if (z < y) d = (d + speed[z]) % m;  // 如果是最后一个人追第一个人,那么需要等第一个人先跑一次
    if (d <= speed[y]) return 1;  // 一轮就可以追上
    if (speed[y] <= speed[z]) return INF;  // y速度太慢,永远追不上z
    // 经过上面y<x的处理,这里都认为是x先跑追y
    // ay(t+1) >= az(t) + d -> t >= (d-ay)/(ay-az) 小数转正数 t >= (d-ay + ay-az-1)/(ay-az)
    //   -> t >= (d-az-1)/(ay-az)
    // y需要t+1才能追上z,所以最后还要+1, 上面这些判断可以保证ay > az
    return (d - speed[z] - 1) / (speed[y] - speed[z]) + 1;  
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", p + i, speed + i);
        pos[i] = i;
        p[i]--;  // 方便环上%m操作
    }
    // 根据所在位置排序,这样可以来构建双向列表(前后指针说明了,x是谁以及z是谁)
    std::sort(pos + 1, pos + n + 1, [](const int& y, const int& z){
        return p[y] < p[z];
    });

    // 第一个位置y是pos[i], 这个位置的下一个是ri[y],上一个是le[y]
    for (int i = 1; i <= n; i++) {
        int y = pos[i];
        int nxt = i + 1;
        if (nxt > n) nxt = 1;
        ri[y] = pos[nxt];
        int pre = i - 1;
        if (pre < 1) pre = n;
        le[y] = pos[pre];
    }

    // 将所有y追z的事件加入到event_queue中
    for (int i = 1; i <= n; i++) {
        event_queue.insert(std::make_pair(GetRound(i, ri[i]), i));
    }

    for (;;) {
        if (event_queue.begin()->first == INF) break;
        int y = event_queue.begin()->second;  // y追上了z
        int z = ri[y];
        event_queue.erase(event_queue.begin());  // 先移除y
        event_queue.erase(std::make_pair(GetRound(z, ri[z]), z));  // z被追上了, 移除之
        if (!event_queue.empty()) {  // 追y的那个人也要先调整一下
            event_queue.erase(std::make_pair(GetRound(le[y], y), le[y]));
        }
        p[y] += GetRound(y, z);  // 调整当前位置
        p[y] %= m;
        speed[y]--;  // 调整速度
        int z2 = ri[z];
        ri[y] = z2;  // 调整链表的next
        le[z2] = y;
        event_queue.insert(std::make_pair(GetRound(le[y], y), le[y]));  // 重新计算x追y(y的pos变化了)
        event_queue.insert(std::make_pair(GetRound(y, z2), y));  // 重新计算y追z2
    }
    printf("%d\n", (int)event_queue.size());
    for (auto& kv : event_queue)
        printf("%d ", kv.second);
    printf("\n");
    return 0;
}
