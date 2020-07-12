package main

import (
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `
示例 1：

 



输入：n = 4, left = [4,3], right = [0,1]
输出：4
解释：如上图所示：
-下标 0 处的蚂蚁命名为 A 并向右移动。
-下标 1 处的蚂蚁命名为 B 并向右移动。
-下标 3 处的蚂蚁命名为 C 并向左移动。
-下标 4 处的蚂蚁命名为 D 并向左移动。
请注意，蚂蚁在木板上的最后时刻是 t = 4 秒，之后蚂蚁立即从木板上掉下来。（也就是说在 t = 4.0000000001 时，木板上没有蚂蚁）。
示例 2：



输入：n = 7, left = [], right = [0,1,2,3,4,5,6,7]
输出：7
解释：所有蚂蚁都向右移动，下标为 0 的蚂蚁需要 7 秒才能从木板上掉落。
示例 3：



输入：n = 7, left = [0,1,2,3,4,5,6,7], right = []
输出：7
解释：所有蚂蚁都向左移动，下标为 7 的蚂蚁需要 7 秒才能从木板上掉落。
示例 4：

输入：n = 9, left = [5], right = [4]
输出：5
解释：t = 1 秒时，两只蚂蚁将回到初始位置，但移动方向与之前相反。
示例 5：

输入：n = 6, left = [6], right = [0]
输出：6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-moment-before-all-ants-fall-out-of-a-plank
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 int   `json:"n"`
	Arg2 []int `json:"left"`
	Arg3 []int `json:"right"`
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
		ret := getLastMoment(in.Arg1, in.Arg2, in.Arg3)
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
// 两只蚂蚁碰头各自掉头，其实可以认为他们没有掉头，而是继续往前走。所以这个题求的是某一只离终点最远的蚂蚁什么时候到达。这里left和right要分开计算
func getLastMoment(n int, left []int, right []int) int {
	mx := 0
	for _, v := range left {
		// 向左的蚂蚁计算到0的举例的最大值
		if v > mx {
			mx = v
		}
	}

	for _, v := range right {
		mx2 := n - v
		if mx2 > mx {
			mx = mx2
		}
	}

	return mx
}
