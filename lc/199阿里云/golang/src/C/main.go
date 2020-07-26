package main

import (
	"fnpkg"
	"log"
)

// TODO 1 修改文本
const textOriginal = `
给你二叉树的根节点 root 和一个整数 distance 。

如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。

返回树中 好叶子节点对的数量 。

 

示例 1：

 



输入：root = [1,2,3,-1,4], distance = 3
输出：1
解释：树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。
示例 2：



输入：root = [1,2,3,4,5,6,7], distance = 3
输出：2
解释：好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4 。
示例 3：

输入：root = [7,1,4,6,-1,5,3,-1,-1,-1,-1,-1,2], distance = 3
输出：1
解释：唯一的好叶子节点对是 [2,5] 。
示例 4：

输入：root = [100], distance = 1
输出：0
示例 5：

输入：root = [1,1,1], distance = 2
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// TODO 2 修改输入格式
type In struct {
	Arg1 []int `json:"root"`
	Arg2 int   `json:"distance"`
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
		ret := countPairs(constructTree(0, in.Arg1), in.Arg2)
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

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// k 当前节点在数组中的下标
func constructTree(k int, arr []int) *TreeNode {
	if k >= len(arr) {
		return nil
	}

	if arr[k] == -1 { // null 改成 -1 来处理，否则无法用[]int承接null这个值，python中才允许有
		return nil
	}

	pleft := constructTree(2*k+1, arr)
	pright := constructTree(2*k+2, arr)
	proot := &TreeNode{
		Val:   arr[k],
		Left:  pleft,
		Right: pright,
	}

	return proot
}

// 以上代码不需要提交，评测机已经实现了

// TODO 5 定义变量
// vars

type TreeNode2 struct {
	Parent *TreeNode2
	Val    int
	Left   *TreeNode2
	Right  *TreeNode2
}

var mp map[*TreeNode2]int
var ans int

// TODO 6 初始化变量
func initVars() {
	mp = make(map[*TreeNode2]int)
	ans = 0
}

// TODO 7 实现算法
// 数据规模是100个节点，暴力搜索就可以了，O(N^2)复杂度
// 1 找到所有的叶子节点，构建一个map可供查询
// 2 从每个叶子节点开始广度优先遍历，如果在distance范围内找到另外的叶子节点，那么res+=1
// 3 处理完所有叶子节点即得到了解

func iter(root *TreeNode2) {
	if root == nil {
		panic("impossible")
	}

	if root.Left == nil && root.Right == nil {
		mp[root] = 1
		return
	}

	if root.Left != nil {
		iter(root.Left)
	}

	if root.Right != nil {
		iter(root.Right)
	}
}

// 实际数据不止100，有400的case
func search(start *TreeNode2, distance int) {
	// log.Printf("start from [%v]", start.Val)
	mark := make(map[*TreeNode2]int)
	mark[start] = 0 // 0步走到自己
	queue := []*TreeNode2{start}
	for len(queue) > 0 {
		front := queue[0]
		queue = queue[1:]
		v := mark[front]
		nodes := []*TreeNode2{front.Parent, front.Left, front.Right}
		for _, node := range nodes {
			if node != nil {
				if _, ok := mark[node]; !ok {
					mark[node] = v + 1
					if v+1 <= distance { // 剪枝
						queue = append(queue, node)
					}
					if node.Left == nil && node.Right == nil && v+1 <= distance { // 是个叶子节点
						ans += 1
						// log.Printf("[%v] leaf ok", node.Val)
					} else {
						// log.Printf("[%v] inter", node.Val)
					}
				}
			}
		}
	}
}

func countPairs(root *TreeNode, distance int) int {
	initVars()

	root2 := constructTree2(nil, root)
	iter(root2)

	for k := range mp {
		search(k, distance)
	}

	return ans / 2
}

func constructTree2(parent *TreeNode2, root *TreeNode) *TreeNode2 {
	if root == nil {
		return nil
	}

	proot := &TreeNode2{
		Parent: parent,
		Val:    root.Val,
	}
	pleft := constructTree2(proot, root.Left)
	pright := constructTree2(proot, root.Right)
	proot.Left = pleft
	proot.Right = pright

	return proot
}
