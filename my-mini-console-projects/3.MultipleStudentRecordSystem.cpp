#include<iostream>
#include<string>

using namespace std;

struct Student{ //Structure of student record
    string name;
    int rollNo;
    float marks;
};

void addStudent(Student student[], int &count){
    if(count >= 100){//This code will check the limit of student list
        cout<<"Student limit reached.\n";
        return;
    }

    cout<<"\nEnter name: ";//Add the student name
    cin.ignore();
    getline(cin,student[count].name);

    cout <<"Enter roll number: ";//add the student Roll Number 
    cin>>student[count].rollNo;

    cout<<"Enter marks: ";//add the marks of student
    cin>>student[count].marks;

    cout <<"Student added successfully.\n";
    count++;//update the list by adding 1
}
void showAllStudents(Student student[], int count){//All data
    if(count==0){
        cout<<"No students to show.\n";
        return;
    }
    cout<<"\n--- All Students ---\n";
    for(int i = 0; i < count;i++){
        cout <<"student #"<<i + 1<<endl;
        cout <<"Name: " <<student[i].name<<endl;
        cout <<"Roll: " <<student[i].rollNo<<endl;
        cout <<"Marks: "<<student[i].marks<<endl;
        cout<<"------------------------\n";
    }    
}
void updateMarks(Student student[], int count){//updateing marks function
    int roll;
    cout <<"Enter roll number to update marks: ";
    cin >>roll;

    for(int i = 0; i < count; i++){
        if(student[i].rollNo == roll){
            cout <<"Enter new marks: ";
            cin >> student[i].marks;
            cout<<"Marks updated.\n";
            return;
        }
    }
   cout<<"Student with roll number "<< roll <<"not found.\n";
}
int main(){
    Student students[100];
    int studentCount = 0;
    int choice;

    while (true) {//record menu 
        cout << "\n===== STUDENT RECORD MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Update Marks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                showAllStudents(students, studentCount);
                break;
            case 3:
                updateMarks(students, studentCount);
                break;
            case 4:
                cout << "Exiting system.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }    

return 0; 
}