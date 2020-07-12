package main

import (
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `
示例 1：

输入：mat = [[1,0,1],
            [1,1,0],
            [1,1,0]]
输出：13
解释：
有 6 个 1x1 的矩形。
有 2 个 1x2 的矩形。
有 3 个 2x1 的矩形。
有 1 个 2x2 的矩形。
有 1 个 3x1 的矩形。
矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
示例 2：

输入：mat = [[0,1,1,0],
            [0,1,1,1],
            [1,1,1,0]]
输出：24
解释：
有 8 个 1x1 的子矩形。
有 5 个 1x2 的子矩形。
有 2 个 1x3 的子矩形。
有 4 个 2x1 的子矩形。
有 2 个 2x2 的子矩形。
有 2 个 3x1 的子矩形。
有 1 个 3x2 的子矩形。
矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
示例 3：

输入：mat = [[1,1,1,1,1,1]]
输出：21
示例 4：

输入：mat = [[1,0,1],[0,1,0],[1,0,1]]
输出：5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-submatrices-with-all-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 [][]int `json:"mat"`
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
		ret := numSubmat(in.Arg1)
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

// 如果n行m列都是1，那么公式如下推导
// 1 2 3 ... m
// 2 4 6
// 3 6 9
// ...
// n 2n 3n

// (1+n)*n/2 * (1+m)*m/2
// n=1,m=1 -> 1*1 = 1
// n=2,m=1 -> 3*1 = 3
// n=2,m=2 -> 3*3 = 9
// n=2,m=3 -> 3 * 6 = 18
// n=150,m=150 -> 11325^2 = 1.3e8

// TODO 7 实现算法
// 参考: https://leetcode-cn.com/problems/count-submatrices-with-all-ones/solution/5454-tong-ji-quan-1-zi-ju-xing-by-lin-miao-miao/
func numSubmat(mat [][]int) int {
	n := len(mat)
	m := len(mat[0])
	left := make([][]int, n)
	for i := range left {
		left[i] = make([]int, m)
	}

	// 计算每一行的left[i][j]
	for i := 0; i < n; i++ {
		c := 0
		for j := 0; j < m; j++ {
			if mat[i][j] == 1 {
				c++
			} else {
				c = 0
			}
			left[i][j] = c
		}
	}

	// 从第i行往第k行计算全1子矩形个数
	r := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			mi := 0x7f7f7f7f
			for k := i; k >= 0; k-- {
				if left[k][j] < mi {
					mi = left[k][j]
				}
				r += mi // 第一次计算i行，逐个往上移动，每次+上最小的全1行（水桶原理）
			}
		}
	}

	return r
}
