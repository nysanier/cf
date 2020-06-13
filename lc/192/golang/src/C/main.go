package main

// TODO 1 修改文本
const textOriginal = `
示例：

输入：
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
输出：
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

解释：
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // 你原本在浏览 "leetcode.com" 。访问 "google.com"
browserHistory.visit("facebook.com");     // 你原本在浏览 "google.com" 。访问 "facebook.com"
browserHistory.visit("youtube.com");      // 你原本在浏览 "facebook.com" 。访问 "youtube.com"
browserHistory.back(1);                   // 你原本在浏览 "youtube.com" ，后退到 "facebook.com" 并返回 "facebook.com"
browserHistory.back(1);                   // 你原本在浏览 "facebook.com" ，后退到 "google.com" 并返回 "google.com"
browserHistory.forward(1);                // 你原本在浏览 "google.com" ，前进到 "facebook.com" 并返回 "facebook.com"
browserHistory.visit("linkedin.com");     // 你原本在浏览 "facebook.com" 。 访问 "linkedin.com"
browserHistory.forward(2);                // 你原本在浏览 "linkedin.com" ，你无法前进任何步数。
browserHistory.back(2);                   // 你原本在浏览 "linkedin.com" ，后退两步依次先到 "facebook.com" ，然后到 "google.com" ，并返回 "google.com"
browserHistory.back(7);                   // 你原本在浏览 "google.com"， 你只能后退一步到 "leetcode.com" ，并返回 "leetcode.com"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-browser-history
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
`

type BrowserHistory struct {
	history []string
	current int
}


func Constructor(homepage string) BrowserHistory {
	p := BrowserHistory{
		history : []string{homepage},  // TODO 最多5000次，cap可以优化
		current : 0,
	}
	return p
}


func (this *BrowserHistory) Visit(url string)  {
	this.history = this.history[:this.current+1]
	this.history = append(this.history, url)
	this.current += 1
}


func (this *BrowserHistory) Back(steps int) string {
	// step cur newc
	// 1    0   0
	// 1    1   0
	// 1    2   1
	if steps >= this.current {
		this.current = 0
	} else {
		this.current -= steps
	}

	return this.history[this.current]
}


func (this *BrowserHistory) Forward(steps int) string {
	// step cur len newc
	// 1    0   3   1
	// 1    1   3   2
	// 1    2   3   2
	n := len(this.history)
	m := n - this.current - 1
	if steps > m {
		this.current = n - 1
	} else {
		this.current += steps
	}

	return this.history[this.current]
}


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */