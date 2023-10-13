#include "Array.h"
#include "Queue.h"
#include "Stack.h"
#include <iomanip>
#include <fstream>
#include<cstring>
#include<cstdlib> //Only for Clear Screen

#define _CRT_SECURE_NO_WARNINGS //trying to resolve a time error
int main()
{
	/*auto t = std::time(nullptr);
	auto tm = *std::localtime_s(&t);*/
	//put_time(&tm, "%d-%m-%Y %H-%M-%S");
	struct tm newtime;
	time_t t = time(NULL);
	localtime_s(&newtime, &t);
	string log = "Log" + localtime_s(&newtime, &t);
	ofstream logFile;
	logFile.open(log);
	
	logFile << "Log file started at process time: " << localtime_s(&newtime, &t) << endl;
	//prompt
PROMPT:
	string path = "apple-18.pgm", input = " ";
	cout << "Enter File name (for testing use apple-18.pgm):  " << endl;
	cin >> path;
	try
	{
		ifstream file(path);
		if (file)
		{
			cout << "File found..." << endl;
			file.close();
		}
		else
			throw(path);
	}
	catch (string Incorrectpath)
	{
		cout << "Incorrect File Name" << endl;
		goto PROMPT;
	}
	int height, length=0;
	ifstream file;
	file.open(path);
	cout << "Reading File..." << endl;
	for (int i = 0; i < 7; i++) {

		file >> input;
		if (i == 7 - 1)
		{
			length = stoi(input);//stoo -> string to integer func
		}
		else if (i == 7 - 2)//      ^
		{
			height = stoi(input);
		}		
	} //reading file for dimensions
	file.close();

	logFile << "Piucture made at time: " << localtime_s(&newtime, &t) << endl;
	Picture pic(length, height);
	pic.Read(path);

	//Everything above is for  implementation of the questoins.
	//The file to be manipulated will be asked for first, then we will extract size
	//Read it and retrurn as the opject "pic"

	int QuestionNumber = 0;
	char QuestionPart = ' ';
LABEL:
	logFile << "terminal started at: " << localtime_s(&newtime, &t) << endl;
	system("CLS");
	cout << "Welcome to 21i_1679's AKA Ibrahim Akhtars(Mine) Implementatino of Assignment Module 1" << endl;
	cout << "1: Statistics of the Image.\n2: Component Extraction from Queue.\n3: Component Extraction from Stack."<< endl;
	cout << "Enter the question number you wish to view (1,2,3): " << endl;
	cin >> QuestionNumber;
	switch (QuestionNumber)
	{
	//Question 1
	case 1:
	{

		logFile << "Question 1: " << localtime_s(&newtime, &t) << endl;
		cout << "a) Mean pixel value by adding all the pixel values and dividing it by the no. of pixels\n"
			<< "b) The number of blackand no.of white pixels.\n"
			<< "c) The average no.of black pixels in each row." << endl;
		cout << "Enter option (a,b,c,d): " << endl;
		cin >> QuestionPart;
		switch (QuestionPart)
		{
		case 'A':
		{
			
		}
		case 'a':
		{

			logFile << "Question1 part a: " << localtime_s(&newtime, &t) << endl;
			cout << pic.mean();
			break;
		}
		case 'B':
		{
			
		}
		case 'b':
		{
	
			logFile << "Question1 part b: " << localtime_s(&newtime, &t) << endl;
			cout << "No. of Balck Pixels: " << pic.noBlackPixels()<< endl;
			cout << "No. of WHite Pixels: " << pic.noWhitePixels() << endl;
			break;
		}
		case 'C':
		{

		}
		case 'c':
		{

			logFile << "Question1 part c: " << localtime_s(&newtime, &t) << endl;
			int * Average = pic.RowAverage();
			for (int i = 0; i < height; i++)
				cout << Average[i] << endl;
			break;
		}
		case 'D':
		{

		}
		case 'd':
		{
			logFile << "Question1 part d: " << localtime_s(&newtime, &t) << endl;
			Picture* NegativePic = pic.ConvertToNegative();
			cout << "Object of type ptr->Picture named NegativePic has been made containing the Negative of " << path << " ." << endl;
			break;
		}
		default:
		{

			logFile << "Incorrect option entered: " << localtime_s(&newtime, &t) << endl;
			cout << "Incorrect option number: " << endl;
			goto LABEL;
		}
		}
		
	}
	//Question 2
	case 2:
	{

		logFile << "Question2: " << localtime_s(&newtime, &t) << endl;
		Queue q(length * height);
		cout << "Main Implementation of this code is currently in development\n"
			<< "However Queue.cpp and Queue.h is in the code as of now and functional"
			<<"The entire image can be found enqueued in the queue named 'q'"<< endl;
		break;
	}
	//Question 3
	case 3:
	{

		logFile << "Question3: " << localtime_s(&newtime, &t) << endl;
		Stack s(length * height);
		cout << "Main Implementation of this code is currently in development\n"
			<< "However Stack.cpp and Queue.h is in the code as of now and functional"
			<< "The entire image can be found pushed in the stack named 's'" << endl;
		break;
	}
	//Question Number Incorrect
	default:
	{

		logFile << "Incorrect question number: " << localtime_s(&newtime, &t) << endl;
		cout << "Kindly enter a valid question number." << endl;
		goto LABEL;
	}
	}
}

