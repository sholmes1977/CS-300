//============================================================================
// Name        : Project.cpp
// Author      : Shaun Holmes
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//Use the definition of the structure course

struct Course{
	string courseNum;
	string name;
	vector <string> prerequisites;
};
//Use the function to split the string in the list

vector<string> tokenize(string s, string del = "")
		{
	vector<string>stringArray;
	int start = 0;
	int end = s.find(del);
	while(end != -1){
		stringArray.push_back(s.substr(start, end - start));
		start = end + del.size();
		end = s.find(del, start);
	}
	stringArray.push_back(s.substr(start, end - start));
	return stringArray;
		}
//Use the function to load the file and store details into list of courses

vector<Course>LoadDataStructure()
		{
	// the object ifstream class to open file
	ifstream fin("abcu.txt", ios::in);
	vector<Course>courses;
	string line;

	//Use the infinite loop
	while(1)
	{
		getline(fin,line);
		//end of file to reach then looped
		if(line=="-1")
			break;
		Course course;

		//getting information separated by commas

		vector<string> tokenizedinformation=tokenize(line,",");
		//Storing information of the course

		course.courseNum=tokenizedinformation[0];
		course.name=tokenizedinformation[1];

		//store the prerequisites
		for(int i=2;i<tokenizedinformation.size(); i++)
		{
			course.prerequisites.push_back(tokenizedinformation[1]);
		}

		//appending into courses
		courses.push_back(course);
	}
	//file to be closed
	fin.close();
	//return the list
	return courses;
		}
//print information given of course
void printCourse(Course course)
{
	string courseNum=course.courseNum;
	string name = course.name;
	vector<string>prerequisites=course.prerequisites;
	cout<<"Course Number:" <<courseNum<<endl;
	cout<<"Course Name: " <<name<<endl;
	cout<<"Prerequisites:";
	for(int i=0; i<prerequisites.size(); i++)
	{
		cout<<prerequisites[i]<<"";
	}
	cout<<"\n\n";
	}
//Print the information about each course in proper format
void printCourseList(vector<Course>courses)
{
	int n=courses.size();
	//bubble sort to sort the list
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		for(courses[j].courseNum> courses[j+1].courseNum)
	}
	swap(courses[j+1], courses[j]);
}
	//print all courses information
	for(int i=0; i<n; i++)
	{
		printCourse(courses[i]);
	}

	//search for the user entered course number

	void searchCourse(vector<Course>courses)
	{
		int n=courses.size();
		string courseNum;
		int f=0;
		cout<<"Enter courseNum:";
		cin>>courseNum;
		for(int i=0; i<n; i++)
		{
			if(course[i].courseNum==courseNum)
			{
				f=1;
				printCourse(courses[i]);
				break;
			}
		}
		//if course name not found print error message
		if(f==0)
		{
			cout<<"Course with given number not found\n";
		}
	}
	int main(int argc, char**argv)
	{
		vector<Course>courses;
		//Menu to print

		cout<<"1. Load Data Structure\n";
		cout<<"2. Print Course List\n";
		cout<<"3. Print Course\n";
		cout<<"4. Exit\n";
		int ch;
	//the loop with break if the user enter 4
		do{
			cout<<"\nEnter your choice:";
			cin>>ch;
			switch(ch)
			{
			case 1: courses=LoadDataStructure(); break;
			case 2: printCourseList(courses);break;
			case 3: searchCourse(course);break;
			case 4: cout<<"Exit\n"; break;
			default: cout<<"Invalid Choice\n";
			}
			}While(ch!=4);
			return 0;
	}
