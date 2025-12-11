#pragma once

#include <string>
#include <map>

namespace vsa::village {

class EntitiesRegistry
{
public:
    static EntitiesRegistry& get_instance();

private:
    EntitiesRegistry();

public:
    void register_resident(const std::string& id, const std::string& name);
    [[nodiscard]] const std::map<std::string, std::string>& get_residents() const;

private:
    std::map<std::string, std::string> m_residents;
};

template <typename T>
class ResidentRegistrator
{
public:
    ResidentRegistrator()
    {
        auto& r = EntitiesRegistry::get_instance();
        r.register_resident(T::get_id(), T::get_name());
    }
};

} // vsa
