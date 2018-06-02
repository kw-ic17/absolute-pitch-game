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
   printf("│       게임을 시작하시겠습니까?       │ \n");
   printf("│       1. 예.         2. 아니오       │ \n");
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
      printf("│                                            │ \n");
      printf("│다시 입력해주세요.                          │ \n");
      printf("│                                            │ \n");
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
   printf("│  도  │   레  │  미   │  파  │   솔  │   라  │   시  │ \n");
   printf("│      │       │       │      │       │       │       │ \n");
   printf("└─────────────────────────────────────────────────────┘ \n");

}
void start()
{
   printf("\n계이름을 맞춰보세요 \n");
   printf("최대 두 번 들려드립니다. \n");
   printf("1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시 \n\n");
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
   printf("│다시 들려드릴까요?                          │ \n");
   while (1) {
      printf("│1. 네.    2. 아니요.                        │ \n");
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
         printf("│다시 입력해주세요.                          │ \n");
         continue;
      }
   }

}
int guess(char ch)//계이름 맞추기
{
   int num;
   printf("┌────────────────────────────────────────────┐ \n");
   printf("│계이름은 무엇일까요?                        │ \n");

   //scanf("%d", &num);
   while (1) {
      num = _getch();
      if (ch == 'z') {
         if (num == '1') {
            printf("│정답입니다!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7') {
            printf("│아쉽게 틀렸네요.                            │ \n");
            printf("│계이름은 '도'였습니다.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│다시 입력해주세요.                          │ \n");
            printf("│                                            │ \n");
            printf("│1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시    │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'x') {
         if (num == '2') {
            printf("│정답입니다!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '1' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7') {
            printf("│아쉽게 틀렸네요.                            │ \n");
            printf("│계이름은 '레'였습니다.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│다시 입력해주세요.                          │ \n");
            printf("│                                            │ \n");
            printf("│1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시    │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'c') {
         if (num == '3') {
            printf("│정답입니다!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '1' || num == '4' || num == '5' || num == '6' || num == '7') {
            printf("│아쉽게 틀렸네요.                            │ \n");
            printf("│계이름은 '미'였습니다.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│다시 입력해주세요.                          │ \n");
            printf("│                                            │ \n");
            printf("│1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시    │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'v') {
         if (num == '4') {
            printf("│정답입니다!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '1' || num == '5' || num == '6' || num == '7') {
            printf("│아쉽게 틀렸네요.                            │ \n");
            printf("│계이름은 '파'였습니다.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│다시 입력해주세요.                          │ \n");
            printf("│                                            │ \n");
            printf("│1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시    │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'b') {
         if (num == '5') {
            printf("│정답입니다!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '1' || num == '6' || num == '7') {
            printf("│아쉽게 틀렸네요.                            │ \n");
            printf("│계이름은 '솔'였습니다.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│다시 입력해주세요.                          │ \n");
            printf("│                                            │ \n");
            printf("│1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시    │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'n') {
         if (num == '6') {
            printf("│정답입니다!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '5' || num == '1' || num == '7') {
            printf("│아쉽게 틀렸네요.                            │ \n");
            printf("│계이름은 '라'였습니다.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│다시 입력해주세요.                          │ \n");
            printf("│                                            │ \n");
            printf("│1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시    │ \n");
            printf("│                                            │ \n");
            continue;
         }
      }
      if (ch == 'm') {
         if (num == '7') {
            printf("│정답입니다!                                 │ \n");
            printf("└────────────────────────────────────────────┘ \n"); user++; break;
         }
         else if (num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '1') {
            printf("│아쉽게 틀렸네요.                            │ \n");
            printf("│계이름은 '시'였습니다.                      │ \n");
            printf("└────────────────────────────────────────────┘ \n"); break;
         }
         else {
            printf("│                                            │ \n");
            printf("│다시 입력해주세요.                          │ \n");
            printf("│                                            │ \n");
            printf("│1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시    │ \n");
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
   int key = 0; // 도: 0, 레: 1, 미: 2, . . . , 시: 6
   int duration = 1000; // 100 ms
   char buffer;

   for (int i = 0; i < 9; i++) {
      while ((ch = game_rand()) != 27) {//loop until the input key is not ESC 아스키코드 27
         piano_keyboard();
         printf("┌────────────────────────────────────────────┐ \n");
         printf("│ ♥♥♥♥♥♥   %d번째 문제   ♥♥♥♥♥♥   │ \n", i + 1);
         printf("│                                            │ \n");
         octave = findOctave(ch); //find octave
         Beep(freq, duration);
         replay();
         user = guess(ch);
         printf("\n계속하려면 엔터를 눌러주세요. \n");
         _getch();
         system("cls");
         break;
      }
   }
   while ((ch = game_rand()) != 27) {//loop until the input key is not ESC 아스키코드 27
      piano_keyboard();
      printf("┌────────────────────────────────────────────┐ \n");
      printf("│ ♥♥♥♥♥♥   %d번째 문제   ♥♥♥♥♥♥  │ \n", 10);
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
   else freq = 0;
   
   return 0;
}
int game_rand() //랜덤함수 숫자 뽑기
{
   int sound;//97~122를 받아야함.
   srand((unsigned)time(NULL));

   while (1)
   {
      sound = rand() % 122 + 1; //0~122
      if (sound >= 97 && sound == 'z' || sound == 'x' || sound == 'c' || sound == 'v' || sound == 'b'|| sound == 'n' || sound == 'm') {
         break;
      }

   }
   return sound;
}
void Howmany(int user) //결과 출력
{

   if (user == 9 || user == 10)
   {
      printf("\n%s님은 10번 중 %d번을 맞췄어요~\n\n", nickname, user);
      printf("절대음감의 고수~ 베토벤이세요?\n\n");
   }
   else  if (user >= 6 && user <= 8)
   {
      printf("\n%s님은 10번 중 %d번을 맞췄어요~\n\n", nickname, user);
      printf("절대음감은 아니더라도.. 상대음감?^^!\n\n");
   }
   else  if (user >= 3 && user <= 5)
   {
      printf("\n%s님은 10번 중 %d번을 맞췄어요~\n\n", nickname, user);
      printf("평범한 음치시네요~\n\n");
   }
   else
   {
      printf("\n%s님은 10번 중 %d번을 맞췄어요~\n\n", nickname, user);
      printf("실력이 부족하군요! 연습해오세요.\n\n");
   }
   system("pause");
}
