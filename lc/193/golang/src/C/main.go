package main

import (
	"fnpkg"
	"log"
	"sort"
)

// TODO 1 修改文本
const textOriginal = `
示例 0：

输入：bloomDay = [1000000000,1000000000], m = 1, k = 1
输出：1000000000
解释：需要等 1000000000 天才能采到花来制作花束


示例 1：

输入：bloomDay = [1,10,3,10,2], m = 3, k = 1
输出：3
解释：让我们一起观察这三天的花开过程，x 表示花开，而 _ 表示花还未开。
现在需要制作 3 束花，每束只需要 1 朵。
1 天后：[x, _, _, _, _]   // 只能制作 1 束花
2 天后：[x, _, _, _, x]   // 只能制作 2 束花
3 天后：[x, _, x, _, x]   // 可以制作 3 束花，答案为 3
示例 2：

输入：bloomDay = [1,10,3,10,2], m = 3, k = 2
输出：-1
解释：要制作 3 束花，每束需要 2 朵花，也就是一共需要 6 朵花。而花园中只有 5 朵花，无法满足制作要求，返回 -1 。
示例 3：

输入：bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
输出：12
解释：要制作 2 束花，每束需要 3 朵。
花园在 7 天后和 12 天后的情况如下：
7 天后：[x, x, x, x, _, x, x]
可以用前 3 朵盛开的花制作第一束花。但不能使用后 3 朵盛开的花，因为它们不相邻。
12 天后：[x, x, x, x, x, x, x]
显然，我们可以用不同的方式制作两束花。
示例 4：

输入：bloomDay = [1000000000,1000000000], m = 1, k = 1
输出：1000000000
解释：需要等 1000000000 天才能采到花来制作花束
示例 5：

输入：bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
输出：9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 []int `json:"bloomDay"`
	Arg2 int   `json:"m"`
	Arg3 int   `json:"k"`
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
		ret := minDays(in.Arg1, in.Arg2, in.Arg3)
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
func minDays(bloomDay []int, m int, k int) int {
	n := len(bloomDay)
	arr := make([]int, n)
	copy(arr, bloomDay)

	sort.Ints(arr)

	mx := len(bloomDay)
	mi := m * k
	if mi > mx {
		return -1
	}

	l := mi - 1
	h := mx - 1
	for l < h {
		mid := (l + h) / 2
		c := getCount(bloomDay, arr[mid], k)
		if c >= m {
			h = mid
		} else {
			l = mid + 1
		}
	}

	return arr[h]
}

func getCount(bloomDay []int, limit int, k int) int {
	r := 0
	c := 0  // 当前已经连续的话数量，达到k多，可以构成一束
	for _, v := range bloomDay {
		if v > limit {
			c = 0  // 不连续了，重置
			continue
		}

		// 累计
		c += 1
		if c == k {  // 累计到1束的两
			r += 1
			c = 0
		}
	}

	return r
}