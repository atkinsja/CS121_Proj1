//***********************************************************
//
// Programmer:		Jeremy Atkins
// Instructor		Professor Mackay
// Course:			CS 121
// Date:			3/14/2018
// Program Name:	Project_1
// Program file:	Project_1.cpp
// Input files:		proj1data.txt
// Output Files:	Atkins_Jeremy_proj1results.txt
// Included files:	Project_1.cpp, proj1data.txt
// Purpose:			Open given file, parse file for relevent
//					data while discarding junk, then output
//					results into another file
//
//***********************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	ifstream input_file;												//input file
	ofstream output_file;												//output file
	istringstream input_file_stream;									//converted string to stream
	string input_string, justify_string, output_string;					//input as a string, left or right as a string, string to output
	string input_file_name = "proj1data.txt";							//name of input file
	string output_file_name = "Atkins_Jeremy_proj1results.txt";			//name of output file
	
	int fill_int, field_width;											//fill character integer, field width
	char justify_char, fill_char;										//left or right as a char, fill character as a character
	
	input_file.open(input_file_name);									//opens input file
	output_file.open(output_file_name);									//opens output file

	if (input_file.is_open())											//if input file is open
	{
		while (getline(input_file, input_string))						//gets data from file line by line, stores in input_string
		{
			input_file_stream.str("");									//clears input stream to start loop
			input_file_stream.clear();

			input_file_stream.str(input_string);						//converts input_string into a data stream

			input_file_stream >> fill_int;								//gets the fill character stored as its ASCII integer value
			input_file_stream.ignore(1000, ' ');						//skips 1000 characters or until a blank space is found to remove junk

			input_file_stream >> field_width;							//gets the field width stored as an integer
			input_file_stream.ignore(1000, ' ');						//skips 1000 characters or until a blank space is found to remove junk

			input_file_stream >> justify_char;							//gets the justification character
			input_file_stream.ignore(1000, ' ');						//skips 1000 characters or until a blank space is found to remove junk

			getline(input_file_stream, output_string);					//gets the final string to be output

			fill_char = static_cast<char> (fill_int);					//gets the character at the integer value of fill_int

			//converts the justification character to a string that can be used
			if (justify_char == 'r' || justify_char == 'R')				//if justification is right
				justify_string = "right";
			else if (justify_char == 'l' || justify_char == 'L')		//if justification is left
				justify_string = "left";
			else                                                        //if justification data is left or right
				justify_string = "Invalid justification data";

			//outputs the results to output_file
			if (output_file.is_open())									//if output file is open
			{
				output_file << "With a fill character of: " << fill_char << "," << endl;		//fill character
				output_file << "a field width of: " << field_width << "," << endl;				//field width
				output_file << "a justification of: " << justify_string << "," << endl;			//justification
				output_file << "and the string: " << output_string << endl;						//output string

				//changes results according to justification
				if (justify_char == 'r' || justify_char == 'R')			//if justification is right
					output_file << "\nThe output is: " << setfill(fill_char) << setw(field_width) << right << output_string << endl;
				else if (justify_char == 'l' || justify_char == 'L')	//if justification is left
					output_file << "\nThe output is: " << setfill(fill_char) << setw(field_width) << left << output_string << endl;
				else                                                    //if justification data is not left or right
					output_file << "\nThe output is: " << setfill(fill_char) << setw(field_width) << justify_string << output_string << endl;

				output_file << endl << endl << endl;					//new lines between each set of output
			}
			else                                                        //output file cannot be opened
			{
				cout << "Cannot open output file." << endl;
				return -1;
			}
		}//end while

		input_file.close();												//closes the input file
		output_file.close();											//closes the output file
	}
	else                                                                //input file cannot be opened
	{
		cout << "Cannot open input file." << endl;
		return -1;
	}

	cout << output_file_name << " written successfully." << endl;				//tells user the output file was written
	return 0;
}