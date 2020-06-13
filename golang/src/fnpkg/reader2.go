package fnpkg

// 二
// 1 读入文件
// 2 简单校验input和output是否匹配
// 3 根据外部需求构建input/output

type FnIOReader2 interface {
	ReadListInt() (in []int, out int)
	// ReadLlistInt() (in []int, out int)
	// ReadListList() (in []int, out []int)
}

type FnIOReaderImpl struct {
	// Data string
	// IO   []string
	// In   []string
	// Out  []string
}

// func (p *FnIOReaderImpl) Init(filepath *string) {

// }

// func (p *FnIOReaderImpl) ReadListInt() (in []int, out int) {
// 	// json.Unmarshal
// }
