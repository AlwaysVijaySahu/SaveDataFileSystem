// Vijay Sahu
// This class can be used for writing logs by date and time

#pragma once

#include <ctime>
#include <atlstr.h>
#include <iostream>
#include <fstream>

#define	 DATE_BUFFER	100

namespace myServerLib {
	class CLogWrite
	{
	public:
		CLogWrite();
		CLogWrite(char LogFileName[]);
		~CLogWrite();

		/*
		Function use set Default fileName
		*/
		void SetFileName(char fileName[]);


		/*
		Function use to create a folder by Date
		*/
		void CreateFolderByDate(char fileName[]);

		/*
		Function use to create a Log File
		*/
		void WriteLog(char filename[], char data[]);

		/*
		Function use to get Today's Date
		*/
		char* GetTodayDate();

		/*
		Function to check the folder already exist
		Return true if Folder already exist otherwise return false
		*/
		bool FolderExists(CString strFolderName);
	private:
		bool m_isFileName;
		char m_fileName[200];
	};

}
