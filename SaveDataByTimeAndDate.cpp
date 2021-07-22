
#include "stdafx.h"
#include "SaveDataByTimeAndDate.h"


/*            VIJAY SAHU              */


wchar_t *GetWC_C(const char *c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}




	ln_SaveDataByTimeAndDate::ln_SaveDataByTimeAndDate()
	{
		m_isFileName = false;
		// Check if LOG foldeer exists, if not create it
		if (!FolderExists("LOG"))
		{

			//Create LOG folder 
			wchar_t *path;
			path = GetWC_C("SaveDataByTimeAndDate");
			/*path = calloc(123, sizeof *path);
			wcspy(pm, L"LOG");*/
			CreateDirectory(path, NULL);
		}
	}

	ln_SaveDataByTimeAndDate::ln_SaveDataByTimeAndDate(char LogFileName[])
	{
		m_isFileName = true;
		strcpy(m_fileName, LogFileName);
		// Check if LOG foldeer exists, if not create it
		if (!FolderExists("SaveDataByTimeAndDate"))
		{

			//Create LOG folder 
			wchar_t *path;
			path = GetWC_C("SaveDataByTimeAndDate");
			/*path = calloc(123, sizeof *path);
			wcspy(pm, L"LOG");*/
			CreateDirectory(path, NULL);
		}

	}




	ln_SaveDataByTimeAndDate::~ln_SaveDataByTimeAndDate()
	{

	}

	/*
	Check CLogWrite.h for details
	*/
	void ln_SaveDataByTimeAndDate::SetFileName(char fileName[])
	{
		m_isFileName = true;
		strcpy(m_fileName, fileName);
	}



	
	void ln_SaveDataByTimeAndDate::CreateFolderByDate(char fileName[])
	{
		std::time_t result = std::time(nullptr);
		char buffer[80];
		struct tm * timeinfo;
		char testFolder[200];

	//	char path[] = "LOG";
		timeinfo = localtime(&result);
		strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);

		strcpy(testFolder, fileName);
		strcat(testFolder, "\\");
		strcat(testFolder, buffer);
		
		if (!FolderExists(testFolder))
		{
			
			const size_t cSize = strlen(testFolder) + 1;
			wchar_t* wc = new wchar_t[cSize];
			mbstowcs(wc, testFolder, cSize);

			//LPCTSTR myDir = CA2W(testFolder);

			CreateDirectory(wc, NULL);
		}
	}

	
	void ln_SaveDataByTimeAndDate::SaveFloatArray(char foldername1[],float* data , int ARRAYSIZE)
	{
		
		std::time_t result = std::time(nullptr);
		//std::cout << std::asctime(std::localtime(&result))
		
		struct tm * timeinfo;
		char buffer[80];
		char myFilename[200];
		char myFilename2[200];
		LPCTSTR myDir1 = CA2W(foldername1);
		CHAR sysTimeStr[11] = {};
		SYSTEMTIME systemTime;
		GetLocalTime(&systemTime);
		sprintf_s(sysTimeStr,
			"%u-%02u-%02u",
			systemTime.wHour,
			systemTime.wMinute,
			systemTime.wSecond);
		try
		 {

		if (!(GetFileAttributes(myDir1) != INVALID_FILE_ATTRIBUTES))
		{
			const size_t cSize1 = strlen(foldername1) + 1;
			wchar_t* wc1 = new wchar_t[cSize1];
			mbstowcs(wc1, foldername1, cSize1);
			CreateDirectory(wc1, NULL);
		}
		
			timeinfo = localtime(&result);
			strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
			std::string str(buffer);

			strcpy_s(myFilename2, foldername1);
			strcat_s(myFilename2, "\\");
			
			strcpy_s(myFilename, myFilename2);
			strcat_s(myFilename, buffer);
			CString testFolder = CString(myFilename);
	
			//Create FOlder by Date if it does not exist
			CreateFolderByDate(foldername1);
			strcat_s(myFilename, "\\");
			
			strcat_s(myFilename, sysTimeStr);
			strcat_s(myFilename, ".txt");

			std::ofstream file(myFilename);
		
			for (int i = 0; i < ARRAYSIZE; i++)
			{
				file << data[i] << std::endl;
			}
			
			file.close();
		}
		catch (std::exception ex)
		{

		}
	}

	void ln_SaveDataByTimeAndDate::SaveIntArray(char foldername1[], int* data, int ARRAYSIZE)
	{
		std::time_t result = std::time(nullptr);
		//std::cout << std::asctime(std::localtime(&result))

		struct tm * timeinfo;
		char buffer[80];
		char myFilename[200];
		char myFilename2[200];
		char* str3 = std::asctime(std::localtime(&result));

		try
		{
			timeinfo = localtime(&result);
			strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
			std::string str(buffer);

			strcpy_s(myFilename2, foldername1);
			strcat_s(myFilename2, "\\");

			strcpy_s(myFilename, myFilename2);
			strcat_s(myFilename, buffer);
			CString testFolder = CString(myFilename);

			//Create FOlder by Date if it does not exist
			CreateFolderByDate(foldername1);
			strcat_s(myFilename, "\\");

			if (m_isFileName)
			{
				strcat_s(myFilename, m_fileName);
			}
			else
			{
				strcat_s(myFilename, str3);
			}
			int ArraySize = sizeof(data) / sizeof(data[0]);

			std::ofstream file(myFilename, std::ofstream::app);

			for (int i = 0; i < ARRAYSIZE; i++)
			{
				file << data[i] << std::endl;
			}

			file.close();

		}
		catch (std::exception ex)
		{

		}
	}


	void ln_SaveDataByTimeAndDate::SaveShortArray(char foldername1[], short* data, int ARRAYSIZE)
	{
		std::time_t result = std::time(nullptr);
		//std::cout << std::asctime(std::localtime(&result))

		struct tm * timeinfo;
		char buffer[80];
		char myFilename[200];
		char myFilename2[200];
		char* str3 = std::asctime(std::localtime(&result));

		try
		{
			timeinfo = localtime(&result);
			strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
			std::string str(buffer);

			strcpy_s(myFilename2, foldername1);
			strcat_s(myFilename2, "\\");

			strcpy_s(myFilename, myFilename2);
			strcat_s(myFilename, buffer);
			CString testFolder = CString(myFilename);

			//Create FOlder by Date if it does not exist
			CreateFolderByDate(foldername1);
			strcat_s(myFilename, "\\");

			if (m_isFileName)
			{
				strcat_s(myFilename, m_fileName);
			}
			else
			{
				strcat_s(myFilename, str3);
			}
			int ArraySize = sizeof(data) / sizeof(data[0]);

			std::ofstream file(myFilename, std::ofstream::app);

			for (int i = 0; i < ARRAYSIZE)i++)
			{
				file << data[i] << std::endl;
			}

			file.close();

			/*if (FolderExists(testFolder))
			{
			std::ofstream file(myFilename, std::ofstream::app);
			file << data << ": " << std::asctime(std::localtime(&result)) << "\n";
			file.close();

			}
			else
			{
			LPCTSTR ime = CA2W(myFilename);
			CreateDirectory(ime, 0);

			strcat_s(myFilename, "\\");
			strcat_s(myFilename, filename);

			std::ofstream file(myFilename, std::ofstream::app);
			file << data << ": " << std::asctime(std::localtime(&result)) << "\n";
			file.close();

			}*/

			//strcat_s(myFilename, "\\");
			//strcat_s(myFilename, filename);


			////get date



			////std::ofstream file(filename, std::ofstream::app);
			//std::ofstream file(myFilename, std::ofstream::app);
			//file << data << ": " << std::asctime(std::localtime(&result)) << "\n";
			//file.close();
		}
		catch (std::exception ex)
		{

		}
	}


void ln_SaveDataByTimeAndDate::SaveUnsignedShortArray(char foldername1[], unsigned short* data, int ARRAYSIZE)
	{
		std::time_t result = std::time(nullptr);
		//std::cout << std::asctime(std::localtime(&result))

		struct tm * timeinfo;
		char buffer[80];
		char myFilename[200];
		char myFilename2[200];
		char* str3 = std::asctime(std::localtime(&result));

		try
		{
			timeinfo = localtime(&result);
			strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
			std::string str(buffer);

			strcpy_s(myFilename2, foldername1);
			strcat_s(myFilename2, "\\");

			strcpy_s(myFilename, myFilename2);
			strcat_s(myFilename, buffer);
			CString testFolder = CString(myFilename);

			//Create FOlder by Date if it does not exist
			CreateFolderByDate(foldername1);
			strcat_s(myFilename, "\\");

			if (m_isFileName)
			{
				strcat_s(myFilename, m_fileName);
			}
			else
			{
				strcat_s(myFilename, str3);
			}
			int ArraySize = sizeof(data) / sizeof(data[0]);

			std::ofstream file(myFilename, std::ofstream::app);

			for (int i = 0; i < ARRAYSIZE)i++)
			{
				file << data[i] << std::endl;
			}

			file.close();

			/*if (FolderExists(testFolder))
			{
			std::ofstream file(myFilename, std::ofstream::app);
			file << data << ": " << std::asctime(std::localtime(&result)) << "\n";
			file.close();

			}
			else
			{
			LPCTSTR ime = CA2W(myFilename);
			CreateDirectory(ime, 0);

			strcat_s(myFilename, "\\");
			strcat_s(myFilename, filename);

			std::ofstream file(myFilename, std::ofstream::app);
			file << data << ": " << std::asctime(std::localtime(&result)) << "\n";
			file.close();

			}*/

			//strcat_s(myFilename, "\\");
			//strcat_s(myFilename, filename);


			////get date



			////std::ofstream file(filename, std::ofstream::app);
			//std::ofstream file(myFilename, std::ofstream::app);
			//file << data << ": " << std::asctime(std::localtime(&result)) << "\n";
			//file.close();
		}
		catch (std::exception ex)
		{

		}
	}

	
	char* ln_SaveDataByTimeAndDate::GetTodayDate()
	{
		// Function For getting today's date
		std::time_t result = std::time(nullptr);
		char buffer[80];
		struct tm * timeinfo;
		timeinfo = localtime(&result);
		strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);		//"%x-%I:%M%p"
		return buffer;
	}

	

	bool ln_SaveDataByTimeAndDate::FolderExists(CString strFolderName)
	{
		return GetFileAttributes(strFolderName) != INVALID_FILE_ATTRIBUTES;
	}
