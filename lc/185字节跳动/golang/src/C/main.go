package main

import (
	"fnpkg"
	"log"
	"sort"
)

// 1 修改文本
const textOriginal = `
示例 1：

输入：croakOfFrogs = "croakcroak"
输出：1 
解释：一只青蛙 “呱呱” 两次
示例 2：

输入：croakOfFrogs = "crcoakroak"
输出：2 
解释：最少需要两只青蛙，“呱呱” 声用黑体标注
第一只青蛙 "crcoakroak"
第二只青蛙 "crcoakroak"
示例 3：

输入：croakOfFrogs = "croakcrook"
输出：-1
解释：给出的字符串不是 "croak" 的有效组合。
示例 4：

输入：croakOfFrogs = "croakcroa"
输出：-1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// 2 修改输入格式
type In struct {
	Arg1 string `json:"croakOfFrogs"`
	// Arg2 int   `json:"n"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// 3 修改输出格式
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

		// 4 修改函数名
		ret := minNumberOfFrogs(in.Arg1)
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

var segList [][2]int
//var seqList [5][]int  // 每个字符所出现的位置
var seqList [26][]int  // 每个字符所出现的位置
var mp map[rune]int
var lmax int
var rmax int

// 10^5/5 = 2e4
func Init() {
	rmax = -1
	lmax = 1e5
	mp = make(map[rune]int)
	for i, v := range "croak" {
		mp[v] = i
	}
	segList = make([][2]int, 0)
	for _, v := range "croak" {
		//seqList[i] = make([]int, 0, 2e4)
		seqList[v-'a'] = make([]int, 0, 2e4)
	}
}

// croak 5个字母必须等数量，否则返回-1
// 组合左右的croak得到n/5个线段，计算线段重叠度最大的位置
// 这个题需要线段树，否则会超时！
func minNumberOfFrogs(croakOfFrogs string) int {
	Init()
	for i, c := range croakOfFrogs {
		//seqList[mp[c]] = append(seqList[mp[c]], i)
		seqList[c-'a'] = append(seqList[c-'a'], i)
	}
	var lenList []int
	for _, c := range "croak" {
		//lenList = append(lenList, len(seqList[mp[c]]))
		lenList = append(lenList, len(seqList[c-'a']))
	}
	sort.Ints(lenList)

	// 数量不等
	l1 := lenList[0]
	l2 := lenList[4]
	if l1 != l2 {
		return -1
	}

	for i:=0; i<l1; i++ {
		// 不是正常顺序的croak
		if seqList['c'-'a'][i] > seqList['r'-'a'][i] {
			return -1
		}
		if seqList['r'-'a'][i] > seqList['o'-'a'][i] {
			return -1
		}
		if seqList['o'-'a'][i] > seqList['a'-'a'][i] {
			return -1
		}
		if seqList['a'-'a'][i] > seqList['k'-'a'][i] {
			return -1
		}
		l := seqList['c'-'a'][i]
		r := seqList['k'-'a'][i]
		if l < lmax {
			lmax = l
		}
		if r > rmax {
			rmax = r
		}
		segList = append(segList, [2]int{l, r})
	}

	// TODO: 找到所有线段重叠最大的位置
	ret := FindFrogCountBySegtree()
	//ret := FindFrogCount()
	return ret
}


/*
前面52个case都可以暴力过，最后一个必须用线段树！
52 / 55 个通过测试用例
状态：超出时间限制
*/

func FindFrogCount() int {
	mk := make([]int, 1e5)
	for _, seg := range segList {
		a := seg[0]
		b := seg[1]
		for i:=a; i<=b; i++ {
			mk[i] += 1
		}
	}

	mx := 0
	for _, v := range mk {
		if v > mx {
			mx = v
		}
	}
	return mx
}


func FindFrogCountBySegtree() int {
	st := NewSegtree(lmax, rmax)
	for _, seg := range segList {
		l := seg[0]
		r := seg[1]
		st.Insert(l, r)
	}
	ret := st.Calc()
	return ret
}

// 线段树
type Segtree struct {
	root *SegtreeNode
}

// 构建一个线段树
func NewSegtree(left, right int) *Segtree {
	if left > right {
		panic(1)
	}

	st := &Segtree{
		root: &SegtreeNode{
			Lvalue: left,
			Rvalue: right,
		},
	}
	return st
}

func (p *Segtree) Calc() int {
	return p.root.calc()
}

func (p *Segtree) Insert(left, right int) {
	if left > right {
		panic(2)
	}
	if left < p.root.Lvalue {
		panic(3)
	}
	if right > p.root.Rvalue {
		panic(4)
	}

	p.root.insert(left, right)
}

// 线段树节点
// 每一个节点都覆盖了左右子树的范围
type SegtreeNode struct {
	Lvalue int
	Rvalue int
	Cnt int // 统计值
	Lchild *SegtreeNode
	Rchild *SegtreeNode
}

// 选择左右子树中最大的重叠度，再加上自身的重叠度
func (p *SegtreeNode) calc() int {
	lcnt := 0
	rcnt := 0
	if p.Lchild != nil {
		lcnt = p.Lchild.calc()
	}
	if p.Rchild != nil {
		rcnt = p.Rchild.calc()
	}
	lrmax := lcnt
	if rcnt > lrmax {
		lrmax = rcnt
	}
	ret := lrmax + p.Cnt
	return ret
}

func (p *SegtreeNode) insert(left, right int) {
	/*
		50 / 55 个通过测试用例
		这个条件如果没有处理，那么相当于每个点都会深入到最深的节点
	*/
	if p.Lvalue == left && p.Rvalue == right {
		p.Cnt += 1 // 统计值
		return
	}

	// [3,4] -> h=3 -> [3,3], [4,4]
	// [3,5] -> h=4 -> [3,4], [5,5]
	h := (p.Lvalue + p.Rvalue) / 2
	switch {
	case right <= h: // h归属左边
		p.CheckLchild(h)
		p.Lchild.insert(left, right)
	case left > h:
		p.CheckRchild(h)
		p.Rchild.insert(left, right)
	default:
		p.CheckLchild(h)
		p.CheckRchild(h)
		p.Lchild.insert(left, h)
		p.Rchild.insert(h+1, right)
	}

}

// 不需要创建所有的节点！
func (p *SegtreeNode) CheckLchild(h int) {
	if p.Lchild == nil {
		p.Lchild = &SegtreeNode{
			Lvalue: p.Lvalue,
			Rvalue: h, // h归属左边
		}
	}
}
func (p *SegtreeNode) CheckRchild(h int) {
	if p.Rchild == nil {
		p.Rchild = &SegtreeNode{
			Lvalue: h+1,
			Rvalue: p.Rvalue,
		}
	}
}
