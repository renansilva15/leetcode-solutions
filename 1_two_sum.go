package main

import "fmt"

func twoSum(nums []int, target int) []int {
	result := []int{-1, -1}

	hashmap := make(map[int]int)

	for idx, num := range nums {
		if val, ok := hashmap[target-num]; ok {
			result[0] = val
			result[1] = idx
			break
		}

		hashmap[num] = idx
	}

	return result
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9

	result := twoSum(nums, target)

	output := fmt.Sprintf("[%d, %d]", result[0], result[1])

	fmt.Println(output)
}
