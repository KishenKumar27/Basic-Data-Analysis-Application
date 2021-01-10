/*///////////////////////////////////////////////////////////////////////////////////
TCP1101 Assignment Part 2
Trimester 1, 2020/2021
by << Satishnair A/L Krishnan >>
Team Leader: Satishnair A/L Krishnan, 019-7814961, 1181103485@student.mmu.edu.my
Team members:
Avinash Imanuel a/l Gana Raj Imanuel, 016-3759349, 1181103370@student.mmu.edu.my
Ahmad Luqman bin Ahmad Lutpi, 019-3868897, 1191101434@student.mmu.edu.my
Kishen Kumar A/L Sivalingam, 012-3399367, 1191101423@student.mmu.edu.my

*////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------
//Programmer: Satishnair Krishnan
//Median(Function Prototype)
double findMedian_a( vector<int> , int );   int Median_Sort_Value_Maths();
double findMedian_b( vector<int> , int );   int Median_Sort_Value_Science();
double findMedian_c( vector<int> , int );   int Median_Sort_Value_Malay();
//Mean
double findAverage_a( vector<int>, int);    int Mean_Value_Maths();
double findAverage_b( vector<int>, int);    int Mean_Value_Science();
double findAverage_c( vector<int>, int);    int Mean_Value_Malay();
//Minimum
double findMinimum_a( vector<int>, int);    int Minimum_Value_Maths();
double findMinimum_b( vector<int> , int);   int Minimum_Value_Science();
double findMinimum_c( vector<int>, int);    int Minimum_Value_Malay();
//Maximum
double findMaximum_a( vector<int>, int);    int Maximum_Value_Maths();
double findMaximum_b( vector<int>, int);    int Maximum_Value_Science();
double findMaximum_c( vector<int>, int);    int Maximum_Value_Malay();
//Pearson’s Correlation
float correlationCoefficient_a(vector<int>, vector<int>, vector<int>, int);  int correlationCoefficient_Maths();
float correlationCoefficient_b(vector<int>, vector<int>, vector<int>, int);  int correlationCoefficient_BS();
float correlationCoefficient_c(vector<int>, vector<int>, vector<int>, int);  int correlationCoefficient_MB();

//-----------------------------------------------------------------------------------------------------------------------
//Programmer: Ahmad Luqman
//Variance (Function Prototype)
double variance (vector <int>, int);    int Variance_Value_Maths ();
double variance2 (vector <int>, int);   int Variance_Value_Science ();
double variance3 (vector <int>, int);   int Variance_Value_Malay ();

//Standard Deviation (Function Prototype)
double standardDeviation (vector <int>, int);   int Standard_Deviation_Maths ();
double standardDeviation2 (vector <int>, int);  int Standard_Deviation_Science ();
double standardDeviation3 (vector <int>, int);  int Standard_Deviation_Malay ();

//Frequency (Function Prototype)
int Frequency_Maths(); int Frequency_Science();   int Frequency_Malay();

//-----------------------------------------------------------------------------------------------------------------------
//Programmer: Avinash Imanuel
//Histogram
float findmaxfirst(vector<int> X, int n);
float histogramfreq(vector<int> X, int n);
int Plot_Histogram_Maths(); int Plot_Histogram_Science(); int Plot_Histogram_Malay();

//Statistical Report in TEXT and HTML files.
void Statistical_Report_TXT();  int MathsReport(); int ScienceReport(); int MalayReport();
void Statistical_Report_HTML(); int Maths_HTML(); int Science_HTML(); int Malay_HTML();

//-----------------------------------------------------------------------------------------------------------------------
//Programmer: Kishen Kumar
// Linear Regression Line(Function Prototype)
float linear_a(vector<int>, vector<int>, vector<int>, int);  int regressionLine_MS();
float linear_b(vector<int>, vector<int>, vector<int>, int);  int regressionline_BS();
float linear_c(vector<int>, vector<int>, vector<int>, int);  int regressionline_MB();



// Sorting data(Function Prototype)
vector <int> ascending(vector <int>, int); vector <int> descending(vector <int>, vector <int>);
int Ascending_Descending_Maths();   int Ascending_Descending_Science(); int Ascending_Descending_Malay();


// Table's Below Mean and Above mean(Function Prototype)
double mean(vector <int>, int); double distinctmean(vector <int>, int); int  Table_below_mean_Table_above_mean_Maths();
double mean2(vector <int>, int); double distinctmean2(vector <int>, int); int  Table_below_mean_Table_above_mean_Science();
double mean3(vector <int>, int); double distinctmean3(vector <int>, int); int  Table_below_mean_Table_above_mean_Malay();

//-----------------------------------------------------------------------------------------------------------------------


//All the functions of Menu
void main_menu(); void What_Sub_Pearson(); void What_Sub_Regression(); void MathsStatsMenu(); void ScienceStatsMenu(); void MalayStatsMenu();


//-----------------------------------------------------------------------------------------------------------------------
//INFILING DATA100 FIRST
/**********************
Programmer: 	Satishnair Krishnan
Name:       	vector<int> openMS, vector<int> openSC, vector<int> openBM
task:           Reads the data100.csv file and infile it to the vector.
data in:    	infilling ist of data values to their respective vectors.
data returned:  data values under the row of every subject.
Referred to: https://www.geeksforgeeks.org/csv-file-management-using-c/
**********************/
vector<int> openMS()
{
ifstream infile;
infile.open("data100.csv");
string q;
string x;
getline(infile, x);
getline(infile, q);
getline(infile,x);
int rows = stoi(x);
vector<int> mathVector;

for (int j=0; j < rows; j++){
	for (int i=0; i<5; i++){
		if (i != 4){
			getline(infile, x, ',');// ","=reads till the end
			int m= stoi(x);//stoi=string to integer
			if (i == 2){
				mathVector.push_back(m);//push_back=inserting new data
			}
		}
    }
}

infile.close();
return mathVector;
}

vector<int> openSC()
{
ifstream infile1;
infile1.open("data100.csv");
string q;
string x;
getline(infile1, x);
getline(infile1, q);
getline(infile1,x);
int rows = stoi(x);
vector<int> sVector;

for (int j=0; j < rows; j++){
	for (int i=0; i<5; i++){
		if (i != 4){
			getline(infile1, x, ',');
			int m= stoi(x);
			if (i == 3){
				sVector.push_back(m);
			}
		}
    }
}

infile1.close();
return sVector;
}

vector<int> openBM()
{
ifstream infile;
infile.open("data100.csv");
string q;
string x;
getline(infile, x);
getline(infile, q);
getline(infile,x);
int rows = stoi(x);
vector<int> maVector;

for (int j=0; j < rows; j++){
	for (int i=0; i<5; i++){
		if (i != 4){
			getline(infile, x, ','); // ","=reads till the end
			int m = stoi(x); //stoi=string to integer
		}
		if (i == 4){
            getline(infile, x, '\n'); // "\n"=reads till the end
            int m = stoi(x); //stoi=string to integer
            maVector.push_back(m); //push_back=inserting new data
			}

    }
}
infile.close();
return maVector;
}


//--------------------------------------------------------------------------

//CALCULATIONS FOR MATHS
//FINDING TABLE BELOW MEAN AND TABLE ABOVE MEAN
/**********************
Programmer: 	Kishen Kumar
Name:       	mean, mean2, mean3
task:           Calculate the mean from the list of data values of math subject
data in:    	List of data values of math subject in an ordered vector and the size
                of the data value.
data returned:  The mean from the list of data values of math subject
Referred to:	Gaddis, C++ From Control Structures Through Objects, 8th Ed.
**********************/
 double mean(vector <int> X, int n)
{
   float sum;
   double mean;


    for(int i=0; i<n; i++){
        sum= sum + X[i];
        }
    mean = double(sum) / n;
    return mean;
}


/**********************
Programmer: 	Kishen Kumar
Name:       	distinctmean, distinctmean2, distinctmean3,
task:           Display the data which is lesser than the mean under the table below
                mean in the sorted form and also display the data which is
                higher than the mean under the table above mean in the sorted form
                for the math subject
data in:    	List of data values for the math subject in an ordered vector and the size
                of the data value.
data returned:  The data values of the math subject which are higher and lower than the mean value
Referred to:	Gaddis, C++ From Control Structures Through Objects, 8th Ed.
                kartik. (2018). Sorting a vector in C++.
Retrieved from: https://www.geeksforgeeks.org/sorting-a-vector-in-c/
**********************/
double distinctmean(vector <int> X, int n)
{

    double x_mean;
    x_mean = mean(X, n);

    sort(X.begin(), X.end());

    cout << endl;
    cout<<"SUBJECT NAME: MATH\n";
    cout << "MATH MEAN = " << x_mean << endl;
    cout << "---------------------" << endl;
    cout << "Table below math mean" << endl;
    cout << "---------------------" << endl;

    for (int i =0; i < n; i++)
    {
        if (X[i] < x_mean)
        {
            cout << X[i] << endl;
        }
    }

    cout << endl;
    cout << "Math mean = " << x_mean << endl << endl;

    cout << "---------------------" << endl;
    cout << "Table above math mean" << endl;
    cout << "---------------------" << endl;

    for (int i =0; i < n; i++)
    {
        if (X[i] > x_mean)
        {
            cout << X[i] << endl;

        }

    }

    cout << endl;
   cout << "Math mean = ";
    return x_mean;
}

/**********************
Programmer: 	Kishen Kumar
Name:       	Table_below_mean_Table_above_mean_Maths, Table_below_mean_Table_above_mean_Science, Table_below_mean_Table_above_mean_Malay,
task:           Read from the list of data values and call the function
                of calculating table below mean and table above mean with
                passing of the list of data values and the size of it to the function
                for the math subject.
data in:    	List of data values in an ordered vector and the size
                of the data value for the math subject
data returned:  The data values which are higher and lower than the mean value for the
                math subject
Referred to:	Gaddis, C++ From Control Structures Through Objects, 8th Ed.
**********************/
int  Table_below_mean_Table_above_mean_Maths()
{
    system("cls");
    vector<int> X = openMS();
	int n = X.size();
	cout << distinctmean(X, n) << endl;
    system("pause");
    MathsStatsMenu();
    return 0;

}



//FUNCTION FOR CALCULATING VARIANCE
/**********************
Programmer: Ahmad Luqman
Name:    variance, variance2, variance3
 task:    Calculates the variance of the data values in the vector.
data in:   List of data values in a vector and the size of the data value.
data returned:  The value of the variance of the subject.
Referred to: https://www.programiz.com/cpp-programming/examples/standard-deviation
**********************/
double variance(vector<int> a, int n)

{
    // Compute mean (average of elements)
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
     double mean = sum / n;

    // Compute sum squared
    // differences with mean.
     int count = 1;
    double sqDiff = 0;
    for (int i = 0; i < n; i++)
        sqDiff += (a[i] - mean) * (a[i] - mean);
        count = count+ 1;
    return sqDiff / (n-1);
}

/**********************
Programmer: Ahmad Luqman
Name:    Variance_Value_Science, Variance_Value_Maths, Variance_Value_BM
 task:    Print the method to find the variance and the value of the Variance.
data in:
data returned:
Referred to:
**********************/
//DRIVER CODE
int Variance_Value_Maths()
{
    system("cls");
    vector<int> a = openMS();
	int n = a.size();

   cout<<"---------------------------"<<endl;
   cout << "The Method To Find Variance"<<endl;
   cout<<"---------------------------"<<endl;
   cout<< "Mean     =(Sum of maths scores)/(number of scores)"<<endl;
   cout<< "Variance =((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "         ="<<variance(a, n) << endl<< endl;
    system("pause");
    MathsStatsMenu();
    return 0;
}


//FUNCTION FOR CALCULATING STANDARD DEVIATION
/**********************
Programmer: Ahmad Luqman
Name:       standardDeviation, standardDeviation2, standardDeviation3
 task:        Calculates the Standard Deviation of the data values in the vector.
data in:   List of data values in a vector and the size of the data value.
data returned:  The value of standard deviation for the subject.
Referred to: https://www.programiz.com/cpp-programming/examples/standard-deviation
**********************/
double standardDeviation(vector<int> a,int n)
{
    return sqrt(variance(a, n));
}


/**********************
Programmer: Ahmad Luqman
Name:       Standard_Deviation_Science, Standard_Deviation_Maths, Standard_Deviation_Malay,
 task:        Print the method to find Standard Deviation and the value of Standard Deviation.
data in:
data returned:
Referred to:
**********************/
//DRIVER CODE
int Standard_Deviation_Maths()
{
    system("cls");
    vector<int> a = openMS();
	int n = a.size();

   cout<<"-------------------------------------"<<endl;
   cout << "The Method To Find Standard Deviation"<<endl;
   cout<<"-------------------------------------"<<endl;
   cout<< "Mean               =(Sum of maths scores)/(number of scores)"<<endl;
   cout<< "Variance           =((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "Standard Deviation =sqrt((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "                   ="<< standardDeviation(a, n) << endl;
    system("pause");
    MathsStatsMenu();
    return 0;
}

//FINDING MEDIAN
/**********************
Programmer: 	Satishnair Krishnan
Name:       	findMedian_a, findMedian_b, findMedian_c.
task:           Calculates Median of the data values in the vector.
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:  The elements before sorting in the vector and after sorting
                then calculates the median.
Referred to: https://www.geeksforgeeks.org/sorting-a-vector-in-c/
**********************/

double findMedian_a( vector<int> a, int n)
{
        cout<<"Elements before sorting =>" <<endl<<endl;
	    for (auto i : a)
          cout << " " << i << " ";
        cout<<endl<<endl;

 	    // First we sort the array
	    cout << "Sorted Data =>" << endl<<endl;
	    sort(a.begin(), a.end());

	    for (auto x : a)
          cout << " " << x << " ";

        cout<<endl<<endl;
    	cout<< "Median = {(n + 1) / 2}th value"<<endl;
        cout << "Median = ";


        // If size of the a[] is even
	if (n % 2 == 0) {
		// Find the average of value at
		// index N/2 and (N-1)/2
		return (double)(a[(n - 1) / 2] + a[n / 2])/ 2.0;
	}

	// If size of the a[] is odd
	else {
		// Value at index (N/2)th
		// is the median
		return (double)a[n / 2];
	}

}

/**********************
Programmer: 	Satishnair Krishnan
Name:       	Median_Sort_Value_Maths, Median_Sort_Value_Science, Median_Sort_Value_Malay,
task:           prints out the elements before sorting in the vector and after sorting
                then the median.
data in:
data returned:
Referred to: https://www.geeksforgeeks.org/sorting-a-vector-in-c/
**********************/

int Median_Sort_Value_Maths()
{
    system("cls");
    vector<int> a = openMS();
	int n = a.size();
    cout<<findMedian_a(a, n)<<endl;
    system("pause");
    MathsStatsMenu();
	return 0;
}



//FINDING MEAN VALUE
/**********************
Programmer: 	Satishnair Krishnan
Name:       	findAverage_a, findAverage_b, findAverage_c.
task:           Calculates the mean from the vector.
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:  mean of the data values in the vector input.
Referred to:
**********************/
double findAverage_a( vector<int> a, int n)
{
    system("cls");
    double mean;
    int sum=0;

    for(int i=0; i<n; i++){
        sum= sum + a[i];
        }
    mean = double(sum) / n;
    cout<< endl<< endl;
    cout<< "Mean= (Sum of scores)/ (number of scores)" << endl;
    cout<< "    = (" <<sum << ")/(" << n << ")"<<endl;
    cout <<"    = ";
    return mean;

}

/**********************
Programmer: 	Satishnair Krishnan
Name:       	Mean_Value_Maths, Mean_Value_Science, Mean_Value_Malay,
task:           prints out the mean of the vector.
data in:
data returned:
Referred to:
**********************/
int Mean_Value_Maths()
{
    vector<int> a = openMS();
	int n = a.size();
	cout << findAverage_a(a, n) << endl;
    system("pause");
    MathsStatsMenu();
	return 0;
}



//FINDING MINIMUM VALUE
/**********************
Programmer: 	Satishnair Krishnan
Name:       	findMinimum_a, findMinimum_b, findMinimum_c,
task:           Calculates the minimum value from the data values in the vector.
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:  minimum of the data values in the vector input.
Referred to:
**********************/
double findMinimum_a( vector<int> a, int n)
{

int minimum;
minimum = a[0];
for(int i=0; i<n; i++){
	if(a[i] < minimum){
		minimum = a[i];
	}
}
cout<< "First we read the Maths scores which are 100 integers."<<endl;
cout<<"Then, we pick the Least value in that row."<<endl<<endl;
cout<<"The minimum value of Maths subject is: "<<endl;
 return minimum;
}

/**********************
Programmer: 	Satishnair Krishnan
Name:       	Minimum_Value_Maths ,Minimum_Value_Science ,Minimum_Value_Malay ,
task:           prints out the minimum value of the vector.
data in:
data returned:
Referred to:
**********************/
int Minimum_Value_Maths()
{
    system("cls");
    vector<int> a = openMS();
	int n = a.size();
	cout << findMinimum_a(a, n) << endl<< endl;
    system("pause");
    MathsStatsMenu();
   return 0;
}




//FINDING MAXIMUM VALUE
/**********************
Programmer: 	Satishnair Krishnan
Name:       	findMaximum_a, findMaximum_b, findMaximum_c,
task:           Calculates the maximum value from the data values in the vector.
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:  maximum of the data values in the vector input.
Referred to:
**********************/
double findMaximum_a( vector<int> a, int n)
{

int maximum;
maximum = a[0];
for(int i=0; i<n; i++){
	if(a[i] > maximum){
		maximum = a[i];
	}
}
cout<< "First we read the Maths scores which are 100 integers."<<endl;
cout<<"Then, we pick the Least value in that row."<<endl<<endl;
cout<<"The maximum value of Maths subject is: "<<endl;
 return maximum;
}


/**********************
Programmer: 	Satishnair Krishnan
Name:       	Maximum_Value_Maths ,Maximum_Value_Science ,Maximum_Value_Malay ,
task:           prints out the minimum value of the vector.
data in:
data returned:
Referred to:
**********************/
int Maximum_Value_Maths()
{
    system("cls");
    vector<int> a = openMS();
	int n = a.size();
	cout << findMaximum_a(a, n) << endl<< endl;
    system("pause");
    MathsStatsMenu();
   return 0;
}

//--------------------------------------------------------------------------
//CALCULATIONS FOR SCIENCE
//FINDING TABLE BELOW MEAN AND TABLE ABOVE MEAN
//DONE BY: KISHEN KUMAR
 double mean2(vector <int> X, int n)
{
   float sum;
   double mean;


    for(int i=0; i<n; i++){
        sum= sum + X[i];
        }
    mean = double(sum) / n;
    return mean;
}


double distinctmean2(vector <int> X, int n)
{

    double x_mean;
    x_mean = mean2(X, n);

    sort(X.begin(), X.end());

    cout << endl;
    cout<<"SUBJECT NAME: SCIENCE\n";
    cout << "SCIENCE MEAN = " << x_mean << endl;
    cout << "------------------------" << endl;
    cout << "Table below Science mean" << endl;
    cout << "------------------------" << endl;

    for (int i =0; i < n; i++)
    {
        if (X[i] < x_mean)
        {
            cout << X[i] << endl;
        }
    }

    cout << endl;
    cout << "Science mean = " << x_mean << endl << endl;

    cout << "------------------------" << endl;
    cout << "Table above Science mean" << endl;
    cout << "------------------------" << endl;

    for (int i =0; i < n; i++)
    {
        if (X[i] > x_mean)
        {
            cout << X[i] << endl;
        }
    }

    cout << endl;
   cout << "Science mean = ";
    return x_mean;
}


int  Table_below_mean_Table_above_mean_Science()
{
    system("cls");
    vector<int> X = openSC();
	int n = X.size();
	cout << distinctmean2(X, n) << endl;
    system("pause");
    ScienceStatsMenu();
    return 0;
}




//FINDING VARIANCE AND STANDARD DEVIATION
//DONE BY: AHMAD LUQMAN
double variance2(vector<int> a, int n)

{
    // Compute mean (average of elements)
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
     double mean = sum / n;

    // Compute sum squared
    // differences with mean.
     int count = 1;
    double sqDiff = 0;
    for (int i = 0; i < n; i++)
        sqDiff += (a[i] - mean) * (a[i] - mean);
        count = count+ 1;


    return sqDiff / (n-1);
}
//DONE BY: AHMAD LUQMAN
double standardDeviation2(vector<int> a,int n)
{
    return sqrt(variance2(a, n));
}

// Driver Code
int Variance_Value_Science()
{
    system("cls");
    vector<int> a = openSC();
	int n = a.size();

   cout<<"---------------------------"<<endl;
   cout << "The Method To Find Variance"<<endl;
   cout<<"---------------------------"<<endl;
   cout<< "Mean     =(Sum of maths scores)/(number of scores)"<<endl;
   cout<< "Variance =((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "         ="<< variance2(a, n) << endl<< endl;
    system("pause");
    ScienceStatsMenu();
    return 0;
}

int Standard_Deviation_Science()
{
    system("cls");
    vector<int> a = openSC();
	int n = a.size();

   cout<<"-------------------------------------"<<endl;
   cout << "The Method To Find Standard Deviation"<<endl;
   cout<<"-------------------------------------"<<endl;
   cout<< "Mean               =(Sum of maths scores)/(number of scores)"<<endl;
   cout<< "Variance           =((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "Standard Deviation =sqrt((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "                   ="<< standardDeviation2(a, n) << endl;
    system("pause");
    ScienceStatsMenu();
	return 0;

}

//FINDING MEDIAN
//DONE BY: SATISHNAIR
double findMedian_b( vector<int> a, int n)
{
        cout<<"Elements before sorting =>" <<endl<<endl;
	    for (auto i : a)
          cout << " " << i << " ";
        cout<<endl<<endl;

 	    // First we sort the array
	    cout << "Sorted Data =>" << endl<<endl;
	    sort(a.begin(), a.end());

	    for (auto x : a)
          cout << " " << x << " ";

        cout<<endl<<endl;
    	cout<< "Median = {(n + 1) / 2}th value"<<endl;
        cout << "Median = ";


        // If size of the a[] is even
	if (n % 2 == 0) {
		// Find the average of value at
		// index N/2 and (N-1)/2
		return (double)(a[(n - 1) / 2] + a[n / 2])/ 2.0;
	}

	// If size of the a[] is odd
	else {
		// Value at index (N/2)th
		// is the median
		return (double)a[n / 2];
	}
}

int Median_Sort_Value_Science()
{
    system("cls");
    vector<int> a = openSC();
	int n = a.size();
	cout << findMedian_b(a, n) << endl<< endl;
    system("pause");
    ScienceStatsMenu();
	return 0;
}


//FINDING MEAN VALUE
//DONE BY: SATISHNAIR
double findAverage_b( vector<int> a, int n)
{
    system("cls");
    double mean;
    int sum=0;

    for(int i=0; i<n; i++){
        sum= sum + a[i];
        }
    mean = double(sum) / n;
    cout<< endl<< endl;
    cout<< "Mean= (Sum of scores)/ (number of scores)" << endl;
    cout<< "    = (" <<sum << ")/(" << n << ")"<<endl;
    cout <<"    = ";
    return mean;

}
int Mean_Value_Science()
{
    vector<int> a = openSC();
	int n = a.size();
	cout << findAverage_b(a, n) << endl;
    system("pause");
    ScienceStatsMenu();
	return 0;
}



//FINDING MINIMUM VALUE
//DONE BY: SATISHNAR
double findMinimum_b( vector<int> a, int n)
{

int sminimum;
sminimum = a[0];
for(int i=0; i<n; i++){
	if(a[i] < sminimum){
		sminimum = a[i];
	}
}
cout<< "First we read the Science scores which are 100 integers."<<endl;
cout<<"Then, we pick the Least value in that row."<<endl<<endl;
cout<<"The minimum value of Science subject is: "<<endl;
 return sminimum;
}


int Minimum_Value_Science()
{
    system("cls");
    vector<int> a = openSC();
	int n = a.size();
	cout << findMinimum_b(a, n) << endl<< endl;
    system("pause");
    ScienceStatsMenu();
   return 0;
}



//FINDING MAXIMUM VALUE
//DONE BY: SATISHNAIR
double findMaximum_b( vector<int> a, int n)
{

int smaximum;
smaximum = a[0];
for(int i=0; i<n; i++){
	if(a[i] > smaximum){
		smaximum = a[i];
	}
}
cout<< "First we read the Science scores which are 100 integers."<<endl;
cout<<"Then, we pick the Highest value in that row."<<endl<<endl;
cout<<"The maximum value of Science subject is: "<<endl;
 return smaximum;
}


int Maximum_Value_Science()
{
    system("cls");
    vector<int> a = openSC();
	int n = a.size();
	cout << findMaximum_b(a, n) << endl<< endl;
    system("pause");
    ScienceStatsMenu();
   return 0;
}


//--------------------------------------------------------------------------
//BAHASA MELAYU CALCULATIONS
//FINDING TABLE BELOW MEAN AND TABLE ABOVE MEAN
//DONE BY: KISHEN KUMAR
 double mean3(vector <int> X, int n)
{
   float sum;
   double mean;


    for(int i=0; i<n; i++){
        sum= sum + X[i];
        }
    mean = double(sum) / n;
    return mean;
}


double distinctmean3(vector <int> X, int n)
{

    double x_mean;
    x_mean = mean3(X, n);

    sort(X.begin(), X.end());

    cout << endl;
    cout<<"SUBJECT NAME: MALAY\n";
    cout << "MALAY MEAN = " << x_mean << endl;
    cout << "----------------------" << endl;
    cout << "Table below Malay mean" << endl;
    cout << "----------------------" << endl;

    for (int i =0; i < n; i++)
    {
        if (X[i] < x_mean)
        {
            cout << X[i] << endl;
        }
    }

    cout << endl;
    cout << "Malay mean = " << x_mean << endl << endl;
    cout << "----------------------" << endl;
    cout << "Table above Malay mean" << endl;
    cout << "----------------------" << endl;

    for (int i =0; i < n; i++)
    {
        if (X[i] > x_mean)
        {
            cout << X[i] << endl;
        }
    }

    cout << endl;
   cout << "Malay mean = ";
    return x_mean;
}


int  Table_below_mean_Table_above_mean_Malay()
{
    system("cls");
    vector<int> X = openBM();
	int n = X.size();
	cout << distinctmean3(X, n) << endl;
    system("pause");
    MalayStatsMenu();
    return 0;
}

//FINDING VARIANCE AND STANDARD DEVIATION
//DONE BY: AHMAD LUQMAN
double variance3(vector<int> a, int n)

{
    // Compute mean (average of elements)
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
     double mean = sum / n;

    // Compute sum squared
    // differences with mean.
     int count = 1;
    double sqDiff = 0;
    for (int i = 0; i < n; i++)
        sqDiff += (a[i] - mean) * (a[i] - mean);
        count = count+ 1;
    return sqDiff / (n-1);
}

//DONE BY: AHMAD LUQMAN
double standardDeviation3(vector<int> a,int n)
{
    return sqrt(variance3(a, n));
}

// Driver Code
int Variance_Value_Malay()
{
    system("cls");
    vector<int> a = openBM();
	int n = a.size();

   cout<<"---------------------------"<<endl;
   cout << "The Method To Find Variance"<<endl;
   cout<<"---------------------------"<<endl;
   cout<< "Mean     =(Sum of maths scores)/(number of scores)"<<endl;
   cout<< "Variance =((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "         ="<< variance3(a, n) << endl<< endl;
    system("pause");

    MalayStatsMenu();
    return 0;
}

int Standard_Deviation_Malay()
{
    system("cls");
    vector<int> a = openBM();
	int n = a.size();

   cout<<"-------------------------------------"<<endl;
   cout << "The Method To Find Standard Deviation"<<endl;
   cout<<"-------------------------------------"<<endl;
   cout<< "Mean               =(Sum of maths scores)/(number of scores)"<<endl;
   cout<< "Variance           =((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "Standard Deviation =sqrt((value-mean)*(value-mean))/(n-1)"<<endl;
   cout<< "                   ="<< standardDeviation3(a, n) << endl;
    system("pause");
    MalayStatsMenu();
	return 0;

}


//FINDING MEDIAN
double findMedian_c( vector<int> a, int n)
{
        cout<<"Elements before sorting =>" <<endl<<endl;
	    for (auto i : a)
          cout << " " << i << " ";
        cout<<endl<<endl;

 	    // First we sort the array
	    cout << "Sorted Data =>" << endl<<endl;
	    sort(a.begin(), a.end());

	    for (auto x : a)
          cout << " " << x << " ";

        cout<<endl<<endl;
    	cout<< "Median = {(n + 1) / 2}th value"<<endl;
        cout << "Median = ";


        // If size of the a[] is even
	if (n % 2 == 0) {
		// Find the average of value at
		// index N/2 and (N-1)/2
		return (double)(a[(n - 1) / 2] + a[n / 2])/ 2.0;
	}

	// If size of the a[] is odd
	else {
		// Value at index (N/2)th
		// is the median
		return (double)a[n / 2];
	}
}

int Median_Sort_Value_Malay()
{
    system("cls");
    vector<int> a = openSC();
	int n = a.size();
	cout << findMedian_c(a, n) << endl<< endl;
    system("pause");
    MalayStatsMenu();
	return 0;

}


//FINDING MEAN VALUE
//DONE BY: SATISHNAIR
double findAverage_c( vector<int> a, int n)
{
    system("cls");
    double mean;
    int sum=0;

    for(int i=0; i<n; i++){
        sum= sum + a[i];
        }
    mean = double(sum) / n;
    cout<< endl<< endl;
    cout<< "Mean= (Sum of scores)/ (number of scores)" << endl;
    cout<< "    = (" <<sum << ")/(" << n << ")"<<endl;
    cout <<"    = ";
    return mean;

}
int Mean_Value_Malay()
{
    vector<int> a = openBM();
	int n = a.size();
	cout << findAverage_c(a, n) << endl;
    system("pause");
    MalayStatsMenu();
    return 0;

}


//FINDING MINIMUM VALUE
//DONE BY: SATISHNAIR
double findMinimum_c( vector<int> a, int n)
{

int minimum;
minimum = a[0];
for(int i=0; i<n; i++){
	if(a[i] < minimum){
		minimum = a[i];
	}
}
cout<< "First we read the Malay scores which are 100 integers."<<endl;
cout<<"Then, we pick the Least value in that row."<<endl<<endl;
cout<<"The minimum value of Malay subject is: "<<endl;
 return minimum;
}


int Minimum_Value_Malay()
{
    system("cls");
    vector<int> a = openBM();
	int n = a.size();
	cout << findMinimum_c(a, n) << endl<< endl;
    system("pause");
    MalayStatsMenu();
   return 0;
}



//FINDING MAXIMUM VALUE
//DONE BY: SATISHNAIR
double findMaximum_c( vector<int> a, int n)
{

int maximum;
maximum = a[0];
for(int i=0; i<n; i++){
	if(a[i] > maximum){
		maximum = a[i];
	}
}
cout<< "First we read the Malay scores which are 100 integers."<<endl;
cout<<"Then, we pick the Highest value in that row."<<endl<<endl;
cout<<"The maximum value of Malay subject is: "<<endl;
return maximum;
}


int Maximum_Value_Malay()
{
    system("cls");
    vector<int> a = openBM();
	int n = a.size();
	cout << findMaximum_c(a, n) << endl<< endl;
    system("pause");
    MalayStatsMenu();
   return 0;
}


//--------------------------------------------------------------------------
//FINDING PEARSON'S CORRELATION
/**********************
Programmer: 	Satishnair Krishnan
Name:       	correlationCoefficient_a, correlationCoefficient_b, correlationCoefficient_c
task:           Calculates Pearson's Correlation between two subjects.
data in:    	List of data values of first subject in an ordered vector, List of data values of second subject
                in an ordered vector and the size of the data value.
data returned:  Pearson's Correlation with computations in tabular form.
Referred to: https://www.geeksforgeeks.org/program-find-correlation-coefficient/
**********************/
//FUNCTIONS THAT RETURNS CORRELATION COEFFICIENT.
//FINDING CORRELATION COEFFICIENT MS(Maths and Science)
float correlationCoefficient_a(vector<int> X, vector<int> Y, vector<int> Z, int n)
{

    cout << " X = Scores of Maths\t ";cout << " Y = Scores of Science\t ";cout << " Z = Scores of Malay\n ";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|   X\t|Y\t|Z\t|X^2\t|Y^2\t|Z^2\t|XY\t|XZ\t|YZ     |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    int sum_X = 0, sum_Y = 0, sum_Z = 0; int sum_XY = 0, sum_XZ = 0, sum_YZ = 0; int squareSum_X = 0, squareSum_Y = 0, squareSum_Z = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X,Y,Z.
        sum_X = sum_X + X[i]; sum_Y = sum_Y + Y[i]; sum_Z = sum_Z + Z[i];

        // sum of (X[i] * Y[i]), (X[i] * Z[i]), (Y[i] * Z[i]).
        sum_XY = sum_XY + (X[i] * Y[i]); sum_XZ = sum_XZ + (X[i] * Z[i]); sum_YZ = sum_YZ + (Y[i] * Z[i]);

        // sum of square of array elements.
        squareSum_X = squareSum_X + (X[i] * X[i]); squareSum_Y = squareSum_Y + (Y[i] * Y[i]); squareSum_Z = squareSum_Z + (Z[i] * Z[i]);;

        cout <<"|  "<< X[i]<<" \t| "<< Y[i]<<"\t| "<< Z[i]<<"\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
    cout <<"| "<< sum_X<< "\t|"; cout <<sum_Y<< "\t|"; cout << sum_Z << "\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << endl<<endl;

    cout << "FINDING THE PEARSON'S CORRELATION BETWEEN MATHEMATICS AND SCIENCE"<<endl;
    cout << "-------------" << endl;
    cout<< "Calculations "<<endl;
    cout << "-------------" << endl<< endl;
    cout<< "Sum of Maths    = (sum_X)       =   "<<sum_X<<endl;
    cout<< "Sum of Science  = (sum_Y)       =   "<<sum_Y<<endl;
    cout<< "Maths*Science   = (sum_XY)      =   "<<sum_XY<<endl;
    cout<< "Maths*Maths     = (squareSum_X) =   "<<squareSum_X<<endl;
    cout<< "Science*Science = (squareSum_Y) =   "<<squareSum_Y<<endl<<endl;


    cout << "-----------------------------------------" << endl;
    cout<< "The method to get Pearson's Correlation" <<endl;
    cout << "-----------------------------------------" << endl<< endl;

    cout << "Pearson's Correlation " << endl;
    cout << "--------------------" << endl << endl;

    cout << "=((n*sum_XY)-(sum_X*sum_Y))/sqrt(((n*squareSum_X)-(sum_X*sum_X))*((n*squareSum_Y)-(sum_Y*sum_Y)))"<<endl;
    cout << "=((" << n << "*" << sum_XY << ")" "-" << "(" << sum_X << "*" << sum_Y << "))"<< "/"<< "sqrt(((" << n << "*" << squareSum_X << ")-(" << sum_X << "*" << sum_X<< "))" << "*((" << n << "*" << squareSum_Y << ")-(" << sum_Y << "*" << sum_Y<<")))"<<endl;
    cout << "=" ;


    // use formula for calculating correlation coefficient.
    double first = double(n * sum_XY - sum_X * sum_Y);
    double p = n * squareSum_X - sum_X * sum_X;
    double q = n * squareSum_Y - sum_Y * sum_Y;
    double second = sqrt(p*q);
    double corr = first/second;
    return corr;
}


/**********************
Programmer: 	Satishnair Krishnan
Name:       	correlationCoefficient_Maths, correlationCoefficient_Science, correlationCoefficient_Malay,
task:           prints out Pearson's Correlation with computations in tabular form.
data in:
data returned:
Referred to: https://www.geeksforgeeks.org/program-find-correlation-coefficient/
**********************/
//DRIVER FUNCTION
int correlationCoefficient_Maths()
{
    system("cls");

    vector<int> X = openMS();
    vector<int> Y = openSC();
    vector<int> Z = openBM();
    //Find the size of array.
    int n = X.size();
    //Function call to correlationCoefficient.
    cout<<correlationCoefficient_a(X, Y, Z, n) <<endl<<endl;
    system("pause");
    What_Sub_Pearson();
    return 0;
}


//FUNCTIONS THAT RETURNS CORRELATION COEFFICIENT.
//FINDING CORRELATION COEFFICIENT BS(Bahasa Melayu and Science)
float correlationCoefficient_b(vector<int> X, vector<int> Y, vector<int> Z, int n)
{

    cout << " X = Scores of Maths\t ";cout << " Y = Scores of Science\t ";cout << " Z = Scores of Malay\n ";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|   X\t|Y\t|Z\t|X^2\t|Y^2\t|Z^2\t|XY\t|XZ\t|YZ     |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    int sum_X = 0, sum_Y = 0, sum_Z = 0; int sum_XY = 0, sum_XZ = 0, sum_YZ = 0; int squareSum_X = 0, squareSum_Y = 0, squareSum_Z = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X,Y,Z.
        sum_X = sum_X + X[i]; sum_Y = sum_Y + Y[i]; sum_Z = sum_Z + Z[i];

        // sum of (X[i] * Y[i]), (X[i] * Z[i]), (Y[i] * Z[i]).
        sum_XY = sum_XY + (X[i] * Y[i]); sum_XZ = sum_XZ + (X[i] * Z[i]); sum_YZ = sum_YZ + (Y[i] * Z[i]);

        // sum of square of array elements.
        squareSum_X = squareSum_X + (X[i] * X[i]); squareSum_Y = squareSum_Y + (Y[i] * Y[i]); squareSum_Z = squareSum_Z + (Z[i] * Z[i]);;

        cout <<"|  "<< X[i]<<" \t| "<< Y[i]<<"\t| "<< Z[i]<<"\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
    cout <<"| "<< sum_X<< "\t|"; cout <<sum_Y<< "\t|"; cout << sum_Z << "\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << endl<<endl;

    cout << "FINDING THE PEARSON'S CORRELATION BETWEEN MALAY AND SCIENCE"<<endl;
    cout << "-------------" << endl;
    cout<< "Calculations "<<endl;
    cout << "-------------" << endl<< endl;
    cout<< "Sum of Malay    = (sum_Z)       =  "<<sum_Z<<endl;
    cout<< "Sum of Science  = (sum_Y)       =  "<<sum_Y<<endl;
    cout<< "Malay*Science   = (sum_YZ)      =  "<<sum_YZ<<endl;
    cout<< "Malay*Malay     = (squareSum_Z) =  "<<squareSum_Z<<endl;
    cout<< "Science*Science = (squareSum_Y) =  "<<squareSum_Y<<endl<<endl;


    cout << "-----------------------------------------" << endl;
    cout<< "The method to get Pearson's Correlation" <<endl;
    cout << "-----------------------------------------" << endl<< endl;

    cout << "Pearson's Correlation " << endl;
    cout << "--------------------" << endl << endl;

    cout << "=((n*sum_ZY)-(sum_Z*sum_Y))/sqrt(((n*squareSum_Z)-(sum_Z*sum_Z))*((n*squareSum_Y)-(sum_Y*sum_Y)))"<<endl;
    cout << "=((" << n << "*" << sum_YZ << ")" "-" << "(" << sum_Z << "*" << sum_Y << "))"<< "/"<< "sqrt(((" << n << "*" << squareSum_Z << ")-(" << sum_Z << "*" << sum_Z<< "))" << "*((" << n << "*" << squareSum_Y << ")-(" << sum_Y << "*" << sum_Y<<")))"<<endl;
    cout << "=" ;


    // use formula for calculating correlation coefficient.
    double first = double(n * sum_YZ - sum_Z * sum_Y);
    double p = n * squareSum_Z - sum_Z * sum_Z;
    double q = n * squareSum_Y - sum_Y * sum_Y;
    double second = sqrt(p*q);
    double corr = first/second;
    return corr;
}

//DRIVER FUNCTION
int correlationCoefficient_BS()
{
    system("cls");

    vector<int> X = openMS();
    vector<int> Y = openSC();
    vector<int> Z = openBM();

    //Find the size of array.
    int n = X.size();
    //Function call to correlationCoefficient.
    cout<<correlationCoefficient_b(X, Y, Z, n) <<endl<<endl;


    system("pause");
    What_Sub_Pearson();
    return 0;
}

//FUNCTIONS THAT RETURNS CORRELATION COEFFICIENT.
//FINDING CORRELATION COEFFICIENT MB(Maths and Bahasa Melayu)
float correlationCoefficient_c(vector<int> X, vector<int> Y, vector<int> Z, int n)
{

    cout << " X = Scores of Maths\t ";cout << " Y = Scores of Science\t ";cout << " Z = Scores of Malay\n ";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|   X\t|Y\t|Z\t|X^2\t|Y^2\t|Z^2\t|XY\t|XZ\t|YZ     |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    int sum_X = 0, sum_Y = 0, sum_Z = 0; int sum_XY = 0, sum_XZ = 0, sum_YZ = 0; int squareSum_X = 0, squareSum_Y = 0, squareSum_Z = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X,Y,Z.
        sum_X = sum_X + X[i]; sum_Y = sum_Y + Y[i]; sum_Z = sum_Z + Z[i];

        // sum of (X[i] * Y[i]), (X[i] * Z[i]), (Y[i] * Z[i]).
        sum_XY = sum_XY + (X[i] * Y[i]); sum_XZ = sum_XZ + (X[i] * Z[i]); sum_YZ = sum_YZ + (Y[i] * Z[i]);

        // sum of square of array elements.
        squareSum_X = squareSum_X + (X[i] * X[i]); squareSum_Y = squareSum_Y + (Y[i] * Y[i]); squareSum_Z = squareSum_Z + (Z[i] * Z[i]);

        cout <<"|  "<< X[i]<<" \t| "<< Y[i]<<"\t| "<< Z[i]<<"\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
    cout <<"| "<< sum_X<< "\t|"; cout <<sum_Y<< "\t|"; cout << sum_Z << "\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << endl<<endl;

    cout << "FINDING THE PEARSON'S CORRELATION BETWEEN MALAY AND MATHEMATICS"<<endl;
    cout << "-------------" << endl;
    cout<< "Calculations "<<endl;
    cout << "-------------" << endl<< endl;
    cout<< "Sum of Malay = (sum_Z)       = "<<sum_Z<<endl;
    cout<< "Sum of Maths = (sum_X)       = "<<sum_X<<endl;
    cout<< "Malay*Maths  = (sum_XZ)      = "<<sum_XZ<<endl;
    cout<< "Malay*Malay  = (squareSum_Z) = "<<squareSum_Z<<endl;
    cout<< "Maths*Maths  = (squareSum_X) = "<<squareSum_X<<endl<<endl;


    cout << "-----------------------------------------" << endl;
    cout<< "The method to get Pearson's Correlation" <<endl;
    cout << "-----------------------------------------" << endl<< endl;

    cout << "Pearson's Correlation " << endl;
    cout << "--------------------" << endl << endl;

    cout << "=((n*sum_XZ)-(sum_Z*sum_X))/sqrt(((n*squareSum_Z)-(sum_Z*sum_Z))*((n*squareSum_X)-(sum_X*sum_X)))"<<endl;
    cout << "=((" << n << "*" << sum_XZ << ")" "-" << "(" << sum_Z << "*" << sum_X << "))"<< "/"<< "sqrt(((" << n << "*" << squareSum_Z << ")-(" << sum_Z << "*" << sum_Z<< "))" << "*((" << n << "*" << squareSum_X << ")-(" << sum_X << "*" << sum_X<<")))"<<endl;
    cout << "=" ;


    // use formula for calculating correlation coefficient.
    double first = double(n * sum_XZ - sum_Z * sum_X);
    double p = n * squareSum_Z - sum_Z * sum_Z;
    double q = n * squareSum_X - sum_X * sum_X;
    double second = sqrt(p*q);
    double corr = first/second;
    return corr;
}
//DRIVER FUNCTION
int correlationCoefficient_MB()
{
    system("cls");

    vector<int> X = openMS();
    vector<int> Y = openSC();
    vector<int> Z = openBM();

    //Find the size of array.
    int n = X.size();
    //Function call to correlationCoefficient.
    cout<<correlationCoefficient_c(X, Y, Z, n) <<endl<<endl;
    system("pause");
    What_Sub_Pearson();
    return 0;
}



//-------------------------------------------------------------------------
//FINDING LINEAR REGRESSION LINE
/**********************
Programmer: 	Kishen Kumar
Name:       	linear_a, linear_b, linear_c
task:           To calculate the linear regression line of mathematics and
                science subjects.
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:  Linear regression line of mathematics and science subjects which
                consists of y-intercept and slope m
Referred to:	Gaddis, C++ From Control Structures Through Objects, 8th Ed.
**********************/
//FINDING REGRESSION LINE MS
//FUNCTION THAT RETURNS LINEAR REGRESSION LINE.
float linear_a(vector<int> X, vector<int> Y, vector<int> Z, int n)
{

    cout << " X = Scores of Maths\t ";cout << " Y = Scores of Science\t ";cout << " Z = Scores of Malay\n ";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|   X\t|Y\t|Z\t|X^2\t|Y^2\t|Z^2\t|XY\t|XZ\t|YZ     |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    int sum_X = 0, sum_Y = 0, sum_Z = 0; int sum_XY = 0, sum_XZ = 0, sum_YZ = 0; int squareSum_X = 0, squareSum_Y = 0, squareSum_Z = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X,Y,Z.
        sum_X = sum_X + X[i]; sum_Y = sum_Y + Y[i]; sum_Z = sum_Z + Z[i];

        // sum of (X[i] * Y[i]), (X[i] * Z[i]), (Y[i] * Z[i]).
        sum_XY = sum_XY + (X[i] * Y[i]); sum_XZ = sum_XZ + (X[i] * Z[i]); sum_YZ = sum_YZ + (Y[i] * Z[i]);

        // sum of square of array elements.
        squareSum_X = squareSum_X + (X[i] * X[i]); squareSum_Y = squareSum_Y + (Y[i] * Y[i]); squareSum_Z = squareSum_Z + (Z[i] * Z[i]);;

        cout <<"|  "<< X[i]<<" \t| "<< Y[i]<<"\t| "<< Z[i]<<"\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
    cout <<"| "<< sum_X<< "\t|"; cout <<sum_Y<< "\t|"; cout << sum_Z << "\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << endl<<endl;

    cout << "FINDING THE LINEAR REGRESSION LINE"<<endl;
    cout << "SUBJECTS: MATHEMATICS AND SCIENCE"<<endl;


    cout << "-------------" << endl;
    cout<< "Calculations "<<endl;
    cout << "-------------" << endl<< endl;


    cout<< "Sum of Maths    = "<<sum_X<<endl;
    cout<< "Sum of Science  = "<<sum_Y<<endl;
    cout<< "Maths*Science   = "<<sum_XY<<endl;
    cout<< "Maths*Maths     = "<<squareSum_X<<endl;
    cout<< "Science*Science = "<<squareSum_Y<<endl<<endl;

    double m,c,m1,m2,c1,c2;


            m1 = ((n*sum_XY)-(sum_X*sum_Y));
            m2=((n*squareSum_X) - (sum_X*sum_X));
            m= m1/m2;
            c1=((sum_Y)*(squareSum_X))-((sum_X)*(sum_XY));
            c2=((n*squareSum_X)-(sum_X*sum_X));
            c = c1/c2;

            cout << "-----------------------------------------" << endl;
            cout<< "The method to get Linear Regression Line" <<endl;
            cout << "-----------------------------------------" << endl<< endl;

            cout << "Slope m" << endl;
            cout << "------------" << endl;

            cout << "=(" << n << "*" << sum_XY << "-" << "(" << sum_X << "*" << sum_Y << ")/" << "(" << n << "*"; cout << squareSum_X << "-" << "(" << sum_X << "*" << sum_X << ")" << endl; cout << "=" <<m << endl << endl;


            cout << "Intercept Between Math And Science c"<< endl;
            cout << "------------------------------------" << endl;

            cout << "=(" <<sum_Y << ")-(" << m << "*" << sum_X << ")" << "/" << n << endl; cout << "= " << c << endl << endl; cout << "Linear equation is y = mx + c" << endl;
            cout << "Linear equation y = " << m << "x + ";


    return c;
}



/**********************
Programmer: 	Kishen Kumar
Name:       	regressionLine_MS(), regressionLine_BS(), regressionLine_MB(),
task:           To call the function of linear regression line of mathematics and
                science subjects
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:  List of data values in an ordered vector and the size
                of the data value.
Referred to:	Gaddis, C++ From Control Structures Through Objects, 8th Ed.
**********************/
//DRIVER FUNCTION
int regressionLine_MS()
{
    system("cls");

    vector<int> X = openMS();
    vector<int> Y = openSC();
    vector<int> Z = openBM();
    //Find the size of array.
    int n = X.size();
    //Function call to correlationCoefficient.

    cout<<linear_a(X, Y, Z, n) <<endl;
    system("pause");
    What_Sub_Regression();
    return 0;

}

//FINDING REGRESSION LINE BS
// FUNCTION THAT RETURNS LINEAR REGRESSION LINE.
float linear_b(vector<int> X, vector<int> Y, vector<int> Z, int n)
{

    cout << " X = Scores of Maths\t ";cout << " Y = Scores of Science\t ";cout << " Z = Scores of Malay\n ";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|   X\t|Y\t|Z\t|X^2\t|Y^2\t|Z^2\t|XY\t|XZ\t|YZ     |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    int sum_X = 0, sum_Y = 0, sum_Z = 0; int sum_XY = 0, sum_XZ = 0, sum_YZ = 0; int squareSum_X = 0, squareSum_Y = 0, squareSum_Z = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X,Y,Z.
        sum_X = sum_X + X[i]; sum_Y = sum_Y + Y[i]; sum_Z = sum_Z + Z[i];

        // sum of (X[i] * Y[i]), (X[i] * Z[i]), (Y[i] * Z[i]).
        sum_XY = sum_XY + (X[i] * Y[i]); sum_XZ = sum_XZ + (X[i] * Z[i]); sum_YZ = sum_YZ + (Y[i] * Z[i]);

        // sum of square of array elements.
        squareSum_X = squareSum_X + (X[i] * X[i]); squareSum_Y = squareSum_Y + (Y[i] * Y[i]); squareSum_Z = squareSum_Z + (Z[i] * Z[i]);;

        cout <<"|  "<< X[i]<<" \t| "<< Y[i]<<"\t| "<< Z[i]<<"\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
    cout <<"| "<< sum_X<< "\t|"; cout <<sum_Y<< "\t|"; cout << sum_Z << "\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << endl<<endl;

    cout << "FINDING THE LINEAR REGRESSION LINE"<<endl;
    cout << "SUBJECTS: MALAY AND SCIENCE"<<endl;


    cout << "-------------" << endl;
    cout<< "Calculations "<<endl;
    cout << "-------------" << endl<< endl;


    cout<< "Sum of Malay    = "<<sum_Z<<endl;
    cout<< "Sum of Science  = "<<sum_Y<<endl;
    cout<< "Malay*Science   = "<<sum_YZ<<endl;
    cout<< "Malay*Malay     = "<<squareSum_Z<<endl;
    cout<< "Science*Science = "<<squareSum_Y<<endl<<endl;

    double m,c,m1,m2,c1,c2;


            m1 = (n*sum_YZ)-(sum_Y*sum_Z);
            m2= (n*squareSum_Y) - (sum_Y*sum_Y);
            m= m1/m2;
            c1=(sum_Z*squareSum_Y)-(sum_Y*sum_YZ);
            c2=(n*squareSum_Y)-(sum_Y*sum_Y);
            c = c1/c2;

            cout << "-----------------------------------------" << endl;
            cout<< "The method to get Linear Regression Line" <<endl;
            cout << "-----------------------------------------" << endl<< endl;

            cout << "Slope m" << endl;
            cout << "------------" << endl;

            cout << "=(" << n << "*" << sum_YZ << "-" << "(" << sum_Z << "*" << sum_Y << ")/" << "(" << n << "*"; cout << squareSum_Z << "-" << "(" << sum_Z << "*" << sum_Z << ")" << endl; cout << "=" <<m << endl << endl;


            cout << "Intercept Between Malay And Science c"<< endl;
            cout << "------------------------------------" << endl;

            cout << "=(" <<sum_Y << ")-(" << m << "*" << sum_Z << ")" << "/" << n << endl; cout << "= " << c << endl << endl; cout << "Linear equation is y = mx + c" << endl; cout << "Linear equation y = " << m << "x + ";

    return c;
}



//DRIVER FUNCTION
int regressionline_BS()
{
    system("cls");

    vector<int> X = openMS();
    vector<int> Y = openSC();
    vector<int> Z = openBM();

    //Find the size of array.
    int n = X.size();
    //Function call to correlationCoefficient.
    cout<<linear_b(X, Y, Z, n) <<endl;
    system("pause");
    What_Sub_Regression();
    return 0;

}

//FINDING REGRESSION LINE MB
// FUNCTION THAT RETURNS LINEAR REGRESSION LINE.
float linear_c(vector<int> X, vector<int> Y, vector<int> Z, int n)
{

    cout << " X = Scores of Maths\t ";cout << " Y = Scores of Science\t ";cout << " Z = Scores of Malay\n ";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|   X\t|Y\t|Z\t|X^2\t|Y^2\t|Z^2\t|XY\t|XZ\t|YZ     |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    int sum_X = 0, sum_Y = 0, sum_Z = 0; int sum_XY = 0, sum_XZ = 0, sum_YZ = 0; int squareSum_X = 0, squareSum_Y = 0, squareSum_Z = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X,Y,Z.
        sum_X = sum_X + X[i]; sum_Y = sum_Y + Y[i]; sum_Z = sum_Z + Z[i];

        // sum of (X[i] * Y[i]), (X[i] * Z[i]), (Y[i] * Z[i]).
        sum_XY = sum_XY + (X[i] * Y[i]); sum_XZ = sum_XZ + (X[i] * Z[i]); sum_YZ = sum_YZ + (Y[i] * Z[i]);

        // sum of square of array elements.
        squareSum_X = squareSum_X + (X[i] * X[i]); squareSum_Y = squareSum_Y + (Y[i] * Y[i]); squareSum_Z = squareSum_Z + (Z[i] * Z[i]);

        cout <<"|  "<< X[i]<<" \t| "<< Y[i]<<"\t| "<< Z[i]<<"\t|"; cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|"; cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
    cout <<"| "<< sum_X<< "\t|"; cout <<sum_Y<< "\t|"; cout << sum_Z << "\t|";
    cout <<squareSum_X<<"\t|"<<squareSum_Y<<"\t|"<<squareSum_Z<<"\t|";
    cout <<sum_XY<<"\t|"<<sum_XZ<<"\t|"<<sum_YZ<<"\t|"<<endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << endl<<endl;

    cout << "FINDING THE LINEAR REGRESSION LINE"<<endl;
    cout << "SUBJECTS: MALAY AND MATHEMATICS"<<endl;


    cout << "-------------" << endl;
    cout<< "Calculations "<<endl;
    cout << "-------------" << endl<< endl;


    cout<< "Sum of Malay    = "<<sum_Z<<endl;
    cout<< "Sum of Maths    = "<<sum_X<<endl;
    cout<< "Malay*Maths     = "<<sum_XZ<<endl;
    cout<< "Malay*Malay     = "<<squareSum_Z<<endl;
    cout<< "Maths*Maths     = "<<squareSum_X<<endl<<endl;

    double m,c,m1,m2,c1,c2;


            m1 = (n*sum_XZ)-(sum_X*sum_Z);
            m2=(n*squareSum_X) - (sum_X*sum_X);
            m= m1/m2;
            c1=(sum_Z*squareSum_X)-(sum_X*sum_XZ);
            c2=(n*squareSum_X)-(sum_X*sum_X);
            c = c1/c2;

            cout << "-----------------------------------------" << endl;
            cout<< "The method to get Linear Regression Line" <<endl;
            cout << "-----------------------------------------" << endl<< endl;

            cout << "Slope m" << endl;
            cout << "------------" << endl;

            cout << "=(" << n << "*" << sum_XZ << "-" << "(" << sum_Z << "*" << sum_X << ")/" << "(" << n << "*"; cout << squareSum_Z << "-" << "(" << sum_Z << "*" << sum_Z << ")" << endl; cout << "=" <<m << endl << endl;


            cout << "Intercept Between Malay And Math c"<< endl;
            cout << "------------------------------------" << endl;

            cout << "=(" <<sum_X << ")-(" << m << "*" << sum_Z << ")" << "/" << n << endl; cout << "= " << c << endl << endl; cout << "Linear equation is y = mx + c" << endl; cout << "Linear equation y = " << m << "x + ";

    return c;
}



//DRIVER FUNCTION
int regressionline_MB()
{
    system("cls");

    vector<int> X = openMS();
    vector<int> Y = openSC();
    vector<int> Z = openBM();

    //Find the size of array.
    int n = X.size();
    //Function call to correlationCoefficient.
    cout<<linear_c(X, Y, Z, n) <<endl;
    system("pause");
    What_Sub_Regression();
    return 0;

}

//-------------------------------------------------------------------------

//FINDING FREQUENCY
//FINDING FREQUENCY OF MATHS
//FUNCTION THAT RETURNS FREQUENCY.
/********
Programmer: Ahmad Luqman
Name:    Frequency_Science, Frequency_Maths, Frequency_Malay
Task:  Print the mark and its frequencies side by side in a tabular form.
data in:   List of data values in a vector and the size of the data value.
data returned:
Referred to: https://www.quora.com/How-do-I-write-a-program-to-find-the-frequency-of-the-presence-of-an-element-in-an-array-in-C++
*******/
int Frequency_Maths()
{
     system("cls");
    vector<int> a = openMS();
    int n = a.size();
    int freq[n];

    for(int i=0;i<=n;i++)
    {
      freq[i]=0;
    }

    for(int i=0;i<n;i++)
    {
       freq[(a[i])]+=1;
    }

    cout<<"FREQUENCY\n";cout<<"SUBJECT NAME: MATH\n";
    cout<<"---------------------"<<endl;
    cout<< "|"<<setw(5)<< "MARK" << "    |"  << "FREQUENCY|"  <<endl;
    cout<<"---------------------"<<endl;

   for (int i=0; i<=a.size(); i++)
    {
        cout << "|"<<setw(5)<< (int)(i) << "    |"<< setw(5) << freq[i] <<setw(5)<< "|"  << endl;
    }

    cout<<"---------------------"<<endl;
    system("pause");
    MathsStatsMenu();
    return 0;
}

int Frequency_Science()
{
   system("cls");
    vector<int> a = openSC();
    int n = a.size();
    int freq[n];

    for(int i=0;i<=n;i++)
    {
      freq[i]=0;
    }

    for(int i=0;i<n;i++)
    {
       freq[(a[i])]+=1;
    }

    cout<<"FREQUENCY\n";cout<<"SUBJECT NAME: SCIENCE\n";
    cout<<"---------------------"<<endl;
    cout<< "|"<<setw(5)<< "MARK" << "    |"  << "FREQUENCY|"  <<endl;
    cout<<"---------------------"<<endl;

   for (int i=0; i<=a.size(); i++)
    {
        cout << "|"<<setw(5)<< (int)(i) << "    |"<< setw(5) << freq[i] <<setw(5)<< "|"  << endl;
    }

    cout<<"---------------------"<<endl;

    system("pause");
    ScienceStatsMenu();
    return 0;
}

int Frequency_Malay()
{
    system("cls");
    vector<int> a = openBM();
    int n = a.size();
    int freq[n];

    for(int i=0;i<=n;i++)
    {
      freq[i]=0;
    }

    for(int i=0;i<n;i++)
    {
       freq[(a[i])]+=1;
    }

    cout<<"FREQUENCY\n";cout<<"SUBJECT NAME: MALAY\n";
    cout<<"---------------------"<<endl;
    cout<< "|"<<setw(5)<< "MARK" << "    |"  << "FREQUENCY|"  <<endl;
    cout<<"---------------------"<<endl;

   for (int i=0; i<=a.size(); i++)
    {
        cout << "|"<<setw(5)<< (int)(i) << "    |"<< setw(5) << freq[i] <<setw(5)<< "|"  << endl;
    }

    cout<<"---------------------"<<endl;

    system("pause");
    MalayStatsMenu();
    return 0;
}

//-------------------------------------------------------------------------

//FINDING ASCENDING OR DESCENDING
/**********************
Programmer: 	Kishen Kumar
Name:       	ascending
task:           Sort the data values in the ascending order for every subjects
data in:    	List of data values in an ordered vector and the size
                of the data value for every subjects
data returned:  Sorted data in the ascending order for every subjects
Referred to:	include help.com. (n.d.). C++ program to sort an array in Ascending Order.
                kartik. (2018). Sorting a vector in C++.
Retrieved from: https://www.includehelp.com/cpp-programs/sort-an-array-in-ascending-order.aspx
                https://www.geeksforgeeks.org/sorting-a-vector-in-c/
**********************/

//FINDING ASCENDING AND DESCENDING OF MATHS
vector <int> ascending(vector <int> a, int n)
{
    sort(a.begin(),a.end());
        cout<<endl<<endl;
    return a;
}

/**********************
Programmer: 	Kishen Kumar
Name:       	descending
task:           Sort the data values in the descending order for every subjects
data in:    	List of data values in an ordered vector and the size
                of the data value for every subjects
data returned:  Sorted data in the descending order for every subjects
Referred to:	include help.com. (n.d.). C++ program to sort an array in Descending Order.
                kartik. (2018). Sorting a vector in C++.
Retrieved from: https://www.includehelp.com/cpp-programs/sort-an-array-in-descending-order.aspx
                https://www.geeksforgeeks.org/sorting-a-vector-in-c/
**********************/
vector <int> descending(vector <int> f, vector <int> d)
{
	    cout << "DATA SORTED IN ASCENDING AND DESCENDING ORDER =>" << endl<<endl;
	    sort(f.begin(), f.end(),greater<int>());


    return f;
}


/**********************
Programmer: 	Kishen Kumar
Name:       	Ascending_Descending_Maths, Ascending_Descending_Science, Ascending_Descending_Malay,
task:           Calling the functions that make the data in the ascending order
                and descending order and retrieve the data from the functions and
                display the sorted data in the tabular form for the math subject.
data in:    	List of data values in an ordered vector and the size
                of the data value for the math subject.
data returned:  Sorted data in the ascending and descending order for the math subject
Referred to:	Gaddis, C++ From Control Structures Through Objects, 8th Ed.
**********************/
int Ascending_Descending_Maths()
{
    system("cls");
    vector<int> a = openMS();
    vector<int> b = openSC();
    vector<int> c = openBM();
	int n = a.size();
	int y = b.size();
	int u = c.size();

	 vector<int> d,f,e,s,q,w;
    e=ascending(b, y);
    s=descending(b, e);
    q=ascending(c, u);
    w=descending(c, q);

    d = ascending(a, n);
    f = descending(a, d);
    cout<<"  MATHS      SCIENCE      MALAY\n";
    cout<<"----------------------"<<"------------"<<endl;
    cout<< "|"<<setw(5)<< "ASCENDING" << "|"<<setw(5)<< "ASCENDING" << "|"  <<  "|"<<setw(5)<< "ASCENDING" << "|"  <<endl;

    cout<<"----------------------"<<"------------"<<endl;
    for (int i=0; i<f.size(); i++){
        cout << "|"<<setw(5)<< d[i] << "    |"<<"|"<<setw(5)<<   e[i] << "    |"<< "|"<<setw(5)<< q[i] << "    |"<< endl;
    }
    cout<<"---------------------"<<"------------"<<endl;

    system("pause");
    MathsStatsMenu();
    return 0;
}

int Ascending_Descending_Science()
{
    system("cls");
    vector<int> a = openSC();
	int n = a.size();
	 vector<int> d,f;
    d = ascending(a, n);
    f = descending(a, d);
    cout<<"SUBJECT NAME: SCIENCE\n";
    cout<<"----------------------"<<endl;
    cout<< "|"<<setw(5)<< "ASCENDING" << "|"  << "DESCENDING|"  <<endl;
    cout<<"----------------------"<<endl;

    for (int i=0; i<f.size(); i++){
        cout << "|"<<setw(5)<< d[i] << "    |"<< setw(5) << f[i] <<setw(6)<< "|"  << endl;
    }
    cout<<"---------------------"<<endl;

    system("pause");
    ScienceStatsMenu();
    return 0;
}

int Ascending_Descending_Malay()
{
    system("cls");
    vector<int> a = openBM();
	int n = a.size();
	 vector<int> d,f;
    d = ascending(a, n);
    f = descending(a, d);
    cout<<"SUBJECT NAME: MALAY\n";
    cout<<"----------------------"<<endl;
    cout<< "|"<<setw(5)<< "ASCENDING" << "|"  << "DESCENDING|"  <<endl;
    cout<<"----------------------"<<endl;

    for (int i=0; i<f.size(); i++){
        cout << "|"<<setw(5)<< d[i] << "    |"<< setw(5) << f[i] <<setw(6)<< "|"  << endl;
    }
    cout<<"---------------------"<<endl;

    system("pause");
    MalayStatsMenu();
    return 0;
}




//-------------------------------------------------------------------------
// FINDING HISTOGRAM
/**********************
Programmer: 	Avinash Imanuel
Name:       	findmaxfirst
task:           Calculates the max value from the data values for the
                scaling of the histogram.
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:   maximum value from the vector input
Referred to:	worldbestlearningcenter.com (n.d.) C++ program for histogram. Retrieved from https://www.worldbestlearningcenter.com/index_files/cpp-example-histogram.htm
**********************/
float findmaxfirst(vector<int> X, int n)
{
    int a=X[0];
       for(int i=0;i<n;i++)
        if(a < X[i])
            a=X[i];
    return a;
}


/**********************
Programmer: 	Avinash Imanuel
Name:       	histogramfreq
task:           Calculates the frequency and prints out the textual
histogram form of the data values using asterisks.
data in:    	List of data values in an ordered vector and the size
                of the data value.
data returned:  Histogram that uses asterisk to define its
                occurrences.
Referred to:	worldbestlearningcenter.com (n.d.) C++ program for histogram. Retrieved from https://www.worldbestlearningcenter.com/index_files/cpp-example-histogram.htm
**********************/
float histogramfreq(vector<int> X, int n)
{
    int m;
   int a = findmaxfirst( X, n); //find max value of data points
   if(a>=n)
       m=a+1;
   else
       m=n;

   int freqr[m]; //declare frequency array with an appropriate size
   //The size of frequency array can be the size of the maths array
   //or the max value of the maths array items plus 1

    for(int i=0;i<m;i++) //initialize frequency array
          freqr[i]=0;

   //compute frequencies
   for(int i=0;i<n;i++)
       freqr[X[i]]++;

   //print histogram
    cout<<"------------------------------\n";
    cout<< "|"<<setw(5)<< "   MARK" << "  |"  << "FREQUENCY|"  << "ASTERIK |"  <<endl;
    cout<<"------------------------------\n";

    for(int i=0;i<m;i++){

        cout << "|"<<setw(5)<< i << "    |"<< setw(5) << freqr[i] <<setw(5)<< ":" ;

    for(int j=1;j<=freqr[i];j++) cout<<" *";
       cout<<endl;
    }
    cout<<" ----------------------------\n";

   return 0;


}

/**********************
Programmer: 	Avinash Imanuel
Name:       	Plot_Histogram_Maths ,Plot_Histogram_Science, Plot_Histogram_Malay
task:           Prints out the histogram respective to the subject
data in:
data returned:
Referred to:
**********************/
// HISTOGRAM FOR MATHS SUBJECT
int Plot_Histogram_Maths()
{
    system("cls");
    vector<int> X = openMS();
    int n = X.size();

    cout<<"-------------------";
    cout<<"\n....Histogram....\n";
    cout<<" ------------------- \n\n";
    cout<<"SUBJECT NAME: MATHS\n";
    histogramfreq(X,n);

    system("pause");
    MathsStatsMenu();
    return 0;
}

// HISTOGRAM FOR SCIENCE SUBJECT
int Plot_Histogram_Science()
{
    system("cls");
    vector<int> X = openSC();
    int n = X.size();

    cout<<"-------------------";
    cout<<"\n....Histogram....\n";
    cout<<" ------------------- \n\n";
    cout<<"SUBJECT NAME: SCIENCE\n";
    histogramfreq(X,n);

    system("pause");
    ScienceStatsMenu();
    return 0;
}

// HISTOGRAM FOR MALAY SUBJECT
int Plot_Histogram_Malay()
{
    system("cls");
    vector<int> X = openBM();
    int n = X.size();

    cout<<"-------------------";
    cout<<"\n....Histogram....\n";
    cout<<" ------------------- \n\n";
    cout<<"SUBJECT NAME: MALAY\n";
    histogramfreq(X,n);

    system("pause");
    MalayStatsMenu();
    return 0;
}
//-------------------------------------------------------------------------
// STATISTICAL REPORT IN TEXT FILE
/**********************
Programmer: 	Avinash Imanuel
Name:       	MathsReport,ScienceReport,MalayReport
task:           Prints out the statistical report of each respective
                subjects into a text file in a tabular form
data in:
data returned:
Referred to:
**********************/
 void Statistical_Report_TXT();
 void Statistical_Report_HTML();

MathsReport()
{
    system("cls");
    vector<int> a = openMS(); vector<int> b = openSC(); vector<int> c = openBM(); int n = a.size();

    ofstream outfile;
    outfile.open("outok.txt", ios::out | ios::trunc );
    outfile << "------------------------------------------- " << endl;
    outfile << "|     STAT NAME    | SUBJECT  | STAT VALUE|" << endl;
    outfile << "------------------------------------------- " << endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Minimum           | Maths    |"<< findMinimum_a(a, n) <<setw(11)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Maximum           | Maths    |"<< findMaximum_a(a, n) <<setw(10)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Median            | Maths    |"<< findMedian_a(a, n) <<setw(10)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Mean              | Maths    |" << findAverage_a(a, n) <<setw(7)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Variance          | Maths    |" << variance(a, n) <<setw(5)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Standard Deviation| Maths    |" << standardDeviation(a, n) <<setw(5)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Correlation       | Maths    |" << correlationCoefficient_a(a, b, c, n) <<setw(3)<<"|"<< endl;
    outfile << "---------------------------------------------- " << endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Regression Line   | Maths    |" << "y=mx+" << linear_a(a, b, c, n) <<setw(3)<<"|"<< endl;
    outfile << "---------------------------------------------- " << endl;
    outfile.close();

    system("cls");
    cout<<endl<<endl;
    cout<<" -----------------------------------------------------------------"<<endl;
    cout<<" Please Launch outputok.txt in order to view Statistical Report =>"<<endl;
    cout<<" -----------------------------------------------------------------"<<endl<<endl;

    system("pause");
    Statistical_Report_TXT();
	return 0;
}

ScienceReport()
{
    system("cls");
    vector<int> a = openMS(); vector<int> b = openSC(); vector<int> c = openBM(); int n = b.size();

    ofstream outfile;
    outfile.open("outok.txt", ios::out | ios::trunc );
    outfile << "------------------------------------------- " << endl;
    outfile << "|     STAT NAME    | SUBJECT  | STAT VALUE|" << endl;
    outfile << "------------------------------------------- " << endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Minimum           | Science  |"<< findMinimum_b(b, n) <<setw(11)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Maximum           | Science  |"<< findMaximum_b(b, n) <<setw(9)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Median            | Science  |"<< findMedian_b(b, n) <<setw(8)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Mean              | Science  |" << findAverage_b(b, n) <<setw(7)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Variance          | Science  |" << variance2(b, n) <<setw(5)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Standard Deviation| Science  |" << standardDeviation2(b, n) <<setw(5)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Correlation       | Science  |" << correlationCoefficient_b(a, b, c, n) <<setw(3)<<"|"<< endl;
    outfile << "---------------------------------------------- " << endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Regression Line   | Science  |" << "y=mx+" << linear_b(a, b, c, n) <<setw(3)<<"|"<< endl;
    outfile << "---------------------------------------------- " << endl;
    outfile.close();

    system("cls");
    cout<<endl<<endl;
    cout<<" -----------------------------------------------------------------"<<endl;
    cout<<" Please Launch outputok.txt in order to view Statistical Report =>"<<endl;
    cout<<" -----------------------------------------------------------------"<<endl<<endl;

    system("pause");
    Statistical_Report_TXT();
	return 0;
}

MalayReport()
{
    system("cls");
    vector<int> a = openMS(); vector<int> b = openSC(); vector<int> c = openBM(); int n = c.size();

    ofstream outfile;
    outfile.open("outok.txt", ios::out | ios::trunc );
    outfile << "------------------------------------------- " << endl;
    outfile << "|     STAT NAME    | SUBJECT  | STAT VALUE|" << endl;
    outfile << "------------------------------------------- " << endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Minimum           | Malay    |"<< findMinimum_c(c, n) <<setw(11)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Maximum           | Malay    |"<< findMaximum_c(c, n) <<setw(10)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app );
    outfile << "|Median            | Malay    |"<< findMedian_c(c, n) <<setw(10)<<"|"<<endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Mean              | Malay    |" << findAverage_c(c, n) <<setw(7)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Variance          | Malay    |" << variance3(c, n) <<setw(5)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Standard Deviation| Malay    |" << standardDeviation3(c, n) <<setw(5)<<"|"<< endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Correlation       | Malay    |" << correlationCoefficient_c(a, b, c, n) <<setw(2)<<"|"<< endl;
    outfile << "---------------------------------------------- " << endl;
    outfile.close();    outfile.open("outok.txt", ios::out | ios::app);
    outfile << "|Regression Line   | Malay    |" << "y=mx+" << linear_c(a, b, c, n) <<setw(3)<<"|"<< endl;
    outfile << "---------------------------------------------- " << endl;
    outfile.close();

    system("cls");
    cout<<endl<<endl;
    cout<<" -----------------------------------------------------------------"<<endl;
    cout<<" Please Launch outputok.txt in order to view Statistical Report =>"<<endl;
    cout<<" -----------------------------------------------------------------"<<endl<<endl;

    system("pause");
    Statistical_Report_TXT();
	return 0;
}


//-------------------------------------------------------------------------
// STATISTICAL REPORT IN HTML FILE
/**********************
Programmer: 	Avinash Imanuel
Name:       	Maths_HTML,Science_HTML,Malay_HTML
task:           Prints out the statistical report of each respective
                subjects into a html file in a tabular form
data in:
data returned:
Referred to:
**********************/
Maths_HTML()
{
    system("cls");
    vector<int> a = openMS(); vector<int> b = openSC(); vector<int> c = openBM(); int n = a.size();

    ofstream outfile;
    outfile.open("outok2.html", ios::out | ios::trunc );

    outfile <<
   R"( <style>
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
//  background-color: #dddddd;
}
</style>)"
     R"(<table>
  <tr>
    <th>STATISTICAL NAME </th>
    <th>SUBJECT </th>
    <th> STATISTICAL VALUE </th>
  </tr> )"
  R"(<tr>
    <td>  Minimum</td>
    <td> Maths    </td>)"
    "<td>"<<findMinimum_a(a, n)<<" </td>"
R"(  </tr>
  <tr>
    <td>Maximum           </td>
    <td> Maths    </td>)"
    "<td>"<<findMaximum_a(a, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Median            </td>
    <td> Maths    </td>)"
   "<td>"<<findMedian_a(a, n)<<" </td>"
   R"(</tr>
  <tr>
    <td>Mean          </td>
    <td> Maths    </td>)"
    "<td>"<<findAverage_a(a, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Variance          </td>
    <td> Maths    </td>)"
    "<td>"<<variance(a, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Standard Deviation</td>
    <td> Maths    </td>)"
  "<td>"<< standardDeviation(a, n)<<" </td>"
 R"( </tr>
  <tr>
    <td>Correlation       </td>
    <td> Maths    </td>)"
   "<td>"<<correlationCoefficient_a(a, b, c, n)<<" </td>"
 R"( </tr>
  <tr>
    <td>Regression Line   </td>
    <td> Maths    </td>)"
    "<td>"<<"y=mx+" <<linear_a(a, b, c, n)<<" </td>"
 R"( </tr>

</table>)";

outfile.close();

    system("cls");
    cout<<endl<<endl;
    cout<<" -----------------------------------------------------------------"<<endl;
    cout<<" Please Launch outputok2.html in order to view Statistical Report =>"<<endl;
    cout<<" -----------------------------------------------------------------"<<endl<<endl;

    system("pause");
    Statistical_Report_HTML();
	return 0;
}

Science_HTML()
{
    system("cls");
    vector<int> a = openMS(); vector<int> b = openSC(); vector<int> c = openBM(); int n = b.size();

    ofstream outfile;
    outfile.open("outok2.html", ios::out | ios::trunc );
outfile <<
   R"( <style>
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
//  background-color: #dddddd;
}
</style>)"
     R"(<table>
  <tr>
    <th>STATISTICAL NAME </th>
    <th>SUBJECT </th>
    <th> STATISTICAL VALUE </th>
  </tr> )"
  R"(<tr>
    <td>  Minimum</td>
    <td> Science    </td>)"
    "<td>"<<findMinimum_b(b, n)<<" </td>"
R"(  </tr>
  <tr>
    <td>Maximum           </td>
    <td> Science    </td>)"
    "<td>"<<findMaximum_b(b, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Median            </td>
    <td> Science    </td>)"
   "<td>"<<findMedian_b(b, n)<<" </td>"
   R"(</tr>
  <tr>
    <td>Mean          </td>
    <td> Science    </td>)"
    "<td>"<<findAverage_b(b, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Variance          </td>
    <td> Science    </td>)"
    "<td>"<<variance2(b, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Standard Deviation</td>
    <td> Science    </td>)"
  "<td>"<< standardDeviation2(b, n)<<" </td>"
 R"( </tr>
  <tr>
    <td>Correlation       </td>
    <td> Science    </td>)"
   "<td>"<<correlationCoefficient_b(a, b, c, n)<<" </td>"
 R"( </tr>
  <tr>
    <td>Regression Line   </td>
    <td> Science   </td>)"
    "<td>"<<"y=mx+" <<linear_b(a, b, c, n)<<" </td>"
 R"( </tr>
</table>)";
outfile.close();

    system("cls");
    cout<<endl<<endl;
    cout<<" -----------------------------------------------------------------"<<endl;
    cout<<" Please Launch outputok2.html in order to view Statistical Report =>"<<endl;
    cout<<" -----------------------------------------------------------------"<<endl<<endl;

    system("pause");
    Statistical_Report_HTML();
	return 0;
}

Malay_HTML()
{
    system("cls");
    vector<int> a = openMS(); vector<int> b = openSC(); vector<int> c = openBM(); int n = c.size();

    ofstream outfile;
    outfile.open("outok2.html", ios::out | ios::trunc );
            outfile <<
   R"( <style>
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
//  background-color: #dddddd;
}
</style>)"
     R"(<table>
  <tr>
    <th>STATISTICAL NAME </th>
    <th>SUBJECT </th>
    <th> STATISTICAL VALUE </th>
  </tr> )"
  R"(<tr>
    <td>  Minimum</td>
    <td> Malay    </td>)"
    "<td>"<<findMinimum_c(c, n)<<" </td>"
R"(  </tr>
  <tr>
    <td>Maximum           </td>
    <td> Malay    </td>)"
    "<td>"<<findMaximum_c(c, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Median            </td>
    <td> Malay    </td>)"
   "<td>"<<findMedian_c(c, n)<<" </td>"
   R"(</tr>
  <tr>
    <td>Mean          </td>
    <td> Malay    </td>)"
    "<td>"<<findAverage_c(c, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Variance          </td>
    <td> Malay    </td>)"
    "<td>"<<variance3(c, n)<<" </td>"
  R"(</tr>
  <tr>
    <td>Standard Deviation</td>
    <td> Malay    </td>)"
  "<td>"<< standardDeviation3(c, n)<<" </td>"
 R"( </tr>
  <tr>
    <td>Correlation       </td>
    <td> Malay    </td>)"
   "<td>"<<correlationCoefficient_c(a, b, c, n) <<" </td>"
 R"( </tr>
  <tr>
    <td>Regression Line   </td>
    <td> Malay    </td>)"
    "<td>"<<"y=mx+" <<linear_a(a, b, c, n)<<" </td>"
 R"( </tr>
</table>)";
outfile.close();

    system("cls");
    cout<<endl<<endl;
    cout<<" -----------------------------------------------------------------"<<endl;
    cout<<" Please Launch outputok2.html in order to view Statistical Report =>"<<endl;
    cout<<" -----------------------------------------------------------------"<<endl<<endl;

    system("pause");
    Statistical_Report_HTML();
	return 0;
}

//----------------------------------------------------------------------------------------------------------------
//LOAD DATA FUNCTION
int Load_Data()
{
    system("cls");
    ifstream inFile;
    inFile.open("data10.txt");

    if (!inFile.is_open()) cout << "ERROR: File Open" << '\n';

    string a,b,c,d,e;

 while(inFile.good())
    {
        getline(inFile, a, ',');
        getline(inFile, b, ',');
        getline(inFile, c, ',');
        getline(inFile, d, ',');
        getline(inFile, e, ',');

            cout  << a << setw(15)   ;
            cout  << b << setw(15)  ;
            cout  << c << setw(15)  ;
            cout  << d << setw(15)  ;
            cout  << e << setw(15)  ;
            cout<<endl;

    }




system("pause");
    inFile.close();
    main_menu();
    return 0;
}


//----------------------------------------------------------------------------------------------------------------
//SELECTION MAKER
string getTheChoice(string message, string minimum, string max)
{
    string ch;

    cout << message<< "(" <<minimum << "..." << max << "): ";
    cin >> ch;

    while( ch != "1" && ch != "2" && ch != "3" && ch != "4")
    {
        cout << "Invalid Input! Please choose the given options."<< endl << endl;
        cout << message<< "(" <<minimum << "..." << max << "): ";
        cin >> ch;
    }

    return ch;
}

//SELECTION MAKER FOR CALCULATIONS
string getCalcChoice(string message, string minimum, string max)
{
    string ch;

    cout << message<< "(" <<minimum << "..." << max << "): ";
    cin >> ch;

    while( ch != "1" && ch != "2" && ch != "3" && ch != "4"&& ch != "5"&& ch != "6"&& ch != "7"&& ch != "8"&& ch != "9"&& ch != "10"&& ch != "11"&& ch != "12"&& ch != "13"&& ch != "14")
    {
        cout << "Invalid Input! Please choose the given options."<< endl << endl;
        cout << message<< "(" <<minimum << "..." << max << "): ";
        cin >> ch;
    }

    return ch;
}
string getDataPrintChoice(string message, string minimum, string max)
{
    string ch;

    cout << message<< "(" <<minimum << "..." << max << "): ";
    cin >> ch;

    while( ch != "1" && ch != "2" && ch != "3")
    {
        cout << "Invalid Input! Please choose the given options."<< endl << endl;
        cout << message<< "(" <<minimum << "..." << max << "): ";
        cin >> ch;
    }

    return ch;
}

//----------------------------------------------------------------------------------------------------------------
// DESIGN OF EXIT
void ending()
{
    system("cls");
    cout << endl<< endl;
    cout << setw(45) << "***********************" <<endl;
    cout << setw(45) << "||      THE END       ||" <<endl;
    cout << setw(45) << "||THANK YOU FOR USING ||" << endl;
    cout << setw(45) << "||  THIS APPLICATION  ||" <<endl;
    cout << setw(45) << "***********************" <<endl <<endl;
    exit(0);

}


//----------------------------------------------------------------------------------------------------------------
//CALCULATION PART
//MENU FOR COMPUTATIONS TO USE
void What_Sub();
void title();
//CHOOSING PEARSON'S CORRELATION SUBJECTS MENU
void What_Sub_Pearson()
{
     string choice;
        system("cls");
        title();
        cout <<"  Select The Subject " << endl;
        cout <<"  ------------------ " << endl;
        cout <<"  1. Mathematics and Science    " << endl;
        cout <<"  2. Bahasa Melayu and Science  " << endl;
        cout <<"  3. Bahasa Melayu and Mathematics  " << endl;
        cout <<"  4. Exit            " << endl;

   choice = getTheChoice("Enter choice", "1","4");

    if (choice == "1") correlationCoefficient_Maths();
    else if (choice == "2") correlationCoefficient_BS();
    else if (choice == "3") correlationCoefficient_MB();
    else if (choice == "4") What_Sub();
}

//CHOOSING REGRESSION LINE BETWEEN SUBJECTS MENU
void What_Sub_Regression()
{
     string choice;

        system("cls");
        title();
        cout <<"  Select The Subject " << endl;
        cout <<"  ------------------ " << endl;
        cout <<"  1. Mathematics and Science    " << endl;
        cout <<"  2. Bahasa Melayu and Science  " << endl;
        cout <<"  3. Bahasa Melayu and Mathematics  " << endl;
        cout <<"  4. Exit            " << endl;

    choice = getTheChoice("Enter choice", "1","4");

    if (choice == "1") regressionLine_MS();
    else if (choice == "2") regressionline_BS();
    else if (choice == "3") regressionline_MB();
    else if (choice == "4") What_Sub();
}




//MENU OF COMPUTATIONS FOR MATHS
void MathsStatsMenu()
{
    string choice;

        system("cls");
         title();
        cout << "  Mathematics Stats Menu " << endl;
        cout << "  ------------------" << endl;
        cout << "  1. Minimum      " << endl;
        cout << "  2. Maximum     " << endl;
        cout << "  3. Median  " << endl;
        cout << "  4. Mean  " << endl;
        cout << "  5. Variance  " << endl;
        cout << "  6. Standard Deviation  " << endl;
        cout << "  7. Frequency     "<< endl;
        cout << "  8. Histogram   "<< endl;
        cout << "  9. Table below mean & Table above mean   "<< endl;
        cout << "  10.Pearson" << "\'" <<"s" << " Correlation"<< endl;
        cout << "  11.Linear regression Line  "<< endl;
        cout << "  12.Sort by ascending or sort by descending  "<< endl;
        cout << "  13.Back           " << endl;
        cout << "  14.Exit           " << endl;

    choice = getCalcChoice("Enter choice", "1","4");

    if (choice == "1") Minimum_Value_Maths();
    else if (choice == "2") Maximum_Value_Maths();
    else if (choice == "3") Median_Sort_Value_Maths();
    else if (choice == "4") Mean_Value_Maths();
    else if (choice == "5") Variance_Value_Maths();
    else if (choice == "6") Standard_Deviation_Maths();
    else if (choice == "7") Frequency_Maths();
    else if (choice == "8") Plot_Histogram_Maths();
    else if (choice == "9") Table_below_mean_Table_above_mean_Maths();
    else if (choice == "10") What_Sub_Pearson();
    else if (choice == "11") What_Sub_Regression();
    else if (choice == "12") Ascending_Descending_Maths();
    else if (choice == "13") What_Sub();
    else if (choice == "14") ending();
}


//MENU OF COMPUTATIONS FOR SCIENCE
void ScienceStatsMenu()
{
    string choice;

        system("cls");
         title();
        cout << "  Science Stats Menu " << endl;
        cout << "  ------------------" << endl;
        cout << "  1. Minimum      " << endl;
        cout << "  2. Maximum     " << endl;
        cout << "  3. Median  " << endl;
        cout << "  4. Mean  " << endl;
        cout << "  5. Variance  " << endl;
        cout << "  6. Standard Deviation  " << endl;
        cout << "  7. Frequency     "<< endl;
        cout << "  8. Histogram   "<< endl;
        cout << "  9. Table below mean & Table above mean   "<< endl;
        cout << "  10.Pearson" << "\'" <<"s" << " Correlation"<< endl;
        cout << "  11.Linear regression Line  "<< endl;
        cout << "  12.Sort by ascending or sort by descending  "<< endl;
        cout << "  13.Back           " << endl;
        cout << "  14.Exit           " << endl;


    choice = getCalcChoice("Enter choice", "1","4");

    if (choice == "1") Minimum_Value_Science();
    else if (choice == "2") Maximum_Value_Science();
    else if (choice == "3") Median_Sort_Value_Science();
    else if (choice == "4") Mean_Value_Science();
    else if (choice == "5") Variance_Value_Science();
    else if (choice == "6") Standard_Deviation_Science();
    else if (choice == "7") Frequency_Science();
    else if (choice == "8") Plot_Histogram_Science();
    else if (choice == "9") Table_below_mean_Table_above_mean_Science();
    else if (choice == "10") What_Sub_Pearson();
    else if (choice == "11") What_Sub_Regression();
    else if (choice == "12") Ascending_Descending_Science();
    else if (choice == "13") What_Sub();
    else if (choice == "14") ending();

}


//MENU OF COMPUTATIONS FOR MALAY
void MalayStatsMenu()
{
    string choice;

        system("cls");
         title();
        cout << "  Mathematics Stats Menu " << endl;
        cout << "  ------------------" << endl;
        cout << "  1. Minimum      " << endl;
        cout << "  2. Maximum     " << endl;
        cout << "  3. Median  " << endl;
        cout << "  4. Mean  " << endl;
        cout << "  5. Variance  " << endl;
        cout << "  6. Standard Deviation  " << endl;
        cout << "  7. Frequency     "<< endl;
        cout << "  8. Histogram   "<< endl;
        cout << "  9. Table below mean & Table above mean   "<< endl;
        cout << "  10.Pearson" << "\'" <<"s" << " Correlation"<< endl;
        cout << "  11.Linear regression Line  "<< endl;
        cout << "  12.Sort by ascending or sort by descending  "<< endl;
        cout << "  13.Back           " << endl;
        cout << "  14.Exit           " << endl;

    choice = getCalcChoice("Enter choice", "1","4");

    if (choice == "1") Minimum_Value_Malay();
    else if (choice == "2") Maximum_Value_Malay();
    else if (choice == "3") Median_Sort_Value_Malay();
    else if (choice == "4") Mean_Value_Malay();
    else if (choice == "5") Variance_Value_Malay();
    else if (choice == "6") Standard_Deviation_Malay();
    else if (choice == "7") Frequency_Malay();
    else if (choice == "8") Plot_Histogram_Malay();
    else if (choice == "9") Table_below_mean_Table_above_mean_Malay();
    else if (choice == "10") What_Sub_Pearson();
    else if (choice == "11") What_Sub_Regression();
    else if (choice == "12") Ascending_Descending_Malay();
    else if (choice == "13") What_Sub();
    else if (choice == "14") ending();

}

//----------------------------------------------------------------------------------------------------------------
void Data_Print();
//SUBJECT CHOOSING
void Statistical_Report_TXT()
{
     string choice;

        system("cls");
        title();
        cout <<"  Select The Subject " << endl;
        cout <<"  ------------------ " << endl;
        cout <<"  1. Mathematics     " << endl;
        cout <<"  2. Science         " << endl;
        cout <<"  3. Bahasa Melayu   " << endl;
        cout <<"  4. Exit            " << endl;

    choice = getTheChoice("Enter choice", "1","4");

    if (choice == "1") MathsReport();
    else if (choice == "2") ScienceReport();
    else if (choice == "3") MalayReport();
    else if (choice == "4") Data_Print();

}

void Statistical_Report_HTML()
{
     string choice;

        system("cls");
        title();
        cout <<"  Select The Subject " << endl;
        cout <<"  ------------------ " << endl;
        cout <<"  1. Mathematics     " << endl;
        cout <<"  2. Science         " << endl;
        cout <<"  3. Bahasa Melayu   " << endl;
        cout <<"  4. Exit            " << endl;

    choice = getTheChoice("Enter choice", "1","4");

    if (choice == "1") Maths_HTML();
    else if (choice == "2") Science_HTML();
    else if (choice == "3") Malay_HTML();
    else if (choice == "4") Data_Print();

}

void Data_Print()
{
        string choice;

        system("cls");
        title();
        cout <<"  -----------------------------" << endl;
        cout <<"  Select The Statistical Report" << endl;
        cout <<"  -----------------------------" << endl<< endl;
        cout <<"  1. Statistical Report In TEXT File" << endl;
        cout <<"  2. Statistical Report In HTML File" << endl;
        cout <<"  3. Exit            " << endl;

    choice = getDataPrintChoice("Enter choice", "1","4");

    if (choice == "1") Statistical_Report_TXT();
    else if (choice == "2") Statistical_Report_HTML();
    else if (choice == "3") main_menu();


}

void What_Sub()
{
     string choice;

        system("cls");
        title();
        cout <<"  Select The Subject " << endl;
        cout <<"  ------------------ " << endl;
        cout <<"  1. Mathematics     " << endl;
        cout <<"  2. Science         " << endl;
        cout <<"  3. Bahasa Melayu   " << endl;
        cout <<"  4. Exit            " << endl;

    choice = getTheChoice("Enter choice", "1","4");

    if (choice == "1") MathsStatsMenu();
    else if (choice == "2") ScienceStatsMenu();
    else if (choice == "3") MalayStatsMenu();
    else if (choice == "4") main_menu();

}


void title()
{
    cout << endl<< endl;
    cout << setw(25) << "***********************" <<endl;
    cout << setw(25) << "||BASIC DATA ANALYSIS||" << endl;
    cout << setw(25) << "||    APPLICATION    ||" <<endl;
    cout << setw(25) << "***********************" <<endl <<endl;
}

//------------------------------------------------------------------------

//MAIN MENU
void main_menu()
{
    string choice;

        system("cls");
         title();
        cout << setw(20) <<" Main Menu        " << endl;
        cout << setw(20) <<"------------------" << endl;
        cout << setw(20) <<"1. Load Data      " << endl;
        cout << setw(20) <<"2. Print Data     " << endl;
        cout << setw(20) <<"3. Compute Stats  " << endl;
        cout << setw(20) <<"4. Exit           " << endl;


    choice = getTheChoice("Enter choice", "1","4");

    if (choice == "1") Load_Data();
    else if (choice == "2") Data_Print();
    else if (choice == "3") What_Sub();
    else if (choice == "4") ending();

}



int main()
{
    main_menu();

    return 0;
}


