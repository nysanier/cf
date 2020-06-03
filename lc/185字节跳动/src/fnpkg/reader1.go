package fnpkg

import (
	"bytes"
	"encoding/json"
	"fmt"
	"strings"
)

// 一
// 1 读入文件
// 2 校验匹配
// 3 将key=val转化为"key":val，然后整体包上{}

type Reader1 interface {
	ReadIOList(text string) ([]string, []string)
	// in 和 out 必须是指针，否则无法返回结果
	Read(text string, v interface{})    // 类似json.Unmarshal
	ReadOut(text string, v interface{}) // 没有kv结构
	Write(v interface{}) string
}

func NewReader1() Reader1 {
	impl := new(reader1Impl)
	// impl.Data = text
	return impl
}

type reader1Impl struct {
	// Data string
	// IO   []string
	// In   []string
	// Out  []string
}

const (
	SeqIn  = "in"
	SeqOut = "out"
)

func (*reader1Impl) ReadIOList(text string) ([]string, []string) {
	l := strings.Split(text, "\n")
	var s1, s2 []string
	seq := SeqOut
	for _, line := range l {
		p1 := strings.Index(line, "输入：")
		p2 := strings.Index(line, "输出：")
		if p1 < 0 && p2 < 0 {
			continue
		}

		// 支持prefix不在开始的位置！
		if p1 >= 0 {
			s1 = append(s1, line[p1+len("输入："):])
			if seq == SeqIn {
				panic("seq not valid")
			}
			seq = SeqIn
			continue
		}

		if p2 >= 0 {
			s2 = append(s2, line[p2+len("输出："):])
			if seq == SeqOut {
				panic("seq not valid")
			}
			seq = SeqOut
			continue
		}

	}

	return s1, s2
}

func (*reader1Impl) Write(v interface{}) string {
	buf, err := json.Marshal(v)
	if err != nil {
		panic(err)
	}
	return string(buf)
}

func (*reader1Impl) ReadOut(text string, v interface{}) {
	err := json.Unmarshal([]byte(text), v)
	if err != nil {
		panic(err)
	}
	// log.Printf("v: %#v", v)
}

// 原始信息: text := `target = [1,3], n = 3`
// 第1步: s1 = []string{"target ", " [1,3], n ", " 3"}
// 第2步: s2 = []string{"target", "[1,3]", "n", "3"}
// 第3步: jsonStr = `{"target":[1,3], "n":3}`
// 第4步: in: main.FnIn{Target:[]int{1, 3}, N:3}
func (*reader1Impl) Read(text string, v interface{}) {
	// 1 根据等号(=)拆分字符串
	s1 := splitText(text)

	// 2 将中间的v1,k2; v2,k3再拆分开
	s2 := splitV1k2(s1)

	// 3 根据k1,v1,k2,v2...序列构建一个json串
	jsonStr := buildJsonStr(s2)

	// 4 解析json串
	err := json.Unmarshal([]byte(jsonStr), v)
	if err != nil {
		panic(err)
	}
	// log.Printf("v: %#v", v)
}

func splitText(text string) []string {
	s1 := strings.Split(text, "=")
	l1 := len(s1)
	if l1 < 2 {
		panic("l1 < 2")
	}
	return s1
}

func splitV1k2(s1 []string) []string {
	l1 := len(s1)
	s2 := []string{strings.TrimSpace(s1[0])}
	for i := 1; i < l1-1; i++ {
		p := strings.LastIndex(s1[i], ",")
		if p < 0 {
			panic("can't find ','")
		}
		s2 = append(s2, strings.TrimSpace(s1[i][:p]))
		s2 = append(s2, strings.TrimSpace(s1[i][p+1:]))
	}
	s2 = append(s2, strings.TrimSpace(s1[l1-1]))
	return s2
}

func buildJsonStr(s2 []string) string {
	l2 := len(s2)
	if l2%2 != 0 {
		panic("l2 % 2 != 0")
	}

	buf := bytes.NewBuffer(nil)
	buf.WriteString("{")

	buf.WriteString(fmt.Sprintf(`"%s":%s`, s2[0], s2[1]))
	for i := 2; i < l2; i += 2 {
		buf.WriteString(fmt.Sprintf(`, "%s":%s`, s2[i], s2[i+1]))
	}

	buf.WriteString("}")

	return buf.String()
}
