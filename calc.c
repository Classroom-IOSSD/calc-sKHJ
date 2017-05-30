
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result=0; 
    int line = 0;

	fp = fopen("read.txt", "r");
	if (fp != NULL) {
		my_fscanf(fp, "%d", &line);

		for (int i = 0; i<line && !feof(fp); i++) {
			my_fscanf(fp, "%d %c %d", &operand1, &operator, &operand2);
			switch (operator) {
			case '+':
				result = add(operand1, operand2);
				break;
			case '-':
				result = minus(operand1, operand2);
				break;
			case '*':
				result = mul(operand1, operand2);
				break;
			case '/':
				result = div(operand1, operand2);
				break;
			}
			printf("%d %c %d = %lf\n",
				operand1, operator, operand2, result);
		}
	}
	else
		printf("ERRROR");
	return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
void my_scanf(const char*, FILE*);
int main(void) {
	FILE* f = fopen("input.txt",
		"r");
	//fputs("123x", f);
	rewind(f);
	my_scanf("%u%c%u", f);
	fclose(f);
}

void my_scanf(const char* fmt, FILE* s) {
	if (*fmt == '%') {
		int c;
		switch (*++fmt) {
		case 'u':
			while (isspace(c = getc(s))) {} // skip leading white space
			unsigned int num = 0;
			while (isdigit(c)) {
				num = num * 10 + c - '0';
				c = getc(s);
			}
			printf("%%u scanned %u\n", num);
			ungetc(c, s);
		case 'c':
			c = getc(s);
			printf("%%c scanned '%c'\n", c);
		}
	}
}
*/