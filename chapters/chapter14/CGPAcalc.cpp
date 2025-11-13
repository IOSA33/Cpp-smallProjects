#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Subject {
    std::string m_subjectName{};
    int m_studentGrade{};

public:
    Subject(const std::string& subjectName, int studentGrade)
            : m_subjectName(subjectName), m_studentGrade(studentGrade) {
        std::cout << "Subject added and name is " << m_subjectName << std::endl;
    }


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
    Student(const int id, const std::string& name)
            : m_id{id}, m_name(name) { // Constructor after ":", can use {} or ().
        std::cout << "Student(" << id << ", " << name << ") constructed\n";
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
            std::cout << fst << " : " << snd << ", ";
            ++count;
            studentGPA += snd;
        }
        std::cout << "GPA = ";
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
    out << student.getId() << ", " << student.getName() << "\n(" << student.getGPA() << ")";
    return out;
}

int main() {
    std::cout << "STUDENTS courses and their gpa \n";

    std::vector<Student> vector = {};

    Student topias{1, "qweqwe"};

    Subject topiasMath{"math", 4};
    topias.addSubjectToStudent(topiasMath);

    Subject topiasAlgebra{"algebra", 5};
    topias.addSubjectToStudent(topiasAlgebra);

    vector.emplace_back(topias);

    for (auto& student : vector) {
        std::cout << student;
    }

    return EXIT_SUCCESS;
}