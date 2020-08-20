//Federico Baron
//8/29/18
//ifPractice

//if(boolexp) stmt
//C has no boolean type
//0=FALSE, any non-zero value = TRUE

int main(){
	//get age
	int age;
	printf("How old are you?\n");
	scanf("%d",&age);

	//print if we can drive
	if (age<15){
		printf("You are eligible to drive\n");
		printf("did you take your written test?\n");
	}
	else{
		print("you can take the test in %d years",16-age);
	}
	printf("Goodbye\n");

	return 0;
}