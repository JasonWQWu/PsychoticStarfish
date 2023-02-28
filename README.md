
# Documentation
Gradebook project for CSC 212 Spring 2023

## Summary
This is our gradebook assignment for CSC 212. Our group consist of **Jason Wu, Eric Chin, Shuichi Kameda, and Nathan Chen.** Our Objective for this assignment is to be able to import in a file has holds a student's grades for CSC 212, be able to view them individually, reveal the overall grade for the course, edit the score for each lab, assignment, exam and project. Included in the documentation will contain our planning of this program at the start, the compliation instructions on how to run the program correctly, how to actually use the program once running, and examples of the input and outputs of the program followed with a video guide link at the end of this page.

## Planning
When we first brainstormed the program out, we had some rough draft ideas with psudo-flowcharts.
Below are out initial flowchats of the program.


<p align="center">
	<img src="/images/psudo1.png" width="350" height="500">
	<img src="/images/psudo2.png" width="350" height="500">
</p>

As you can see from the first image, this is the rough draft for the main.cpp long with the gradebook.cpp and gradebook.h.
When the main.cpp starts, our first goal planned was to open the gradebook data. The data should be specific towards the student with thier own personal grades. Our proposed file type of choice was **Comma Seperated Values (CSV)** file. The file will be opened and read into the program with a readCSV function, which will then prompt to start our user interface (UI). We wanted the UI to be within the terminal  of the **CLion IDE** (Recommended IDE for the class), meaning the runtime and compilation instructions will be written for CLion.  Within the UI, we planned to have the user select options that will be prompt into the terminal. 

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
To compile the gradebook program, you will have to download the files within the repository. Then you will need an IDE. We use CLion by Jetbrains as the IDE as it has a dedicated compiler for C++. If you choose to use another IDE, make sure you have a compiler that can compile C++11 available. 

You will first open CLion and create a new project, selecting C++11 as the desired language version. Then, you will extract the downloaded files into the path of the project. To access the data sets where the CSVs are located, please move the CSV files into /cmake-build-debug path to ensure it runs within CLion. If you would like to use a personal gradebook data set, please place the CSV file into the the same path. Once the files are in place, they should look like the image below.

![CLion directory example](/images/clion_directory_example.PNG)

To make sure CLion is able to execute the program, be sure the **CMakeList.txt** file contains the files these three files within the **add_executable** function like this image below.
 
 ![CMake](/images/clion_cmake.PNG)
 
Once all the files are inplace, you can run main.cpp to start the program on the top right of CLion. No additional Command Line Arguments (CLAs) are needed for the gradebook to run.

## Runtime Instructions
Once the program is running, the terminal will be the main output of the UI. When prompt into the UI, you will face the initial terminal output. This initial output will be asking for the file name of the CSV data set. 

![Runtime Input](/images/runtime_input.PNG)

This will prompt the program to read and open the requested file. If successful, the program will send the user to the main UI of the gradebook. If the file name is incorrect, an error will be returned to the user within the terminal. Please make sure you enter in the file name exactly how it is spelled, with the same capitalization as the file name.

## Sample input/output screenshots

Once you have the program up and running, you are free to use it how you would like! Here are the ways you can utilize each option once you run and input the desired CSV file.

You will first be prompt to the main 4 options of our gradebook program. 
![Gradebook options](/images/options.PNG)


### Display Progression 
Within our first option, which is Display Progress, you are then able to select 3 more options on what kind of progression to view within your grades.

<p align="left">
	<img src="/images/runtime_display_prog.PNG">
	
</p>
<br />
The first option will be the individual assignment to view.
<p align="left">
	<img src="/images/runtime_dp_individual.PNG">
	
</p>
Be sure to input the individual assignment name exactly.

<br />
Secondly, you will view the category of assignments desired.
<p align="left">
	<img src="/images/runtime_dp_category.PNG">
	
</p>
Be sure to input the categories of assignments exactly.

<br />
Lastly, the course progression can be viewed.
<p align="left">
	<img src="/images/runtime_course.PNG">
	
</p>

Within the courses option, you have three different options to choose from as well.

The option to show all grades will be the first.
<p align="left">
	<img src="/images/runtime_course_1.PNG">
	
</p>

Next will be the option to view the grades from a specific category with the overall category grade.
<p align="left">
	<img src="/images/runtime_course_2.PNG">
	
</p>

Lastly, you can view only the overall grade of the course.
<p align="left">
	<img src="/images/runtime_course_3.PNG">
	
</p>

### Update
The second option within the main UI is updating your grades. You can update an individual assignment or lab's grade once it its graded by the TAs or by the Professor. Look at the image below for an example.  
<p align="left">
	<img src="/images/runtime_update.PNG">
	
</p>
As you can see, the grade for Lab_05 is updated to 15/20.

### Retrieve CSV
The third option of the main UI is to output the new grades into a completely brand new CSV file. If you did not make any updated changes to any of the grades, this option is not needed for the users. To update the grades, the UI will prompt you to enter a new file name for the updated CSV. The file name does not have to include the file type (.csv) at the end.
<p align="left">
	<img src="/images/runtime_output.PNG">
	
</p>

The output file will result in the same directory as your input file. It will not output until the program is ended with the next option.

### Quit
Once you are done using the gradebook program, the last option of the main UI will end the program's use. 
![Quit](/images/runtime_quit.PNG)

## Walkthrough Video
[Click here to watch the walkthrough video!](https://youtu.be/Rze0r_RRUl4)


