#include "GoogleGlog.h"

#include <iomanip>

namespace xiso {

void MyPrefixFormatter(std::ostream &s, const google::LogMessage &m, void * /*data*/)
{
    s << "[" << std::setw(4) << 1900 + m.time().year() << std::setw(2) << 1 + m.time().month() << std::setw(2) << m.time().day() << ' '
      << std::setw(2) << m.time().hour() << ':' << std::setw(2) << m.time().min() << ':' << std::setw(2) << m.time().sec() << "."
      << std::setw(6) << m.time().usec() << ' ' << std::setfill(' ') << std::setw(5) << m.thread_id() << std::setfill('0') << ' '
      << m.basename() << ':' << m.line() << "][" << google::GetLogSeverityName(m.severity())[0] << "]";
}

void google_glog_initialize(const std::string &log_path, const std::string &log_name)
{
    FLAGS_max_log_size              = 1800;
    FLAGS_logtostdout               = true;
    FLAGS_colorlogtostdout          = true;
    FLAGS_stop_logging_if_full_disk = true;

    std::string log_filename = log_path + "/" + log_name;
    google::InitGoogleLogging(log_name.c_str());
    google::SetLogDestination(google::GLOG_INFO, log_filename.c_str());
    google::EnableLogCleaner(std::chrono::hours(24) * 7);
    google::InstallPrefixFormatter(&MyPrefixFormatter);
}

} // namespace xiso