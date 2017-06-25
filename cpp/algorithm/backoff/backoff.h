#ifndef __LIB_CPP_ALGORITHM_BACKOFF_H__
#define __LIB_CPP_ALGORITHM_BACKOFF_H__
/**
 * @file backoff.h
 * @author binhfile
 * @brief Giao diện cho các thuật toán backoff
 * Backoff: Thuật toán áp dụng cho trường hợp cần truyền lại các bản tin trong truyền thông.
 *   Các thuật toán backoff khác nhau về thời gian trễ giuax các lần truyền lại 
 *   nhắm tránh xung đột khi có nhiều bản tin cùng truyền vào một thời điểm.
 * @ref https://www.awsarchitectureblog.com/2015/03/backoff.html
 */
#include <functional>
namespace library{namespace cpp{namespace algorithm{
    class IBackoff {
    public:
        virtual ~IBackoff(){}
        /**
         * @brief Thực thi 'action' với 'numberOfTry' lần thực hiện lại.
         *   Nếu 'action' trả về 0 tương ứng với hành động thành công -> Run trả về  gía trị 0.
         *   Nếu 'action' trả về khác 0 tương ứng với lỗi -> Thực hiện lại 'action' tới khi thành công hoặc sau 'numberOfTry' lần lỗi.
         *     Trả về  gía trị lỗi sau cùng của 'action'
         * @param numberOfTry Số lần thực hiện 'action' trong trường hợp lỗi
         * @param action Hàm thực hiện
         * @return int Mã lỗi
         */
        virtual int Run(int numberOfTry, const std::function<int()>& action) = 0;
    };
}}}
/**
 * 
 */
#endif