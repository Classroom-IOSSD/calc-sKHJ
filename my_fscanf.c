
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	while (*format) {
		if (*format == '%') {
			int c;
			format++;
			switch (*format) {
			case 'd':
				while (!isdigit(c = getc(fp))) {} // skip leading white space
				unsigned int num = 0;
				while (isdigit(c)) {
					num = num * 10 + c - '0';
					c = getc(fp);
				}
				int *tmp = va_arg(list, int);
			    *tmp = num;
				//ungetc(c, fp);
				break;

			case 'c':
				
				c = getc(fp);
				int *tmp2 = va_arg(list, int);
				*tmp2 = c;
				break;
			}

		}
		else {
			format++;
		}
	}

	va_end(list);
}


