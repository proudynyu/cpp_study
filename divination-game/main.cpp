#include <iostream>

using namespace std;

int main()
{
	cout << "**********************************" << endl;
	cout << "*                                *" << endl;
	cout << "* Welcome to the Divination Game *" << endl;
	cout << "*                                *" << endl;
	cout << "**********************************" << endl;

	cout << endl;
	cout << "Let's see, what dificult you wanna play?" << endl;

	int nDificult = 1;
	int nChoiceDificult;
	cout << "1: Easy" << endl;
	cout << "2: Medium" << endl;
	cout << "3: Hard" << endl;
	cin >> nChoiceDificult;

	switch (nChoiceDificult)
	{
	case 1:
		nDificult = 10;
		break;
	case 2:
		nDificult = 100;
		break;
	case 3:
		nDificult = 1000;
		break;
	default:
		nDificult = 10;
		break;
	}

	system("pause");
	const int nGuestNumber = rand() % nDificult;

	bool loop = true;
	int choices = 0;
	double dScore = 1000.0f;

	while (loop)
	{
		system("cls");
		int nInputNumber;
		cout << "What's your hint? (0 to";
		cout << nDificult;
		cout << ") \tScore:" << dScore << endl;
		cout << ">> ";
		cin >> nInputNumber;

		if (nInputNumber == nGuestNumber)
		{
			loop = false;
			break;
		}
		else if (nInputNumber < nGuestNumber)
			cout << "A little more :D" << endl;
		else
			cout << "A little less 0.0" << endl;

		dScore = dScore - abs(nGuestNumber - nInputNumber) / 2.0;
		choices++;
		system("pause");
	}

	system("cls");
	cout << "Congratulations!" << endl;
	cout << "Your hint was correct in " << choices << "!" << endl;
	cout.precision(2);
	cout << fixed;
	cout << "Your score is: " << dScore << endl;
}