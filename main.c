#include <stdio.h>
#include <string.h>
#include <windows.h>

int numToKey(int keyNum){
  int keys[10] = {
    VK_0,
    VK_1,
    VK_2,
    VK_3,
    VK_4,
    VK_5,
    VK_6,
    VK_7,
    VK_8,
    VK_9
  };

  return keys[keyNum];
}

void speak(char* word){
  char command[500] = "start ./Softalk.exe /W:";
  strcat(command,word);

  system(command);
}

int main(void){
  char* words[10];

  words[0] = "何もない";
  words[1] = "こっちへ行こう";
  words[2] = "あっちに敵がいる";
  words[3] = "";
  words[4] = "";
  words[5] = "";
  words[6] = "";
  words[7] = "";
  words[8] = "";
  words[9] = "";

  while(1){
    for(int i = 0;i < 10;i++){
      if((GetAsyncKeyState(VK_SHIFT) < 0)&&(GetAsyncKeyState(numToKey(i)) < 0)){
        speak(words[i]);
      }
    }
  }

  return 0;
}