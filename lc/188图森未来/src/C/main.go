package main

import (
	"fnpkg"
	"log"
)

// 1 修改文本
const textOriginal = `
示例 1：



输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
输出：8 
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
示例 2：



输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
输出：6
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
示例 3：

输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// 2 修改输入格式
type In struct {
	Arg1 int     `json:"n"`
	Arg2 [][]int `json:"edges"`
	Arg3 []bool  `json:"hasApple"`
	// Arg4 int   `json:"n"`
}

// 3 修改输出格式
type Out int

func main() {
	log.SetFlags(log.Lshortfile | log.Lmicroseconds)

	const textOriginal = `
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
输出：0
`
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
		ret := minTime(in.Arg1, in.Arg2, in.Arg3)
		retStr := reader.Write(ret)

		if retStr == outStr {
			log.Printf("---- [%v] ok", i)
		} else {
			log.Printf("---- [%v] failed", i)
			log.Printf("---- ret=%v", ret)
			log.Printf("---- out=%v", out)
		}
	}

}

var mark []bool

// 树的问题，递归解决
func minTime(n int, edges [][]int, hasApple []bool) int {
	mat := make([][]int, n)
	for _, edge := range edges {
		a := edge[0]
		b := edge[1]
		mat[a] = append(mat[a], b)
		mat[b] = append(mat[b], a)
	}

	mark = make([]bool, n)
	mark[0] = true
	ret, _ := calc(0, mat, hasApple)

	return ret
}

// return 步数，是否有苹果
func calc(n int, mat [][]int, hasApple []bool) (int, bool) {
	ret := 0
	hasChild := false
	for _, v := range mat[n] {
		if mark[v] {
			continue
		}

		hasChild = true
		mark[v] = true
		childValue, ok := calc(v, mat, hasApple)
		if ok {
			ret += 2 + childValue
		}
	}

	if !hasChild {
		//log.Printf("n=%v, ret=%v", n, ret)
		return ret, hasApple[n]
	}

	//log.Printf("n=%v, ret=%v", n, ret)
	if ret > 0 {
		return ret, true
	}

	return 0, hasApple[n]
}
