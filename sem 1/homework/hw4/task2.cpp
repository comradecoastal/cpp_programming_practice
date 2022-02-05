#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// declaration of structure for student
struct Student;

// structure for lesson
struct Lesson {
    std::string subject, lecturer, date;
    std::vector<Student *> attendees; // students attend lesson

    // constructor
    Lesson(std::string subject, std::string lecturer, std::string date) {
        this->subject = std::move(subject);
        this->lecturer = std::move(lecturer);
        this->date = std::move(date);
    }

    void print() {
        // simple function that prints information about the lesson
        std::cout << "Lesson \"" << subject << "\" by " << lecturer << " on " << date << std::endl;
    }

    void print_students(); // function that prints a list of attendees

    int find_student(Student student); // function that looks for a Student in attendees
};

// structure for student
struct Student {
    std::string name;
    unsigned group, year;
    std::vector<Lesson *> lessons;

    Student(std::string name, unsigned group, unsigned year) {
        this->name = std::move(name);
        this->group = group;
        this->year = year;
    }

    void print() {
        // prints info about the student
        std::cout << "Student: " << name << ", group " << group << ", year " << year << std::endl;
    }

    void print_lessons() {
        // prints a list of lessons attended by student
        std::cout << "Lessons attended by ";
        this->print();
        for (auto lesson: lessons) {
            lesson->print();
        }
        std::cout << "\n";
    };

    int find_lesson(const Lesson &lesson); // looks for a Lesson in lessons
};

void Lesson::print_students() {
    // prints a list of students attending lesson
    std::cout << "Students attending ";
    this->print();
    for (auto student: attendees) {
        student->print();
    }
    std::cout << "\n";
}

// overload == operator for Student struct
bool operator==(const Student &a, const Student &b) {
    return (a.name == b.name) && (a.group == b.group) && (a.year == b.year);
}

// overload == operator for Lesson struct
bool operator==(const Lesson &a, const Lesson &b) {
    return (a.subject == b.subject) && (a.lecturer == b.lecturer) && (a.date == b.date);
}

int Student::find_lesson(const Lesson &lesson) {
    // returns the position of lesson in lessons, -1 if lesson not present
    int pos = -1;
    for (int i = 0; i < lessons.size(); i++) {
        if (*lessons.at(i) == lesson) {
            pos = i;
            break;
        }
    }
    return pos;
}

int Lesson::find_student(Student student) {
    // returns the position of student in attendees, -1 if student not present
    int pos = -1;
    for (int i = 0; i < attendees.size(); i++) {
        if (*attendees.at(i) == student) {
            pos = i;
            break;
        }
    }
    return pos;
}

//int findStudentInLesson(Lesson &lesson, Student &student) {
//    int pos = -1;
//    for (int i = 0; i < lesson.attendees.size(); i++) {
//        if (*lesson.attendees.at(i) == student) {
//            pos = i;
//            break;
//        }
//    }
//    return pos;
//}
//
//int findLessonInStudent(Lesson &lesson, Student &student) {
//    int pos = -1;
//    for (int i = 0; i < student.lessons.size(); i++) {
//        if (*student.lessons.at(i) == lesson) {
//            pos = i;
//            break;
//        }
//    }
//    return pos;
//}

void assignLesson(Lesson &lesson, Student &student) {
    /**
     * Assigns student to lesson.
     * If student already assigned to lesson writes a message and does nothing
     *
     * @param lesson Lesson struct - the lesson to be attended
     * @param student Student struct - the student to attend the lesson
     */
    if (lesson.find_student(student) == -1) {
        lesson.attendees.push_back(&student);
        student.lessons.push_back(&lesson);
    } else {
        std::cout << "Student already assigned to lesson!" << std::endl;
    }
}

void cancelLesson(Lesson &lesson, Student &student) {
    /**
     * Removes student from lesson.
     * If student not attend lesson to begin with writes a message and does nothing
     *
     * @param lesson Lesson struct - the lesson to remove the student from
     * @param student Student struct - the student to be removed from the lesson
     */
    int pos = lesson.find_student(student);
    if (pos == -1) {
        std::cout << "Student is not attending this lesson!" << std::endl;
    } else {
        int pos_les = student.find_lesson(lesson);
        lesson.attendees.erase(lesson.attendees.begin() + pos);
        student.lessons.erase(student.lessons.begin() + pos_les);
    }
};

int main() {
    Student misha("Misha", 10, 2020);

    Student gosha("Gosha", 9, 2020);

    Lesson math("math", "Redkozubova", "11/09/21");

    Lesson physics("physics", "Gavrikov", "12/09/21");

    misha.print();
    gosha.print();
    math.print();
    physics.print();

    assignLesson(math, misha);
    assignLesson(physics, gosha);
    assignLesson(math, gosha);
    assignLesson(physics, misha);

    cancelLesson(physics, misha);
    cancelLesson(physics, misha);

    assignLesson(math, gosha);

    misha.print_lessons();
    gosha.print_lessons();
    math.print_students();
    physics.print_students();

    return 0;
}

