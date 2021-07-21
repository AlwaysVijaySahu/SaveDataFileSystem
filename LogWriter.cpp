
// Vijay sahu
// This class can be used for writing logs by date and time


#include "stdafx.h"
#include "LogWriter.h"



 wchar_t *GetWC(const char *c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}


 namespace myServerLib {

	 CLogWrite::CLogWrite()
	 {
		 m_isFileName = false;
		 // Check if LOG foldeer exists, if not create it
		 if (!FolderExists("LOG"))
		 {

			 //Create LOG folder 
			 wchar_t *path;
			 path = GetWC("LOG");
			 /*path = calloc(123, sizeof *path);
			 wcspy(pm, L"LOG");*/
			 CreateDirectory(path, NULL);
		 }
	 }

	 CLogWrite::CLogWrite(char LogFileName[])
	 {
		 m_isFileName = true;
		 strcpy(m_fileName, LogFileName);
		 // Check if LOG foldeer exists, if not create it
		 if (!FolderExists("LOG"))
		 {

			 //Create LOG folder 
			 wchar_t *path;
			 path = GetWC("LOG");
			 /*path = calloc(123, sizeof *path);
			 wcspy(pm, L"LOG");*/
			 CreateDirectory(path, NULL);
		 }

	 }




	 CLogWrite::~CLogWrite()
	 {

	 }

	 /*
	 Check CLogWrite.h for details
	 */
	 void CLogWrite::SetFileName(char fileName[])
	 {
		 m_isFileName = true;
		 strcpy(m_fileName, fileName);
	 }



	 /*
	 Check CLogWrite.h for details
	 */
	 void CLogWrite::CreateFolderByDate(char fileName[])
	 {
		 std::time_t result = std::time(nullptr);
		 char buffer[80];
		 struct tm * timeinfo;
		 char testFolder[200];

		 char path[] = "LOG";
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

	 /*
	 Check CLogWrite.h for details
	 */
	 void CLogWrite::WriteLog(char filename[], char data[])
	 {
		 std::time_t result = std::time(nullptr);
		 //std::cout << std::asctime(std::localtime(&result))

		 struct tm * timeinfo;
		 char buffer[80];
		 char myFilename[200];

		 try
		 {

			 timeinfo = localtime(&result);
			 strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
			 std::string str(buffer);

			 strcpy_s(myFilename, "LOG\\");
			 strcat_s(myFilename, buffer);
			 CString testFolder = CString(myFilename);

			 //Create FOlder by Date if it does not exist
			 CreateFolderByDate("LOG");
			 strcat_s(myFilename, "\\");
			 if (m_isFileName)
			 {
				 strcat_s(myFilename, m_fileName);
			 }
			 else
			 {

				 strcat_s(myFilename, filename);
			 }

			 std::ofstream file(myFilename, std::ofstream::app);
			 file << data << ": " << std::asctime(std::localtime(&result)) << "\n";
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
			 std::ofstream file(filename, std::ofstream::app);
			 file << data << " Exception: " << std::asctime(std::localtime(&result)) << "\n";
			 file.close();
		 }
	 }

	 /*
	 Check CLogWriter.h for detail
	 */
	 char* CLogWrite::GetTodayDate()
	 {
		 std::time_t result = std::time(nullptr);
		 char buffer[80];
		 struct tm * timeinfo;
		 timeinfo = localtime(&result);
		 strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);		//"%x-%I:%M%p"
		 return buffer;
	 }

	 /*
	 Check CLogWrite.h for details
	 */
	 bool CLogWrite::FolderExists(CString strFolderName)
	 {
		 return GetFileAttributes(strFolderName) != INVALID_FILE_ATTRIBUTES;
	 }
 }
