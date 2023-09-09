// Patel Tirth 
// Id: 172244212

#ifndef SDDS_EMPPROFILE_H
#define SDDS_EMPPROFILE_H

#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace sdds {
	struct Employee {
		std::string id;
		std::string name;
		bool load(std::ifstream& f) {
			f >> id >> name;
			return f.good();
		}

		void print(std::ostream& os) const {
			os << std::setw(10) << id << std::setw(7) << name << std::endl;
		}
	};

	struct Salary {
		std::string id;
		double salary;
		bool load(std::ifstream& f) {
			f >> id >> salary;
			return f.good();
		}

		void print(std::ostream& os) const {
			os << std::setw(10) << id << std::setw(10) << salary << std::endl;
		}
	};


	struct EmployeeWage {
		std::string name{};
		double n_salary{};
		int n_counter{};
		static int recCount;
		static bool Trace;

		EmployeeWage() {
			n_counter = ++recCount;
			if (Trace)
			{
				std::cout << "Default Constructor [" << n_counter << "]" << std::endl;
			}
		}

		EmployeeWage(const std::string& str, double sal)
		{
			this->name = str;
			this->n_salary = sal;
			n_counter = ++recCount;
			if (Trace)
			{
				std::cout << "Ovdrloaded Constructor" << std::setw(6) << "[" << n_counter << "]" << std::endl;
			}
		}

		EmployeeWage(const EmployeeWage& copyEmpProf) {
			this->name = copyEmpProf.name;
			this->n_salary = copyEmpProf.n_salary;
			n_counter = ++recCount;
			if (Trace)
			{
				std::cout << "Copy Constructor " << std::setw(11) << "[" << n_counter << "] from [" << copyEmpProf.n_counter << "]" << std::endl;
			}
		}

		~EmployeeWage() {
			if (Trace)
			{
				std::cout << "Destructor " << std::setw(17) << "[" << n_counter << "]" << std::endl;
			}
		}



		void rangeValid() {
			if (n_salary < 0 || n_salary > 99999) {
				throw std::string("*** Employees salaray range is not valid");
			}
		}


		void print(std::ostream& os)const {
			os << std::setw(15) << name << std::setw(10) << n_salary << std::endl;
		}

	};
}
#endif //SDDS_EMPPROFILE_H