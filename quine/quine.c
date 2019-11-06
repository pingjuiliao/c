#include <stdio.h>

int
main(void) {

char *s = "#include <stdio.h>\n\nint\nmain(void) {\n\nchar *s = %c%s%c;\nprintf(s, 34, s, 34) ;\n\n}";
printf(s, 34, s, 34) ;

}
