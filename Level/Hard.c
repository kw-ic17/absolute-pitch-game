#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include<MMSystem.h> 
#pragma comment(lib, "winmm.lib" )

void wannaplay();
int findOctave(char ch);
int findFreq(int octabe, char ch);
void piano_define();
int game_rand();
void piano_keyboard();
void replay();
int guess(char ch);
void Howmany(int user);
void name();
void start();

double freq = 0;
int user = 0;
char nickname[50];

int main()
{
   wannaplay();
   piano_define();
   return 0;
}
void wannaplay()
{
   sndPlaySoundA("C:/bgm/maplebgm.wav", SND_ASYNC | SND_NODEFAULT);
   int choose;
   printf("\n\n");
   printf("┌──────────────────────────────────────┐ \n");
   printf("│                                      │ \n");
   printf("│              GAME START              │ \n");
   printf("│       1. YES         2. NO           │ \n");
   printf("│                                      │ \n");
   printf("└──────────────────────────────────────┘ \n");

   scanf("%d", &choose);
   if (choose == 1) {
      system("cls");
      name();
      start();
      return;
   }
   else if (choose == 2)
      exit(1);
   else {
      printf("┌──────────────────────┐ \n");
      printf("│                      │ \n");
      printf("│     ENTER AGAIN.     │ \n");
      printf("│                      │ \n");
      printf("└──────────────────────┘ \n");
      system("pause");
      system("cls");
      wannaplay();
   }

}
void name()
{
   printf("player: ");
   scanf("%s", nickname);
   system("cls");
}
void piano_keyboard()
{
   printf("\n");
   printf("│￣￣■■■￣■■■￣￣│￣￣■■■￣■■■￣■■■￣￣｜ \n");
   printf("│    ■■■  ■■■    │    ■■■  ■■■  ■■■    │ \n");
   printf("│    ■■■  ■■■    │    ■■■  ■■■  ■■■    │ \n");
   printf("│    ■■■  ■■■    │    ■■■  ■■■  ■■■    │ \n");
   printf("│    ■■■  ■■■    │    ■■■  ■■■  ■■■    │ \n");
   printf("│    ■■■  ■■■    │    ■■■  ■■■  ■■■    │ \n");
   printf("│      │       │       │      │       │       │       │ \n");
   printf("│      │       │       │      │       │       │       │ \n");
   printf("│      │       │       │      │       │       │       │ \n");
   printf("│      │       │       │      │       │       │       │ \n");
   printf("│      │       │       │      │       │       │       │ \n");
   printf("│   C  │   D   │   E   │   F  │   G   │   A   │   B   │ \n");
   printf("│      │       │       │      │       │       │       │ \n");
   printf("└─────────────────────────────────────────────────────┘ \n");

}
void start()
{
   printf("\nGuess the syllable note! \n");
   printf("You can listen to the sound maximum TWO TIMES. \n");
   printf("1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B \n\n");
   PlaySound(NULL, 0, 0);
   sndPlaySoundA("C:/bgm/startment.wav", SND_ASYNC | SND_NODEFAULT);
   system("pause");
   PlaySound(NULL, 0, 0);
   system("cls");
}
void replay()
{
   int choose;
   int duration = 1000; // 1000 ms
   printf("Repaet one more time?                          │ \n");
   while (1) {
      printf("│1. YES    2. NO                            │ \n");
      printf("└────────────────────────────────────────────┘ \n");
      choose = _getch();
      if (choose == '1') {
         Beep(freq, duration);
         break;
      }
      else if (choose == '2')
         break;
      else {
         printf("┌────────────────────────────────────────────┐ \n");
         printf("│  ENTER AGAIN.                              │ \n");
         continue;
      }
   }

}
int guess(char ch)//guessing the syllable note
{
   int num;
   printf("┌────────────────────────────────────────────┐ \n");
   printf("│  What is the note of the sound?            │ \n");

   //scanf("%d", &num);
   while (1) {
      num = _getch();
      if (ch == 'z' || ch == 'a' || ch == 'q') {
         if (num == '1') {
            printf("│   Correct!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7') {
            printf("│Sorry,                                    │ \n");
            printf("│The note was 'C'.                         │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│       ENTER AGAIN                          │ \n");
            printf("│                                            │ \n");
            printf("│1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B           │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'x' || ch == 's' || ch == 'w') {
         if (num == '2') {
            printf("│   Correct!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '1' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7') {
            printf("│     Sorry,                                 │ \n");
            printf("│     The note was 'D'.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│       ENTER AGAIN                          │ \n");
            printf("│                                            │ \n");
            printf("│1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B           │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'c' || ch == 'd' || ch == 'e') {
         if (num == '3') {
            printf("│   Correct!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '1' || num == '4' || num == '5' || num == '6' || num == '7') {
            printf("│     Sorry,                            │ \n");
            printf("│     The note was 'E'.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│       ENTER AGAIN                          │ \n");
            printf("│                                            │ \n");
            printf("│1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B           │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'v' || ch == 'f' || ch == 'r') {
         if (num == '4') {
            printf("│   Correct!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '1' || num == '5' || num == '6' || num == '7') {
            printf("│     Sorry,                            │ \n");
            printf("│     The note was 'F'.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│       ENTER AGAIN                          │ \n");
            printf("│                                            │ \n");
            printf("│1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B           │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'b' || ch == 'g' || ch == 't') {
         if (num == '5') {
            printf("│   Correct!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '1' || num == '6' || num == '7') {
            printf("│     Sorry,                           │ \n");
            printf("│     The note was 'G'.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│       ENTER AGAIN                          │ \n");
            printf("│                                            │ \n");
            printf("│1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B           │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'n' || ch == 'h' || ch == 'y') {
         if (num == '6') {
            printf("│   Correct!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '5' || num == '1' || num == '7') {
            printf("│     Sorry,                            │ \n");
            printf("│     The note was 'A'.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│       ENTER AGAIN                          │ \n");
            printf("│                                            │ \n");
            printf("│1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B           │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'm' || ch =='j' || ch = 'u') {
         if (num == '7') {
            printf("│   Correct!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '1') {
            printf("│     Sorry,                            │ \n");
            printf("│     The note was 'B'.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│       ENTER AGAIN                          │ \n");
            printf("│                                            │ \n");
            printf("│1-C, 2-D, 3-E, 4-F, 5-G, 6-A, 7-B           │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
   }
   return user;
}
void piano_define()
{
   char ch; //input variable
   int octave = 1;
   int key = 0; // C: 0, D: 1, E: 2, . . . , B: 6
   int duration = 1000; // 100 ms
   char buffer;

   for (int i = 0; i < 9; i++) {
      while ((ch = game_rand()) != 27) {//loop until the input key is not ESC ascii 27
         piano_keyboard();
         printf("┌────────────────────────────────────────────┐ \n");
         printf("│ ♥♥♥♥♥♥      Question number %d     ♥♥♥♥♥♥  │ \n", i + 1);
         printf("│                                            │ \n");
         octave = findOctave(ch); //find octave
         Beep(freq, duration);
         replay();
         user = guess(ch);
         printf("\nTo Continue, press ENTER. \n");
         _getch();
         system("cls");
         break;
      }
   }
   while ((ch = game_rand()) != 27) {//loop until the input key is not ESC ascii code 27
      piano_keyboard();
      printf("┌────────────────────────────────────────────┐ \n");
      printf("│ ♥♥♥♥♥♥      Question number %d     ♥♥♥♥♥♥  │ \n", 10);
      printf("│                                            │ \n");
      octave = findOctave(ch); //find octave
      Beep(freq, duration);
      replay();
      user = guess(ch);
      break;
   }

   Howmany(user);
}

int findOctave(char ch)
{

   int Octave;

   if (ch == 'z' || ch == 'x' || ch == 'c' || ch == 'v' || ch == 'b' || ch == 'n' || ch == 'm') {
      Octave = 3;
   }
   else if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'f' || ch == 'g' || ch == 'h' || ch == 'j') {
	   Octave = 4;
	}
	else if (ch == 'q' || ch == 'w' || ch == 'e' || ch == 'r' || ch == 't' || ch == 'y' || ch == 'u') {
	   Octave = 5;
	}
   else {
      Octave = 0;
   }
   findFreq(Octave, ch);

   return 0;
}



int findFreq(int octabe, char ch)
{
   if (octabe == 3) {
      if (ch == 'z') freq = 130.81;
      else if (ch == 'x') freq = 146.83;
      else if (ch == 'c') freq = 164.81;
      else if (ch == 'v') freq = 174.61;
      else if (ch == 'b') freq = 196.00;
      else if (ch == 'n') freq = 220.00;
      else if (ch == 'm') freq = 246.94;
   }
	else if (octabe == 4) {
	if (ch == 'a') freq = 261.63;
	else if (ch == 's') freq = 293.66;
	else if (ch == 'd') freq = 329.63;
	else if (ch == 'f') freq = 349.23;
	else if (ch == 'g') freq = 392.00;
	else if (ch == 'h') freq = 440.00;
	else if (ch == 'j') freq = 493.88;
	}
	else if (octabe == 5) {
	if (ch == 'q') freq = 523.25;
	else if (ch == 'w') freq = 587.33;
	else if (ch == 'e') freq = 659.25;
	else if (ch == 'r') freq = 698.46;
	else if (ch == 't') freq = 783.99;
	else if (ch == 'y') freq = 880.00;
	else if (ch == 'u') freq = 987.77;
	}
   else freq = 0;
   
   return 0;
}
int game_rand() //picking random number
{
   int sound;
   srand((unsigned)time(NULL));

   while (1)
   {
      sound = rand() % 122 + 1;
      if (sound >= 97 && sound != 'l' && sound != 'i' && sound != 'o' && sound != 'p' && sound != 'k') {
         break;
      }

   }
   return sound;
}
void Howmany(int user) //print results
{

   if (user == 9 || user == 10)
   {
      printf("\n%s got %d times out of 10 ~\n\n", nickname, user);
      printf("You are a master of absolute pitch~ Are you... Beethoven?\n\n");
   }
   else  if (user >= 6 && user <= 8)
   {
      printf("\n%s got %d times out of 10 ~\n\n", nickname, user);
      printf("I guess you are not master in absolute pitch. How about relative pitch instead?^^!\n\n");
   }
   else  if (user >= 3 && user <= 5)
   {
      printf("\n%s got %d times out of 10 ~\n\n", nickname, user);
      printf("You are tone deaf!\n\n");
   }
   else
   {
      printf("\n%s got %d times out of 10 ~\n\n", nickname, user);
      printf("I think you should practice more!\n\n");
   }
   system("pause");
}
