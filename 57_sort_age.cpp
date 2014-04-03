/*
题目：某公司有几万名员工，请完成一个时间复杂度为O(n)的算法对该公司员工的年龄作排序，可使用O(1)的辅助空间。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void SortAges(int* ages,int len){
  if(ages==NULL || len<=0)
    return;
  const int oldestAge = 99;
  int timesOfAge[oldestAge+1];
  for(int i=0;i<=oldestAge;++i){
    int age = ages[i];
    if(age<0 || age>oldestAge){
      throw new exception("age out of range.");
    }
    ++timesOfAge[age];
  }
  int index = 0;
  for(int i=0;i<=oldestAge;++i){
    for(int j=0;j<timesOfAge[i];++j){
      ages[index] = i;
      ++index;
    }
  }
}
