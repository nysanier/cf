package main

import (
	"fnpkg"
	"log"
)

// 1 修改文本
const textOriginal = `
示例 1：

输入：arr = [2,3,1,6,7]
输出：4
解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
示例 2：

输入：arr = [1,1,1,1,1]
输出：10
示例 3：

输入：arr = [2,3]
输出：0
示例 4：

输入：arr = [1,3,5,7,9]
输出：3
示例 5：

输入：arr = [7,11,12,9,5,2,7,17,22]
输出：8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// 2 修改输入格式
type In struct {
	Arg1 []int `json:"arr"`
	// Arg2 int   `json:"n"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// 3 修改输出格式
type Out int

func main() {
	log.SetFlags(log.Lshortfile | log.Lmicroseconds)

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
		ret := countTriplets(in.Arg1)
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

// 提前计算好前缀数组异或，原理如下
// 0 ^ a = a
// a ^ a = 0
// a ^ b ^ a = b
func countTriplets(arr []int) int {
	ret := 0

	count := len(arr)
	if count < 1 {
		panic("arr没有值？")
		return 0
	}

	pre := make([]int, count)

	pre[0] = arr[0]
	for i := 1; i < count; i++ {
		pre[i] = pre[i-1] ^ arr[i]
	}

	// 300^3 = 9e6
	for i := 0; i < count; i++ {
		for j := i + 1; j < count; j++ {
			for k := j; k < count; k++ {
				// 可能 i = 0
				// 但是 j,k > 0
				a := 0
				if i == 0 {
					a = pre[j-1]
				} else {
					a = pre[j-1] ^ pre[i-1]
				}

				b := pre[k] ^ pre[j-1]

				if a == b {
					ret++
				}
			}
		}
	}

	return ret
}

// 会超时！
func countTripletsTimeout(arr []int) int {
	ret := 0

	// 300^4 = 27e8会超时！
	count := len(arr)
	for i := 0; i < count; i++ {
		for j := i + 1; j < count; j++ {
			for k := j; k < count; k++ {
				a := 0
				for x := i; x < j; x++ {
					a ^= arr[x]
				}
				b := 0
				for y := j; y <= k; y++ {
					b ^= arr[y]
				}
				if a == b {
					ret++
				}
			}
		}
	}

	return ret
}

// 字符串处理
// 根据前缀“输入：”找到input，根据“输出：”找到output
// input格式："k1=v1,k2=v2"
// output格式："value", 所以比较ret是否满足output，还算比较容易
