#include <iostream>

using namespace std;

string getHwidCore(string type) {
    char buffer[128];
    std::string result = "";
    string cmd;

    cmd += "wmic ";
    cmd += type;
    cmd += " get serialnumber ";
    cmd += "| find /v \"SerialNumber|\" | findstr /v \"^$\"";

    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            if (isdigit(buffer[0]))
                result += buffer;
        }
    }
    catch (...) {
        _pclose(pipe);
        throw;
    }
    _pclose(pipe);

    return result;
}

string getHwid(string type) {
    string data;

    for (size_t i = 0; i < getHwidCore(type).size(); i++)
    {
        if (isdigit(getHwidCore(type)[i]))
        {
            data += getHwidCore(type)[i];
        }
    }

    return data;
}
