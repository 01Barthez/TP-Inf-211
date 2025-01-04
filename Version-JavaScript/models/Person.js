import { v4 as uuidv4 } from 'uuid';

// Class to Manage global Person
class Person {
    constructor(name, contactInfo, gender) {
        if (!name || !contactInfo || !gender) {
            throw new Error("All required fields must be provided!");
        }

        this.id = uuidv4();
        this.name = name;
        this.contactInfo = contactInfo;
        this.gender = gender;
    }
}

export default Person;

// Test
const person = new Person("Barthez", "barthez@test.store", "Male");

