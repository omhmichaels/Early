/*
 *
 * # Title: Arrays and Vectors
 * # Description:
 * # Author: Michael Martin
 * # Class: COMPSCI 1
 * # 4-15-19
 */


#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int NUM_CTRY = 5;             // Num countries supported
vector<string> ctryNames(NUM_CTRY); // Country names
vector<int>    ctryMins(NUM_CTRY);  // Mins TV watched daily

bool continueFlag;
class getInput {

public:
	string input;
	int data;

	string basePrompt = "Please enter Country Name or applicable command: \n";
	string printDataPrompt = "The country %s current average is %i mins of TV\n";
	string updatedPrompt = "The watch time values for the country %s have been updated to %i mins\n";
	string deletedPrompt = "The watch time value %i mins for the country %s have been deleted\n";
	string continuePrompt = " Would you like to continue? y/n  \n";
	string countryPrompt = "Please enter the country: \n";
	string minutesPrompt = "Please enter the minutes: \n";

	string getString() {
		cin >> input;
		return input;
	}
		
	
	int getInt() {
		cin >> data;
		return data;
	}
};

getInput userInput;

class UI {



public:
	int getMins() {
		cout << userInput.minutesPrompt;
		int mins = userInput.getInt();
		return mins;
	}

	string getCountry() {
		cout <<userInput.countryPrompt;
		string country = userInput.getString();
		return country;
	}
	/*
	void postUpdate() {
		printf(userInput.updatedPrompt, userInput.input data);
	}

	void postDelete() {
		printf(userInput.deletedPrompt, userInput.data, userInput.input);
	}*/
	/*
	void printData() {
		printf(userInput.basePrompt);
		cout << userInput.printDataPrompt, userInput.input, userInput.data;
	}
	*/
	void promptContinue() {
		cout << userInput.continuePrompt;
	}
	void promptBase() {
		cout << userInput.basePrompt;
	}
};

UI interface;

class Commands  {

public:

	
	bool commandFlag;

	void addData(string input, int data) {
		ctryNames.push_back(input);
		ctryMins.push_back(data);
		cout << "You added data for " << input << " with the value " << data << endl;
		NUM_CTRY++;
		commandFlag = true;
	}


	/*
	/*
	void deleteData(string input) {
		for (int i = 0; i < NUM_CTRY; ++i) {
			if (ctryNames.at(i) == input) {
				ctryNames.erase(remove(ctryNames.begin(), ctryNames.end(), input), ctryNames.end());
				ctryMins.erase(remove(ctryNames.begin(), ctryNames.end(), input), ctryNames.end());
				cout << "You deleted data for " << input;
				NUM_CTRY--;
			}
		}
		commandFlag = true;
	}

	*/

	void deleteData(string input) {
		for (int i = 0; i < NUM_CTRY; ++i) {
			if (ctryNames.at(i) == input) {
				ctryNames.erase(ctryNames.begin() +i);
				ctryMins.erase(ctryNames.begin()+ i);
				cout << "You deleted data for " << input;
				NUM_CTRY--;
			}
		}
		commandFlag = true;
	}
	void modData(string input, int data) {

		for (int i = 0; i <NUM_CTRY; ++i) {
			if (ctryNames.at(i) == input) {
				ctryMins.at(i) = data;
				cout << "You modified the data for " << input << " with the value " << data << endl;
			}
		}
		commandFlag = true;
	}

};


void initialData() {

	// Define vector contents
	ctryNames.at(0) = "China";
	ctryMins.at(0) = 158;

	ctryNames.at(1) = "India";
	ctryMins.at(1) = 119;

	ctryNames.at(2) = "Russia";
	ctryMins.at(2) = 226;

	ctryNames.at(3) = "UK";
	ctryMins.at(3) = 242;

	ctryNames.at(4) = "USA";
	ctryMins.at(4) = 283;
}

// Not Found
void notFound(bool flag) {
	if (!flag) {
		cout << "Country/Command not found; try again." << endl;
	}
}


// Time Conversion
void timeConversion(int iterator) {
	int minutes = ctryMins.at(iterator);
	int hrs = minutes / 60;
	int mins = minutes % 60;
	printf(" watches %i hours and %i mins of TV daily.\n", hrs, mins);
}

void printCountry(int iterator) {
	cout << ctryNames.at(iterator);
	timeConversion(iterator);
}


// Max Command Try 5308450981]

void maxCommand() {
	int max = 0;
	string country;
	for (int i = 0; i < NUM_CTRY; ++i) {
		int mins = ctryMins.at(i);
		if (mins > max) {
			max = mins;
			country = ctryNames.at(i);
		}
	}
	cout << country << " watches the most tv at " << max << " mins \n";
}

// PRINT COMMAND
void printCommand() {
	cout << "Now printing all countries data \n\n";
	for (int i = 0; i < NUM_CTRY; ++i) {
		printCountry(i);
	}
}




bool commandCheck(string input) {
	Commands cmd;
	bool commandFlag;
	cout << input << endl;
	if (input == "PRINT") {
		
		printCommand();
		commandFlag = true;
	}
	else if (input == "MAX") {
		maxCommand();
		commandFlag = true;
	}
	else if (input == "ADD") {
		interface.getCountry();
		interface.getMins();
		cmd.addData(userInput.input, userInput.data);
		printCommand();
		commandFlag = true;
	}
	else if (input == "DEL"	) {
		userInput.getString();
		cmd.deleteData(userInput.input);
		commandFlag = true;
	} 
	else if (input == "MOD") {
		interface.getCountry();
		interface.getMins();
		cmd.modData(userInput.input, userInput.data);
		printCommand();
		commandFlag = true;
	}
	if (commandFlag==true) {
		return true;
	}
	else if (commandFlag == false) {
		return false;
	}
}


bool checkCountry(string input) {
	bool foundFlag = false;
	for (int i = 0; i < NUM_CTRY; ++i) {
		if (ctryNames.at(i) == input) {
			// Part one continued 			
			printCountry(i);
			foundFlag = true;
		}
	}
	notFound(foundFlag);
	return foundFlag;
}

 bool continueLogic() {
	interface.promptContinue();
	userInput.getString();
	string input = userInput.input;
	if (input == "y") {
		return true;
	}
	else if (input == "n") {
		cout << "SEEE YA";
		return false;
	}
	else {
		continueLogic();
	}
}

bool appLogic() {

	initialData();

	string cmd = interface.getCountry();

	bool commandFlag = commandCheck(cmd);

	if (commandFlag == false) {
		commandFlag = checkCountry(cmd);
	}
	if (commandFlag == false){
		printCommand();
	}
	return commandFlag = continueLogic();
	
}




int main() {
	bool flag = true;
	while (flag == true){
		return flag = appLogic();
	}
	return 0;
}

// MESS UPS

/*/ Fruitless attempt to get this to work differently
struct Commands {
	vector<string> ctryNames; // Country names
	vector<int>    ctryMins;  // Mins TV watched daily
};


// EXTRA NOT YET FUNCTIONAL Define vector contents
vector<string> cityNameData() {   // Add vector paramater or pointer in future
	vector<string> name;
	name.at(0) = "China";
	name.at(1) = "India";
	name.at(2) = "Russia";
	name.at(3) = "UK";
	name.at(4) = "USA";
	return name;
}
*/
/*/ COMMAND BASE Migrate to class usage in future
struct countryData {
	string country;
	int maxMins;
};

countryData maxCommandLogic(int iterator) {
	int max;
	string country;
	if (ctryMins.at(iterator) > ctryMins.at(iterator-1)) {
		 max = ctryMins.at(iterator);
		 country = ctryNames.at(iterator);
		}
	return countryData { country, max };
}



// MAX COMMAND
void maxCommand() {
	for (int i = 0; i < NUM_CTRY; ++i) {
		countryData maxData = maxCommandLogic(i);
		cout << maxData.country << " watches the most tv at " << maxData.maxMins << "mins \n";
	}

}
*/