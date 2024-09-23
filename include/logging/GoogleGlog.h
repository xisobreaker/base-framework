// =====================================================================================
//  Copyright (C) 2024 by Jiaxing Shao. All rights reserved
//
//  文 件 名:  GoogleGlog.h
//  作    者:  Jiaxing Shao, 980853650@qq.com
//  创建时间:  2024-09-23 13:31:46
//  描    述:  include 此头文件来引入 glog 头文件
// =====================================================================================
#pragma once

#define GLOG_USE_GLOG_EXPORT
#include <glog/logging.h>

/**
 * @brief glog 初始化
 *
 * @param log_path
 * @param log_name
 */
void google_glog_initialize(const std::string &log_path, const std::string &log_name);
