#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void welcomeInfo();
int setInterval();
int setDuration();
void playBeeps(int intBeep, int numBeep);
char readyPrompt(int beepInt, int beepNum);
char goAgain();


int main() {
	int interval = 0, duration = 0;
	
	do {
		welcomeInfo();
		interval = setInterval();
		duration = setDuration();
		playBeeps(interval, duration);	
	} while(goAgain() == 'y');
	
	return 0;
}

void welcomeInfo(){
	cout << "Welcome to the Windows Tone Generator!\n"
		 << "This program plays a sound at a regular interval.\n"
		 << "You can set the interval and the total number of tones!\n"
		 << endl;		
}

int setInterval(){
	int interval;
	cout << "\nPlease enter an interval in seconds (full seconds only): ";
	cin >> interval;
	return interval;
}

int setDuration(){
	int duration;
	cout << "\nPlease enter the total number of tones you wish to play: ";
	cin >> duration;
	return duration;
}

void playBeeps(int intBeep, int numBeep){
	int curBeep = 0;
	int lenBeep = 500;	
	int toneBeep = 500;
	if (readyPrompt(intBeep, numBeep) == 'y'){
		//Play the first beep after a full wait time
		Sleep(intBeep * 1000);
		Beep(toneBeep, lenBeep);
		curBeep++;
		//Play middle beeps with wait time less beep time
		do {
			Sleep(intBeep * 1000 - lenBeep);
			Beep(toneBeep, lenBeep);
			curBeep++;
		} while (curBeep < numBeep - 1);
		//Play last beep extra long
		Sleep(intBeep * 1000 - lenBeep);
		Beep(toneBeep, 2 * lenBeep);		
	}
	else {
		return;
	}
}

char readyPrompt(int beepInt, int beepNum){
	string responseRaw;
	char response;
	cout << "\nAre you ready to play " << beepNum << " tones at a " 
		 << beepInt << " second interval, \nfor a total of " << beepNum * beepInt
		 << " seconds (" << beepNum * beepInt / 60. << " minutes)? [y/n]: ";
	cin >> responseRaw;
	response = tolower(responseRaw.at(0));
	return response;	 
}

char goAgain(){
	string responseRaw;
	char response;
	cout << "\nYour timer has ended. Would you like to start another? [y/n]: ";
	cin >> responseRaw;
	cout << endl  << "========================================" << endl << endl;
	response = tolower(responseRaw.at(0));
	return response;
}
