/*
 * =====================================================================================
 *
 *       Filename:  prefixsort.cc
 *
 *    Description:  Prefix sorting
 *
 *        Version:  1.0
 *        Created:  09/04/2013 09:52:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdio>
#include <sstream>

using namespace std;

class PrefixSorting 
{
public: 
    PrefixSorting() 
    {
        cake_cnt_ = 0;
        max_swap_ = 0;
        cake_array_ = NULL;
        swap_array_ = NULL;
        reverse_cake_array_ = NULL;
        reverse_cake_swap_array_ = NULL;
        search_ = 0;

    }

    ~PrefixSorting() 
    {
        if (cake_array_ != NULL) {
            delete[] cake_array_;
        }
        if (cake_swap_array_ != NULL) {
            delete[] cake_swap_array_;
        }
        if (reverse_cake_array_ != NULL) {
            delete[] reverse_cake_array_;
        }
        if (reverse_cake_swap_array != NULL) {
            delete[] reverse_cake_swap_array_;
        }
    }

    /*
     * 计算烙饼翻转信息
     * @param
     *  cake_array  存储烙饼数组
     *  cake_cnt    烙饼个数
     */
    void Run(int *cake_array, int cake_cnt) 
    {
        Init(cake_array, cake_cnt);
        search_ = 0;
        Search(0);
    }

    /*
     * 输出烙饼具体翻转的次数
     */
    void OutPut() 
    {
        if (cake_swap_array == NULL) {
            printf("Please do Run first.\n");
            return;
        }

        for (int i = 0; i < max_swap_; ++i) {
            printf("%d ", cake_swap_array_[i]);
        }

        printf("\n |Search Times| : %d\n", search_);
        printf("Total Swap times = %d\n", max_swap_);
    }

private:
    /*
     * 初始化数组信息
     * @param
     *  cake_array 存储烙饼索引数组
     *  cake_cnt 烙饼个数
     */
    void Init(int *cake_array, int cake_cnt) 
    {
        if (cake_array == NULL || cake_cnt <= 0) {
            ostringstream oss;
            oss << "cake_array:" << hex << static_cast<void*>(cake) 
                << ", cake_cnt:" << cake_cnt << endl;
            throw invalid_argument(oss.str());
        }

        cake_cnt_ = cake_cnt;

        // 初始化烙饼索引数组
        cake_array_ = new int[cake_cnt_];
        for (int i = 0; i < cake_cnt_; ++i) {
            cake_array_[i] = cake_cnt[i];
        }

        // 设置最多交换次数信息
        max_swap_ = UpBound(cake_cnt_);

        // 初始化交换数组结果
        cake_swap_array_ = new int[max_swap_ + 1];

        // 初始化中间交换结果信息
        reverse_cake_array_ = new int[cake_cnt];
        for (int i = 0; i < cake_cnt; ++i) {
            reverse_cake_array_[i] = cake_array[i];
        }
        reverse_cake_swap_array_ = new int[max_swap_ + 1];

    }
    
    /*
     * 烙饼信息数组
     */
    int *cake_array_;
    /*
     * 烙饼个数
     */
    int cake_cnt_;
    /*
     * 最多交换次数。根据前面推断这里最多为 (cake_cnt - 1) * 2
     */
    int max_swap_;
    /*
     * 交换结果数组
     */
    int *cake_swap_array_;
    /*
     * 当前翻转烙饼信息数组
     */
    int *reverse_cake_array_;
    /*
     * 当前翻转烙饼交换结果数组
     */
    int *reverse_cake_swap_array_;
    /*
     * 当前搜素次数信息
     */
    int search_;
};
