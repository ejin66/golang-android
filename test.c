#include <stdio.h>
#include <android/log.h>
#include "libgodemo.h"

void main() {
	GoString gostring;
	gostring.p = "ejin";
	gostring.n = 4;
	printf("%s", hello(gostring));
}