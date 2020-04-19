package main

import (
	"fmt"
)

func checkIfExist(arr []int) bool {
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
	inputs := []Input{
		{10, 2, 5, 3},
		{7, 1, 14, 11},
		{3, 1, 7, 11},
	}
	for _, arr := range inputs {
		fmt.Println(checkIfExist(arr))
	}
}
