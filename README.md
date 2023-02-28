
# Documentation
Gradebook project for CSC 212 Spring 2023

## Summary
This is our gradebook assignment for CSC 212. Our group consist of **Jason Wu, Eric Chin, Shuichi Kameda, and Nathan Chen.** Our Objective for this assignment is to be able to import in a file has holds a student's grades for CSC 212, be able to view them individually, reveal the overall grade for the course, edit the score for each lab, assignment, exam and project. Included in the documentation will contain our planning of this program at the start, the compliation instructions on how to run the program correctly, how to actually use the program once running, and examples of the input and outputs of the program followed with a video guide.

## Planning
When we first brainstormed the program out, we had some rough draft ideas with psudo-flowcharts.
Below are out initial flowchats of the program.

<p align="center">
	<img src="/images/psudo1.png" width="350" height="500">
	<img src="/images/psudo2.png" width="350" height="500">
</p>

As you can see from the first image, this is the rough draft for the main.cpp long with the gradebook.cpp and gradebook.h.
When the main.cpp starts, our first goal planned was to open the gradebook data. The data should be specific towards the student with thier own personal grades. Our proposed file type of choice was **Comma Seperated Values (CSV)** file. The file will be opened and read into the program with a readCSV function, which will then prompt to start our user interface (UI). We wanted the UI to be within the terminal  of the **CLion IDE** (Recommended IDE for the class). Within the UI, we planned to have the user select options that will be prompt into the terminal. 

Our proposed options for our program will be as follows but not in any specific order: 
* View All (Standings)
	* The option to view all your current grades within the CSC 212 course.
		* Labs
		* Assignments
		* Exams
		* Projects
* Update
	* The option to update any grades that are shown/within the CSV file. 
* Progress
	* The option to show the overall grade for the class with a number (out of 1000) and letter score (A - D).
* Exit
	* The option to exit the program.

Following this basic foundation we have created, we decided to create a completed flowchart.
Below is our finalized flowchart of the program.
![Flowchart](/images/newFlowchart.png)

After the creation of this flowchart, we started working on the psudocode as a foundation guide to start the code. We developed the psudocode 

## Compilation Instructions
To compile the gradebook program, you will have to download the files within the repository. Then you will need an IDE. We suggest and recommend CLion by Jetbrains as the IDE as it has a dedicated compiler for C++. If you choose to use another IDE, make sure you have a compiler that can compile C++11 available. 

Once the files are opened in the IDE, you can run main.cpp to start the program. No additional Command Line Arguments (CLAs) are needed for the gradebook to run. Make sure all the files are within thier respective folders. If you would like to use a personal gradebook data set, please place the CSV file into the /dataset folder.

## Runtime Instructions
Once the program is running, the terminal will be the main output of the UI. When prompt into the UI, you will face the initial terminal output. This initial output will be asking for the file name of the CSV data set. This will prompt the program to read and open the requested file. If successful, the program will send the user to the main UI of the gradebook. If the file name is incorrect, an error will be returned to the user within the terminal. 

## Sample input/output screenshots with brief explanations of the images used

