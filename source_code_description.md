# Function Description
### Before we begin ...
*Core function* -> ***Beep function***

* We will use *****Beep function***** as the core function of **absolute-pitch-game**.
* Making a sound is an essential part of the game.
* beep Use the beep function to produce a note (beep).
* `#include <windows.h>` Create a header file.
* `freq`: Frequency, in units of hertz
* `duration`: Negative duration, in milliseconds.
* 1000 = 1 second

## 1. wannaplay() 
: `Implementation of game start screen` 

A beginning notice appears with **bgm**.
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
: Enter the player name.

```
void name()
{
   printf("player: ");
   scanf("%s", nickname);
   system("cls");
}
```
## 3. start()
: Guide sound float out before the game starts.

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
: Show the piano keyboard

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
: You can hear the sound again.

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
: Guess the pitch.

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
: The basic octave is assigned to 3.
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
: Assign each sound frequency to the keyboard.
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
: Outputs an **ASCII code** of `z`, `x`, `c`, `v`, `b`, `n` and `m` randomly.

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
: Print out the results.
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
