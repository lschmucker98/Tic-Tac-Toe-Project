
/*
 * Tic Tac Toe 
 * ECE 131 Project 3
 * Author: Landon Schmucker
*/
#include <stdio.h>
#include "gfx.h"	//External libraries I will use
#include <math.h>
#include <stdbool.h>

void drawx(int x, int y, int l);
void drawcircle(int x, int y, int r); //Defining Functions I will use
void drawboard(int x, int y);
bool gameover(int *array);

int main()
{	
	int board[3][3] = { 
		{ 0 },
		{ 0 },
		{ 0 },
	};
	char c;
	char turn;
	int again;
	int xsize;
	int ysize;
	FILE *outf;
	outf = fopen("tic_tac_toe.out","a"); // file to put turns in
	
	printf("Please enter the dimensions of the window you would like with a space separating them(x first then y): ");
	scanf("%d %d", &xsize, &ysize); // input for size
	printf("Who will go first if 'x' type x if 'o' type o.\n");
	scanf(" %c",&turn); // input for turn
 	
	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Tic-Tac-Toe");

	// Set the current drawing color to green.
	gfx_color(0,200,100);
	
	//draw board
	drawboard(xsize,ysize);

	while(1){
		// Wait for the user to press a character.
		if(turn == 'x') //player x turn for first turn get from user input &turn
		{
			c = gfx_wait(); // wait for click
			if(c == 1 || c == 2 || c == 3){ //mouse click 1 2 or 3
				if(gfx_xpos() < xsize/(3) && gfx_xpos() > 0 && gfx_ypos() < ysize/(3) && gfx_ypos() > 0)
				{
					if(board[0][0] != 1){
						drawx(xsize/6,ysize/6, xsize/3); //draw a x in top left corner
						board[0][0] = 1;  //fill array spot [0,0] with 1(same for every other line but different spots)
						fprintf(outf,"Player x played x at (0,0)\r\n"); //appends output file(same on every line)
						turn = 'o'; //switches turn
						if(gameover(*board)) //checks if board is full. If yes end game. (same everytime)
							printf("Game is Over\n");
					}
					else
						printf("Please pick another square\n");
				}
				else if(gfx_xpos() < (2*xsize)/(3) && gfx_xpos() > xsize/(3) && gfx_ypos() < (ysize)/(3) && gfx_ypos() > 0)
				{	
					if(board[1][0] != 1){
						drawx(xsize/2,ysize/6, xsize/3); //draw x in middle top
						board[1][0] = 1;
						fprintf(outf,"Player x played x at (1,0)\r\n");
						turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n"); 
					}
					else 
						printf("Please pick another square\n");
				}
				else if(gfx_xpos() < xsize && gfx_xpos() > (2*xsize)/(3) && gfx_ypos() < (ysize)/(3) && gfx_ypos() >  0)
				{
					if(board[2][0] != 1){
						drawx((5*xsize)/6, ysize/6, xsize/3); //draw x in top right
						board[2][0] = 1;
						fprintf(outf,"Player x played x at (2,0)\r\n");
						turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n");
					}
					else
						printf("Please pick another square\n");

				}
				else if(gfx_xpos() < xsize/(3) && gfx_xpos() > 0 && gfx_ypos() < (2*ysize)/(3) && gfx_ypos() > ysize/(3))
				{
					if(board[0][1] != 1){
						drawx(xsize/6,ysize/2, xsize/3); //left middle
						board[0][1] = 1;
						fprintf(outf,"Player x played x at (0,1)\r\n");
						turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n");
					}
					else
						printf("Please pick another square\n");
				}
				else if(gfx_xpos() < xsize/(3) && gfx_xpos() > 0 && gfx_ypos() > (2*ysize)/(3) && gfx_ypos() < ysize)
				{
					if(board[0][2] != 1){
                                                drawx(xsize/6,(5*ysize)/6, xsize/3); // bottom left corner
						board[0][2] = 1;
						fprintf(outf,"Player x played x at (0,2)\r\n");
                                                turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n");
					}
                                        else
                                                printf("Please pick another square\n");
				}
				else if(gfx_xpos() > xsize/(3) && gfx_xpos() < (2*xsize)/(3) && gfx_ypos() > ysize/(3) && gfx_ypos() < (2*ysize)/(3))
				{
					if(board[1][1] != 1){
						drawx(xsize/2, ysize/2, xsize/3); //middle square
						board[1][1] = 1;
						fprintf(outf,"Player x played x at (1,1)\r\n");
						turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n");
					}
					else
						printf("Please pick another square\n");
						
				}
				else if(gfx_xpos() > (2*xsize)/(3) && gfx_xpos() < xsize && gfx_ypos() > ysize/(3) && gfx_ypos() < (2*ysize)/(3))
				{
					if(board[2][1] != 1){
						drawx((5*xsize)/6, ysize/2, xsize/3); //right middle
						board[2][1] = 1;
						fprintf(outf,"Player x played x at (2,1)\r\n");
						turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n");
					}
					else
						printf("Please pick another square\n");

				}
				else if(gfx_xpos() > (2*xsize)/(3) && gfx_xpos() < xsize && gfx_ypos() > (2*ysize)/(3) && gfx_ypos() < ysize)
				{
					if(board[2][2] != 1){
						drawx((5*xsize)/6, (5*ysize)/6, xsize/3); //bottom right corner
						board[2][2] = 1;
						fprintf(outf,"Player x played x at (2,2)\r\n");
						turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n");
					}
					else
						printf("Please pick another square\n");
				}	
				else if(gfx_ypos() > (2*ysize)/(3) && gfx_ypos() < ysize && gfx_xpos() > xsize/(3) && gfx_xpos() < (2*xsize)/(3))
				{
					if(board[1][2] != 1){
						drawx(xsize/2, (5*ysize)/6, xsize/3); //bottom middle
						board[1][2] = 1;
						fprintf(outf,"Player x played x at (1,2)\r\n");
						turn = 'o';
						if(gameover(*board))
                                                        printf("Game is Over\n");
					}
					else
						printf("Please pick another square\n");
				}
		}
		}	
		else { //player 'o' turn
			c = gfx_wait();
                        if(c == 1 || c == 2 || c == 3){
                                if(gfx_xpos() < xsize/(3) && gfx_xpos() > 0 && gfx_ypos() < ysize/(3) && gfx_ypos() > 0)
				{
                              		if(board[0][0] != 1){
                                                drawcircle(xsize/6,ysize/6, xsize/6); //top left
                                                board[0][0] = 1;  
						fprintf(outf,"Player o played o at (0,0)\r\n");
                                                turn = 'x';
						if(gameover(*board))
                                                        printf("Game is Over\n");
                                        }
                                        else
                                                printf("Please pick another square\n");
				}
                                else if(gfx_xpos() < (2*xsize)/(3) && gfx_xpos() > xsize/(3) && gfx_ypos() < (ysize)/(3) && gfx_ypos() > 0)
                                {
                                	if(board[1][0] != 1){
                                                drawcircle(xsize/2,ysize/6, xsize/6); //draw x in middle top
                                                board[1][0] = 1;
						fprintf(outf,"Player o played o at (1,0)\r\n");
                                                turn = 'x';
						if(gameover(*board))
                                                        printf("Game is Over\n");
                                        }
                                        else
                                                printf("Please pick another square\n");
                                }
                                else if(gfx_xpos() < xsize && gfx_xpos() > (2*xsize)/(3) && gfx_ypos() < (ysize)/(3) && gfx_ypos() >  0)
                                {
                                	if(board[2][0] != 1){
                                                drawcircle((5*xsize)/6, ysize/6, xsize/6); //draw x in top right
                                                board[2][0] = 1;
						fprintf(outf,"Player o played o at (2,0)\r\n");
                                                turn = 'x';
						if(gameover(*board))
                                                        printf("Game is Over\n");
                                        }
                                        else
                                                printf("Please pick another square\n");
                                }
                                else if(gfx_xpos() < xsize/(3) && gfx_xpos() > 0 && gfx_ypos() < (2*ysize)/(3) && gfx_ypos() > ysize/(3))
                                {
                                	if(board[0][1] != 1){
                                                drawcircle(xsize/6,ysize/2, xsize/6); //left middle
                                                board[0][1] = 1;
						fprintf(outf,"Player o played o at (0,1)\r\n");
                                                turn = 'x';
						if(gameover(*board))
                                                        printf("Game is Over\n");
                                        }
                                        else
                                                printf("Please pick another square\n");
                                }
                                else if(gfx_xpos() < xsize/(3) && gfx_xpos() > 0 && gfx_ypos() > (2*ysize)/(3) && gfx_ypos() < ysize)
                                {
                                	if(board[0][2] != 1){
                                                drawcircle(xsize/6,(5*ysize)/6, xsize/6); // bottom left corner
                                                board[0][2] = 1;
						fprintf(outf,"Player o played o at (0,2)\r\n");
                                                turn = 'x';
						if(gameover(*board))
                                                        printf("Game is Over\n");
                                        }
                                        else
                                                printf("Please pick another square\n");
                                }
                                else if(gfx_xpos() > xsize/(3) && gfx_xpos() < (2*xsize)/(3) && gfx_ypos() > ysize/(3) && gfx_ypos() < (2*ysize)/(3))
                                {
                                	if(board[1][1] != 1){
                                                drawcircle(xsize/2, ysize/2, xsize/6); //middle square
                                                board[1][1] = 1;
						fprintf(outf,"Player o played o at (1,1)\r\n");
                                                turn = 'x';
						if(gameover(*board))
                                                        printf("Game is Over\n");
                                        }
                                        else
                                                printf("Please pick another square\n");
                                }
                                else if(gfx_xpos() > (2*xsize)/(3) && gfx_xpos() < xsize && gfx_ypos() > ysize/(3) && gfx_ypos() < (2*ysize)/(3))
                                {
                                	if(board[2][1] != 1){
                                                drawcircle((5*xsize)/6, ysize/2, xsize/6); //right middle
                                                board[2][1] = 1;
						fprintf(outf,"Player o played o at (2,1)\r\n");
                                                turn = 'x';
						if(gameover(*board))
                                                        printf("Game is Over\n");
                                        }
                                        else
                                                printf("Please pick another square\n");
                                }
                               else if(gfx_xpos() > (2*xsize)/(3) && gfx_xpos() < xsize && gfx_ypos() > (2*ysize)/(3) && gfx_ypos() < ysize)
                                {
                                
					if(board[2][2] != 1){
                                                drawcircle((5*xsize)/6, (5*ysize)/6, xsize/6); //bottom right corner
                                                board[2][2] = 1;
						fprintf(outf,"Player o played o at (2,2)\r\n");
                                                turn = 'x';
						if(gameover(*board)){
							printf("Game is Over\n");
                                                  
                                                }
                                                }
                                        
                                        else
                                                printf("Please pick another square\n");
                                }
				else if(gfx_ypos() > (2*ysize)/(3) && gfx_ypos() < ysize && gfx_xpos() > xsize/(3) && gfx_xpos() < (2*xsize)/(3))
                                {
                                	if(board[1][2] != 1){
                                                drawcircle(xsize/2, (5*ysize)/6, xsize/6); //bottom middle
                                                board[1][2] = 1;
						fprintf(outf,"Player o played o at (1,2)\r\n");
                                                turn = 'x';
						if(gameover(*board)){
							printf("Game is Over\n");
						}
                        			}
                        

                                        
                                        else
                                                printf("Please pick another square\n");
                               } 
			}
			if(gameover(*board)){
			printf("Thanks for playing!\n");
      	 		printf("Play again? (y/n)\n");
	                //scanf(" %c",&again);
			again = gfx_wait();
			if(again == 'n'){
				printf("See you later!");
				break;
			}
			else{
				gfx_clear();
                        	board[0][0] = 0;
				board[0][1] = 0;
				board[0][2] = 0;
				board[1][0] = 0;
				board[2][0] = 0;
				board[1][1] = 0;
				board[2][1] = 0;
				board[2][2] = 0;
				board[1][2] = 0;
				drawboard(xsize,ysize);
			}
			}
		}		
	
	}
	return 0;
}
void drawx(int x, int y, int l) //will use board size and xsize and ysize to length
{
	gfx_color(255,0,0);
        gfx_line(x-(l/2),y+(l/2),x+(l/2),y-(l/2));
        gfx_line(x+(l/2),y+(l/2),x-(l/2),y-(l/2));
}
void drawcircle(int x, int y, int r)//r is (l/2) x and y are xsize and ysize
{
	gfx_color(0,0,255);
	float ang;
	for(ang=0; ang <= 2*M_PI; ang += (M_PI/180)) //loops over circle by 1 degree
	{
		gfx_point(x+r*cos(ang),y-r*sin(ang));	
	}
}
void drawboard(int x, int y)
{
	gfx_line(0,(y)/(3),x,(y)/(3));
	gfx_line(0,(2*(y))/(3),x,(2*(y))/(3));  //divides board based on xsize and ysize
	gfx_line((x)/(3),0,(x)/(3),y);
	gfx_line((2*(x))/(3),0,(2*(x))/(3),y);
}
bool gameover(int *array)
{
	int i;
	int j;				
	for(i=0; i <= 2; i++)
	{
		for(j=0; j <= 2; j++)
		{
			if(*(array+i*3+j) == 0)	//loops over full board to see if every tile is filled with 1 which means its been played in
				return false;
		}
	}
	return true;
}
