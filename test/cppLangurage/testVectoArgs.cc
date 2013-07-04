/*
 * =====================================================================================
 *
 *       Filename:  testVectoArgs.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/28/2013 09:43:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

int foo (char * const arg[]) {
    arg[0][0]++;
    return 0;
}

int main (int const argc, char * argv[]) {
    return 0;
}
