package fnpkg

import "log"

// ConfigLog 的godoc, 第一个单词必须是函数名
//
// abcd, 下面需要一个空行, 否则类似html一样, 没有实现换行
//
// 新的一行
func ConfigLog() {
	log.SetFlags(log.Lmicroseconds | log.Lshortfile)
}
