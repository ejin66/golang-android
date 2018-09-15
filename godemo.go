package main

import "C"

//export hello
func hello(message string) *C.char {
	var s = C.CString("hello," + message)
	return s
}

func main() {}