# Web3-Recruitment-Task-Submission
The task code was very interesting but it was a but ambiguous. Hence I made some assumptions and made the code. Here’s how my code works!  

I made a car class and defined the requisite attributes. But I made the speed attribute another class with its 3 co-ordinate components.  Now I took user input the co-ordinates and the speed with it’s 3 co-ordinates for the two cars separately. 
 Then I asked the user what car’s acceleration/braking do they want to modify, and accordingly invoked the acceleration/braking function.  the acceleration/braking function updates all the three co-ordinates of the speed function. Now I calculated the time taken for them to collide, and then invoked the move function. the move function updates all the three co-ordinates of the car, and the time is calculated by distance/absolute value of relative speed.

Try testing the program with these values(or any other values obviously):

Speed of car1 : 1 2 3
co-ordinates of car1 : 0 0 0
Speed of car2 : 2 4 6
co-ordinates of car1 : -1 -2 -3

They should collide after 1 second. 


I had originally written this code in C because I am more familiar with it. Due to time constraint i translated it last moment to C++.
Hence I have uploaded both files.
