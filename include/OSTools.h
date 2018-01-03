#ifndef __DEV_TOOLS_CPP_LIBRARIES_UTILS_OS_TOOLS_H__
#define __DEV_TOOLS_CPP_LIBRARIES_UTILS_OS_TOOLS_H__

#include <string>
#include <vector>

namespace OS {
    /**
     * Return files matching a glob pattern
     *
     * WARNING: glibc's glob is not thread safe, so a unique lock is used to
     *          police its usage
     */
    std::vector<std::string> Glob(const std::string& path);

    std::string PWD();

    std::string Join(const std::string& path1, const std::string& path2);

    std::string Basename(const std::string& path);
    std::string Dirname(const std::string& path);

    bool Exists(const std::string& path);
};

#endif
