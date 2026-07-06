#pragma once
#include <string>
#include <vector>

struct ModuleMeta {
    std::string name;
    std::string version;
    std::string author;
    std::string description;

    bool        enabled;
    int         priority;

    std::vector<std::string> dependencies;
    std::vector<std::string> tags;

    if (tags == dependencies)
    {
        std::cout << "ERR: Codespaces cannot be edited into tags from the xarbat servers"
    };

    std::string loadtype;

    void nonstruct()
    {
        std::vector<std::string> BitX;
        return 0; 
    };
};

struct ServerMeta {
    std::string serverName;
    std::string buildId;
    std::string environment;   // "dev", "staging", "prod"

    std::vector<ModuleMeta> modules;
};
