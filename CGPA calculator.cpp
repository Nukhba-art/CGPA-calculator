#include<iostream>
#include<string>
using namespace std;
class student{
	protected:
		struct Course {
        char grade;
        int credits;
    };
	int id;
	string name;
	 Course*courses;	
	int no_of_courses;
	double totalPointsAccumulated = 0;
    int totalCreditsAccumulated = 0;
	public:	
	student(){
		id=0;
		name="unknown";
       	courses=NULL;
		no_of_courses=0;
	}
	
	~student() { 
	delete[] courses;
	 }	
	
void setStudentInfo() {
        cout << "Enter ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
    }

    void processSemester(int semesterNum) {
        cout << "\n--- Semester " << semesterNum << " ---" << endl;
        cout << "Number of courses: "; cin >> no_of_courses;courses = new Course[no_of_courses];
        double semPoints = 0;
        int semCredits = 0;
for (int i = 0; i < no_of_courses; i++) {
            cout << "Course " << i + 1 << " Grade (A-F): "; cin >> courses[i].grade;
            cout << "Course " << i + 1 << " Credit Hours: "; cin >> courses[i].credits;

                         double val = (courses[i].grade == 'A' || courses[i].grade == 'a') ? 4.0 :
             (courses[i].grade == 'B' || courses[i].grade == 'b') ? 3.0 :
             (courses[i].grade == 'C' || courses[i].grade == 'c') ? 2.0 :
             (courses[i].grade == 'D' || courses[i].grade == 'd') ? 1.0 : 0.0;
semPoints += (val * courses[i].credits);
            semCredits += courses[i].credits;
        }
totalPointsAccumulated += semPoints;
totalCreditsAccumulated += semCredits;
cout << "Semester " << semesterNum << " GPA: " << ((semCredits == 0) ? 0.0 : (semPoints / semCredits)) << endl;
delete[] courses; 
        courses = NULL;
    }
    
 double getCGPA() {
        return (totalCreditsAccumulated == 0) ? 0 : (totalPointsAccumulated / totalCreditsAccumulated);
    }

    void displayCGPA() {
        cout << "\nStudent: " << name << " | ID: " << id << endl;
        cout << "Cumulative CGPA: " << getCGPA() << endl;
    }
};

int main(){
	int no,numsemesters;
	cout<<"Enter number of students:"<<endl;
	cin>>no;
	 student*s1=new student[no];
	for (int i = 0; i < no; i++) {
        s1[i].setStudentInfo();
         cout << "How many semesters has this student completed? ";
        cin >> numsemesters;
        for (int j = 1; j <= numsemesters; j++) {
            s1[i].processSemester(j);
        }
        s1[i].displayCGPA();
    
    }
	delete[]s1;
}
