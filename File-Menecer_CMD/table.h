#pragma once
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void arrowHere_2(int realPosition, int arrowPosition) {
	if (realPosition == arrowPosition) {
		SetConsoleTextAttribute(console, 9);
		cout << " ----->>    ";
	}
	else {
		SetConsoleTextAttribute(console, 4);
		cout << "          ";
	}
}


void Name()
{
	SetConsoleTextAttribute(console, 12);


	const char* logo = R"V0G0N(

                                                                    
           _________ _____ _____    _________     ____    ____ _________ ____  _____ _________   ______ _________ _______    
          |_   ___  |_   _|_   _|  |_   ___  |   |_   \  /   _|_   ___  |_   \|_   _|_   ___  |./ ___  |_   ___  |_   __ \   
            | |_  \_| | |   | |      | |_  \_|     |   \/   |   | |_  \_| |   \ | |   | |_  \_| ./   \_| | |_  \_| | |__) |  
            |  _|     | |   | |   _  |  _|  _      | |\  /| |   |  _|  _  | |\ \| |   |  _|  _| |        |  _|  _  |  __ /   
           _| |_     _| |_ _| |__/ |_| |___/ |    _| |_\/_| |_ _| |___/ |_| |_\   |_ _| |___/ | \.___.'\_| |___/ |_| |  \ \_ 
          |_____|   |_____|________|_________|   |_____||_____|_________|_____|\____|_________|\._____.'_________|____| |___|
          
)V0G0N";

	cout << logo;
	cout << endl;
	SetConsoleTextAttribute(console, 7);
}

bool tree = false;
bool deleteFile = false;
bool deleteFolder = false;
bool renameFile = false;
bool renameFolder = false;
bool moveFile = false;
bool moveFolder = false;
bool creatFolder = false;
bool creatFile = false;
bool sortBySize = false;
bool sortByName = false;
bool openFile = false;
bool infoFile = false;
bool fileCopy = false;
bool exitt = false;

void AskToUser()
{
	cout << endl;
	int position = 1;
	int keyPressed = 0;

	while (keyPressed != 13)
	{
		system("cls");
		Name();
		SetConsoleTextAttribute(console, 11);
		cout << "\n\n\n\n\n\n";
		cout << "WELCOME CRAZY CMD. PRODUCTED BY NIHAD EMINOV" << endl;
		cout << "PLEASE,CHOICE FUNCTIONS" << endl;
		arrowHere_2(1, position);
		cout << "Print all files and subfolders in current folder\n";
		arrowHere_2(2, position);
		cout << "Delete selected file \n";
		arrowHere_2(3, position);
		cout << "Delete selected folder \n";
		arrowHere_2(4, position);
		cout << "Rename selected file \n";
		arrowHere_2(5, position);
		cout << "Rename selected folder \n";
		arrowHere_2(6, position);
		cout << "Move selected file \n";
		arrowHere_2(7, position);
		cout << "Move selected folder \n";
		arrowHere_2(8, position);
		cout << "Create new folder with specified name \n";
		arrowHere_2(9, position);
		cout << "Create empty file with specified name and extension \n";
		arrowHere_2(10, position);
		cout << "Organize files and subfolders by size \n";
		arrowHere_2(11, position);
		cout << "Organize files and subfolders by name \n";
		arrowHere_2(12, position);
		cout << "Open selected file in default app \n";
		arrowHere_2(13, position);
		cout << "Information selected file \n";
		arrowHere_2(14, position);
		cout << "Change selected folder (open new folder) \n";
		arrowHere_2(15, position);
		cout << "Exit \n";

		keyPressed = _getch();

		if (keyPressed == 80 && position != 15)
		{
			position++;
		}
		else if (keyPressed == 72 && position != 1)
		{
			position--;
		}
		else
		{
			position = position;
		}
	}

	switch (position)
	{
	case 1:
		SetConsoleTextAttribute(console, 7);
		tree = true;
		break;
	case 2:
		SetConsoleTextAttribute(console, 7);
		deleteFile = true;
		break;
	case 3:
		SetConsoleTextAttribute(console, 7);
		deleteFolder = true;
		break;
	case 4:
		SetConsoleTextAttribute(console, 7);
		renameFile = true;
		break;
	case 5:
		SetConsoleTextAttribute(console, 7);
		renameFolder = true;
		break;
	case 6:
		SetConsoleTextAttribute(console, 7);
		moveFile = true;
		break;
	case 7:
		SetConsoleTextAttribute(console, 7);
		moveFolder = true;
		break;
	case 8:
		SetConsoleTextAttribute(console, 7);
		creatFolder = true;
		break;
	case 9:
		SetConsoleTextAttribute(console, 7);
		creatFile = true;
		break;
	case 10:
		SetConsoleTextAttribute(console, 7);
		sortBySize = true;
		break;
	case 11:
		SetConsoleTextAttribute(console, 7);
		sortByName = true;
		break;
	case 12:
		SetConsoleTextAttribute(console, 7);
		openFile = true;
		break;
	case 13:
		SetConsoleTextAttribute(console, 7);
		infoFile = true;
		break;
	case 14:
		SetConsoleTextAttribute(console, 7);
		fileCopy = true;
		break;
	case 15:
		SetConsoleTextAttribute(console, 7);
		exitt = true;
		break;

	}
}

