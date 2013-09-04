/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201373075830486/
 *                  题目：给定数组A，大小为n,数组元素为0到n-1的数字，不过有的数字出现了
 *                  多次，有的数字没有出现。请给出算法和程序，统计哪些数字没有出现，哪些
 *                  数字出现了多少次。要求在O(n)的时间复杂度，O(1)
 *
 *        Version:  1.0
 *        Created:  08/30/2013 06:02:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

using std::cout;
using std::endl;

/*
 * 统计数组中的元素个数
 * Input: 
 *  array - 待统计的数组,数组中的元素在0到num - 1之间
 *  num - 数组array的长度
 * Output:
 *  array - 保存统计的结果:
 *              1）array[i] < 0,表示元素i的个数为|array[i]|;
 *              2)array[i] >= 0,表示元素i的个数为0
 *  int - 正常返回0，否则返回负值
 */
int CountArray(int array[], int num) 
{
    int ret = 0;

    if (array == NULL || num <= 0) {
        return -1;
    }

    for (int i = 0; i < num; ++i) {
        int b = array[i];
        if (b >= num) {
            return -1;
        }
        if (b < 0) {
            continue;
        }

        // 对i以后的元素进行处理
        while (b > i && array[b] >= 0) {
            int c = array[b];
            array[b] = -1;
            b = c;
            if (b >= num) {
                return -1;
            }
        }

        // 如果b所指元素已经计数过，则对其继续计数
        if (array[b] < 0) {
            --array[b];
        }
        // 如果b所指元素在i的前面，且未计过数，则对其进行计数
        else {
            array[b] = -1;
        }

    }

    return ret;
}

int main(int argc, char *argv[]) 
{
    int array[] = {0, 3, 3, 4, 3};
    int num = sizeof(array) / sizeof(array[0]);

    CountArray(array, num);

    for (int i = 0; i < num; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
