#include <iostream>
#include <string.h>

using namespace std;

class Employee{
	private:
		int sequence;
		char name[20];
		char job[10];
		float worked_hours;
		float ceo_salary();
	public:
		void set_first_values();
		void get_values(int sequence, char name[20], char job[10], float worked_hours);
		void show();
		char* get_name();
                void set_name(char n[]);
                int get_sequence();
                void set_sequence(int n);
		char* get_job();
                void set_job(char n[]);
		float calculate_salary();
		bool add_work_hour(float hour);
                float get_worked_hours();
                void set_worked_hours(float n);
		void empcopy(Employee &);
		void sortSalary(Employee e[], int n);
};

float Employee::get_worked_hours(){
	return this->worked_hours;
}

void Employee::set_worked_hours(float n){
	this ->sequence=n;
}

int Employee::get_sequence(){
	return this->sequence;
}

void Employee::set_sequence(int n){
	this ->sequence=n;
}

void Employee::set_name(char n[]){
	strcpy(this->name, n);
}

void Employee::set_job(char n[]){
	strcpy(this->job, n);
}

void Employee::set_first_values(){
	this->sequence = 0;
	strcpy(this->name, "");
	strcpy(this->job, "Ajilchin");
	this->worked_hours = 0;
}

void Employee::get_values(int sequence, char name[], char job[], float worked_hours){
	this->sequence = sequence;
	strcpy(this->name, name);
	strcpy(this->job, job);
	this->worked_hours = worked_hours;
}

char* Employee::get_name(){
	return name;
}

char* Employee::get_job(){
	return job;
}

float Employee::calculate_salary(){
	if(strcmp(this->job, "Zahiral") == 0){
		return this->worked_hours * 3000 + this->ceo_salary();
	}else{
		return this->worked_hours * 3000;
	}
}

float Employee::ceo_salary(){
	return 150000;
}

bool Employee::add_work_hour(float hour){
	if(hour>0 && hour<24){
		this->worked_hours = this->worked_hours + hour;
		return 1;
	}else{
		return 0;
	}
}

void Employee::empcopy(Employee &e){
	strcpy(name, e.get_name());
	strcpy(job, e.get_job());
	worked_hours = e.get_worked_hours();
	sequence = e.get_sequence();
}

void Employee::show(){
	cout<<"***************** \nДугаар: "<<sequence<<"\n"<<"Нэр: "<<name<<"\n"<<"Албан тушаал: "<<job<<"\n"
	<<"Ажилласан цаг: "<<worked_hours<<"\n"<<"*****************"<<"\n";
}

void sortSalary(Employee e[], int n){
	for(int i = 1; i <= n; i++){
		for(int k = i + 1; k <= n; k++){
			if(e[i].calculate_salary() < e[k].calculate_salary()){
				Employee temp;
				temp.empcopy(e[i]);
				e[i].empcopy(e[k]);
				e[k].empcopy(temp);
			}
		}
	}
}

int main(){
	int boolean, n, seq, k, p = 1;
	char ner[20];
	char tushaal[10];
	float worked_hour;
	float hour;
	Employee emp[100];
	cout<<"Хэдэн ажилчин оруулах вэ?"<<"\n";
	cin>>n;
	for(int i = 1; i <= n; i++){
		emp[i].set_first_values();
	}
	while(1){
		cout<<"_________________ \n1. Ажилчин бүртгэх \n";
		cout<<"2. Цалин харах \n";
		cout<<"3. Ажилласан цагийг нэмэх \n";
		cout<<"4. Ажилчиний мэдээлэл харах \n";
		cout<<"5. Ажилчидийг цалингаар нь бүлэглэх \n";
		cout<<"6. Бүх ажилчидийн мэдээллийг харах \n";
		cout<<"7. Гарах \n_________________ \n";
		cin>>k;
		switch(k){
			case 1:
				cout<<"Дугаар оруулна уу: ";
				cin>>seq;
				cout<<"Нэрийг оруулна уу: ";
				cin>>ner;
				cout<<"Албан тушаалыг оруулна уу: ";
				cin>>tushaal;
				cout<<"Ажилласан цагийг оруулна уу: ";
				cin>>worked_hour;
				emp[p].get_values(seq, ner, tushaal, worked_hour);
				break;
			case 2:
				cout<<"Ажилчиний дугаарыг оруулна уу: "<<"\n";
				cin>>k;
				cout<<"Ажилчиний нэр: "<<emp[k].get_name()<<"\n"<<"Албан тушаал: "<<emp[k].get_job()<<"\n"<<"Цалин: "<<emp[k].calculate_salary()<<"\n";
				break;
			case 3:
				cout<<"Ажилчиний дугаарыг оруулна уу: "<<"\n";
				cin>>k;
				cout<<"Хэдэн цаг нэмэх вэ? ";
				cin>>hour;
				boolean = emp[k].add_work_hour(hour);
				if(boolean = 1){
					cout<<"Ажилттай боллоо!!!!!"<<"\n";
				}else{
					cout<<"Ажилтгүй боллоо!!!!!\n";
				}
				break;
			case 4:
				cout<<"Ажилчиний дугаарыг оруулна уу: "<<"\n";
				cin>>k;
				emp[k].show();
				break;
			case 5:
				sortSalary(emp,n);
				break;
			case 6:
				for(int i = 1; i <= n; i++){
					cout<<"---------- \nДугаар: "<<emp[i].get_sequence()<<"\n"<<"Нэр: "<<emp[i].get_name()<<"\n"<<
					"Цалин: "<<emp[i].calculate_salary()<<"\n---------- \n";
				}	
				break;
			case 7:
				return 0;
				break;
		}
		p++;
	}
	return 0;
}
