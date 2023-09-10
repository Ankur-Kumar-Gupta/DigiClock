#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <sstream>
#include <conio.h>
#include <windows.h>

using namespace std;

class DigitalClock {
public:
    string displayTime() {
    	
    	clearScreen();
    	updateTime();
    	
        // Convert the time to a local time structure
        struct tm* timeInfo = localtime(&currentTime);
        
        stringstream ss;

        // Display the current local time in HH:MM:SS format
        ss << setw(2) << setfill('0') << timeInfo->tm_hour << ":"
                  << setw(2) << setfill('0') << timeInfo->tm_min << ":"
                  << setw(2) << setfill('0') << timeInfo->tm_sec << endl;
                  return ss.str();
    }

private:
    void updateTime() {
        // Get the current system time
        currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    }

    void clearScreen() {
        // Clear the console screen (platform-dependent)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    time_t currentTime;
};

void ascii_art(string input)
{
    for (int i=0; i < input.size(); i++)
    {
        if (input[i] == '1')
            cout<<" __   ";
        if (input[i]== '2')
            cout<<" _____  ";
        if (input[i]== '3')
            cout<<" _____  ";
        if (input[i] == '4')
            cout<<"   ___  ";
        if (input[i] == '5')
            cout<<" _____  ";
        if (input[i] == '6')
            cout<<"  ____  ";
        if (input[i] == '7')
            cout<<" ______ ";
        if (input[i] == '8')
            cout<<" _____  ";
        if (input[i] == '9')
            cout<<" _____  ";
        if (input[i] == '0')
            cout<<" _____  ";
        if (input[i] == ':')
            cout<<"    ";
    }
    cout<<endl;
    for (int i=0; i < input.size(); i++)
    {
        if (input[i] == '1')
            cout<<"/  |  ";
        if (input[i]== '2')
            cout<<"/ __  \\ ";
        if (input[i]== '3')
            cout<<"|____ | ";
        if (input[i] == '4')
            cout<<"  /   | ";
        if (input[i] == '5')
            cout<<"|  ___| ";
        if (input[i] == '6')
            cout<<" / ___| ";
        if (input[i] == '7')
            cout<<"|___  / ";
        if (input[i] == '8')
            cout<<"|  _  | ";
        if (input[i] == '9')
            cout<<"|  _  | ";
        if (input[i] == '0')
            cout<<"|  _  | ";
        if (input[i] == ':')
            cout<<" _  ";
    }
    cout<<endl;
    for (int i=0; i < input.size(); i++)
    {
        if (input[i] == '1')
            cout<<"`| |  ";
        if (input[i]== '2')
            cout<<"`' / /' ";
        if (input[i]== '3')
            cout<<"    / / ";
        if (input[i] == '4')
            cout<<" / /| | ";
        if (input[i] == '5')
            cout<<"|___ \\  ";
        if (input[i] == '6')
            cout<<"/ /___  ";
        if (input[i] == '7')
            cout<<"   / /  ";
        if (input[i] == '8')
            cout<<" \\ V /  ";
        if (input[i] == '9')
            cout<<"| |_| | ";
        if (input[i] == '0')
            cout<<"| |/' | ";
        if (input[i] == ':')
            cout<<"(_) ";
    }
    cout<<endl;
    for (int i=0; i < input.size(); i++)
    {
        if (input[i] == '1')
            cout<<" | |  ";
        if (input[i]== '2')
            cout<<"  / /   ";
        if (input[i]== '3')
            cout<<"    \\ \\ ";
        if (input[i] == '4')
            cout<<"/ /_| | ";
        if (input[i] == '5')
            cout<<"    \\ \\ ";
        if (input[i] == '6')
            cout<<"| ___ \\ ";
        if (input[i] == '7')
            cout<<"  / /   ";
        if (input[i] == '8')
            cout<<" / _ \\  ";
        if (input[i] == '9')
            cout<<"\\____ | ";
        if (input[i] == '0')
            cout<<"|  /| | ";
        if (input[i] == ':')
            cout<<"    ";
    }
    cout<<endl;
    for (int i=0; i < input.size(); i++)
    {
        if (input[i] == '1')
            cout<<"_| |_ ";
        if (input[i]== '2')
            cout<<"./ /___ ";
        if (input[i]== '3')
            cout<<".___/ / ";
        if (input[i] == '4')
            cout<<"\\___  | ";
        if (input[i] == '5')
            cout<<"/\\__/ / ";
        if (input[i] == '6')
            cout<<"| \\_/ | ";
        if (input[i] == '7')
            cout<<"./ /    ";
        if (input[i] == '8')
            cout<<"| |_| | ";
        if (input[i] == '9')
            cout<<".___/ / ";
        if (input[i] == '0')
            cout<<"\\ |_/ / ";
        if (input[i] == ':')
            cout<<" _  ";
    }
    cout<<endl;
    for (int i=0; i < input.size(); i++)
    {
        if (input[i] == '1')
            cout<<"\\___/ ";
        if (input[i]== '2')
            cout<<"\\_____/ ";
        if (input[i]== '3')
            cout<<"\\____/  ";
        if (input[i] == '4')
            cout<<"    |_/ ";
        if (input[i] == '5')
            cout<<"\\____/  ";
        if (input[i] == '6')
            cout<<"\\_____/ ";
        if (input[i] == '7')
            cout<<"\\_/     ";
        if (input[i] == '8')
            cout<<"\\_____/ ";
        if (input[i] == '9')
            cout<<"\\____/  ";
        if (input[i] == '0')
            cout<<" \\___/  ";
        if (input[i] == ':')
            cout<<"(_) ";
    }
    cout<<endl;
}

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 252);
    DigitalClock clock;
    try {
        while (true) {
            string input = clock.displayTime();
            ascii_art(input);

            this_thread::sleep_for(chrono::seconds(1));
        }
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}

