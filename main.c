#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int numToKey(int keyNum){
  int keys[10] = {
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57
  };

  return keys[keyNum];
}

void speak(char* word){
  char command[500] = "start ./Softalk.exe /W:";
  strcat(command,word);
  printf("読み上げました\n");
  system(command);
}

int main(void){
  setlocale(LC_ALL, "");
  char* words[10];

  words[0] = "何もない";
  words[1] = "こっちへ行こう";
  words[2] = "あっちに敵がいる";
  words[3] = "あっちに敵がいるかも";
  words[4] = "ここを守る";
  words[5] = "ここを見張る";
  words[6] = "ここを漁る";
  words[7] = "武器がないんだけど";
  words[8] = "これ聞こえてる？";
  words[9] = "テストテスト";

  while(1){
    for(int i = 0;i < 10;i++){
      if((GetAsyncKeyState(VK_SHIFT) < 0)&&(GetAsyncKeyState(numToKey(i)) < 0)){
        speak(words[i]);
      }
      Sleep(10);
    }
  }

  return 0;
}