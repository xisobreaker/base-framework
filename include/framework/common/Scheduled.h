#pragma once

#include <chrono>
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <set>
#include <thread>

namespace xiso {

class Scheduled
{
    typedef std::function<void()>     ScheduledFunc;
    typedef std::chrono::system_clock SystemClock;

    struct CrontabTask {
        std::function<void()>                              callback;
        std::chrono::time_point<std::chrono::system_clock> nextTime;
        std::chrono::microseconds                          period;

        bool operator<(const CrontabTask &task) const
        {
            return this->nextTime < task.nextTime;
        }
    };

public:
    Scheduled();
    ~Scheduled();

private:
    void run();

public:
    /**
     * @brief 添加一次性任务
     *
     * @param fn 任务回调
     * @param tp 开始时间
     */
    void addTask(const ScheduledFunc &fn, const std::chrono::time_point<SystemClock> &tp);

    /**
     * @brief 添加定时周期任务
     *
     * @param fn 任务回调
     * @param tp 开始时间
     * @param period 任务周期
     */
    void addTask(const ScheduledFunc &fn, const std::chrono::time_point<SystemClock> &tp, const std::chrono::microseconds &period);

    /**
     * @brief 添加周期任务
     *
     * @tparam Rep
     * @tparam Period
     * @param fn 任务回调
     * @param period 任务周期
     * @param start_now 立即执行任务
     */
    template <typename Rep, typename Period>
    void addTask(const ScheduledFunc &fn, const std::chrono::duration<Rep, Period> &period, bool start_now = false)
    {
        if (start_now) {
            addTask(fn, SystemClock::now(), period);
        } else {
            addTask(fn, SystemClock::now() + period, period);
        }
    }

private:
    bool                         m_runningFlag;
    std::mutex                   m_mutexLock;
    std::condition_variable      m_condition;
    std::unique_ptr<std::thread> m_threadPtr;
    std::multiset<CrontabTask>   m_taskList;
};

} // namespace xiso