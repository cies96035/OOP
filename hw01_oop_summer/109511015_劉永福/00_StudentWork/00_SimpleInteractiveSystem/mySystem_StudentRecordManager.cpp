//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2020/07/18
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER( )
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput( )
{
	mScore.clear();
	mSortedScore.clear();
	//Show the system title
	//Ask to input the number of students
	//Ask to input the score of each student
	//Show the average
	//Show the standard deviation
	//Show the scores in an ascending order
	//
	cout << "STUDENT_RECORD_MANAGER" << endl;

	cout << "Input the number of students." << endl <<  
		"The number of students is in [2,100]:" << endl;
	do{
		cin >> mNumStudents;
	}while(mNumStudents<2 || mNumStudents>100);

	int MAX_score=0,MIN_score=100;
	cout << "Input the score of each student. " << endl <<
		"The score range is [0, 100]. " << endl <<
		"The score value is an integer:" << endl;
	for(int i=0,score ; i<mNumStudents ; i++)
	{
		cout<<'\t'<<i+1<<':';
		do{
			cin>>score;
		}while(score<0 || score>100);
		if(MAX_score<score)
			MAX_score=score;
		if(MIN_score>score)
			MIN_score=score;
		mScore.emplace_back(score);
	}

	computeAverage( );

	computeStandardDeviation( );
	cout << "Range of the scores: [" << MIN_score << ',' << MAX_score << ']' << endl;
	cout << "Average:" << mAverageScore << endl;
	cout << "Standard Deviation:" << mStandardDeviation << endl;
	sortScores( );
	showSortedScores( );
}

double STUDENT_RECORD_MANAGER::computeAverage( )
{
	//Compute the average
	double totalScore = 0.0;
	for(int i=0; i<mScore.size(); i++)
		totalScore+=mScore[i];
	mAverageScore = totalScore/mNumStudents;
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation( )
{
	//Compute the standard deviation
    mStandardDeviation = 0.0;
    if ( mNumStudents < 2 ) return 0.0;
	double sum = 0.0;
	for(int i=0; i<mScore.size(); i++)
		sum+=(mAverageScore-mScore[i])*(mAverageScore-mScore[i]);
	mStandardDeviation = sqrt( sum / (mNumStudents -1) );
	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores( )
{
	//Sorting in an ascending order
	sort(mScore.begin(),mScore.end());
	for(int i=0; i<mScore.size(); i++)
		mSortedScore.emplace_back(mScore[i]);
}

void STUDENT_RECORD_MANAGER::showSortedScores( ) const
{
	//Show the scores in an ascending order

	cout << "Sorted scores:" << endl;
	for ( int i = 0; i < mNumStudents; ++i ) {
		cout << mSortedScore[ i ] << endl;
	}
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	// 
	int num = 0;
	num=upper_bound(mScore.begin(),mScore.end(),s1)-lower_bound(mScore.begin(),mScore.end(),s0);
	return num;
}
// CODE: 2020/07/18. Do not delete this line.