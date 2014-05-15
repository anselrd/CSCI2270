#include <iostream>
#include <cstdlib>
#include "BigNum.h"
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <fstream>
#include <cstring>

using namespace std;
using namespace HW3;
ofstream grade;

#define TOTALTESTS 20

int testNo = 0;
int i = 0;
void tester(){
    cerr << "*** Running test " << (testNo + 1) << " *** "<< endl;
    grade.open ("grade.txt", ios::out | ios::app);
    if (testNo >= TOTALTESTS)
    {
        grade.close();
        cerr << "returning";
        return;
    }
    if (testNo == 0){
        //cout << "DEFAULT CONSTRUCTOR TEST" << endl;
        BigNum test1;
        char* result = test1.printBigNum();
        if (strcmp(result, "0") == 0){
            cerr << "test 1 passed.\n";
            grade << "test 1 passed.\n";
        }else{
            grade << "test 1 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 1){
        //cout << "INT CONSTRUCTOR TESTS" << endl;
        BigNum test2 = 243;
        char* result = test2.printBigNum();
        if (strcmp(result, "243") == 0){
            cerr << "test 2 passed.\n";
            grade << "test 2 passed.\n";
        }else{
            grade << "test 2 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 2){
        BigNum test3 = -243;
        char* result = test3.printBigNum();
        if (strcmp(result, "-243") == 0){
            cerr << "test 3 passed.\n";
            grade << "test 3 passed.\n";
        }else{
            grade << "test 3 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 3){
        BigNum test4 = 0;
        char* result = test4.printBigNum();
        if (strcmp(result, "0") == 0){
            cerr << "test 4 passed.\n";
            grade << "test 4 passed.\n";
        }else{
            grade << "test 4 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 4){
        BigNum test5 = 3458919;
        char* result = test5.printBigNum();
        if (strcmp(result, "3458919") == 0){
            cerr << "test 5 passed.\n";
            grade << "test 5 passed.\n";
        }else{
            grade << "test 5 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 5){ 
        //cout << "STRING CONSTRUCTOR TESTS" << endl;  
        BigNum test6 = (string) "0";
        char* result = test6.printBigNum();
        if (strcmp(result, "0") == 0){
            cerr << "test 6 passed.\n";
            grade << "test 6 passed.\n";
        }else{
            grade << "test 6 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 6){
        BigNum test7 = (string) "9997632187383270741827";
        char* result = test7.printBigNum();
        if (strcmp(result, "9997632187383270741827") == 0){
            cerr << "test 7 passed.\n";
            grade << "test 7 passed.\n";
        }else{
            grade << "test 7 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 7){
        BigNum test8 = (string) "-9997632187383270741827";
        char* result = test8.printBigNum();
        if (strcmp(result, "-9997632187383270741827") == 0){
            cerr << "test 8 passed.\n";
            grade << "test 8 passed.\n";
        }else{
            grade << "test 8 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 8){
        BigNum test9 = (string) "-0008";
        char* result = test9.printBigNum();
        if (strcmp(result, "-8") == 0){
            cerr << "test 9 passed.\n";
            grade << "test 9 passed.\n";
        }else{
            grade << "test 9 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 9){
        BigNum test10 = (string) "-3458919728786732132";
        char* result = test10.printBigNum();
        if (strcmp(result, "-3458919728786732132") == 0){
            cerr << "test 10 passed.\n";
            grade << "test 10 passed.\n";
        }else{
            grade << "test 10 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 10){
        //cout << "COPY CONSTRUCTOR TESTS" << endl;
        BigNum test11a = 243;
        BigNum test11 = test11a;
        char* result = test11.printBigNum();
        if (strcmp(result, "243") == 0){
            cerr << "test 11 passed.\n";
            grade << "test 11 passed.\n";
        }else{
            grade << "test 11 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 11){
        BigNum test12a = (string) "-3458919728786732132";
        BigNum test12 = test12a;
        char* result = test12.printBigNum();
        if (strcmp(result, "-3458919728786732132") == 0){
            cerr << "test 12 passed.\n";
            grade << "test 12 passed.\n";
        }else{
            grade << "test 12 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 12){
        BigNum test13a = -243;
        BigNum test13 = test13a;
        char* result = test13.printBigNum();
        if (strcmp(result, "-243") == 0){
            cerr << "test 13 passed.\n";
            grade << "test 13 passed.\n";
        }else{
            grade << "test 13 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 13){
        BigNum test14a = 3458919;
        BigNum test14 = test14a;
        char* result = test14.printBigNum();
        if (strcmp(result, "3458919") == 0){
            cerr << "test 14 passed.\n";
            grade << "test 14 passed.\n";
        }else{
            grade << "test 14 failed.\n";
        }
        delete [] result;
    }
    //cout << "ASSIGNMENT OPERATOR TESTS" << endl;
    if (testNo == 14){
        BigNum test15;
        BigNum test15a = 3458919;
        
        test15 = test15a;
        char* result = test15.printBigNum();
        if (strcmp(result, "3458919") == 0){
            cerr << "test 15 passed.\n";
            grade << "test 15 passed.\n";
        }else{
            grade << "test 15 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 15){
        BigNum test16;
        BigNum test16a = (string) "-3458919728786732132";
        BigNum test16b = 243;
        
        test16 = test16a = test16b;
        char* result = test16.printBigNum();
        if (strcmp(result, "243") == 0){
            cerr << "test 16 passed.\n";
            grade << "test 16 passed.\n";
        }else{
            grade << "test 16 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 16){
        BigNum test17;
        BigNum test17a;
        
        test17 = test17a;
        char* result = test17.printBigNum();
        if (strcmp(result, "0") == 0){
            cerr << "test 17 passed.\n";
            grade << "test 17 passed.\n";
        }else{
            grade << "test 17 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 17){
        BigNum test18;
        BigNum test18a = (string) "-9997632187383270741827";
        test18 = test18a;
        char* result = test18.printBigNum();
        if (strcmp(result, "-9997632187383270741827") == 0){
            cerr << "test 18 passed.\n";
            grade << "test 18 passed.\n";
        }else{
            grade << "test 18 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 18){
        BigNum test18b = 76878;
        test18b = test18b;
        char* result = test18b.printBigNum();
        if (strcmp(result, "76878") == 0){
            cerr << "test 19 passed.\n";
            grade << "test 19 passed.\n";
        }else{
            grade << "test 19 failed.\n";
        }
        delete [] result;
    }
    if (testNo == 19){
        
// bad Eliz; can't test resize() directly but can force it
//        test18b.resize(200);
	BigNum test19 = (string) "99999999999999999999999999999999";
	BigNum test19b = 1;
	test19b = test19;
	char* result = test19b.printBigNum();
        if (strcmp(result, "99999999999999999999999999999999") == 0){
            cerr << "test 20 passed.\n";
            grade << "test 20 passed.\n";
        }else{
            grade << "test 20 failed.\n";
        }
        delete [] result;
    }
    
    grade.close();
    return;
}

void termination_handler (int param)
{
    grade.close();
    if (++testNo <= TOTALTESTS){
        grade.open ("grade.txt", ios::out | ios::app);
        grade << "test " << testNo << " failed.\n";
        cerr << "\n************** test " << testNo << " failed. ***************\n"; 
        if (testNo == TOTALTESTS){
            cerr << "exiting";
            exit(1);
        }
        return tester();
    }
}

int smallOPTest()
{
	BigNum a = 100;
    BigNum b = -100;
    BigNum c = 101;
    BigNum d = -101;
    BigNum e = 99;
    BigNum f = -99;
    BigNum g = 100;
    
    int cnt = 0; 
    int totalCnt = 0;
    
    cout << "Test for smaller numbers:" << endl;
    
    cout << endl << "Test for '>' operator:" << endl;
    if((a > b) == 1) cnt++;
    cout << "1: " << (a > b) << " -- " << a << " > " << b << endl; 
    if((b > a) == 0) cnt++;
    cout << "0: " << (b > a) << " -- " << b << " > " << a << endl;
    if((c > a) == 1) cnt++;
	cout << "1: " << (c > a) << " -- " << c << " > " << a << endl;
	if((a > c) == 0) cnt++;
	cout << "0: " << (a > c) << " -- " << a << " > " << c << endl;
	if((b > d) == 1) cnt++;
	cout << "1: " << (b > d) << " -- " << b << " > " << d << endl;
	if((d > b) == 0) cnt++;
	cout << "0: " << (d > b) << " -- " << d << " > " << b << endl;
	if((a > e) == 1) cnt++;
	cout << "1: " << (a > e) << " -- " << a << " > " << e << endl;
	if((e > a) == 0) cnt++;
	cout << "0: " << (e > a) << " -- " << e << " > " << a << endl;
	if((f > b) == 1) cnt++;
	cout << "1: " << (f > b) << " -- " << f << " > " << b << endl;
	if((b > f) == 0) cnt++;
	cout << "0: " << (b > f) << " -- " << b << " > " << f << endl;
	if((a > g) == 0) cnt++;
	cout << "0: " << (a > g) << " -- " << a << " > " << g << endl;
	
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11)
		cout << "Test Passed!" << endl; 
	totalCnt = cnt;
	cnt = 0;
	
	cout << endl << "Test for '>=' operator:" << endl;
    if((a >= b) == 1) cnt++;
    cout << "1: " << (a >= b) << " -- " << a << " >= " << b << endl;
    if((b >= a) == 0) cnt++;
    cout << "0: " << (b >= a) << " -- " << b << " >= " << a << endl;
    if((c >= a) == 1) cnt++;
	cout << "1: " << (c >= a) << " -- " << c << " >= " << a << endl;
	if((a >= c) == 0) cnt++;
	cout << "0: " << (a >= c) << " -- " << a << " >= " << c << endl;
	if((b >= d) == 1) cnt++;
	cout << "1: " << (b >= d) << " -- " << b << " >= " << d << endl;
	if((d >= b) == 0) cnt++;
	cout << "0: " << (d >= b) << " -- " << d << " >= " << b << endl;
	if((a >= e) == 1) cnt++;
	cout << "1: " << (a >= e) << " -- " << a << " >= " << e << endl;
	if((e >= a) == 0) cnt++;
	cout << "0: " << (e >= a) << " -- " << e << " >= " << a << endl;
	if((f >= b) == 1) cnt++;
	cout << "1: " << (f >= b) << " -- " << f << " >= " << b << endl;
	if((b >= f) == 0) cnt++;
	cout << "0: " << (b >= f) << " -- " << b << " >= " << f << endl;
	if((a >= g) == 1) cnt++;
	cout << "1: " << (a >= g) << " -- " << a << " >= " << g << endl;
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << endl << "Test for '<' operator:" << endl;
    
    if((a < b) == 0) cnt++;
    cout << "0: " << (a < b) << " -- " << a << " < " << b << endl;
    if((b < a) == 1) cnt++;
    cout << "1: " << (b < a) << " -- " << b << " < " << a << endl;
    if((c < a) == 0) cnt++;
	cout << "0: " << (c < a) << " -- " << c << " < " << a << endl;
	if((a < c) == 1) cnt++;
	cout << "1: " << (a < c) << " -- " << a << " < " << c << endl;
	if((b < d) == 0) cnt++;
	cout << "0: " << (b < d) << " -- " << b << " < " << d << endl;
	if((d < b) == 1) cnt++;
	cout << "1: " << (d < b) << " -- " << d << " < " << b << endl;
	if((a < e) == 0) cnt++;
	cout << "0: " << (a < e) << " -- " << a << " < " << e << endl;
	if((e < a) == 1) cnt++;
	cout << "1: " << (e < a) << " -- " << e << " < " << a << endl;
	if((f < b) == 0) cnt++;
	cout << "0: " << (f < b) << " -- " << f << " < " << b << endl;
	if((b < f) == 1) cnt++;
	cout << "1: " << (b < f) << " -- " << b << " < " << f << endl;
	if((a > g) == 0) cnt++;
	cout << "0: " << (a < g) << " -- " << a << " < " << g << endl;
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << endl << "Test for '<=' operator:" << endl;
    if((a <= b) == 0) cnt++;
    cout << "0: " << (a <= b) << " -- " << a << " <= " << b << endl;
    if((b <= a) == 1) cnt++;
    cout << "1: " << (b <= a) << " -- " << b << " <= " << a << endl;
    if((c <= a) == 0) cnt++;
	cout << "0: " << (c <= a) << " -- " << c << " <= " << a << endl;
	if((a <= c) == 1) cnt++;
	cout << "1: " << (a <= c) << " -- " << a << " <= " << c << endl;
	if((b <= d) == 0) cnt++;
	cout << "0: " << (b <= d) << " -- " << b << " <= " << d << endl;
	if((d <= b) == 1) cnt++;
	cout << "1: " << (d <= b) << " -- " << d << " <= " << b << endl;
	if((a <= e) == 0) cnt++;
	cout << "0: " << (a <= e) << " -- " << a << " <= " << e << endl;
	if((e <= a) == 1) cnt++;
	cout << "1: " << (e <= a) << " -- " << e << " <= " << a << endl;
	if((f <= b) == 0) cnt++;
	cout << "0: " << (f <= b) << " -- " << f << " <= " << b << endl;
	if((b <= f) == 1) cnt++;
	cout << "1: " << (b <= f) << " -- " << b << " <= " << f << endl;
	if((a <= g) == 1) cnt++;
	cout << "1: " << (a <= g) << " -- " << a << " <= " << g << endl;
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << endl << "Test for '==' operator:" << endl;
    
    if((a == b) == 0) cnt++;
    cout << "0: " << (a == b) << " -- " << a << " == " << b << endl;
    if((a == c) == 0) cnt++;
    cout << "0: " << (a == c) << " -- " << a << " == " << c << endl;
    if((a == g) == 1) cnt++;
    cout << "1: " << (a == g) << " -- " << g << " == " << g << endl;
    
    if(cnt < 3) 
		cout << "Test Failed!" << endl;
	if(cnt == 3) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
    
    cout << endl << "Test for '!=' operator:" << endl;
    
    if((a == g) == 1) cnt++;
    cout << "1: " << (a != b) << " -- " << a << " != " << b << endl;
    if((a != c) == 1) cnt++;
    cout << "1: " << (a != c) << " -- " << a << " != " << c << endl;
    if((a != g) == 0) cnt++;
    cout << "0: " << (a != g) << " -- " << g << " != " << g << endl;
    
    if(cnt < 3) 
		cout << "Test Failed!" << endl;
	if(cnt == 3) 
		cout << "Test Passed!" << endl << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << "Total Small Number Tests Passed: " << endl;
	cout << totalCnt << "/50" << endl << endl;
	
	return totalCnt;
}

int largeOPTest()
{
	BigNum a = BigNum("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigNum b = BigNum("-1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigNum c = BigNum("1000000000000000000000000000000000001200000000000000000000000000044000000000000000000000000000000000000000");
    BigNum d = BigNum("-1000000000000000000000000230000000120000000000000000000000000000002345000000000000000000000000000000000000");
    BigNum e = 99;
    BigNum f = -99;
    BigNum g = BigNum("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    int cnt = 0; 
    int totalCnt = 0;
    
    cout << "Test for larger numbers:" << endl;
    
    cout << endl << "Test for '>' operator:" << endl;
    if((a > b) == 1) cnt++;
    cout << "1: " << (a > b) << " -- " << a << " > " << b << endl; 
    if((b > a) == 0) cnt++;
    cout << "0: " << (b > a) << " -- " << b << " > " << a << endl;
    if((c > a) == 1) cnt++;
	cout << "1: " << (c > a) << " -- " << c << " > " << a << endl;
	if((a > c) == 0) cnt++;
	cout << "0: " << (a > c) << " -- " << a << " > " << c << endl;
	if((b > d) == 1) cnt++;
	cout << "1: " << (b > d) << " -- " << b << " > " << d << endl;
	if((d > b) == 0) cnt++;
	cout << "0: " << (d > b) << " -- " << d << " > " << b << endl;
	if((a > e) == 1) cnt++;
	cout << "1: " << (a > e) << " -- " << a << " > " << e << endl;
	if((e > a) == 0) cnt++;
	cout << "0: " << (e > a) << " -- " << e << " > " << a << endl;
	if((f > b) == 1) cnt++;
	cout << "1: " << (f > b) << " -- " << f << " > " << b << endl;
	if((b > f) == 0) cnt++;
	cout << "0: " << (b > f) << " -- " << b << " > " << f << endl;
	if((a > g) == 0) cnt++;
	cout << "0: " << (a > g) << " -- " << a << " > " << g << endl;
	
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11)
		cout << "Test Passed!" << endl; 
	totalCnt = cnt;
	cnt = 0;
	
	cout << endl << "Test for '>=' operator:" << endl;
    if((a >= b) == 1) cnt++;
    cout << "1: " << (a >= b) << " -- " << a << " >= " << b << endl;
    if((b >= a) == 0) cnt++;
    cout << "0: " << (b >= a) << " -- " << b << " >= " << a << endl;
    if((c >= a) == 1) cnt++;
	cout << "1: " << (c >= a) << " -- " << c << " >= " << a << endl;
	if((a >= c) == 0) cnt++;
	cout << "0: " << (a >= c) << " -- " << a << " >= " << c << endl;
	if((b >= d) == 1) cnt++;
	cout << "1: " << (b >= d) << " -- " << b << " >= " << d << endl;
	if((d >= b) == 0) cnt++;
	cout << "0: " << (d >= b) << " -- " << d << " >= " << b << endl;
	if((a >= e) == 1) cnt++;
	cout << "1: " << (a >= e) << " -- " << a << " >= " << e << endl;
	if((e >= a) == 0) cnt++;
	cout << "0: " << (e >= a) << " -- " << e << " >= " << a << endl;
	if((f >= b) == 1) cnt++;
	cout << "1: " << (f >= b) << " -- " << f << " >= " << b << endl;
	if((b >= f) == 0) cnt++;
	cout << "0: " << (b >= f) << " -- " << b << " >= " << f << endl;
	if((a >= g) == 1) cnt++;
	cout << "1: " << (a >= g) << " -- " << a << " >= " << g << endl;
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << endl << "Test for '<' operator:" << endl;
    
    if((a < b) == 0) cnt++;
    cout << "0: " << (a < b) << " -- " << a << " < " << b << endl;
    if((b < a) == 1) cnt++;
    cout << "1: " << (b < a) << " -- " << b << " < " << a << endl;
    if((c < a) == 0) cnt++;
	cout << "0: " << (c < a) << " -- " << c << " < " << a << endl;
	if((a < c) == 1) cnt++;
	cout << "1: " << (a < c) << " -- " << a << " < " << c << endl;
	if((b < d) == 0) cnt++;
	cout << "0: " << (b < d) << " -- " << b << " < " << d << endl;
	if((d < b) == 1) cnt++;
	cout << "1: " << (d < b) << " -- " << d << " < " << b << endl;
	if((a < e) == 0) cnt++;
	cout << "0: " << (a < e) << " -- " << a << " < " << e << endl;
	if((e < a) == 1) cnt++;
	cout << "1: " << (e < a) << " -- " << e << " < " << a << endl;
	if((f < b) == 0) cnt++;
	cout << "0: " << (f < b) << " -- " << f << " < " << b << endl;
	if((b < f) == 1) cnt++;
	cout << "1: " << (b < f) << " -- " << b << " < " << f << endl;
	if((a > g) == 0) cnt++;
	cout << "0: " << (a < g) << " -- " << a << " < " << g << endl;
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << endl << "Test for '<=' operator:" << endl;
    if((a <= b) == 0) cnt++;
    cout << "0: " << (a <= b) << " -- " << a << " <= " << b << endl;
    if((b <= a) == 1) cnt++;
    cout << "1: " << (b <= a) << " -- " << b << " <= " << a << endl;
    if((c <= a) == 0) cnt++;
	cout << "0: " << (c <= a) << " -- " << c << " <= " << a << endl;
	if((a <= c) == 1) cnt++;
	cout << "1: " << (a <= c) << " -- " << a << " <= " << c << endl;
	if((b <= d) == 0) cnt++;
	cout << "0: " << (b <= d) << " -- " << b << " <= " << d << endl;
	if((d <= b) == 1) cnt++;
	cout << "1: " << (d <= b) << " -- " << d << " <= " << b << endl;
	if((a <= e) == 0) cnt++;
	cout << "0: " << (a <= e) << " -- " << a << " <= " << e << endl;
	if((e <= a) == 1) cnt++;
	cout << "1: " << (e <= a) << " -- " << e << " <= " << a << endl;
	if((f <= b) == 0) cnt++;
	cout << "0: " << (f <= b) << " -- " << f << " <= " << b << endl;
	if((b <= f) == 1) cnt++;
	cout << "1: " << (b <= f) << " -- " << b << " <= " << f << endl;
	if((a <= g) == 1) cnt++;
	cout << "1: " << (a <= g) << " -- " << a << " <= " << g << endl;
	
	if(cnt < 11) 
		cout << "Test Failed!" << endl;
	if(cnt == 11) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << endl << "Test for '==' operator:" << endl;
    
    if((a == b) == 0) cnt++;
    cout << "0: " << (a == b) << " -- " << a << " == " << b << endl;
    if((a == c) == 0) cnt++;
    cout << "0: " << (a == c) << " -- " << a << " == " << c << endl;
    if((a == g) == 1) cnt++;
    cout << "1: " << (a == g) << " -- " << g << " == " << g << endl;
    
    if(cnt < 3) 
		cout << "Test Failed!" << endl;
	if(cnt == 3) 
		cout << "Test Passed!" << endl; 
	totalCnt += cnt;
	cnt = 0;
    
    cout << endl << "Test for '!=' operator:" << endl;
    
    if((a == g) == 1) cnt++;
    cout << "1: " << (a != b) << " -- " << a << " != " << b << endl;
    if((a != c) == 1) cnt++;
    cout << "1: " << (a != c) << " -- " << a << " != " << c << endl;
    if((a != g) == 0) cnt++;
    cout << "0: " << (a != g) << " -- " << g << " != " << g << endl;
    
    if(cnt < 3) 
		cout << "Test Failed!" << endl;
	if(cnt == 3) 
		cout << "Test Passed!" << endl << endl; 
	totalCnt += cnt;
	cnt = 0;
	
	cout << "Total Large Number Tests Passed: " << endl;
	cout << totalCnt << "/50" << endl << endl;
	
	return totalCnt;
	
}

void operatorTest()
{
	int cnt = largeOPTest() + smallOPTest();
	cout << cnt << "/100" << endl;
	if(cnt == 100)
		cout << "Looks like you passed all of the tests. Nice work." << endl;
	else 
		cout << "Looks like you failed some tests. Better go back and look over your work" << endl;

}

void add()
{
	int cnt = 0;
	int totalCnt = 0;
	
	cout << "Addition Tester:" << endl;
	cout << "Simple Tests" << endl;
	
	BigNum a = 1;
	BigNum b = 2;
	BigNum c = -1;
	BigNum d = -2;
	BigNum e = 10;
	BigNum f = -20;
	BigNum g = 100;
	BigNum h = 9;
	BigNum i = 27;
	BigNum j = 150;
	BigNum k = 199;
	
	cout << a << " + " << a << " = " << "        2  :  " << a+a << endl;
	if((a+a) == 2) cnt++;
	cout << a << " + " << b << " = " << "        3  :  " << a+b << endl;
	if((a+b) == 3) cnt++;
	cout << b << " + " << a << " = " << "        3  :  " << b+a << endl;
	if((b+a) == 3) cnt++;
	cout << a << " + " << c << " = " << "       0  :  " << a+c << endl;
	if((a+c) == 0) cnt++;
	cout << a << " + " << d << " = " << "      -1  :  " << a+d << endl;
	if((a+d) == -1) cnt++;
	cout << a << " + " << e << " = " << "      11  :  " << a+e << endl;
	if((a+e) == 11) cnt++;
	cout << a << " + " << f << " = " << "    -19  :  " << a+f << endl;
	if((a+f) == -19) cnt++;
	cout << a << " + " << g << " = " << "    101  :  " << a+g << endl;
	if((a+g) == 101) cnt++;
	cout << g << " + " << c << " = " << "    99  :  " << g+c << endl;
	if((g+c) == 99) cnt++;
	cout << h << " + " << a << " = " << "       10  :  " << h+a << endl;
	if((h+a) == 10) cnt++;
	cout << h << " + " << i << " = " << "      36  :  " << h+i << endl;
	if((h+i) == 36) cnt++;
	cout << j << " + " << j << " = " << "  300  :  " << j+j << endl;
	if((j+j) == 300) cnt++;
	cout << k << " + " << k << " = " << "  398  :  " << k+k << endl;
	if((k+k) == 398) cnt++;
	cout << k << " + " << a << " = " << "    200  :  " << k+a << endl;
	if((k+a) == 200) cnt++;
	cout << i << " + " << k << " = " << "   226  :  " << i+k << endl;
	if((i+k) == 226) cnt++;
	
	if(cnt < 15)
		cout << "Tests Failed!" << endl << endl;
	if(cnt == 15)
		cout << "Tests Passed!" << endl << endl;
	cout << cnt << "/15" << endl;
	totalCnt = cnt;
	cout << totalCnt;
	cnt = 0;
}

void sub()
{
	int cnt = 0;
	int totalCnt = 0;
	
	cout << "Subtraction Tester:" << endl;
	cout << "Simple Tests" << endl;
	
	BigNum a = 1;
	BigNum b = 2;
	BigNum c = -1;
	BigNum d = -2;
	BigNum e = 15;
	BigNum f = -19;
	BigNum g = 100;
	BigNum h = 10;
	BigNum i = 27;
	BigNum j = 1000;
	BigNum k = 199;
	
	cout << a << " - " << a << " = " << "        0  :  " << a-a << endl;
	if((a-a) == 0) cnt++;
	cout << a << " - " << b << " = " << "       -1  :  " << a-b << endl;
	if((a-b) == -1) cnt++;
	cout << b << " - " << a << " = " << "        1  :  " << b-a << endl;
	if((b-a) == 1) cnt++;
	cout << a << " - " << c << " = " << "       2  :  " << a-c << endl;
	if((a-c) == 2) cnt++;
	cout << a << " - " << d << " = " << "       3  :  " << a-d << endl;
	if((a-d) == 3) cnt++;
	cout << a << " - " << e << " = " << "     -14  :  " << a-e << endl;
	if((a-e) == -14) cnt++;
	cout << f << " - " << a << " = " << "    -20  :  " << f-a << endl;
	if((f-a) == -20) cnt++;
	cout << a << " - " << g << " = " << "    -99  :  " << a-g << endl;
	if((a-g) == -99) cnt++;
	cout << c << " - " << g << " = " << "  -101  :  " << c-g << endl;
	if((c-g) == -101) cnt++;
	cout << i << " - " << h << " = " << "     17  :  " << i-h << endl;
	if((i-h) == 17) cnt++;
	cout << j << " - " << a << " = " << "   999  :  " << j-a << endl;
	if((j-a) == 999) cnt++;
	cout << j << " - " << b << " = " << "   998  :  " << j-b << endl;
	if((j-b) == 998) cnt++;
	cout << j << " - " << c << " = " << " 1001  :  " << j-c << endl;
	if((j-c) == 1001) cnt++;
	cout << f << " - " << k << " = " << " -218  :  " << f-k << endl;
	if((f-k) == -218) cnt++;
	cout << k << " - " << j << " = " << "-801  :  " << k-j << endl;
	if((k-j) == -801) cnt++;
	
	if(cnt < 15)
		cout << "Tests Failed!" << endl << endl;
	if(cnt == 15)
		cout << "Tests Passed!" << endl << endl;
	cout << cnt << "/15" << endl;
	totalCnt = cnt;
	cout << totalCnt;
	cnt = 0;
	
	
	
}

void mult()
{
	
	
	
}

void div()
{
	BigNum a;
	cin >> a;
	
	cout << factorial(a) << endl;
}

void other()
{
	BigNum a = 10;
	BigNum b = 9;
	BigNum c = 1;
	BigNum d = 27;
	BigNum e;
	BigNum f;
	cin >> e;
	cin >> f;
	e+=f;
	
}

void everySub()
{
	BigNum a;
	BigNum b;
	int high;
	int low;
	cout << "Enter lower bound value: ";
	cin >> low;
	cout << "Enter upper bound value: ";
	cin >> high;
	int test = 0;
	int fail = 0;
	int i = 0;
	int k = 0;
	for(i = low; i <= high; i++)
	{
		b = i;
		for(k = low; k <= high; k++)
			{
				test++;
				a = k;
				if((b-a) != (i-k))
				{
					fail++;
					cout << "TEST FAIL:" << endl;
					cout << "i-k = " << i << " - " << k << " = " << i-k << endl;
					cout << "b-a = " << b << " - " << a << " = " << b-a << endl;
					cout << endl;
				}
			}
		
	}
	cout << "May be wrong because over the size of an int:" << endl;
	cout << test-fail << "/" << test << endl;
	cout << fail << " Tests failed" << endl;
}

void everyAdd()
{
	BigNum a;
	BigNum b;
	
	int i = 0;
	int k = 0;
	int low;
	int high;
	cout << "Enter lower bound value: ";
	cin >> low;
	cout << "Enter upper bound value: ";
	cin >> high;
	int test = 0;
	int fail = 0;
	for(i = low; i <= high; i++)
	{
		b = i;
		for(k = low; k <= high; k++)
			{
				test++;
				a = k;
				if((b+a) != (i+k))
				{
					fail++;
					cout << "TEST FAIL:" << endl;
					cout << "i+k = " << i << " + " << k << " = " << i+k << endl;
					cout << "b+a = " << b << " + " << a << " = " << b+a << endl;
					cout << endl;
				}
			}
		
	}
	cout << "May be wrong because over the size of an int:" << endl;
	cout << test-fail << "/" << test << endl;
}

void everyMult()
{
	BigNum a;
	BigNum b;
	int high;
	int low;
	cout << "Enter lower bound value: ";
	cin >> low;
	cout << "Enter upper bound value: ";
	cin >> high;
	int test = 0;
	int fail = 0;
	int i = 0;
	int k = 0;
	for(i = low; i <= high; i++)
	{
		b = i;
		for(k = low; k <= high; k++)
			{
				test++;
				a = k;
				if((b*a) != (i*k))
				{
					fail++;
					cout << "TEST FAIL:" << endl;
					cout << "i*k = " << i << " * " << k << " = " << i*k << endl;
					cout << "b*a = " << b << " * " << a << " = " << b*a << endl;
					cout << endl;
				}
			}
		
	}
	cout << "May be wrong because over the size of an int:" << endl;
	cout << test-fail << "/" << test << endl;
	cout << fail << " Tests failed" << endl;
}

int main()
{
	int menu;
	while(menu != 11)
	{
		cout << endl << endl;
		cout << "MENU" << endl;
		cout << " 1: Dr. White's Tests(FIXED)" << endl;
		cout << " 2: Operators('<'  '>'  '<='  '>='  '=='  '!=')" << endl;
		cout << " 3: Addition" << endl;
		cout << " 4: Subtraction" << endl;
		cout << " 5: Every Add" << endl;
		cout << " 6: Every Subtraction" << endl;
		cout << " 7: Multiplication" << endl;
		cout << " 8: Division" << endl;
		cout << " 9: Other" << endl;
		cout << "10: cin/cout tester" << endl;
		cout << "11: Exit" << endl << endl;
		cout << ":";
		cin >> menu;
		if(menu == 1)
		{
		grade.open ("grade.txt");
		grade.close();
		signal (SIGSEGV, termination_handler);
		signal (SIGABRT, termination_handler);
		signal (SIGFPE, termination_handler);
		signal (SIGILL, termination_handler);
		signal (SIGSEGV, termination_handler);
		signal (SIGTERM, termination_handler);
		for (testNo = 0; testNo < TOTALTESTS; testNo++){
			tester();
		}
		grade.close();
	}
		if(menu == 2)
			operatorTest();
		if(menu == 3)
			add();
		if(menu == 4)
			sub();
		if(menu == 5)
			everyAdd();	
		if(menu == 6)
			everySub();
		if(menu == 7)
			everyMult();
		if(menu == 8)
			div();
		if(menu == 9)
			other();
		if(menu == 10)
		{
			BigNum a;
			cin >> a;
			cout << a << endl;
			cout << a.printBigNum() << endl;
		}
	}
	return 0;
}
