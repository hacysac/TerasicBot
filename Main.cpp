#include <iostream>
#include "Spider.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    Spider spider;

	cout << "Spider Init" << endl;
	spider.Init();
	
	cout << "Spider Standup" << endl;	
	spider.Standup();

	cout << "Waiting for Command..." << endl;
	bool done = false;
	while (!done)
	{
		char cmd_chr;
		cout << "Enter Next Command: ";
		cin >> cmd_chr;
		
		switch (cmd_chr)
		{
			case 'f':
				cout << "CMD_FORDWARD" << endl;
				spider.MoveForward();
				break;
			case 'b':
				cout << "CMD_BACKWARD" << endl;
				spider.MoveBackward();
				break;
			case 'r':
				cout << "CMD_RIGHT" << endl;
				spider.TurnRight();
				break;
			case 'l':
				cout << "CMD_LEFT" << endl;
				spider.TurnLeft();
				break;
			case 'q':
				cout << "CMD_SQUARE" << endl;
				spider.WalkSquare(4);
				break;
			case 's':
				cout << "CMD_STOP" << endl;
				done = true;
				break;
			default:
				cout << "IDLE or UNKNOWN COMMAND" << endl;
				break;
		}
	}

	return 0;
}
