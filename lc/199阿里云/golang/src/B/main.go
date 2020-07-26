package main

import (
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `
示例 1：

输入：target = "10111"
输出：3
解释：初始配置 "00000".
从第 3 个灯泡（下标为 2）开始翻转 "00000" -> "00111"
从第 1 个灯泡（下标为 0）开始翻转 "00111" -> "11000"
从第 2 个灯泡（下标为 1）开始翻转 "11000" -> "10111"
至少需要翻转 3 次才能达成 target 描述的状态
示例 2：

输入：target = "101"
输出：3
解释："000" -> "111" -> "100" -> "101".
示例 3：

输入：target = "00000"
输出：0
示例 4：

输入：target = "001011101"
输出：5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulb-switcher-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 string `json:"target"`
	// Arg2 int   `json:"n"`
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
		ret := minFlips(in.Arg1)
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
// 从左往右扫描，连续相同的为同一段（如110011表示3端），得到需要的段数，首段如果值是0，不需要反转，其他的段数就是需要反转的次数
func minFlips(target string) int {
	flag1 := -1 // 是否找到了1, flag1的位置

	for i, v := range target {
		if v == '1' {
			flag1 = i
			break
		}
	}

	if flag1 < 0 {
		return 0
	}

	// 2次扫描，代码可以写的更简单一点
	val := uint8('1') // 当前段的值，flag1=true后有效
	cnt := 1          // 段数，flag1=true后有效
	for i := flag1 + 1; i < len(target); i++ {
		if target[i] != val {
			val = target[i]
			cnt++
		}
	}

	return cnt
}
