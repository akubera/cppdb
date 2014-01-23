/* 
 * File:   driver_manager.h
 * Author: andrewkubera
 *
 * Created on January 6, 2014, 9:47 PM
 */

#pragma once


#include "cppdb.hpp"
#include "driver.hpp"

#include <map>
#include <regex>
#include <string>

CPPDB_NAMESPACE_BEGIN

// the default path to look for drivers
const std::string driver_path_default("./build/drivers/");

// regex to match driver libraries (lib_<NAME>_driver.*)
const std::regex driver_file_regex("lib_([^_]*)_driver\\..*");


class Driver;

class DriverManager
{
public:

    static void LoadDrivers(const std::string& path = driver_path_default);

    static std::vector<std::string> GetDriverNames(const std::string& path = driver_path_default);

    static std::shared_ptr<Driver> GetDriverWithName(const std::string& driver_name);

    static std::vector<std::string> SearchPath;
    static void UnloadDriver(const std::string& name);

protected:
    static std::map<std::string, std::shared_ptr<Driver>> _drivers;
    static std::map<std::string, void*> _driver_libraries;
    static bool _drivers_loaded;

protected:
    static std::shared_ptr<Driver> FindDriver(const std::string& driver_name);
    static std::shared_ptr<Driver> LoadDriver(void *, const std::string& name);

};

CPPDB_NAMESPACE_END
