#include <iostream>


class Classroom {
protected:
    std::string description;
    bool availability;
public:
    virtual std::string getDescription() {
        return description;
    }
    virtual bool isAvailable() = 0;
    virtual void reserve() = 0;
};

class LectureRoom : public Classroom {
    bool isAvailable() override {
        return availability;
    }
    void reserve() override {
        availability = true;
    }
};

class SeminarRoom : public Classroom {
    bool isAvailable() override {
        return availability;
    }
    void reserve() override {
        availability = true;
    }
};

class ComputerRoom : public Classroom {
    bool isAvailable() override {
        return availability;
    }
    void reserve() override {
        availability = true;
    }
};


class CondimentDecorator : public Classroom {
protected:
    Classroom* classroom_;
public:
    CondimentDecorator() {
        std::cout << "decorator constructor\n";
    }
    virtual std::string getDescription() = 0;
    void reserve() override {
        availability = false;
    }
    ~CondimentDecorator() {
        delete classroom_;
        std::cout << "decorator destructor\n";
    }
};

class Projector : public CondimentDecorator {
public:
    Projector(Classroom *classroom) {
        std::cout << "projector constructor\n";
        classroom_ = classroom;
    }
    std::string getDescription() override {
        return classroom_->getDescription() + ", Projector";
    }
    bool isAvailable() override {
        return true && classroom_->isAvailable();
    }
    ~Projector() {
        std::cout << "projector destructor\n";
    }
};

class Whiteboard : public CondimentDecorator {
public:
    Whiteboard(Classroom *classroom) {
        std::cout << "whiteboard constructor\n";
        classroom_ = classroom;
    }
    std::string getDescription() override {
        return classroom_->getDescription() + ", Whiteboard";
    }
    bool isAvailable() override {
        return true && classroom_->isAvailable();
    }
    ~Whiteboard() {
        std::cout << "whiteboard destructor\n";
    }
};

class Markers : public CondimentDecorator {
public:
    Markers(Classroom *classroom) {
        std::cout << "markers constructor\n";
        classroom_ = classroom;
    }
    std::string getDescription() override {
        return classroom_->getDescription() + ", Markers";
    }
    bool isAvailable() override {
        return false && classroom_->isAvailable();
    }
    ~Markers() {
        std::cout << "markers destructor\n";
    }
};


int main() {
    Classroom *classroom = new LectureRoom();
    std::cout << classroom->getDescription() << ", " << std::boolalpha << classroom->isAvailable() << "\n";
    delete classroom;

    Classroom *classroom1 = new SeminarRoom();
    classroom1 = new Whiteboard(classroom1);
    classroom1 = new Markers(classroom1);

    std::cout << classroom1->getDescription() << ", " << std::boolalpha << classroom1->isAvailable() << "\n";
    delete classroom1;



    return 0;
}
