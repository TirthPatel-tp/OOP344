// Patel Tirth 
// Id: 172244212
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		for (int i = 0; i < (int)emp.size(); i++) {
			for (int j = 0; j < (int)sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage* wage = new EmployeeWage(emp[i].name, sal[j].salary);

					try {


						wage->rangeValid();
					}
					catch (std::string& err) {
						delete wage;
						throw err;

					}
					activeEmp.sinValid(emp[i].id) ? activeEmp += wage : throw std::string("invalid sin");
					delete wage;
				}
			}
		}

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		for (int i = 0; i < (int)emp.size(); i++) {
			for (int j = 0; j < (int)sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					std::shared_ptr<EmployeeWage> wage(new EmployeeWage(emp[i].name, sal[j].salary));

					try {
						wage->rangeValid();
					}
					
					catch (std::string& err) {
						throw err;
					}

					activeEmp.sinValid(emp[i].id) ? activeEmp += wage : throw std::string("invalid sin");
				}
			}
		}

		return activeEmp;
	}
}