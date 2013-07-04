// =====================================================================================
// 
//       Filename:  CQueue.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/15/2013 07:20:50 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <CQueue.h>

/**
 * Append an element at the tail of the queue
 **/
template<typename T> void CQueue<T>::appendTail(const T& element) 
{
    // push the new element into m_stack1
    m_stack1.push(element);
}

/**
 * Delete the head from the queue
 **/
template<typename T> void CQueue<T>::deleteHead() 
{
    // if m_stack2 is empty, and there are some 
    // elements in m_stack1, push them into m_stack2
    if (m_stack2.empty()) {
        while (!m_stack1.empty()) {
            T& data = m_stack1.top();
            m_stack1.pop();
            m_stack2.push(data);
        }
    }

    // pop the element from m_stack2
    assert(!m_stack2.empty());
    m_stack2.pop();
}
