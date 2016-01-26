// MAIN.CPP

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

/* Created by: 	Chermine
 * Date: 		Created				08:00PM, Monday, 9/18/15
 *				Added menu			11:00PM, Monday, 11/23/15
 *				Added write event	12:00PM, Monday, 12/28/15
 *
 * Description:
 * Takes in some event information and prints that event.
 * Recalls previously saved events.
 * 
 * Future functionality:
 * Reads and writes events from text file. Events kept in vector.
 * Treated as linked list using vector iterators.
 * (DEV Q: Why vector iterators?
 *	So we can pop off the top of our list easily, but also delete
 *	members of the list more fluidly. (Look at the vector vs
 *  linked list and such stuff from 280/281 for complexities))
 * Sorts by name, date, love, priority, nerves, and several
 * algorithms that determine which event should be completed first.
 *
 * Ability to add to and pop off events.
 * 
 * Futher ambitious uptakings:
 * Warnings for when events are coming near.
 * 
 * 
 * Dev NOTES:
 *		-fix string to num stuff
 *		-
 *
 *
 */ 
struct Event {
	string name;
	string date;
	string love;
	string priority;
	string nerves;
};

static void printEvent(Event event) {
	printf("%s:\nDue: %s\n\tLove: %s\n\tPriority: %s\n\tNerves: %s\n",
			event.name.c_str(), event.date.c_str(), event.love.c_str(), event.priority.c_str(), event.nerves.c_str());
}

static int isNum(string str) {
	for (unsigned long i = 0; i < str.length(); ++i) {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			str.erase(str.begin()+i);
		}
	}
	if (str.empty()) {
		return -1;
	}
	return stoi(str);
}

static int menu() {
	string input;

	int num = -1;
	
	printf("Welcome to the Ultimate Sort Machine!\n\r\n");
	printf("We sort your events and to dos so you don't have\n");
	printf("to decide what to do next.\n\n");
	while (1) {
		printf("What would you like to do? Choose an option. (Irony)\n");
		printf("\t1. Add an event.\n\r");
		printf("\t2. See my saved events.\n\r");
		getline(cin, input);

		// Limit the user to only
		// being able to enter numbers for this section.
		// Implement for later numbers too.
		
		if (input.length() > 2 ||
			(input[0] >= 'a' && input[0] <='Z') ||
			(input[1] >= 'a' && input[1] <='Z')) {
			num = stoi(input);
		} else {
			// try again
			printf("Please type a number shown above.\n\r");
		}
		if (num != 1 && num != 2) {
			printf("Please type a number shown above.\n\r");
		} else if (input == "exit") {
			printf("Closing the Ultimate Sort Machine!\n\r");
			exit(0);
		} else {
			break;
		}
	}
	return num;
}

int main(int argc, char* argv[]) {
	int op = menu();
	ifstream infile;
	ofstream outfile;
	Event event;

	if (op == 1) {
		//add event
		printf("What is the event name?\n");
		getline(cin, event.name);
		printf("What is the event date?\n");
		getline(cin, event.date);
		printf("How much do you love this event?\n");
		getline(cin, event.love);
		printf("What priority does the event have?\n");
		getline(cin, event.priority);
		printf("How nervous will this make you if you hold off on the event?\n");
		getline(cin, event.nerves);
		outfile.open("test.txt");
		while (!outfile.eof()) {
			// get to end of file.
			outfile;
		}
		outfile << event.name << "\n";
		//outfile << event.date << "\n";
		//outfile << event.love << "\n";
		//outfile << event.priority << "\n";
		//outfile << event.nerves << "\n";
		printf("Event saved.\n");

	} else if (op == 2) {
		//view saved events
		infile.open("test.txt");
		getline(infile, event.name);
		getline(infile, event.date);
		getline(infile, event.love);
		getline(infile, event.priority);
		getline(infile, event.nerves);
		printEvent(event);
	} else {
		printf("error: op not recognized.\n");
		exit(1);
	}


	/*cout << "Enter event name: ";
	getline(cin, event.name);
	cout << "Enter the date this event occurs: ";
	getline(cin, event.date);
	cout << "On a scale of 0 to 10:\n\n"
		 << "How much do you love this event? ";
	getline(cin, event.love);
	cout << "What priority is this? ";
	getline(cin, event.priority);
	cout << "How nervous will this make you if you hold off on it? ";
	getline(cin, event.nerves);

	cout << "\n\nSo, the event you just entered is:\n";*/
	//printEvent(event);
	

	return 0;
}
