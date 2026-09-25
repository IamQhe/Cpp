#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    // 默认使用当前目录，也可以通过命令行参数指定目录
    std::string dirPath = (argc > 1) ? argv[1] : ".";
    
    if (!fs::exists(dirPath)) {
        std::cerr << "目录不存在: " << dirPath << std::endl;
        return 1;
    }
    
    if (!fs::is_directory(dirPath)) {
        std::cerr << "路径不是目录: " << dirPath << std::endl;
        return 1;
    }
    
    std::vector<std::pair<std::string, std::time_t>> matchedFiles;
    
    try {
        // 递归遍历目录
        for (const auto& entry : fs::recursive_directory_iterator(dirPath)) {
            if (!entry.is_regular_file()) continue;
            
            // 获取最后修改时间
            auto ftime = fs::last_write_time(entry);
            
            // C++20 之前需要转换 file_time_type 到 system_clock
            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
            );
            std::time_t tt = std::chrono::system_clock::to_time_t(sctp);
            
            std::tm* localTime = std::localtime(&tt);
            
            // 判断年份是否为 2025
            if (localTime->tm_year + 1900 == 2025) {
                matchedFiles.push_back({entry.path().string(), tt});
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "遍历目录时出错: " << e.what() << std::endl;
        return 1;
    }
    
    // 输出结果
    std::cout << "在目录 [" << dirPath << "] 下，最后修改日期为 2025 年的文件：" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    
    for (const auto& [path, tt] : matchedFiles) {
        std::tm* localTime = std::localtime(&tt);
        std::cout << std::put_time(localTime, "%Y-%m-%d %H:%M:%S")
                  << "  " << path << std::endl;
    }
    
    std::cout << std::string(60, '-') << std::endl;
    std::cout << "共找到 " << matchedFiles.size() << " 个文件。" << std::endl;
    
    return 0;
}