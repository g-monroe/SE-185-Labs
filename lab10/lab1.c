
// Lab 10 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output
// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename); 
void calcSel(int* py, int max, int* px);
//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) ;
int joy1, joy2, joy11, joy1Old, joy2Old, joy11Old;
void calcJoy(int js1, int js2, int js11);
void draw_character(int x, int y, char use);
void drawWords(char* wl[MAXWORDS], int* py, int maxLen);
int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	char sent[80] = "";
	char sentBackUp[80] = "";
	int wordSize =0;
	int wordCount;
	int capp = 0;
	int py;
	int on=1;
	int b_Up, b_Up_Old, b_Down, b_Down_Old, b_Left, b_Left_Old, b_Right, b_Right_Old, t, j1, j2, _j1, _j2;
	//Reset Joysticks
	joy1=0;
	joy11=0;
	joy1Old=1;
	joy11Old=1;
	joy2=0;
	py=0;
			int px = 1;
	b_Up_Old =0;
	b_Down_Old =0;
	b_Left_Old =0;
	b_Right_Old =0;
	//Grab Words
	wordCount = readWords(wordlist, argv[1]);
	initscr();
	refresh();
	int y = 0;
	int x = 0;
	for (int i=0; i<wordCount; i++){
		if ((i%15) != 0){
			mvprintw(y + 1, x, " %s\n", wordlist[i]);//draw selected word
			y++;
		}else{
			y= 0;
			x += 15;
			mvprintw(y, x, " %s\n", wordlist[i]);//draw selected word
		}
	}
	refresh();
	do{
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_Up, &b_Right, &b_Down, &b_Left, &j1, &j2, &_j1, &_j2);
		joy1Old = joy1;//Used to precision checking.
		joy11Old = joy11;
		//Calucate the joystick movement
		calcJoy(j2, _j2, j1); //j2 = Joy 1, _js2 = Joy 2
		calcSel(&py, wordCount, &px);
		//Draw Selected Words
		//drawWords(wordlist, &py, wordCountS);
		int px_Draw = (px * 15);
		char ptr[] = "*";
		int selected = (py + ((px -1)* 15));
		mvprintw(py-1, px_Draw, " ", ptr);//draw selected word
		mvprintw(py+1, px_Draw, " ", ptr);//draw selected word
		mvprintw(py, px_Draw, "%s", ptr);//draw selected word
		if ((py%15) == 0 && py != 0){
			if (joy1 == 2){
				px += 1;
			    py = 0;
			}
		}else{
			if (joy1 == 1 && px != 1 && py== 0){
				mvprintw(py, px_Draw, " ", ptr);//Clear Old;
				px -= 1;
			    py = 14;
			}
		}
		if (joy11Old!=joy11){
			if (px != 6 && joy11 == 2){
				mvprintw(py, px_Draw, " ", ptr);//Clear Old;
				if (px == 5){
					py = 0;
				}
				px += 1;
			}
			if (px != 1 && joy11 == 1){
				mvprintw(py, px_Draw, " ", ptr);//Clear Old;
				px -= 1;
			}
		}
		//Print Sentence
		mvprintw(15, 1, "\nStatement:%d:%d:%s                      ", px,py,sent);
		
		//Triangle
		if (b_Up != b_Up_Old && b_Up == 1){//Check if button is pressed
			strcpy(sentBackUp, sent);//Set Backup
			wordSize = 1;//New word added
			if (capp == 0){//Check if it needs caplized
				strcat(sent, wordlist[selected]);
				strcat(sent, " ");	
			}else{//if it needs caplized
				char str[255];
				strcpy(str, wordlist[selected]);
				//^set Temp
				if (isalpha(str[0])){//Check if letter
					str[0] = toupper(str[0]);
				}
				//Add new word.
				strcat(sent, str);
				strcat(sent, " ");
				capp = 0;
			}
		}
		//Cross or X
		if (wordSize != 0 && b_Down != b_Down_Old && b_Down == 1){
			//Set it to the backup sentence saved earlier
			strcpy(sent, sentBackUp);
			wordSize = 0;
		}
		//Square Add without space
		if (b_Left != b_Left_Old && b_Left == 1){//Check if button is pressed
			strcpy(sentBackUp, sent);//Set Backup
			wordSize = 1;//New word added
			if (capp == 1){//Check if it needs caplized
				strcat(sent, wordlist[selected]);
			}else{//Capilize
				char str[255];
				strcpy(str, wordlist[selected]);
				if (isalpha(str[0])){//Check if letter
					str[0] = toupper(str[0]);
				}
				strcat(sent, str);
				strcat(sent, " ");
				capp = 0;
			}
		}
		//Circle
		if (b_Right != b_Right_Old && b_Right == 1){//Cap next word.
			capp = 1;
		}
		//Update button presses
		b_Up_Old = b_Up;
		b_Down_Old = b_Down;
		b_Left_Old = b_Left;
		b_Right_Old = b_Right;
		refresh();
	}while(on == 1);
	endwin();
    return 0;
	}

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}
void calcSel(int* py, int max, int* px){
	if (joy1Old!=joy1){
		
		if (joy1 == 1 && *py != 0){
			*py = *py - 1;
		}
		if (joy1 == 2 && *py <= max && *px != 6){
			*py = *py + 1;
		}
		
	}
}
void calcJoy(int js1, int js2, int js11){
	if (js2 < -40){
		joy2 = 1;
	}else if (js2 > 40){
		joy2 = 2;
	}else{
		joy2 = 0;
	}
	if (js1 < -40){
		joy1 = 1;
	}else if (js1 > 40){
		joy1 = 2;
	}else{
		joy1 = 0;
	}
	if (js11 < -40){
		joy11 = 1;
	}else if (js11 > 40){
		joy11 = 2;
	}else{
		joy11 = 0;
	}
}
void drawWords(char* wl[MAXWORDS], int* py, int maxLen){

}
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}