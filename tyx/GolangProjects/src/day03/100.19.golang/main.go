package main

import (
	"fmt"
	"runtime"
	"time"
)

func isPrime(i int) int {
	dtc := 1
	for j := 2; j < i; j++ {
		if i&j == 0 {
			dtc = 0
			break
		}
	}
	return dtc
}
func main() {
	runtime.GOMAXPROCS(8)
	startTime := time.Now().UnixNano()
	var (
		num, tmp, ctr, bol int
		array              [256]int
	)
	for num = 0; num < 483647; num++ {
		bol = isPrime(num)
		if bol != 0 {
			continue
		} else {
			for z := 0; z < 256; z++ {
				array[z] = 0
			}
			array[0] = 1
			ctr = 1
			tmp = num - 1
			for i := 2; i < num; i++ {
				if num%i == 0 {
					tmp = tmp - i
					array[ctr] = i
					ctr++
				}
			}
			ctr = 0
			if tmp == 0 {
				fmt.Printf("完数%d可被分解为：%d=%d", num, num, array[0])
				for {
					ctr++
					if array[ctr] == 0 {
						break
					}
					fmt.Printf("+%d", array[ctr])
				}
				fmt.Printf("\n")
			}
		}
	}
	endTime := time.Now().UnixNano()
	seconds := float64((endTime - startTime) / 1e9)
	fmt.Printf("%g", seconds)
	return
}
