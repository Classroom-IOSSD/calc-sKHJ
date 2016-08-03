#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result=0; 
        int line = 0;
         
        double (*calPointer)(int,int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=1; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				calPointer = add;
				break;
				case '-':
				calPointer = minus;
				break;
				case '*':
				calPointer = mul;
                                break;
				case '/':
				calPointer = div;
				break;
			}	
                        result 	= calPointer(operand1, operand2);
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

