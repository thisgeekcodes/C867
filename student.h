#pragma once



//Enum Class to print specific student data
enum class printEnum { studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram, ALL };


class student {
	public:
			const static int daysArray = 3; // constant size of array
	private:
			string studentID, firstName, lastName, emailAddress, Color;
			int age;
			DegreeProgramEnum degreeprogram;
			float daysInCourse[daysArray];
public:


		//destructor
		~student();

		//getters
		string get_studentID();
		string get_firstName();
		string get_lastName();
		string get_emailAddress();
		int get_age();
		float* get_daysInCourse();
		DegreeProgramEnum get_degreeprogram();

		//setters

		void set_studentID(string studentID);
		void set_firstName(string firstName);
		void set_lastName(string lastName);
		void set_emailAddress(string emailAddress);
		void set_age(int age);
		void set_daysInCourse(float daysInCourse[]);
		void set_degreeprogram(DegreeProgramEnum degreeprogram);
		//full constructor w/ params
		student(
			string studentID = "ID",
			string firstName = "FNAME",
			string lastName = "LNAME",
			string emailAddress = "EMAIL",
			int age = 0,
			float daysInCourse[] = {},
			DegreeProgramEnum degreeprogram = DegreeProgramEnum::SOFTWARE);
		//print function
		void print(printEnum item) const;


				};
