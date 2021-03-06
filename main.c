// ============================
//
//    PROJECT MEGACHESSATRON
//
// ============================


/*
MIT License

Copyright (c) 2017 Team Cos-Inifinity NITH

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "common.h"

int main(int argc, char const *argv[]){
	#ifdef DEBUG
	runTests();
	return 0;
	#endif
	//what level you selected
	if(argv[1] != '\0'){
		printf("LEVEL = %s \n",argv[1]);
	}
	else{
		puts("LEVEL = 4 (default)\n");
	}

	// Setup intial position
	position *current_position;
	char initboard[8][8]={"rnbqkbnr","pppppppp","........",
		"........","........","........","PPPPPPPP","RNBQKBNR"};
	current_position = createNewPosition(initboard);
	
	displayBoard(current_position);

	int p = 1;
	// run the till someone doesnt win or 100 moves played
	while(isGameRunning(current_position) && p<200)
	{
		// print whose turn it is
		//printf("Its is %s's turn\n", (current_position->turn=='w')?"White":"Black");
		int depth = 4;
		if (argc == 2)
		{
			depth = atoi(argv[1]);
		}
		current_position = getBestMove(current_position, depth);
		char* c = moveplayed(current_position).coordinates;
		
		displayBoard(current_position);
		
		if(p%2 == 1){
			// white's turn
			printf("%2d. %s ... \t\t (%d) \n\n",(p+1)/2, c, current_position->evaluation);
		} else {
			// black's turn
			printf("%2d.    ... %s\t\t (%d)\n\n",p/2, c,  current_position->evaluation);
		}
		
		fflush(stdout);
		p++;
	}
	
	deletePosition(current_position);
	return 0;
}

// TODO KING SAFETY
// TODO tempo
// TODO pawn structure
// TODO passed pawns
// TODO UCI/xBoard protocol
// TODO licence
// TODO 3-fold repetition
// TODO 50 move rule
// TODO PGN mode
