//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2020/07/17
//
#include "mySystemApp.h"

using namespace std;

#define STUDENT_INFO "Name:¼B¥ÃºÖ   ID:109511015"

void MY_SYSTEM_APP::showMyStudentInfo_2020_Summer( ) const
{
	cout << "*******************************" << endl;
    cout << "Date:\t2020/07/17" << endl;
	cout << "Student ID:\t109511015" << endl;
	cout << "Student Name:\t¼B¥ÃºÖ" << endl;
	cout << "Student Email:\tcies96035.eed09@nctu.edu.tw" << endl;
	cout << "*******************************" << endl;
}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
	mSystemType = SYSTEM_TYPE_MONTE_CARLO;
    string title = STUDENT_INFO;
        glutSetWindowTitle(title.data( ));
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = true;
}

void MY_SYSTEM_APP::update( )
{

}
// CODE: 2020/7/17. Do not delete this line.



