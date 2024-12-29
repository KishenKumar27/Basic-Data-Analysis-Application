# Basic Data Analysis Application

This repository contains a C++ application designed for basic data analysis. It allows users to load, compute, and visualize statistical data for different subjects, including Mathematics, Science, and Bahasa Melayu. The application supports various statistical calculations such as mean, median, mode, variance, standard deviation, frequency, Pearson correlation, linear regression, and more. Additionally, the application provides functionality to generate reports in both text and HTML formats.

## Project Structure

The project consists of the following directories and files:

```bash
Basic-Data-Analysis-Application/
│
├── Flowchart/
│   ├── Flowchart-tc01-1181102720-part1.pdf
│   ├── Frequency.rap
│   ├── Linear Regression Line.rap
│   ├── Pearson's Correlation.rap
│   ├── Statistical_Report_Html.html
│   ├── Statistical_Report_Txt.txt
│   ├── abovem.rap
│   ├── application.rap
│   ├── applicationStatsReportHtml.rap
│   ├── applicationStatsReportTxt.rap
│   ├── ascending.rap
│   ├── belowm.rap
│   ├── data.csv
│   ├── descending.rap
│   ├── frequency200911a.rap
│   ├── mean.rap
│   ├── median.rap
│   └── minimum200911a.rap
│
├── Part 1/
│   ├── PF Assignment Part 1.pdf
│   └── Problem Statement.docx
│
├── Part 2/
│   ├── 353703_Assignment Part 2 Submission.docx
│   └── PF ASSIGNMENT PART 2.docx
│
├── Source Codes/
│   └── BasicDataAnalysisProgram/
│       ├── data10.txt
│       ├── data100.csv
│       ├── data_analysis.cpp
│       ├── outok.txt
│       └── outok2.html
│
├── Task/
│   ├── 345813_TCP1101 Assignment.pdf
│   ├── Briefing Link.docx
│   └── data100.csv
│
├── .gitignore
├── README.md
```

## Features

- **Data Loading**: Reads data from a CSV file and loads it into vectors for further analysis.
- **Statistical Calculations**: Supports multiple statistical calculations such as:
  - Mean, Median, Mode
  - Standard Deviation, Variance
  - Frequency distribution
  - Pearson’s Correlation Coefficient
  - Linear Regression
- **Data Sorting**: Sorts data in ascending and descending order for comparison.
- **Histograms**: Visualizes data distribution with histograms.
- **Report Generation**: Generates statistical reports in both text and HTML formats.
- **Subject-Based Analysis**: Perform statistical analysis for Mathematics, Science, and Bahasa Melayu.

## Requirements

- C++ compiler (e.g., g++, clang)
- C++ Standard Library
- CSV file (`data100.csv`) with appropriate data for analysis

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/KishenKumar27/Basic-Data-Analysis-Application.git
   ```

2  Navigate to the specific folder
   ```bash
   cd Source Codes/BasicDataAnalysisProgram
   ```

3. Compile the C++ code:
   ```bash
   g++ data_analysis.cpp -o data_analysis
   ```

4. Run the application:
   ```bash
   ./data_analysis
   ```

## License
This project is part of the TCP1101 Programming Language Fundamentals coursework.
