#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#include "table.h"

//----------------------------------------------------------------------------------------------------------------------------//---
//--------------------------------------------------------For sort by size function------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------//---
struct FileInfo                                                                                                               //---
{																															  //---
	wstring name;																											  //---
	ULONGLONG size;																											  //---
	bool isFolder;																											  //---
};																															  //---
                                                                                                                              //---
bool CompareFileSize(const FileInfo& a, const FileInfo& b) 																	  //---
{																															  //---
	return a.size > b.size;																									  //---
}																															  //---
																															  //---
vector<FileInfo> GetFolderContents(const wstring& folderPath) 																  //---
{																															  //---
	vector<FileInfo> contents;																								  //---
	                                                                                                                          //---
	WIN32_FIND_DATAW findData;																								  //---
	HANDLE hFind = FindFirstFileW((folderPath + L"\\*").c_str(), &findData);												  //---
	                                                                                                                          //---
	if (hFind != INVALID_HANDLE_VALUE) 																						  //---
	{																														  //---
		do {																												  //---
			ULONGLONG fileSize = 0;																							  //---
			                                                                                                                  //---
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 													  //---
			{																												  //---
				fileSize = (ULONGLONG)findData.nFileSizeHigh << 32 | findData.nFileSizeLow;									  //---
			}																												  //---
																															  //---
			wstring fileName = findData.cFileName;																			  //---
			bool isFolder = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);											  //---
			                                                                                                                  //---
			if (fileName != L"." && fileName != L"..") 																		  //---
			{																												  //---
				contents.push_back({ fileName, fileSize, isFolder });														  //---
			}																												  //---
		} while (FindNextFileW(hFind, &findData));																			  //---
		                                                                                                                      //---
		FindClose(hFind);																									  //---
	}																														  //---
																															  //---
	return contents;																										  //---
}																															  //---
																															  //---
//----------------------------------------------------------------------------------------------------------------------------//---
//----------------------------------------------------------------------------------------------------------------------------//---
int main()
{
	while (true)
	{
		AskToUser();
		system("cls");

		//Tree CPP folder

		if (tree)
		{
			system("cd c: && c: && tree");
			cout << endl;
			tree = false;
		}

		// Delete selected file
		else if (deleteFile)
		{
			char fileName[50];
			cout << "Enter delete file name an extention: ";
			cin >> fileName;
			if (remove(fileName) != 0)
				perror("Error deleting file");
			else
				puts("File successfully deleted");
			cout << endl;
			deleteFile = false;
		}

		// Delete selected folder
		else if (deleteFolder)
		{
			char folderName[50];
			cout << "Enter folder name: ";
			cin >> folderName;

			string command = "rmdir " + string(folderName);
			system(command.c_str());
			cout << "Folder successfully deleted" << endl;
			deleteFolder = false;

		}
		//Rename selected file
		else if (renameFile)
		{
			int result;
			char* oldname = new char[100];
			cout << "Enter the old name of the file:";
			cin >> oldname;
			char* newname = new char[100];
			cout << "Enter the new name of the file: ";
			cin >> newname;

			result = rename(oldname, newname);
			if (result == 0)
				puts("File successfully renamed");
			else
				perror("Error renaming file");

			delete[] oldname;
			delete[] newname;
			renameFile = false;
		}
		//Rename seleceted folder
		else if (renameFolder)
		{
			wstring oldName, newName;
			wcout << L"Enter the old name of the folder: ";
			getline(wcin, oldName);

			wcout << L"Enter the new name of the folder: ";
			getline(wcin, newName);

			bool result = MoveFile(oldName.c_str(), newName.c_str());

			if (result)
			{
				wcout << L"Folder renamed successfully.\n";
			}
			else
			{
				wcout << L"Failed to rename folder. Error code: " << GetLastError() << L"\n";
			}
			cout << endl;
			renameFolder = false;
		}
		//Move selected file
		else if (moveFile)
		{
			wstring source, destination;
			wcout << L"Enter the source file path: ";
			getline(wcin, source);

			wcout << L"Enter the destination file path: ";
			getline(wcin, destination);

			if (MoveFile(source.c_str(), destination.c_str())) {
				cout << "File moved successfully." << endl;
			}
			else {
				cerr << "Failed to move file. Error code: " << GetLastError() << endl;
			}
			cout << endl;
			moveFile = false;
		}
		//Move selected folder
		else if (moveFolder)
		{
			string srcFolder;
			cout << "Enter the source folder name: ";
			getline(cin, srcFolder);

			string destFolder;
			cout << "Enter the destination folder name: ";
			getline(cin, destFolder);

			wstring srcFolderW(srcFolder.begin(), srcFolder.end());
			wstring destFolderW(destFolder.begin(), destFolder.end());

			bool success = MoveFile(srcFolderW.c_str(), destFolderW.c_str());

			if (success) {
				cout << "Folder moved successfully." << endl;
			}
			else {
				cout << "Error moving folder." << endl;
			}
			cout << endl;
			moveFolder = false;
		}
		//Creat new Folder with specified name
		else if (creatFolder)
		{
			char folderName[50];
			cout << "Enter folder name: ";
			cin >> folderName;

			string command = "mkdir " + string(folderName);
			system(command.c_str());
			cout << "Folder successfully created" << endl;
			cout << endl;
			creatFolder = false;
		}
		//Creat new file with specified name
		else if (creatFile)
		{
			string fileName;
			cout << "Enter file name: ";
			cin >> fileName;
			ofstream file(fileName, ios::app);
			file.close();
			cout << "File successfully created" << endl;
			creatFile = false;
		}
		//Sort folder by size
		else if (sortBySize)
		{
			wstring folderPath;

			wcout << L"Enter the folder path: ";
			getline(wcin, folderPath);

			auto contents = GetFolderContents(folderPath);

			sort(contents.begin(), contents.end(), CompareFileSize);

			for (const auto& item : contents) {
				if (item.isFolder) {
					wprintf(L"[Folder] %s\n", item.name.c_str());
				}
				else {
					wprintf(L"%-20llu %s\n", item.size, item.name.c_str());
				}
			}
			cout << endl;
			sortBySize = false;
		}
		//Sort folder by name
		else if (sortByName)
		{
			char folderName[150];
			cout << "Enter folder name with sort by name: ";
			cin >> folderName;
			string path(folderName);
			string command("dir /a-d ");

			command.append(path);
			const char* final_command = command.c_str();

			system(final_command);
			cout << "Sorted by name successfully" << endl;
			sortByName = false;
		}
		//Open selected file or folder
		else if (openFile)
		{
			wstring fileName, directory;
			wcout << L"Enter file name: ";
			getline(wcin, fileName);
			wcout << L"Enter file directory: ";
			getline(wcin, directory);

			LPCWSTR parameters = L"";
			LPCWSTR verb = L"open";

			ShellExecute(NULL, verb, fileName.c_str(), parameters, directory.c_str(), SW_SHOW);
			cout << "File successfully opened" << endl;
			openFile = false;
		}
		//Info selected folder
		else if (infoFile)
		{
			char fileName[50];
			cout << "Enter file or folder name: ";
			cin >> fileName;

			string command = "dir " + string(fileName);
			system(command.c_str());
			infoFile = false;
		}
		//Move folder in ichindekilerini
		else if (fileCopy)
		{
			wstring sourceFolder;
			cout << "Please add your file location end '\\\\' this sign" << endl;
			wcout << L"Enter file location: ";
			getline(wcin, sourceFolder);
			wstring targetFolder;
			wcout << L"Enter seccond file location: ";
			getline(wcin, targetFolder);
			bool check = false;

			wstring sourceSearch = sourceFolder + L"*.*";
			WIN32_FIND_DATA fileData;
			HANDLE hFind = FindFirstFile(sourceSearch.c_str(), &fileData);

			if (hFind != INVALID_HANDLE_VALUE)
			{
				do
				{
					if ((fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
						(wcscmp(fileData.cFileName, L".") == 0 || wcscmp(fileData.cFileName, L"..") == 0))
					{
						continue;
					}

					wstring sourceFilePath = sourceFolder + fileData.cFileName;
					wstring targetFilePath = targetFolder + fileData.cFileName;

					if (MoveFile(sourceFilePath.c_str(), targetFilePath.c_str()) == 0)
					{
						wcout << "Failed to move file " << sourceFilePath << endl;
					}
					else
					{
						check = true;
					}
				} while (FindNextFile(hFind, &fileData) != 0);

				if (check)
				{
					cout << "File successfully moved" << endl;
				}
				FindClose(hFind);
			}
		}
		//Exit program
		else if (exitt)
		{
			
			break;
		}

		int keyPressed = 0;
		cout << "Press Enter for continue";
		while (keyPressed != 13)
		{
			keyPressed = _getch();

		}

	}
}


