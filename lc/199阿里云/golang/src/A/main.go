package main

import (
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `
示例 1：



输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
输出："leetcode"
解释：如图所示，"codeleet" 重新排列后变为 "leetcode" 。
示例 2：

输入：s = "abc", indices = [0,1,2]
输出："abc"
解释：重新排列后，每个字符都还留在原来的位置上。
示例 3：

输入：s = "aiohn", indices = [3,1,4,2,0]
输出："nihao"
示例 4：

输入：s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
输出："arigatou"
示例 5：

输入：s = "art", indices = [1,0,2]
输出："rat"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 string `json:"s"`
	Arg2 []int  `json:"indices"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// TODO 3 修改输出格式
type Out string

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
		ret := restoreString(in.Arg1, in.Arg2)
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

// TODO 5 定义变量
// vars

// TODO 6 初始化变量
func initVars() {
}

// TODO 7 实现算法
func restoreString(s string, indices []int) string {
	buf := make([]byte, len(s))
	for i, v := range indices {
		buf[v] = s[i]
	}

	return string(buf)
}
