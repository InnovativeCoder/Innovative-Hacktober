/* A quine is a program which takes
 * no input and produces its own
 * source code as its only output.
 */

#include <stdio.h>

void main(){
	char *s = "void main(){\n\tchar *s = %c%s%c;\n\tprintf(s,34,s,34);\n}";
	printf(s,34,s,34);
}

