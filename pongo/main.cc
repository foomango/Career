// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/23/2013 10:41:39 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <string>
using namespace std;

//���������MaxSum����
int MaxSum(int* a,int n)
{
  //write your code here
  int sum = 0;
  if (!a) {
    return sum;
  }

  int begin = 0;
  int end = 1;
  sum = a[begin];
  int cur = sum;
  for (; end < n; end++) {
      if (cur < 0) {
        begin = end;
        cur = a[begin];
      } else {
        cur += a[end];
      }

      if (sum < cur) {
        sum = cur;
      }
  }

  return sum;
}

//start ��ʾ������Ϊ�Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
//�������main���������е���������д��MaxSum����������
int main()
{   
    //wirte your code here;
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int max = MaxSum(a, sizeof(a) / sizeof(a[0]));
    cout << max << endl;

    return 0;  
} 
//end   ��ʾ������Ϊ�Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�
