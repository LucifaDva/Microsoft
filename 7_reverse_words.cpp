#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void exchange(char& x,char&y){
  char tmp = x;
  x = y;
  y = tmp;
}
void Reverse_words(char* sentence,int len){
  for(int i=0;i<len/2+1;i++){
    exchange(sentence[i],sentence[len-i-1]);
  }
  for(int i=0;i<len;i++)
    cout<<sentence[i]<<"--->";
  cout<<endl;
}
int main(){
  char sentence[]="I am a student.";
  int len = sizeof(sentence)/sizeof(sentence[0]);
  cout<<len<<endl;
  Reverse_words(sentence,len);
  return 0;
}
