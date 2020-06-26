package main

import (
	"container/heap"
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `


输入：rains = [1,0,2,3,0,1,2]
输出：[-1,1,-1,-1,2,-1,-1]

输入：rains = [1,0,2,0,2,1]
输出：[-1,1,-1,2,-1,-1]


示例 1：

输入：rains = [1,2,3,4]
输出：[-1,-1,-1,-1]
解释：第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，装满水的湖泊包括 [1,2,3]
第四天后，装满水的湖泊包括 [1,2,3,4]
没有哪一天你可以抽干任何湖泊的水，也没有湖泊会发生洪水。
示例 2：

输入：rains = [1,2,0,0,2,1]
输出：[-1,-1,2,1,-1,-1]
解释：第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，我们抽干湖泊 2 。所以剩下装满水的湖泊包括 [1]
第四天后，我们抽干湖泊 1 。所以暂时没有装满水的湖泊了。
第五天后，装满水的湖泊包括 [2]。
第六天后，装满水的湖泊包括 [1,2]。
可以看出，这个方案下不会有洪水发生。同时， [-1,-1,1,2,-1,-1] 也是另一个可行的没有洪水的方案。
示例 3：

输入：rains = [1,2,0,1,2]
输出：[]
解释：第二天后，装满水的湖泊包括 [1,2]。我们可以在第三天抽干一个湖泊的水。
但第三天后，湖泊 1 和 2 都会再次下雨，所以不管我们第三天抽干哪个湖泊的水，另一个湖泊都会发生洪水。
示例 4：

输入：rains = [69,0,0,0,69]
输出：[-1,69,1,1,-1]
解释：任何形如 [-1,69,x,y,-1], [-1,x,69,y,-1] 或者 [-1,x,y,69,-1] 都是可行的解，其中 1 <= x,y <= 10^9
示例 5：

输入：rains = [10,20,20]
输出：[]
解释：由于湖泊 20 会连续下 2 天的雨，所以没有没有办法阻止洪水。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/avoid-flood-in-the-city
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 []int `json:"rains"`
	// Arg2 int   `json:"n"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// TODO 3 修改输出格式
type Out []int

func main() {
	log.SetFlags(log.Lshortfile | log.Lmicroseconds)

	reader := fnpkg.NewLCReader1()
	InList, OutList := reader.ReadIOList(textOriginal)

	lin := len(InList)
	lout := len(OutList)
	if lin != lout {
		panic("lin != lout")
	}

	for i, text := range InList {
		in := new(In)
		reader.Read(text, in)

		var out Out
		reader.ReadOut(OutList[i], &out)
		outStr := reader.Write(out)

		// TODO 4 修改函数名
		ret := avoidFlood(in.Arg1)
		retStr := reader.Write(ret)

		if retStr == outStr {
			log.Printf("[%v] ok", i)
		} else {
			log.Printf("[%v] failed", i)
			log.Printf("actual=%v", ret)
			log.Printf("expect=%v", out)
		}
	}

}

//定义一个正方形的结构体
type Rectangle struct {
	index  int // 湖泊在数组中的索引
	value int // 湖泊编号
}

// 定义一个堆结构体
type RectHeap []Rectangle

// 实现heap.Interface接口 part1:
// 实现sort.Iterface
func (rech RectHeap) Len() int {
	return len(rech)
}
func (rech RectHeap) Swap(i, j int) {
	rech[i], rech[j] = rech[j], rech[i]
}
func (rech RectHeap) Less(i, j int) bool {
	return rech[i].index > rech[j].index  // index 大的在前面
}

// 实现heap.Interface接口 part2:
// 实现heap.Interface接口定义的额外方法
func (rech *RectHeap) Push(x interface{}) {
	*rech = append(*rech, x.(Rectangle))
}
func (rech *RectHeap) Pop() (interface{}) {
	n := len(*rech)
	r := (*rech)[n-1]      // 返回删除的元素
	*rech = (*rech)[:n-1] // [n:m]不包括下标为m的元素
	return r
}

// 模拟+贪心：从后往前处理，需要一个堆
func avoidFlood(rains []int) []int {
	mp := make(map[int][]int)
	ans := make([]int, len(rains))
	for i, rain := range rains {
		a := mp[rain]
		a = append(a, i)
		mp[rain] = a
	}

	hp := &RectHeap{}
	heap.Init(hp)
	stkmp := make(map[int]int) // 当前heap中有那些湖泊，一旦同一个湖泊超过一次需要0，则无解
	for i := len(rains)-1; i >= 0; i-- {
		rain := rains[i]
		a := mp[rain]
		l := len(a)

		if rain > 0 {
			// 已经入栈过一次，无法清空湖泊（两者之间找不到0）
			if stkmp[rain] > 0 {
				return []int{}
			}

			if l < 2 {  // 这个湖泊前面没有降雨，不用入栈
				ans[i] = -1
				continue
			}

			// 入栈
			stkmp[rain] = 1
			heap.Push(hp, Rectangle{a[l-2], rain})
			ans[i] = -1
			continue
		}

		// 遇到0
		if rain != 0 {
			panic(2)
		}

		// 不需要清空
		if len(*hp) == 0 {
			ans[i] = 1  // 随便填个值: 1
			continue
		}

		// 贪心，取最近最急的湖泊
		vp := heap.Pop(hp).(Rectangle)
		v := vp.value
		stkmp[v] = 0
		av := mp[v]
		mp[v] = av[:len(av)-1]
		ans[i] = v
	}

	// 还有湖泊无法及时清空
	if len(*hp) > 0 {
		return []int{}
	}

	return ans
}


/*
74 / 78 个通过测试用例
输入：rains = [1,0,2,3,0,1,2]
输出：[]
预期：[-1,1,-1,-1,2,-1,-1]
*/
// TODO 7 实现算法
// 模拟+贪心：从后往前处理，借助一个栈
func avoidFloodWrongAnswer2(rains []int) []int {
	mp := make(map[int][]int)
	ans := make([]int, len(rains))
	for i, rain := range rains {
		a := mp[rain]
		a = append(a, i)
		mp[rain] = a
	}

	stk := []int{} // 堆栈。入栈，意味着这个湖泊之前有降雨，需要0来清空湖泊
	stkmp := make(map[int]int) // 当前栈中有那些湖泊，一旦同一个湖泊超过一次需要0，则无解
	for i := len(rains)-1; i >= 0; i-- {
		rain := rains[i]
		a := mp[rain]
		l := len(a)

		if rain > 0 {
			// 已经入栈过一次，无法清空湖泊（两者之间找不到0）
			if stkmp[rain] > 0 {
				return []int{}
			}

			if l < 2 {  // 这个湖泊前面没有降雨，不用入栈
				ans[i] = -1
				continue
			}

			// 入栈
			stkmp[rain] = 1
			stk = append(stk, rain)
			ans[i] = -1
			continue
		}

		// 遇到0
		if rain != 0 {
			panic(2)
		}

		// 不需要清空
		if len(stk) == 0 {
			ans[i] = 1  // 随便填个值: 1
			continue
		}

		// 贪心，取最近最急的湖泊
		v := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		stkmp[v] = 0
		av := mp[v]
		mp[v] = av[:len(av)-1]
		ans[i] = v
	}

	// 还有湖泊无法及时清空
	if len(stk) > 0 {
		return []int{}
	}

	return ans
}


// 模拟+贪心：从后往前处理
func avoidFloodWrongAnswer1(rains []int) []int {
	mp := make(map[int][]int)
	ans := make([]int, len(rains))
	for i, rain := range rains {
		a := mp[rain]
		a = append(a, i)
		mp[rain] = a
		if rain > 0 {
			ans[i] = -1
		}
	}

	a0, _ := mp[0]

	for i := len(rains)-1; i >= 0; i-- {
		rain := rains[i]
		if rain == 0 {
			continue
		}

		a := mp[rain]
		l := len(a)
		if l < 2 {  // 不会发生洪水，不处理
			continue
		}

		if a[l-1] != i {
			panic("1")
		}

		// 在a0中找一个: <a[l-1] && >a[l-2] 的值
		l0 := len(a0)
		for {
			// 无解
			if l0 == 0 {
				return []int{}
			}

			if a0[l0-1] >= a[l-1] {  // 这个值没用，丢掉
				a0 = a0[:l0-1]
				l0 -= 1
				continue
			}

			if a0[l0-1] <= a[l-2] { // 找不到一个合适的值，返回失败
				return []int{}
			}

			// 处理这个湖泊
			ans[a0[l0-1]] = rain
			a0 = a0[:l0-1]
			l0 -= 1
			mp[rain] = a[:l-1]
			break
		}
	}

	// ans中不能有0！
	for i, v := range ans {
		if v == 0 {
			ans[i] = 1
		}
	}
	return ans
}
