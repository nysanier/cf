package main

import (
	"fnpkg"
	"log"
	"sort"
	"strconv"
)

// 1 修改文本
const textOriginal = `
示例 0：
输入：orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
输出：[["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]]

示例 1：

输入：orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
输出：[["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
解释：
点菜展示表如下所示：
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
对于餐桌 3：David 点了 "Ceviche" 和 "Fried Chicken"，而 Rous 点了 "Ceviche"
而餐桌 5：Carla 点了 "Water" 和 "Ceviche"
餐桌 10：Corina 点了 "Beef Burrito" 
示例 2：

输入：orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
输出：[["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
解释：
对于餐桌 1：Adam 和 Brianna 都点了 "Canadian Waffles"
而餐桌 12：James, Ratesh 和 Amadeus 都点了 "Fried Chicken"
示例 3：

输入：orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
输出：[["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

// 2 修改输入格式
type In struct {
	Arg1 [][]string `json:"orders"`
	// Arg2 int   `json:"n"`
	// Arg3 int   `json:"n"`
	// Arg4 int   `json:"n"`
}

// 3 修改输出格式
type Out [][]string

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
		ret := displayTable(in.Arg1)
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

// 所有人点的菜的品种，排序来输出
var foodMap map[string]int // 名称->顺序号
var foodList []string // food的有序列表

type Table struct {
	FoodMap map[string]int
}

// 最多500桌
var tableList []*Table

func Init() {
	tableList = make([]*Table, 501) // 桌子编号，从1开始。。。
	foodList = make([]string, 0, 21) // 最多20种食物
	foodMap = make(map[string]int)
}

func displayTable(orders [][]string) [][]string {
	Init()

	for _, order := range orders {
		// 3元组["David","3","Ceviche"]
		InsertFoodMap(order[2])
		InsertTable(order[1], order[2])
	}

	SortFood()

	ordList := [][]string{}
	ordList = append(ordList, GetOrderTitle())
	for i, table := range(tableList) {
		// 这一桌没有点餐
		if table == nil || table.FoodMap == nil {
			continue
		}
		var ord []string
		ord = append(ord, strconv.Itoa(i)) // 桌号
		for _, food := range foodList {
			cnt := table.FoodMap[food]
			ord = append(ord, strconv.Itoa(cnt))
		}
		ordList = append(ordList, ord)
	}

	return ordList
}

func InsertFoodMap(food string) {
	foodMap[food] = -1 // 设置key
}

// 为对应的桌号增加某一个菜单项
func InsertTable(tableNum, food string) {
	num, _ := strconv.Atoi(tableNum)
	table := tableList[num]
	if table == nil {
		table = &Table{make(map[string]int)}
		tableList[num] = table
	}

	table.FoodMap[food] += 1
}

// 构造并排序菜单项list
// 设置反查map
func SortFood() {
	for k := range foodMap {
		foodList = append(foodList, k)
	}

	sort.Strings(foodList)

	for i, food := range foodList {
		foodMap[food] = i
	}
}

// 获取菜单标题
func GetOrderTitle() []string {
	var ord []string
	ord = append(ord, "Table")
	for _, food := range foodList {
		ord = append(ord, food)
	}
	return ord
}
