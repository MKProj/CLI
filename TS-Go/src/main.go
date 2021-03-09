package main

import (
	"flag"
	"os/exec"
)

func main() {
	getPtr := flag.String("get", "", "get content by <id>")
	listPtr := flag.String("list", "a", "list all available content or by category\nfs:Formula Sheet\nb:Basics\nn:Notes")
	flag.Parse()

	if *getPtr == "AMK3201" {
		exec.Command("wget", "https://github.com/MKProj/TomorrowStudy/raw/V1.0.0/tmp/AdvFuncMK/AdvFuncMK.pdf").Output()
	}

}
