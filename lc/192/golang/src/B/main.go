package main

import (
	"fnpkg"
	"log"
	"sort"
)

// TODO 1 修改文本
const textOriginal = `
示例 0：

输入：arr = [-7,22,17,3], k = 2
输出：[22,17]

示例 1：

输入：arr = [1,2,3,4,5], k = 2
输出：[5,1]
解释：中位数为 3，按从强到弱顺序排序后，数组变为 [5,1,4,2,3]。最强的两个元素是 [5, 1]。[1, 5] 也是正确答案。
注意，尽管 |5 - 3| == |1 - 3| ，但是 5 比 1 更强，因为 5 > 1 。
示例 2：

输入：arr = [1,1,3,5,5], k = 2
输出：[5,5]
解释：中位数为 3, 按从强到弱顺序排序后，数组变为 [5,5,1,1,3]。最强的两个元素是 [5, 5]。
示例 3：

输入：arr = [6,7,11,7,6,8], k = 5
输出：[11,8,6,6,7]
解释：中位数为 7, 按从强到弱顺序排序后，数组变为 [11,8,6,6,7,7]。
[11,8,6,6,7] 的任何排列都是正确答案。
示例 4：

输入：arr = [6,-3,7,2,11], k = 3
输出：[-3,11,2]
示例 5：

输入：arr = [-7,22,17,3], k = 2
输出：[22,17]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-k-strongest-values-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 []int `json:"arr"`
	Arg2 int   `json:"k"`
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
		ret := getStrongest(in.Arg1, in.Arg2)
		retStr := reader.Write(ret)

		if retStr == outStr {
			log.Printf("[%v] ok", i)
		} else {
			log.Printf("[%v] failed", i)
			log.Printf("ret=%v", ret)
			log.Printf("out=%v", out)
		}
	}

}

// TODO 5 定义变量
// vars
var m int

// TODO 6 初始化变量
func initVars() {
}

// TODO 7 实现算法
// 两次sort：
//  1. 找中位数
//  2. 找前k强
func getStrongest(arr []int, k int) []int {
	initVars()

	m = getMid(arr)
	sort.Sort(MyInts(arr))

	return arr[:k]
}

func getMid(arr []int) int {
	sort.Ints(arr)
	n := len(arr)
	return arr[(n-1)/2]
}

type MyInts []int

func FnAbs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func (p MyInts) Len() int           { return len(p) }
func (p MyInts) Less(i, j int) bool { // 表示排在前面，而不是小于(<)
	a := FnAbs(p[i] - m)
	b := FnAbs(p[j] - m)
	if a > b { // 强，排在前面
		return true
	}

	if a == b && p[i] > p[j] {
		return true
	}

	return false
}
func (p MyInts) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }
