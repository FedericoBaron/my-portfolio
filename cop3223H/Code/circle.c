//Federico Baron


#include <stdio.h>
int main(void){
	int x,y,radius;
	printf("what radius");
	scanf("%d", &radius);

	for(x=-radius;x<=radius;x++){
		for(y=-radius;y<=radius;y++){
			if(x*x + y*y <= radius*radius)
				printf("**");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("%lf", 6.4%1.1);
	return 0;
}