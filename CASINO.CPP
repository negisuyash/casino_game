#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>


class game
{
		int amount,bet,dice,guess;
		char name[100],ch;
	public:

		game()
		{
			amount=1000;
		}

		void player()
		{       drawline('$'); drawline('$');

			amount=1000;
			cout<<"\n\n\t\t\tEnter your name:";
			gets(name);
			cout<<endl<<endl;
			drawline('$'); drawline('$');


			play();


		}

		void drawline(char sym)
		{
			for(int i=0;i<80;i++)
			{
				cout<<sym;
			}
		}

		void play()
		{

			randomize();
			cout<<endl;
			drawline('-');
			wrong_bet:

			cout<<"\n Enter your bet:$";
			cin>>bet;
			if(bet<=amount &&bet>=100)
			amount=amount-bet;
			else if(bet>amount)
			{       textcolor(RED);
				cout<<endl;
				cprintf("BET EXCEEDING AMOUNT");
				goto wrong_bet ;
			}
			else if(bet<100)
			{
				textcolor(RED);
				cout<<endl;
				cprintf("MINIMUM BET IS 100");
				goto wrong_bet;
			}
			else
			{
				textcolor(RED);
				cout<<endl;
				cprintf("WRONG INPUT..ENTER AGAIN");
				goto wrong_bet;
			}
			textcolor(1);
			cout<<endl;
			cprintf(" Enter your guess:");
			cin>>guess;
			dice=rand()%10+1;
			if(dice==guess)
			{       textcolor(2);
				cout<<endl;
				cprintf(" CONGRATULATION!!!! YOU HAVE WON 10x THE BET");
				amount=amount+bet*10;
				cout<<"\nNEW AMOUNT IS $"<<amount<<endl;

			}
			else
			{
				cout<<endl;
				cprintf(" BETTER LUCK NEXT TIME ,YOUR GUESS IS WRONG.") ;
				cout<<"\nCORRECT NUMBER IS:"<<dice;
				cout<<"\n AMOUNT IS $"<<amount<<endl;
				getch();
				if(amount==0)
				{
					textcolor(RED);
					cprintf("\nGAME OVER!!!") ;
					getch();
					menu();

				}
			}
			cout<<endl;
			drawline('-');
			cont();
		}
		void cont()
		{       wrong_one:
			cout<<"\n give another try!!??(y/n)";
			ch=getch();
			if(ch=='y'||ch=='Y')
			{
				play();
			}
			else if(ch=='n'||ch=='N')
			{       record();
				menu();
			}
			else
			{
				cout<<"\n WRONG CHOICE..PLZ ENTER AGAIN\n";
				goto wrong_one;
			}

		}
		void record()
		{
			FILE *fptr;
			fptr=fopen("highscore.txt","a");
			if(fptr==NULL)
			{
				cout<<"ERROR!!" ;
				exit(1);
			}
			fprintf(fptr,"%s : %d \n",name,amount);
			fclose(fptr)            ;

		}

		void scores()
		{
			clrscr();
			FILE *fptr;     char c;
			cout<<"NAME SCORE\n";
			fptr=fopen("highscore.txt","r");
			if(fptr==NULL)
			{
				cout<<"\nERROR!!";
				exit(1);
			}
			c=fgetc(fptr);
			while(ch!=EOF)
			{
				printf("%c",ch);
				ch=fgetc(fptr);
			}
			fclose(fptr);
			cout<<endl;
			cprintf("PRESS ANY KEY...");
			getch();

			menu();
		}

		void about()
		{       int j=15;
			clrscr();
			while(j>0)
			{

				clrscr();
				gotoxy(1,j);
				textcolor(2);
				cprintf("THIS GAME IS DEVELOPED AS A PROJECT BY SUYASH NEGI UNDER THE GUIDANCE MR. RAMANPUNEET SIR.");cout<<endl; cprintf(" IN THIS GAME WE HAVE TO GUESS A NUMBER AND IF THE GUESSED NUMBER MATCHES THE SELECTED NUMBER RANDOMLY CHOOSE BETWEEN 1 TO 10 THEN THE BET AMOUNT WILL BECOME 10x AND IF YOU LOOSE THEN THE AMOUNT IS LOST."); cout<<endl; cprintf("FEATURES:"); cout<<endl; cprintf(" 1.) record maintainance of scores");cout<<endl;cprintf(" 2.)implementation of different OOPs concept");cout<<endl;cprintf(" 3.)modularity is high  ");cout<<endl;
				j--;
				delay(700);



			}
			cout<<"PRESS ANY KEY.......";
			getch();
			menu();
		}
		void quit()
		{       clrscr();

			for(int i=0;i<20;i++)
			{       clrscr();

				textcolor(i);
				gotoxy(28,13);
				cprintf("THANK YOU FOR PLAYING!!!!!");
				delay(450);
			}
		}
		void menu()
		{       clrscr();
			textcolor(RED);
			cout<<endl;
			cprintf("1.) play game");cout<<endl;cprintf("2.)previous scores");cout<<endl; cprintf("3.) about");cout<<endl; cprintf("4.)exit\n ENTER YOUR CHOICE NUMBER: ");

			int menuopt;
			menu_back:
			cin>>menuopt;
			switch(menuopt)
			{
				case 1:
					player();
					break;
				case 2:
					scores();
					break;
				case 3:
					about();
					break;
				case 4:
					quit();
					break;
				default:
					{
						cout<<"wrong choice ,enter again";
						goto menu_back;
					}
			}
		}
}g1;

void main()
{       clrscr();


	g1.menu();

	getch();
}