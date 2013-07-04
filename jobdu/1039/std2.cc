/*
 * =====================================================================================
 *
 *       Filename:  std2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2013 09:55:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
 #include <cstdio>
 using namespace std;
  
  int a[1000000];
   
   int main()
     {
          int n;
          while(scanf("%d", &n) != EOF)
          {
                   int res = 0;
                   for(int i = 0; i < n; i++)
                   {
                                scanf("%d", &a[i]);
                                res ^= a[i];
                            }
           
                   int mask = 1;
                   while((mask & res) == 0)
                       mask = mask << 1;
           
                   int num1 = 0;
                   int num2 = 0;
                   for(int i = 0; i < n; i++)
                       if ((a[i] & mask) == 0)
                           num1 ^= a[i];
                       else
                           num2 ^= a[i];
           
                   if (num1 > num2)
                   {
                                int t = num1;
                                num1 = num2;
                                num2 = t;
                            }
           
                   cout << num1 << ' ' << num2 << endl;
               }
      }
