/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
# include "windows.h"

int t=0,gamestate,torch,room=1,roombg,bg=0,bgc=0,index=0,check,charge=0,hi_score=0,congo=0;
char score[100],life[100],hisco[100];int life_count=3,score_count=0;
char death[7][100]={"bg12.bmp","bg13.bmp","bg14.bmp","bg15.bmp","bg16.bmp","bg17.bmp","bg18.bmp"};
bool menumusic=true,gamemusic;
int X=2000;
double xa[3]={700,700,725},ya[3]={335,317,326},xa1[3]={31,31,6},ya1[3]={335,317,326},xa11[3]={356.5,374.5,365.5},ya11[3]={621,621,646};
double xa2[3]={356.5,374.5,365.5},ya2[3]={46,46,21};
int substate=1;
void high (int n)
{
    FILE *fp = fopen("highscore.txt", "r");
    fscanf(fp, "%d", &hi_score);
    fclose(fp);
    if (n > hi_score)
    {
        congo = 1;
        FILE *fp1 = fopen("highscore.txt", "w");
        fprintf(fp1, "%d", n);
        fclose(fp1);
    }
    else congo=0;
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();
    if (gamestate==1) {

            iShowBMP(0,0,"FINAL BGMENU.bmp");

            iShowBMP(250,400,"play button.bmp");
             iShowBMP(250,300,"INSTRUCTIONS BUTTON.bmp");
              iShowBMP(250,200,"LEVEL BUTTON.bmp");
              iShowBMP(250,100,"QUIT BUTTON.bmp");

            //iShowBMP()
    }
    if (gamestate==2){

            if (room==0){
                if(roombg==0){
                        if (bg==0){
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

                iSetColor(120,239,245);
                iText(550,620,"WINDOW",GLUT_BITMAP_TIMES_ROMAN_24);
                iSetColor(120,239,245);
                iFilledRectangle(678,324,22,4);
                iSetColor(120,239,245);
                iFilledPolygon(xa,ya,3);

            }

        else if (room==1){
             if (roombg==1){
                        if (bg==0){
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
                iSetColor(120,239,245);
                iText(550,620,"WARDROBE",GLUT_BITMAP_TIMES_ROMAN_24);
                iSetColor(120,239,245);
                iFilledRectangle(678,324,22,4);
                iSetColor(120,239,245);
                iFilledPolygon(xa,ya,3);
                iSetColor(120,239,245);
                iFilledRectangle(31,324,22,4);
                iSetColor(120,239,245);
                iFilledPolygon(xa1,ya1,3);
                iSetColor(120,239,245);
                iFilledRectangle(364,599,4,22);
                iSetColor(120,239,245);
                iFilledPolygon(xa11,ya11,3);
        }
        else if (room==2){
             if (roombg==2){
                        if (bg==0){
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
                iSetColor(120,239,245);
                iText(550,620,"DOOR",GLUT_BITMAP_TIMES_ROMAN_24);
                iSetColor(120,239,245);
                iFilledRectangle(31,324,22,4);
                iSetColor(120,239,245);
                iFilledPolygon(xa1,ya1,3);
        }
        else if (room==3){
             if (roombg==3){
                        if (bg==0){
                                if(torch==0) iShowBMP(0,0,"bg off light off vent.bmp");
                                else iShowBMP(0,0,"bg off light on vent.bmp");
                        }

                        else {
                                if(torch==0) iShowBMP(0,0,"bg on light off vent.bmp");
                                else {iShowBMP(0,0,"bg on light on vent.bmp");}
                        }

                }
                else{

                        if(torch==0) iShowBMP(0,0,"bg off light off vent.bmp");
                        else iShowBMP(0,0,"bg off light on vent.bmp");

                }
                iSetColor(120,239,245);
                iText(550,620,"VENT",GLUT_BITMAP_TIMES_ROMAN_24);
                iSetColor(120,239,245);
                iFilledRectangle(363.5,46,4,22);
                iSetColor(120,239,245);
                iFilledPolygon(xa2,ya2,3);
        }
        iSetColor(120,239,245);
            iText(150,10,"CLICK <p> FOR PAUSE,<r> FOR RESUME AND <e> FOR EXIT");

         if(charge>=0&&charge<=20)
    {
        iSetColor(0,255,0);
        iFilledRectangle(5,5,80,15);
    }
    else if(charge>=21&&charge<=40)
    {
        iSetColor(0,255,0);
        iFilledRectangle(5,5,60,15);
        iSetColor(255,255,255);
        iFilledRectangle(65,5,20,15);
    }
    else if(charge>=41&&charge<=60)
    {
        iSetColor(0,255,0);
        iFilledRectangle(5,5,40,15);
        iSetColor(255,255,255);
        iFilledRectangle(45,5,40,15);
    }
    else if(charge>=61&&charge<=80)
    {
        iSetColor(0,255,0);
        iFilledRectangle(5,5,20,15);
        iSetColor(255,255,255);
        iFilledRectangle(25,5,60,15);
    }
    iSetColor(120,239,245);
      sprintf(score,"%d",score_count);
      sprintf(life,"%d",life_count);
      iText(100,620,score,GLUT_BITMAP_HELVETICA_18);
      iText(100,600,life,GLUT_BITMAP_HELVETICA_18);
      iText(20,620,"SCORE:",GLUT_BITMAP_HELVETICA_18);
      iText(20,600,"LIFE:",GLUT_BITMAP_HELVETICA_18);
    }
         else if (gamestate==4) {
               iShowBMP(0,0,death[index]);
                Sleep(25); index++;
                if (index==7) gamestate=6;

          }
          else if (gamestate==5){
            iShowBMP(0,0,"bg instruction page.bmp");
            iShowBMP(20,20,"MENU BUTTON.bmp");
            iShowBMP(500,20,"NEXT BUTTON.bmp");
          }


          else if (gamestate==6) {

            iShowBMP(0,0,"DEATH.bmp");
            iShowBMP(250,250,"MENU BUTTON.bmp");
            iSetColor(255,0,0);
            sprintf(score,"%d",score_count);
            iText(375,350,score,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(275,350,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
            high(score_count);
        if (congo)
        {
            iText(250, 380, "Congratulations!!! New High Score", GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if (!congo)
        {

            iText(250, 380, "HIGH SCORE: ", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(420, 380, itoa(hi_score, hisco, 10), GLUT_BITMAP_TIMES_ROMAN_24);
        }


          }

          else if (gamestate==7){
            iShowBMP(0,0,"INSTRUCTION PAGE 2.bmp");
            iShowBMP(20,50,"BACK BUTTON.bmp");
            iShowBMP(501,50,"MENU BUTTON.bmp");
            iShowBMP(250,370,"WINDOW.bmp");
            iShowBMP(250,320,"WARDROBE.bmp");
            iShowBMP(250,270,"DOOR.bmp");
            iShowBMP(250,220,"VENT.bmp");
          }
           else if (gamestate==8){
            iShowBMP(0,0,"LEVELS.bmp");
            iShowBMP(10,10,"MENU BUTTON.bmp");
            iShowBMP(50,430,"EASY BUTTON.bmp");
            iShowBMP(250,330,"MEDIUM BUTTON.bmp");
            iShowBMP(450,230,"HARD BUTTON.bmp");


          }





}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	//if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

		//place your codes here
		if (gamestate==6)
        {
            if(mx >= 250 && mx <= 452 && my >= 250 && my <= 280)
		{

			menumusic=true;
			gamestate= 1;
			score_count=0;
			 if (menumusic==true) PlaySound("bg menu.wav",NULL,SND_LOOP|SND_ASYNC);

		}
        }
		if (gamestate==1)
		{if(mx >= 250 && mx <= 452 && my >= 400 && my <= 430)
		{

			menumusic=false;
			gamestate= 2;
			if (menumusic==false) PlaySound(0,0,0);

		}}
        if (gamestate==1)
		{if(mx >= 250 && mx <= 452 && my >= 300 && my <= 330)
		{


			gamestate= 5;


		}}
		if (gamestate==1)
		{if(mx >= 250 && mx <= 452 && my >= 200 && my <= 230)
		{

			gamestate=8;
			//menumusic=false;
		}}
		if (gamestate==1)
		{if(mx >= 250 && mx <= 452 && my >= 100 && my <= 130)
		{

			menumusic=false;
			if (menumusic==false) PlaySound(0,0,0);
			exit(0);
			//menumusic=false;
		}}

		if (gamestate==8)
		{if(mx >= 50 && mx <= 252 && my >= 430 && my <= 460)
		{
            substate=1;
			menumusic=false;
			gamestate= 2;
			if (menumusic==false) PlaySound(0,0,0);
			gamemusic=true;

		}}
		if (gamestate==8)
		{if(mx >= 250 && mx <= 452 && my >= 330 && my <= 360)
		{
		    substate=2;
			menumusic=false;
			gamestate= 2;
			if (menumusic==false) PlaySound(0,0,0);
			gamemusic=true;
		}}
		if (gamestate==8)
		{if(mx >= 450 && mx <= 652 && my >= 230 && my <= 260)
		{
		    substate=3;
			menumusic=false;
			gamestate= 2;
			if (menumusic==false) PlaySound(0,0,0);
			gamemusic=true;
		}}
		if (gamestate==8)
		{if(mx >=10 && mx <= 212 && my >= 10 && my <= 40)
		{

			gamestate=1;

		}}

		if (gamestate==5)
		{
		    if(mx >= 20 && mx <= 202 && my >= 20 && my <= 50)
            {
                gamestate=1;
            }
		if(mx >= 501 && mx <= 719 && my >= 20 && my <= 50)
            {
                gamestate=7;
                menumusic=false;
                if (menumusic==false) PlaySound(0,0,0);
                gamemusic=true;
            }


		}

	/*if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}*/
    if (gamestate==7)
		{
		    if(mx >= 20 && mx <= 222 && my >= 50 && my <= 80)
            {
                menumusic=true;
                if (menumusic==true) PlaySound("bg menu.wav",NULL,SND_LOOP|SND_ASYNC);
                gamestate=5; gamemusic=false;
            }
            if(mx >= 500 && mx <= 702 && my >= 50 && my <= 80)
            {
                menumusic=true;
                if (menumusic==true) PlaySound("bg menu.wav",NULL,SND_LOOP|SND_ASYNC);
                gamestate=1; gamemusic=false;
            }
             if(mx >= 250 && mx <= 452 && my >= 370 && my <= 400)
            {
                if (gamemusic==true) PlaySound("bg window.wav",NULL,SND_ASYNC);
            }
             if(mx >= 250 && mx <= 452 && my >= 320 && my <= 350)
            {
                if (gamemusic==true) PlaySound("bg wardrobe.wav",NULL,SND_ASYNC);
            }
             if(mx >= 250 && mx <= 452 && my >= 270 && my <= 300)
            {
                if (gamemusic==true) PlaySound("bg door.wav",NULL,SND_ASYNC);
            }
             if(mx >= 250 && mx <= 452 && my >= 220 && my <= 250)
            {
                if (gamemusic==true) PlaySound("bg vent.wav",NULL,SND_ASYNC);
            }


		}
if (gamestate==2){
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {torch=1; charge++; if(bg==1 && room==roombg) check=1;}
	if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) torch=0;
	}
	}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{


	if(key == 'e')
	{
		//do something with 'x'
		 if (gamestate==2)
		exit(0);
	}
	/*if(key == 'r')
	{
		//do something with 'x'
		 if (gamestate==3) {gamestate=1; menumusic=false;}
	}*/
	//place your codes for other keys here
	if(key == 'p')
	{
		//do something with 'x'
		 if (gamestate==2) {iPauseTimer(0);}
	}
	if(key == 'r')
	{
		//do something with 'x'
		 if (gamestate==2) {iResumeTimer(0);}
	}



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
void iSpecialKeyboard(unsigned char key)
{


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
void change(){


    if (gamestate==2 && substate==1) {t++,gamemusic=true;

    if (t==22) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==53) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==82) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==153) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==173) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);

	if ((t+1)%5==0) {
            roombg=rand()%4;

            if (roombg==0) if (gamemusic==true) PlaySound("bg window.wav",NULL,SND_ASYNC);
            if (roombg==1)  if (gamemusic==true) PlaySound("bg wardrobe.wav",NULL,SND_ASYNC);
            if (roombg==2) if (gamemusic==true) PlaySound("bg door.wav",NULL,SND_ASYNC);
            if (roombg==3) if (gamemusic==true) PlaySound("bg vent.wav",NULL,SND_ASYNC);
                    }

	if (t%5==0 && t!=0) {
            bg=1;

    }

        if ((t-1)%5==0 && t!=1) {
                charge++;
            if (check==1) {bg=0;check=0;score_count+=100;}
           else {bg=0;check=0;life_count--;
                    if (gamemusic==true) PlaySound("knife.wav",NULL,SND_ASYNC); }

        }

if(life_count==0||charge>80)
            {
                gamestate=4;t=0;bgc=0;check=0;charge=0;life_count=3;bg=0;
                if (gamemusic==true) PlaySound("death.wav",NULL,SND_ASYNC);
                gamemusic=false;

            }
    }

}
void change2(){


    if (gamestate==2 && substate==2) {t++,gamemusic=true;

    if (t==22) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==53) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==82) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==153) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==173) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);

	if ((t+1)%5==0) {
            roombg=rand()%4;

            if (roombg==0) if (gamemusic==true) PlaySound("bg window.wav",NULL,SND_ASYNC);
            if (roombg==1)  if (gamemusic==true) PlaySound("bg wardrobe.wav",NULL,SND_ASYNC);
            if (roombg==2) if (gamemusic==true) PlaySound("bg door.wav",NULL,SND_ASYNC);
            if (roombg==3) if (gamemusic==true) PlaySound("bg vent.wav",NULL,SND_ASYNC);
                    }

	if (t%5==0 && t!=0) {
            bg=1;

    }

        if ((t-1)%5==0 && t!=1) {
                charge++;
            if (check==1) {bg=0;check=0;score_count+=100;}
           else {bg=0;check=0;life_count--;
                    if (gamemusic==true) PlaySound("knife.wav",NULL,SND_ASYNC); }

        }

if(life_count==0||charge>80)
            {
                gamestate=4;t=0;bgc=0;check=0;charge=0;life_count=3;bg=0;
                if (gamemusic==true) PlaySound("death.wav",NULL,SND_ASYNC);
                gamemusic=false;

            }
    }

}
void change3(){


    if (gamestate==2 && substate==3) {t++,gamemusic=true;

    if (t==22) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==53) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==82) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==153) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);
    if (t==173) if (gamemusic==true) PlaySound("distraction.wav",NULL,SND_ASYNC);

	if ((t+1)%5==0) {
            roombg=rand()%4;

            if (roombg==0) if (gamemusic==true) PlaySound("bg window.wav",NULL,SND_ASYNC);
            if (roombg==1)  if (gamemusic==true) PlaySound("bg wardrobe.wav",NULL,SND_ASYNC);
            if (roombg==2) if (gamemusic==true) PlaySound("bg door.wav",NULL,SND_ASYNC);
            if (roombg==3) if (gamemusic==true) PlaySound("bg vent.wav",NULL,SND_ASYNC);
                    }

	if (t%5==0 && t!=0) {
            bg=1;

    }

        if ((t-1)%5==0 && t!=1) {
                charge++;
            if (check==1) {bg=0;check=0;score_count+=100;}
           else {bg=0;check=0;life_count--;
                    if (gamemusic==true) PlaySound("knife.wav",NULL,SND_ASYNC); }

        }

if(life_count==0||charge>80)
            {
                gamestate=4;t=0;bgc=0;check=0;charge=0;life_count=3;bg=0;
                if (gamemusic==true) PlaySound("death.wav",NULL,SND_ASYNC);
                gamemusic=false;

            }
    }

}
int main()
{
	//place your own initialization codes here.


	gamestate=1;

	  iSetTimer(3000,change);
	  iSetTimer(2500,change2);
	  iSetTimer(2000,change3);



     if (menumusic==true) PlaySound("bg menu.wav",NULL,SND_LOOP|SND_ASYNC);
	iInitialize(731, 652, "TextInputDemo");
	return 0;
}
