#pragma once

#include <google/protobuf/message.h>
#include <string>

namespace xiso {

/**
 * @brief protobuf 文件数据读取
 *
 * @param message protobuf 数据结构体
 * @param filename 文件名称
 * @return true
 * @return false
 */
bool protobuf_read_from_file(google::protobuf::Message &message, const std::string &filename);

/**
 * @brief protobuf 数据写入文件
 *
 * @param message protobuf 数据结构体
 * @param filename 文件名称
 * @return true
 * @return false
 */
bool protobuf_write_to_file(const google::protobuf::Message &message, const std::string &filename);

} // namespace xiso