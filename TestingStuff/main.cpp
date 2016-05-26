#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Obj.h"

int main(int argc, char* argv) {
	Obj obj;
	obj.loadObject("objects/meinWuerfelA.obj");
	system("pause");
	return 0;
}