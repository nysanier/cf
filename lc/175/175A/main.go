package main

import (
	"fmt"
	"unsafe"
)

func checkIfExist(arr []int) bool {
	fmt.Println(arr)
	// sort.Ints(arr)  // 升序
	// sort.Sort(sort.Reverse(sort.IntSlice(arr))) // 逆序, sort调用的reverse的interface(已经包装了原slice的接口)
	// sort.Sort(sort.Reverse(arr)) // 必须先转换成有sort.Interface接口的格式
	fmt.Println(arr)

	for i, n := range arr {
		for j, m := range arr {
			if i != j && n == 2*m {
				return true
			}
		}
	}

	return false
}

// Input is a type define of input
type Input []int

func main() {
	fmt.Println("int", unsafe.Sizeof(int(0)))
	fmt.Println("int32", unsafe.Sizeof(int32(0)))
	fmt.Println("int64", unsafe.Sizeof(int64(0)))

	inputs := []Input{
		{10, 2, 5, 3},
		{7, 1, 14, 11},
		{3, 1, 7, 11},
	}
	for _, arr := range inputs {
		fmt.Println(checkIfExist(arr))
	}

	// package的好处就是？不用关心定义顺序？
	test1()
	test2()
	test3()
}

// 1 测试%+v的表达力
type Hero struct {
	Name string
	Kind int
}

func test1() {
	a := Hero{"a", 1}
	b := &Hero{"b", 2}
	// {a 1} &{b 2}
	fmt.Println(a, b)
	// 打印字段名！
	// {a 1}, &{Name:b Kind:2}
	fmt.Printf("%v, %+v\n", a, b)
}

// 2 测试打印枚举字符串
type EnumType int

const (
	// ea EnumType = iota
	ea EnumType = 10 // 不是iota情况下，后面的值跟上面是一样的
	eb               // 不需要再指定值
	_
	_
	_           // 补足占位
	e5 EnumType = iota
	e6
)

func test2() {
	// 10, 10
	// 5, 6
	fmt.Printf("%v, %+v\n", ea, eb)
	fmt.Printf("%s, %+v\n", e5, e6)
	// %!s(main.EnumType=5), 6
	// 要正确转换为字符串，还需要手动写String函数，并用switch实现字符串的返回，麻烦！
}

// 3 测试 iota 在标记位（移位）上的应用
type FlagType int

const (
	// 行自增器, 换行才增长. 每次const的出现都会让iota置0
	sa FlagType = 1 << iota // 最好有类型, 这样不会和int等类型混淆(golang是强强类型的,不允许隐式类型转换)
	// sa = 1 << iota // 可以不需要具体类型
	sb
	_ // 跳过不想要的值
	sd
)

func test3() {
	// 1, 2, 8
	fmt.Printf("%v, %+v, %v\n", sa, sb, sd)
}
