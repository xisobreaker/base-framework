#include "ProtobufConfig.h"

#include <fstream>
#include <google/protobuf/text_format.h>
#include <iterator>
#include <sstream>

bool protobuf_read_from_file(google::protobuf::Message &message, const std::string &filename)
{
    std::ifstream ifile(filename);
    if (!ifile.is_open()) {
        return false;
    }

    std::ostringstream oss;
    oss << ifile.rdbuf();
    ifile.close();

    std::string content(oss.str());
    if (!google::protobuf::TextFormat::ParseFromString(content.c_str(), &message)) {
        return false;
    }
    return true;
}

bool protobuf_write_to_file(const google::protobuf::Message &message, const std::string &filename)
{
    std::string output;
    if (!google::protobuf::TextFormat::PrintToString(message, &output)) {
        return false;
    }

    std::ofstream ofile(filename);
    if (!ofile.is_open()) {
        return false;
    }

    ofile.write(output.c_str(), output.length());
    ofile.close();
    return true;
}