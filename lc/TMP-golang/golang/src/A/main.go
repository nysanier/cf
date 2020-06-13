package main

import (
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `

`

// TODO 2 修改输入格式
type In struct {
	Arg1 string `json:"TODO"`
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
		ret := TODO(in.Arg1)
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
func TODO(string) int {
	initVars()
	return 0
}
