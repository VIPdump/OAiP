#include "Students.h"

void Students::print(int i)
{
	cout << "(" << i << ")" << "\tFull Name : " << fname << "\tInitials : " <<  initials; //<< surname << " " << name << " " << lastname << "\tInitials : " << initials;
	cout << "\n\tYear: " << year << "\tGroup: " << group << "\n";
	cout << "\tEstimates: ";
	for (int i = 0; i < 4; i++) {
		cout << estim[i] << " ";
	}
	cout << "\n\tAverage estimate: " << est_aver << "\n\n\n";
}

double Students::score(int* estimates, int size)
{
	if (size == 1)
		return estimates[size - 1];
	return ((size - 1) * score(estimates, size - 1) + estimates[size - 1]) / size;
}

void Students::data()
{
	cout << "Write your full name ";	
	cin.ignore();
	getline(cin, fname);
	/*cin >> surname >> name >> lastname;*/

	cout << "Write your initials ";
	cin >> initials;

	cout << "Write your year ";
	cin >> year;

	cout << "Write your group ";
	cin >> group;

	cout << "Write your estimates for Physics, Chemistry, Mathematics, Computer science ";
	cin >> estim[0] >> estim[1] >> estim[2] >> estim[3];

	est_aver = score(estim, 4);
}
