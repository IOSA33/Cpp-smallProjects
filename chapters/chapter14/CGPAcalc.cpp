#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Subject {
    std::string m_subjectName{};
    int m_studentGrade{};

public:
    void addGradesSubject(const std::string& subject, const int grade) {
        if (grade > 5) {
            std::cout << "Grade is greater than 5, we dont need that\n";
        } else {
            m_subjectName = subject;
            m_studentGrade = grade;
        }
    }

    const std::string& getSubjectName() const {
        return m_subjectName;
    }

    int getGrade() const {
        return m_studentGrade;
    }
};


class Student {
    int m_id{};
    std::string m_name{};
    std::unordered_map<std::string, int> m_GradesSubjects{};

public:
    Student(int id, const std::string& name) : m_id(id), m_name(name) {

    }

    void getNewStudent(const int id, const std::string_view studentName) {
        m_id = id;
        m_name = studentName;
    }

    void addSubjectToStudent(const Subject& sbj) {
        if (m_GradesSubjects.find(sbj.getSubjectName()) == m_GradesSubjects.end()) {
            m_GradesSubjects.insert({sbj.getSubjectName(), sbj.getGrade()});
            std::cout << "New subject and Grading added\n";
        }
    }

    double getGPA() const {
        double studentGPA{};
        int count{};
        for (const auto&[fst, snd]: m_GradesSubjects) {
            std::cout << fst << " : " << snd <<'\n';
            ++count;
            studentGPA += snd;
        }
        return studentGPA / count;
    }

    int getId() const {
        return m_id;
    }

    std::string_view getName() {
        return m_name;
    }
};

std::ostream& operator<<(std::ostream& out, Student& student) {
    out << student.getId() << ", " << student.getName() << ", " << student.getGPA();
    return out;
}

int main() {
    std::cout << "STUDENTS courses and their gpa \n";
    std::cout << "Get new STUDENT or add COURSES to STUDENTS\n";

    std::vector<Student> vector = {};

    Student topias{1, "qweqwe"};
    topias.getNewStudent(1, "sigmaBoy");
    Subject topiasSubjects;
    topiasSubjects.addGradesSubject("math", 4);
    topias.addSubjectToStudent(topiasSubjects);

    vector.emplace_back(topias);

    for (auto& student : vector) {
        std::cout << student;
    }

    return EXIT_SUCCESS;
}