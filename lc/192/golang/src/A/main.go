package main

import (
	"fnpkg"
	"log"
)

// 1 修改文本
const textOriginal = `
示例 1：

输入：nums = [2,5,1,3,4,7], n = 3
输出：[2,3,5,4,1,7] 
解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]
示例 2：

输入：nums = [1,2,3,4,4,3,2,1], n = 4
输出：[1,4,2,3,3,2,4,1]
示例 3：

输入：nums = [1,1,2,2], n = 2
输出：[1,2,1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// 2 修改输入格式
type In struct {
	Arg1 []int `json:"nums"`
	Arg2 int   `json:"n"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// 3 修改输出格式
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

		// 4 修改函数名
		ret := shuffle(in.Arg1, in.Arg2)
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

// 5 定义变量
// TODO

// 6 初始化变量
func Init() {
	// TODO
}

// 7 实现算法
func shuffle(nums []int, n int) []int {
	Init()

	var ret []int
	for i := 0; i < n; i++ {
		ret = append(ret, nums[i])
		ret = append(ret, nums[n+i])
	}

	return ret
}
