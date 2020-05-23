package main

import (
	"fnpkg"
	"log"
)

// 1 修改文本
const textOriginal = `
示例 1：

输入：target = [1,3], n = 3
输出：["Push","Push","Pop","Push"]
解释： 
读取 1 并自动推入数组 -> [1]
读取 2 并自动推入数组，然后删除它 -> [1]
读取 3 并自动推入数组 -> [1,3]
示例 2：

输入：target = [1,2,3], n = 3
输出：["Push","Push","Push"]
示例 3：

输入：target = [1,2], n = 4
输出：["Push","Push"]
解释：只需要读取前 2 个数字就可以停止。
示例 4：

输入：target = [2,3,4], n = 4
输出：["Push","Pop","Push","Push","Push"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/build-an-array-with-stack-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// 2 修改输入格式
type In struct {
	Arg1 []int `json:"target"`
	Arg2 int   `json:"n"`
}

// 3 修改输出格式
type Out []string

// https://leetcode-cn.com/problems/build-an-array-with-stack-operations/
func main() {
	log.SetFlags(log.Lshortfile | log.Lmicroseconds)

	// InList := []string{
	// 	`target = [1,3], n = 3`,
	// 	`target = [1,2,3], n = 3`,
	// 	`target = [1,2], n = 4`,
	// 	`target = [2,3,4], n = 4`,
	// }

	// OutList := []string{
	// 	`["Push","Push","Pop","Push"]`,
	// 	`["Push","Push","Push"]`,
	// 	`["Push","Push"]`,
	// 	`["Push","Pop","Push","Push","Push"]`,
	// }

	reader := fnpkg.NewReader1()
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
		ret := buildArray(in.Arg1, in.Arg2)
		retStr := reader.Write(ret)

		if retStr == outStr {
			log.Printf("[%v] ok", i)
		} else {
			log.Printf("[%v] failed", i)
			log.Printf("ret=%v", ret)
			log.Printf("out=%v", out)
		}
		// log.Printf("[%v] ret=%v, out=%v", i, ret, out)
	}
}

// target中的数字是递增的
// 模拟从1-n往target放入数字
func buildArray(target []int, n int) []string {
	ret := []string{}

	ti := 0 // target数组的下标
	for i := 1; i <= n; i++ {
		// 已经完成target的构建
		if ti >= len(target) {
			break
		}

		// 尝试放入一个数字
		ret = append(ret, "Push")

		// 如果不在target中，那么丢弃
		if target[ti] > i {
			ret = append(ret, "Pop")
			continue
		}

		// 准备下一个数字
		ti++
	}

	return ret
}
