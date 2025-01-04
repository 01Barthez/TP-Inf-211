#pragma once
#include <string>
#include <stdexcept>
#include <uuid/uuid.h>

class Person {
protected:
    std::string id;
    std::string name;
    std::string contactInfo;
    std::string gender;

    static std::string generateUUID() {
        uuid_t uuid;
        uuid_generate(uuid);
        char uuid_str[37];
        uuid_unparse_lower(uuid, uuid_str);
        return std::string(uuid_str);
    }

public:
    Person(const std::string& name, const std::string& contactInfo, const std::string& gender)
        : name(name), contactInfo(contactInfo), gender(gender) {
        if (name.empty() || contactInfo.empty() || gender.empty()) {
            throw std::invalid_argument("All required fields must be provided!");
        }
        id = generateUUID();
    }

    virtual ~Person() = default;

    // Getters
    const std::string& getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getContactInfo() const { return contactInfo; }
    const std::string& getGender() const { return gender; }
};
