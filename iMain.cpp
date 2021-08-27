#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include "windows.h"

int x = 300, y = 300, r = 20;
int gamestate=4,timecount=1,boogeycount=1,torch=0;
int room=1,roombg=1,bg=0;
char lastKey = 0;

/*
	function iDraw() is called again and again by the system.

	*/
void iDraw() {
	//place your drawing codes here
	iClear();
	/*iSetColor(20, 200, 200);
	iFilledCircle(x, y, r);
	iSetColor(20, 200, 0);
	iText(40, 40, "Hi, I am iGraphics");*/
	/*if (room==2) {
            if (bg==0||roombg!=2)  iShowBMP(0,0,"project1.bmp");
            else if (bg==1 && roombg==2) {iShowBMP(0,0,"roombg4.bmp");}
    }
	 else if (room==0)
        {
           if (bg==0||roombg!=0) iShowBMP(0,0,"project2.bmp");
           else if (bg==1 && roombg==0) iShowBMP(0,0,"roombg2.bmp");
     }
	 else if (room==1) {
            if (bg==0||roombg!=1) iShowBMP(0,0,"project3.bmp");
            else if (bg==1 && roombg==1) iShowBMP(0,0,"roombg3.bmp");
     }
	 else if (room==3) {
            if (bg==0||roombg!=3) iShowBMP(0,0,"project4.bmp");
            else if (bg==1 && roombg==3) iShowBMP(0,0,"roombg1.bmp");
     }*/
     if (gamestate==2){
            if (room==0){
                if (roombg==0){
                        if (bg=0){
                                if(torch==0) iShowBMP(0,0,"bg off light off window.bmp");
                                else iShowBMP(0,0,"bg off light on window.bmp");
                        }
                        else {
                                if(torch==0) iShowBMP(0,0,"bg on light off window.bmp");
                                else iShowBMP(0,0,"bg on light on window.bmp");
                        }

                }
                else{

                        if(torch==0) iShowBMP(0,0,"bg off light off window.bmp");
                        else iShowBMP(0,0,"bg off light on window.bmp");

                }

            }
        else if (room==1){
             if (roombg==1){
                        if (bg=0){
                                if(torch==0) iShowBMP(0,0,"bg off light off wardrobe.bmp");
                                else iShowBMP(0,0,"bg off light on wardrobe.bmp");
                        }
                        else {
                                if(torch==0) iShowBMP(0,0,"bg on light off wardrobe.bmp");
                                else iShowBMP(0,0,"bg on light on wardrobe.bmp");
                        }

                }
                else{

                        if(torch==0) iShowBMP(0,0,"bg off light off wardrobe.bmp");
                        else iShowBMP(0,0,"bg off light on wardrobe.bmp");

                }
        }
        else if (room==2){
             if (roombg==2){
                        if (bg=0){
                                if(torch==0) iShowBMP(0,0,"bg off light off door.bmp");
                                else iShowBMP(0,0,"bg off light on door.bmp");
                        }
                        else {
                                if(torch==0) iShowBMP(0,0,"bg on light off door.bmp");
                                else iShowBMP(0,0,"bg on light on door.bmp");
                        }

                }
                else{

                        if(torch==0) iShowBMP(0,0,"bg off light off door.bmp");
                        else iShowBMP(0,0,"bg off light on door.bmp");

                }

        }
        else if (room==3){
             if (roombg==3){
                        if (bg=0){
                                if(torch==0) iShowBMP(0,0,"bg off light off vent.bmp");
                                else iShowBMP(0,0,"bg off light on vent.bmp");
                        }
                        else {
                                if(torch==0) iShowBMP(0,0,"bg on light off vent.bmp");
                                else iShowBMP(0,0,"bg on light on vent.bmp");
                        }

                }
                else{

                        if(torch==0) iShowBMP(0,0,"bg off light off vent.bmp");
                        else iShowBMP(0,0,"bg off light on vent.bmp");

                }
        }
        else if (gamestate==4) {
                 iShowBMP(0,0,"bg12.bmp");
                 /*iShowBMP(0,0,"bg13.bmp");
                iShowBMP(0,0,"bg14.bmp");
                iShowBMP(0,0,"bg15.bmp");
                iShowBMP(0,0,"bg16.bmp");
              iShowBMP(0,0,"bg17.bmp");
               iShowBMP(0,0,"bg18.bmp");
               iShowBMP(0,0,"bg19.bmp");
               iShowBMP(0,0,"bg20.bmp");*/
                //iShowBMP(0,0,"ending death.bmp");
                //gamestate=1;
        }
        else if (gamestate==3) { iSetColor(255,255,255);iText(100,100,"WINNER");}
     }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	/*if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}*/
	if (gamestate==2){
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {torch=1; if (room==roombg) {if (bg==1) bg=0;} }
	if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) torch=0;}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	/*static int c=0;
	if (key == 'q') {
		exit(0);
	}
	else if(lastKey == key){
            c++;
	}
	else{
        printf("lastKey:%c  %d times\n",lastKey,c);
        c = 0;
        lastKey = key;
	}*/

        //printf("%c\n",key);
	//place your codes for other keys here

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	else if (key== GLUT_KEY_LEFT)
    {
        if(room && room!=3) room--;
    }
    else if (key== GLUT_KEY_RIGHT)
    {
        if(room!=3 && room!=2) room++;
    }
    else if (key== GLUT_KEY_UP)
    {
        if(room==1) room=3;
    }
    else if (key== GLUT_KEY_DOWN)
    {
        if(room==3) room=1;
    }
	//place your codes for other keys here
}

void boogey2(){


}

void boogey() {



}

/*void roomboogey(){

      roombg++;
      if (roombg==4) roombg=0;

}*/

void gametime(){
        if (gamestate==2)
        {
            timecount++;
            if (timecount==600) gamestate=3;
        }

}



int main() {
	//place your own initialization codes here.

	//iSetTimer(1750,roomboogey);

        iSetTimer (1000,gametime);

        //iSetTimer (3000,roomboogey);

      //if (bg==0&&timecount>=5) iSetTimer(1000,boogey);
      //if (bg==1) iSetTimer(3000,boogey2);

    //if (gamestate) PlaySound(TEXT("bg menu.wav"),NULL,SND_LOOP);
	iInitialize(1350, 652, "project");

	return 0;
}
