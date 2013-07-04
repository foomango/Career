// =====================================================================================
// 
//       Filename:  CStackWithMin.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/15/2013 08:47:21 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#ifndef CSTACK_WITH_MIN_H
#define CSTACK_WITH_MIN_H

#include <deque>
#include <assert.h>

template<typename T> class CStackWithMin
{
    public:
        CStackWithMin() {}
        ~CStackWithMin() {}

        T& top();
        const T& top() const;

        void push(const T& value);
        void pop();

        const T& min() const;

    private:
        std::deque<T> m_data;           // the elements of stack
        std::deque<size_t> m_minIndex;  // the elements of minimum elements
};

// get the last element of mutable stack
template<typename T> T& CStackWithMin<T>::top() 
{
    return m_data.back();
}

// get the last element of non-mutable stack
template<typename T> const T& CStackWithMin<T>::top() const 
{
    return m_data.back();
}

// insert an element at the top of the stack
template<typename T> void CStackWithMin<T>::push(const T& value) 
{
    // append the data into the end of m_data
    m_data.push_back(value);

    // set the index of minimum element in m_data at the end or m_minIndex
    if (m_minIndex.empty()) {
        m_minIndex.push_back(m_data.size() -1);
    } else {
        size_t index = m_minIndex.back();
        if (value < m_data[index]) {
            m_minIndex.push_back(m_data.size() - 1);
        } else {
            m_minIndex.push_back(index);
        }
    }
}

// erease the element at the end of stack
template<typename T> void CStackWithMin<T>::pop() 
{
    // pop m_data
    m_data.pop_back();

    // pop m_minIndex
    m_minIndex.pop_back();
}

// get the minimus element of stack
template<typename T> const T& CStackWithMin<T>::min() const
{
    assert(!m_data.empty());
    assert(!m_minIndex.empty());
    
    size_t index = m_minIndex.back();
    return m_data[index];
}

#endif
