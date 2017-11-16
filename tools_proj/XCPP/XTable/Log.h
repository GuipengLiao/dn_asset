/* 
 * �ռ�ģ�� 
 */ 

#ifndef  __logger__  
#define  __logger__  
   
#include <iostream>  
#include <iomanip>  
#include <fstream>  
#include <string>  
#include <cstdlib>  
#include <stdint.h>  
#include <vector>

// ��־�ļ�������    
typedef enum 
{  
   INFO,  
   WARN,  
   ERROR,  
   FATAL  
}LogLevel;  


/// ��ʼ����־�ļ�  
/// param info_log_filename ��Ϣ�ļ�������  
/// param warn_log_filename �����ļ�������  
/// param error_log_filename �����ļ������� 
void InitLogger(const std::string& info_log_filename,  
                const std::string& warn_log_filename,  
                const std::string& error_log_filename); 


class Log
{
friend void InitLogger(const std::string& info_log_filename,  
                           const std::string& warn_log_filename,  
                           const std::string& erro_log_filename);  

public:
	Log(LogLevel level) : m_log_level(level) {};  
	~Log(void);
	static std::ostream& Start(LogLevel level,std::string text,const int line,const std::string& function);  
	
private:  
   static std::ostream& GetStream(LogLevel log_rank);  //���ݵȼ���ȡ��Ӧ����־����� 
   static std::ofstream m_info_log_file;  //��Ϣ���ӵ������  
   static std::ofstream m_warn_log_file;  //������Ϣ�������  
   static std::ofstream m_error_log_file; //������Ϣ�������  
   LogLevel m_log_level;   
};

// ���ݲ�ͬ�ȼ������ò�ͬ����������ж�д  
#define LOG(text) Log(INFO).Start(INFO, text,__LINE__,__FUNCTION__)  

#define WARN(text) Log(WARN).Start(WARN,text,__LINE__,__FUNCTION__)

#define ERROR(text) Log(ERROR).Start(ERROR,text,__LINE__,__FUNCTION__)
    
// �����ռǽ��м��ĸ��ֺ�  
#define CHECK(a) if(!(a)){ LOG(ERROR)<<" CHECK failed "<<endl<<#a<< "= "<< (a)<<endl;abort(); }                                                      
   
#define CHECK_NOTNULL(a) if( NULL == (a)){ LOG(ERROR)<<" CHECK_NOTNULL failed "<< #a << "== NULL "<<endl; abort();}
   
#define CHECK_NULL(a) if( NULL != (a)){ LOG(ERROR)<<" CHECK_NULL failed "<<endl<<#a<< "!= NULL "<<endl; abort();} 
   
#define CHECK_EQ(a, b) if(!((a) == (b))) { LOG(ERROR)<<" CHECK_EQ failed "<< endl<<#a<< "= "<<(a) <<endl<< #b<< "= "<<b<< endl; abort();}  
   
#define CHECK_NE(a, b) if(!((a) != (b))) { LOG(ERROR)<<" CHECK_NE failed "<< endl<< #a<< "= "<<(a)<< endl<<#b<<"= "<<b<< endl; abort();}  
   
#define CHECK_LT(a, b)if(!((a) < (b))) { LOG(ERROR)<<" CHECK_LT failed "<< #a<<"= "<<(a)<< endl<< #b<<"= "<<b<<endl; abort();}  
   
#define CHECK_GT(a, b) if(!((a) > (b))) { LOG(ERROR)<<" CHECK_GT failed "<< endl<< #a<<" = "<<a<< endl<<#b<<"= "<<b<< endl; abort(); } 
   
#define CHECK_LE(a, b) if(!((a) <= (b))) { LOG(ERROR)<<" CHECK_LE failed "<< endl<< #a << "= " <<a<< endl<<#b<<"= "<<b<< endl;abort(); }  
   
#define CHECK_GE(a, b) if(!((a) >= (b))) { LOG(ERROR)<<" CHECK_GE failed "<< endl<<#a<<" = "<<a<< endl<<#b<<"= "<<b<< endl;abort();}  
   
#define CHECK_DOUBLE_EQ(a, b)do { CHECK_LE((a), (b)+0.000000000000001L); CHECK_GE((a), (b)-0.000000000000001L); }while (0)  

#endif