/* This is a daily planner. The planner is based on a menu system and runs within the console. 
 * Created by: claycot
 */

#include "stdafx.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void drawMenu();
void handleAction(int selectionNumber, string planner[]);
void drawPlanner(string planner[]);
void addEvent(string planner[]);
void deleteEvent(string planner[]);
void clearPlanner(string planner[]);
void savePlanner(string planner[]);
void loadPlanner(string planner[]);
char loopYesNo();

int main() {
	int actionNumber;
	string dailyPlanner[25];
	cout << "Welcome to your daily planner! Please numerically select an option. " << endl;
	do {
		drawMenu();
		cin >> actionNumber;
		handleAction(actionNumber, dailyPlanner);
		cout << endl;
	} while (loopYesNo() == 'y');

	return 0;
}

void drawMenu() {
	cout << "[1]\t View the current planner. \n"
		 << "[2]\t Add an event to the planner. \n"
		 << "[3]\t Delete an event from the planner. \n"
		 << "[4]\t Clear the planner. \n"
		 << "[5]\t Save the current planner. \n"
		 << "[6]\t Load a planner from file. \n";
}

void handleAction(int selectionNumber, string planner[]) {
	if (selectionNumber == 1) {
		drawPlanner(planner);
	}
	else if (selectionNumber == 2) {
		addEvent(planner);
	}
	else if (selectionNumber == 3) {
		deleteEvent(planner);
	}
	else if (selectionNumber == 4) {
		clearPlanner(planner);
	}
	else if (selectionNumber == 5) {
		savePlanner(planner);
	}
	else if (selectionNumber == 6) {
		loadPlanner(planner);
	}
}

void drawPlanner(string planner[]) {
	cout << "TODAY'S PLANNER\n"
		<< "============================================"
		<< endl;

	for (int i = 1; i <= 24; i++) {
		if (i < 12) {
			cout << setw(2) << i << ":00 AM\t" << planner[i] << "\n";
		}
		else if (i == 12) {
			cout << i << ":00 PM\t" << planner[i] << "\n";
		}
		else if (i > 12) {
			cout << setw(2) << i - 12 << ":00 PM\t" << planner[i] << "\n";
		}
	}
	cout << "============================================"
		 << endl;
}

void addEvent(string planner[]) {
	int time;
	string event;

	cout << "For what time would you like to add an event?\n"
		<< "Please enter an integer between 1 and 24." << endl;
	cin >> time;

	cout << "What would you like to plan for ";
	if (time < 12) {
		cout << time << ":00 AM?" << endl;
	}
	else if (time == 12) {
		cout << time << ":00 PM?" << endl;
	}
	else if (time > 12 && time <= 24) {
		cout << time - 12 << ":00 PM?" << endl;
	}
	cin >> ws;
	getline(cin, event);

	planner[time] = event;
}

void deleteEvent(string planner[]) {
	int time;
	cout << "For what time would you like to delete an event?\n"
		 << "Please enter an integer between 1 and 24." << endl;
	cin >> time;

	planner[time] = "";
}

void clearPlanner(string planner[]) {
	string clearYN;
	cout << "Are you sure that you wish to clear your planner? [y/n]\n";
	cin >> clearYN;

	if (clearYN == "y" || clearYN == "Y") {
		for (int i = 1; i <= 24; i++) {
			planner[i] = "";
		}
		cout << "Your planner has been cleared.\n";
	}
	else {
		cout << "Your planner was not cleared.\n";
	}
}

void savePlanner(string planner[]) {
	ofstream out_file;
	out_file.open("your_daily_planner.txt");
	for (int i = 1; i <= 24; i++) {
		if (i < 12) {
			out_file << setw(2) << setfill('0') << i << ":00 AM\t" << planner[i] << "\n";
		}
		else if (i == 12) {
			out_file << i << ":00 PM\t" << planner[i] << "\n";
		}
		else if (i > 12) {
			out_file << setw(2) << setfill('0') << i - 12 << ":00 PM\t" << planner[i] << "\n";
		}
	}

	out_file.close();
}

void loadPlanner(string planner[]) {
	ifstream in_file;
	in_file.open("your_daily_planner.txt");
	string rawLine;
	string event;
	string rawAMPM;
	int rawTime;
	int time;

	if (in_file.fail()) {
		cout << "The input file was not found. Please locate \"your_daily_planner.txt\"\n"
			 << "and try again.";
	}
	else {
		while (!in_file.eof()) {
			in_file >> ws;
			getline(in_file, rawLine);
			rawAMPM = rawLine.substr(6, 2);
			rawTime = stoi(rawLine.substr(0, 2), nullptr, 10);
			if (rawAMPM == "AM") {
				time = rawTime;
			}
			else if (rawAMPM == "PM" && rawTime == 12) {
				time = 12;
			}
			else if (rawAMPM == "PM" && rawTime != 12) {
				time = rawTime + 12;
			}
			event = rawLine.substr(9);

			planner[time] = event;
		}
	}
}

char loopYesNo() {
	string loopYN;
	cout << "Would you like to perform another action? [y/n]: ";
	cin >> loopYN;
	cout << endl << endl;
	if (loopYN == "y" || loopYN == "Y") {
		return 'y';
	}
	else {
		return 'n';
	}
}
