#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
float string_to_float(char* A,int len){
  float result = 0.0;
  if(A[0]=='-'){
    for(int i=1;i<len;i++)
      result = result*10+(A[i]-'0');
    return -result;
  }else if(A[0]=='+'){
    for(int i=1;i<len;i++)
      result = result*10+(A[i]-'0');
    return result;
  }else{
    for(int i=0;i<len;i++){
      result = result*10+(A[i]-'0');
    }
    return result;
  }
}
bool have(char* A,char key,int len){
  for(int i=0;i<len;i++){
    if(key==A[i])
      return true;
  }
  return false;
}
bool valid(char* A,int len){
  bool valid;
  char B[] = {'0','1','2','3','4','5','6','7','8','9'};
  if(have(B,A[0],10) || A[0]=='+' || A[0]=='-')
    valid = true;
  for(int i=1;i<len;i++){
    if(!have(B,A[i],10))
      valid = false;
  }
  return valid;
}
int main(){
  char s[] = "-3i45";
  int len = sizeof(s)/sizeof(s[0])-1;
  cout<<len<<endl;
  if(valid(s,len)){
    cout<<string_to_float(s,len)<<"*****"<<endl;
  }else{
    cout<<"输入的字符串不能转化成float"<<endl;
  }
  return 0;
}

