package main

import (
	"fmt"
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `
示例 1：

输入：names = ["pes","fifa","gta","pes(2019)"]
输出：["pes","fifa","gta","pes(2019)"]
解释：文件系统将会这样创建文件名：
"pes" --> 之前未分配，仍为 "pes"
"fifa" --> 之前未分配，仍为 "fifa"
"gta" --> 之前未分配，仍为 "gta"
"pes(2019)" --> 之前未分配，仍为 "pes(2019)"
示例 2：

输入：names = ["gta","gta(1)","gta","avalon"]
输出：["gta","gta(1)","gta(2)","avalon"]
解释：文件系统将会这样创建文件名：
"gta" --> 之前未分配，仍为 "gta"
"gta(1)" --> 之前未分配，仍为 "gta(1)"
"gta" --> 文件名被占用，系统为该名称添加后缀 (k)，由于 "gta(1)" 也被占用，所以 k = 2 。实际创建的文件名为 "gta(2)" 。
"avalon" --> 之前未分配，仍为 "avalon"
示例 3：

输入：names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
输出：["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
解释：当创建最后一个文件夹时，最小的正有效 k 为 4 ，文件名变为 "onepiece(4)"。
示例 4：

输入：names = ["wano","wano","wano","wano"]
输出：["wano","wano(1)","wano(2)","wano(3)"]
解释：每次创建文件夹 "wano" 时，只需增加后缀中 k 的值即可。
示例 5：

输入：names = ["kaido","kaido(1)","kaido","kaido(1)"]
输出：["kaido","kaido(1)","kaido(2)","kaido(1)(1)"]
解释：注意，如果含后缀文件名被占用，那么系统也会按规则在名称后添加新的后缀 (k) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/making-file-names-unique
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 []string `json:"names"`
	// Arg2 int   `json:"n"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// TODO 3 修改输出格式
type Out []string

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
		ret := getFolderNames(in.Arg1)
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

// 优化版本，记录每个name当前的index
// 执行用时： 196 ms, 在所有 Go 提交中击败了 35.29% 的用户
//   数据规模卡的很紧啊
func getFolderNames(names []string) []string {
	mp1 := make(map[string]int) // 某个文件名出现的次数
	mp2 := make(map[string]bool)  // 所有最终文件名

	r := []string{}

	for _, name := range names {
		if _, ok := mp2[name]; !ok {
			mp2[name] = true
			r = append(r, name)
			mp1[name] = 1  // 下一个同名文件的起始index
			continue
		}

		// 先找到上次记录的起始index
		_, ok := mp1[name]
		if !ok { // 比如：["kaido","kaido(1)","kaido(2)","kaido(1)(1)","kaido(2)(0)"]
			mp1[name] = 1 // 下一个使用的计数
		}
		nextIndex, _ := mp1[name]
		for i:=nextIndex; true; i++ {
			name2 := fmt.Sprintf("%v(%v)", name, i)
			if _, ok := mp2[name2]; !ok {
				mp2[name2] = true
				r = append(r, name2)
				mp1[name] = i+1  // 更新起始index
				break
			}
		}
	}

	return r
}

// 先暴力求解，不优化，还真的超时了！！！
//   最差的情况就是求全部同名，第n个文件要尝试n-1次才可以找到合适的index
// 31 / 33 个通过测试用例
func getFolderNamesTimeout(names []string) []string {
	// mp1 := make(map[string]int) // 某个文件名出现的次数
	mp2 := make(map[string]bool) // 所有最终文件名

	r := []string{}

	for _, name := range names {
		if _, ok := mp2[name]; !ok {
			mp2[name] = true
			r = append(r, name)
			continue
		}

		for i:=1; true; i++ {
			name2 := fmt.Sprintf("%v(%v)", name, i)
			if _, ok := mp2[name2]; !ok {
				mp2[name2] = true
				r = append(r, name2)
				break
			}
		}
	}

	return r
}
