package main

import (
	"bytes"
	"fnpkg"
	"log"
	"math"
)

// 1 修改文本
const textOriginal = `
1417. 重新格式化字符串
给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。

 

示例 1：

输入：s = "a0b1c2"
输出："0a1b2c"
解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
示例 2：

输入：s = "leetcode"
输出：""
解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
示例 3：

输入：s = "1229857369"
输出：""
解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
示例 4：

输入：s = "covid2019"
输出："c2o0v1i9d"
示例 5：

输入：s = "ab123"
输出："1a2b3"

提示：

1 <= s.length <= 500
s 仅由小写英文字母和/或数字组成。
`

// 2 修改输入格式
type In struct {
	Arg1 string `json:"s"`
	// Arg2 int   `json:"n"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// 3 修改输出格式
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

		// 4 修改函数名
		ret := reformat(in.Arg1)
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

// 分别统计数字和字母的长度
// 如果两者相差超过1，那么无解，返回空串
// 否则长的在前面
func reformat(s string) string {
	ln := 0
	la := 0
	sn := bytes.NewBuffer(nil)
	sa := bytes.NewBuffer(nil)
	for _, c := range(s) {
		if c >= '0' && c <= '9' {
			ln += 1
			sn.WriteRune(c)
			continue
		}
		
		if (c >= 'a' && c <= 'z') {
			la += 1
			sa.WriteRune(c)
			continue
		}
	}


	if math.Abs(float64(ln - la)) > 1 {
		return ""
	}

	buf := make([]byte, ln + la)
	if ln > la {  // 先放数字
		for i, v := range sn.Bytes() {
			buf[i*2] = v
		}
		for i, v := range sa.Bytes() {
			buf[1+i*2] = v
		}
	} else { // 先放字母
		for i, v := range sa.Bytes() {
			buf[i*2] = v
		}
		for i, v := range sn.Bytes() {
			buf[1+i*2] = v
		}
	}

	return string(buf)
}
