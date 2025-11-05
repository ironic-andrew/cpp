#include <iostream>
using namespace std;

class Preschool_education {

    private:

        string child_name;
        string teacher_name;
        string assistant_name;
        string principal_name;
        string parents_names;

    public:

        string copy_name1_1, copy_name1_2, copy_name1_3, copy_name1_4, copy_name1_5;

        void show(){

            cout << "Дошкільна освіта\n";

        };
        string preschool_education_text = "Дошкільна освіта";

        Preschool_education(){

            child_name = "Софія";
            teacher_name = "Олена";
            assistant_name = "Марія";
            principal_name = "Ірина";
            parents_names = "Андрій і Наталія";

            copy_name1_1 = child_name;
            copy_name1_2 = teacher_name;
            copy_name1_3 = assistant_name;
            copy_name1_4 = principal_name;
            copy_name1_5 = parents_names;

        };
        /*
        Preschool_education(const Preschool_education& other){

            child_name = other.child_name;
            teacher_name = other.teacher_name;
            assistant_name = other.assistant_name;
            principal_name = other.principal_name;
            parents_names = other.parents_names;


        };
        */
        ~Preschool_education(){

            child_name = "";
            teacher_name = "";
            assistant_name = "";
            principal_name = "";
            parents_names = "";

            copy_name1_1 = "";
            copy_name1_2 = "";
            copy_name1_3 = "";
            copy_name1_4 = "";
            copy_name1_5 = "";

        };


        
        void show_result(){

            cout << "Дитина - " << child_name << "\n";
            cout << "Вихователь - " << teacher_name << "\n";
            cout << "Помічник вихователя - " << assistant_name << "\n";
            cout << "Завідувач садка - " << principal_name << "\n";
            cout << "Батьки - " << parents_names << "\n";

        };

};


class Primary_education:public Preschool_education{

    private:

        string student_name;
        string teacher_name_primary;
        string class_teacher_name;
        string school_principal_name;
        string parents_primary_names;

    public:
        void show(){

            cout << preschool_education_text << " - " <<"початкова освіта\n";

        };
        string primary_education_text = "початкова освіта";

        Primary_education(){

            student_name = "Максим";
            teacher_name_primary = "Галина";
            class_teacher_name = "Оксана";
            school_principal_name = "Володимир";
            parents_primary_names = "Сергій і Тетяна";

        };
        
        Primary_education& operator=(const Preschool_education& other){

            student_name = other.copy_name1_1;
            teacher_name_primary = other.copy_name1_2;
            class_teacher_name = other.copy_name1_3;
            school_principal_name = other.copy_name1_4;
            parents_primary_names = other.copy_name1_5;
            
        
            return *this;

        };
        

        ~Primary_education(){

            student_name = "";
            teacher_name_primary = "";
            class_teacher_name = "";
            school_principal_name = "";
            parents_primary_names = "";

        };

        void show_result(){

            cout << "Учень - " << student_name << "\n";
            cout << "Учитель - " << teacher_name_primary << "\n";
            cout << "Класний керівник - " << class_teacher_name << "\n";
            cout << "Директор школи - " << school_principal_name << "\n";
            cout << "Батьки - " << parents_primary_names << "\n";
        };

};


class Basic_education:public Primary_education{

    private:

        string pupil_name;
        string subject_teacher_name;
        string class_head_name;
        string vice_principal_name;
        string psychologist_name;

    public:
        void show(){

            cout << preschool_education_text << " - " << primary_education_text << " - " <<"середня освіта\n";

        };
        string basic_education_text = "середня освіта";

        Basic_education(){

            pupil_name = "Дмитро";
            subject_teacher_name = "Ірина";
            class_head_name = "Павло";
            vice_principal_name = "Людмила";
            psychologist_name = "Ольга";

        };


        ~Basic_education(){

            pupil_name = "";
            subject_teacher_name = "";
            class_head_name = "";
            vice_principal_name = "";
            psychologist_name = "";

        };

        void show_result(){

            cout << "Школяр - " << pupil_name << "\n";
            cout << "Вчитель - " << subject_teacher_name << "\n";
            cout << "Класний керівник - " << class_head_name << "\n";
            cout << "Заступник директора - " << vice_principal_name << "\n";
            cout << "Психолог - " << psychologist_name << "\n";

        };

};


class Vocational_education:public Basic_education{

    private:

        string vocational_student_name;
        string training_master_name;
        string special_teacher_name;
        string vocational_principal_name;
        string group_curator_name;

    public:
        void show(){

            cout << preschool_education_text << " - " << primary_education_text << " - " << basic_education_text << " - " <<"провесійна освіта\n";

        };
        string vocational_education_tex = "професійна освіта";

        Vocational_education(){

            vocational_student_name = "Артем";
            training_master_name = "Ігор";
            special_teacher_name = "Наталія";
            vocational_principal_name = "Петро";
            group_curator_name = "Олександр";

        };


        ~Vocational_education(){

            vocational_student_name = "";
            training_master_name = "";
            special_teacher_name = "";
            vocational_principal_name = "";
            group_curator_name = "";

        };

        void show_result(){

            cout << "Учень - " << vocational_student_name << "\n";
            cout << "Майстер виробничого навчання - " << training_master_name << "\n";
            cout << "Викладач спецдисциплін - " << special_teacher_name << "\n";
            cout << "Директор училища - " << vocational_principal_name << "\n";
            cout << "Куратор групи - " << group_curator_name << "\n";

        };

};


class Higher_education:public Vocational_education{

    private:

        string university_student_name;
        string lecturer_name;
        string dean_name;
        string rector_name;
        string phd_student_name;

    public:
        void show(){

            cout << preschool_education_text << " - " << primary_education_text << " - " << basic_education_text << " - " << vocational_education_tex << " - " <<"вища освіта\n";

        };
        string higher_education_tex = "середня освіта";

        Higher_education(){

            university_student_name = "Анна";
            lecturer_name = "Михайло";
            dean_name = "Світлана";
            rector_name = "Іван";
            phd_student_name = "Роман";

        };


        ~Higher_education(){

            university_student_name = "";
            lecturer_name = "";
            dean_name = "";
            rector_name = "";
            phd_student_name = "";

        };

        void show_result(){

            cout << "Студент - " << university_student_name << "\n";
            cout << "Викладач - " << lecturer_name << "\n";
            cout << "Декан - " << dean_name << "\n";
            cout << "Ректор - " << rector_name << "\n";
            cout << "Аспірант - " << phd_student_name << "\n";

        };

    };


    
int main(){

    Preschool_education t1;
    Primary_education t1_1;
    Basic_education t1_1_1;
    Vocational_education t1_1_1_1;
    Higher_education  t1_1_1_1_1;


    t1.show();
    Preschool_education q1{};
    q1.show_result();
    cout << "\n";

    t1_1.show();
    Primary_education q2{};
    q2.show_result();
    cout << "\n";

    t1_1_1.show();
    Basic_education q3{};
    q3.show_result();
    cout << "\n";


    t1_1_1_1.show();
    Vocational_education q4{};
    q4.show_result();
    cout << "\n";

    t1_1_1_1_1.show();
    Higher_education q5{};
    q5.show_result();
    cout << "\n";


    cout << "Оператор присвоєння\n";
    cout << "Оригінал\n";
    q2.show_result();
    cout << "\nПрисвоєний об'єкт\n";
    q2 = q1;
    q2.show_result();

    return 0;
}