package models;

import java.util.UUID;

public abstract class Person {
    protected final String id;
    protected final String name;
    protected final String contactInfo;
    protected final String gender;

    protected Person(String name, String contactInfo, String gender) {
        if (name == null || contactInfo == null || gender == null ||
            name.isEmpty() || contactInfo.isEmpty() || gender.isEmpty()) {
            throw new IllegalArgumentException("All required fields must be provided!");
        }

        this.id = UUID.randomUUID().toString();
        this.name = name;
        this.contactInfo = contactInfo;
        this.gender = gender;
    }

    public String getId() { return id; }
    public String getName() { return name; }
}
