package main

import (
	"fnpkg"
	"log"
	"sort"
)

// TODO 1 修改文本
const textOriginal = `
示例 1：

输入：arr = [5,5,4], k = 1
输出：1
解释：移除 1 个 4 ，数组中只剩下 5 一种整数。
示例 2：

输入：arr = [4,3,1,1,3,3,2], k = 3
输出：2
解释：先移除 4、2 ，然后再移除两个 1 中的任意 1 个或者三个 3 中的任意 1 个，最后剩下 1 和 3 两种整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/least-number-of-unique-integers-after-k-removals
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
type Out int

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
		ret := findLeastNumOfUniqueInts(in.Arg1, in.Arg2)
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

// TODO 7 实现算法
func findLeastNumOfUniqueInts(arr []int, k int) int {
	mp := make(map[int]int)
	for _, v := range arr {
		mp[v] += 1
	}

	a := []int{}
	for _, v := range mp {
		a = append(a, v)
	}

	sort.Ints(a)

	n := len(a)
	c := 0

	for _, v := range a {
		if k < v {
			break
		}

		c += 1
		k -= v
	}

	return n - c
}
