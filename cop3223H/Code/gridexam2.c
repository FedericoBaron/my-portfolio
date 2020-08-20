#define SIZE 10

int getIndexBestArea(int grid[][SIZE]){
	
	int largest = 0;
	int rowc = 0
	int colc = 0
	for(int i = 0; i < SIZE -2; i++){
		for(int j = 0; j < SIZE -2; j++){
			//counts sum of 3x3
			int count = 0;
			for(int r = i; r < i + 3; r++){
				for(int c = j; c < j + 3; c++){
					count = count + grid[r][c];
				}
			}
			if(count > largest){
				largest = count;
				rowc = i + 1;
				colc = j + 1;
			}


		}
	}
	return 10 * rowc + colc;
	
}