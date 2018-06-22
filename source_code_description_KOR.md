# 함수 설명                
### 시작하기 전에 ...                
*핵심 함수* -> ***Beep 함수***               
                
* 우리는 *****Beep 함수*****를 **절대 음감 게임**의 핵심 함수로 사용할 것이다.                
* 이 게임에서 소리를 내는 것은 아주 필수적인 부분이다 .               
* `Beep function`을 사용하여 신호음을 만듭니다.                
* `#include <windows.h>`헤더파일 생성해야한다.             
* `freq`: 주파수, 헤르츠 단위                
* `duration`: 부정적인 지속시간 (1000분의 1초).              
* 1000 = 1초           
               
## 1. wannaplay()                 
: '게임 화면을 시작하는 함수이다.'                
   시작 알림과 동시에 사용자가 설정한 **bgm**가 나오게 된다.
   
```                
void wannaplay()               
{                
   sndPlaySoundA("C:/bgm/maplebgm.wav", SND_ASYNC | SND_NODEFAULT);               
   int choose;               
   printf("\n\n");                
   printf("┌──────────────────────────────────────┐ \n");                
   printf("│                                      │ \n");                
   printf("│          "Start the game?"        │ \n");                
   printf("│        1. YES         2. NO       │ \n");                
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
      printf("│ Please re-enter.                          │ \n");                
      printf("│                                            │ \n");              
      printf("└──────────────────────┘ \n");               
      system("pause");               
      system("cls");               
      wannaplay();               
   }                
}               
```               
                
## 2. name()                
: 사용자 이름을 입력하는 함수이다.               
              
```                
void name()               
{                
   printf("player: ");                
   scanf("%s", nickname);                
   system("cls");               
}               
```                
## 3. start()                
: 게임이 시작되기 전에 가이드 소리가 나오게 하는 함수이다.                
                
```                
void start()               
{                
   printf("\nGuess the pitch. \n");               
   printf("최대 두 번 들려드립니다. \n");               
   printf("1-도, 2-레, 3-미, 4-파, 5-솔, 6-라, 7-시 \n\n");               
   PlaySound(NULL, 0, 0);               
   sndPlaySoundA("C:/bgm/startment.wav", SND_ASYNC | SND_NODEFAULT);               
   system("pause");                
   PlaySound(NULL, 0, 0);                
   system("cls");                
}               
```                
                
## 4. piano_keyboard()                
: 피아노 키보드를 콘솔 창에 표시하는 함수이다.               
                
```                
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
```                
               
## 5. replay()                
: 사용자가 다시 듣길 원할 때 사용되는 함수이다.
: 한번 가이드 사운드를 들려준 후, "Would you like to hear it again?"라는 문구를
  출력하여 사용자가 원하면 'yes'인 1을, 원치 않을 경우 'no'인 2를 선택할 수 있게
  설정하는 함수이다.
               
```               
void replay()               
{               
   int choose;               
   int duration = 1000; // 1000 ms                
   printf("│Would you like to hear it again?                          │ \n");               
   while (1) {                
      printf("│1. YES    2. NO                        │ \n");                
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
         printf("│ Please re-enter.                          │ \n");                
         continue;                
      }                
   }                
```                
                
## 6. guess(char )               
: pitch를 맞춰주는 함수이다.
: 다음 그림과 같이 키보드 속의 'z'가 해당하는 것이 1이라 간주하는 식으로, 숫자순으로 
  'x,c,v,b,n,m'도 동일하게 적용된다.
: z=1, x=2, c=3, v=4, b=5, n=6, m=7로 적용되어, 사용자가 옳다고 생각하는 숫자를 선택하여,
  결과를 도출하는 함수이다.
                
###### picture 1-1               
               
   ![image](https://user-images.githubusercontent.com/39767315/40877275-dadc678c-66b8-11e8-9a12-f1ddcd298b3e.png)               
               
               
               
`z` corresponds to `do` and `do` is `1`, so regard it as the correct.               
`x`,`c`,`v`,`b`,`n`,`m` are in the same way.                
```                
if (ch == 'z') {                
         if (num == '1') {                
            printf("│정답입니다!                                 │ \n");                
            printf("└────────────────────────────────────────────┘ \n"); user++; break;               
```                     
               
## 7. piano_define()                
: `               
                
## 8. findOctave(char )               
: 기본 옥타브는 3에 할당하는 함수이다.               
```                
   if (ch == 'z' || ch == 'x' || ch == 'c' || ch == 'v' || ch == 'b' || ch == 'n' || ch == 'm') {               
      Octave = 3;               
   }                
   else {               
      Octave = 0;                
   }               
   findFreq(Octave, ch);                
```               
                
## 9. findFreq(int , char )               
: 키보드에 각 사운드 주파수를 할당하는 함수이다.                
```               
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
```                
                
## 10. game_rand()                
: `z`, `x`, `c`, `v`, `b`, `n` , `m`의 **ASCII code**를 임의로 출력하는 함수이다.                
                
```                
   int sound;               
   srand((unsigned)time(NULL));               
                   
   while (1)                
   {                
      sound = rand() % 122 + 1;               
      if (sound >= 97 && sound == 'z' || sound == 'x' || sound == 'c' || sound == 'v' || sound == 'b'|| sound == 'n' || sound == 'm') {                
         break;                
      }                
                
   }                
```                
                
## 11. Howmany(int )                
: 사용자의 절대음감 결과를 출력하는 함수이다.                
```                
void Howmany(int user)                 
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
```
