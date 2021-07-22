/*We can Use this class for storing char* , short* , unsigned short* , int array etc in a file system
the file will be named by time in HH-MM-SS

CopyRight : Vijay Sahu
Org       : Accuopt Pvt Ltd*/



#pragma once

#include <ctime>
#include <atlstr.h>
#include <iostream>
#include <fstream>



#define	 DATE_BUFFER	100


	class ln_SaveDataByTimeAndDate
	{
	public:
		ln_SaveDataByTimeAndDate();
		ln_SaveDataByTimeAndDate(char LogFileName[]);
		~ln_SaveDataByTimeAndDate();
		
		/*
		Function use set Default fileName
		*/
		void SetFileName(char fileName[]);
		wchar_t *GetWC_C(const char *c);

		/*
		Function use to create a folder by Date
		*/
		void CreateFolderByDate(char fileName[]);

		/*
		Function use to create a Log File
		*/
		void SaveFloatArray(char foldername1[], float* data, int ARRAYSIZE);
		void SaveShortArray(char foldername1[], short* data, int ARRAYSIZE);
        void SaveIntArray(char foldername1[], short* data, int ARRAYSIZE); 
        void SaveUnsignedShortArray(char foldername1[], unsigned short* data, int ARRAYSIZE);
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

