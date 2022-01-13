NAME OF THE GAME : THE DIGGER  . 

STUDINT NAME : FADI IDKIDEK .
ID : 318498979 .

ABOUT THE GAME :
THIS GAME CONSEST OF DIGGER ND DIAMONDS , THE DIGGER SHOULD EAT THE DIAMONDS , IN THE SAME TIME THERE ARE MONSTERS TAT FOLLWOS THE DIGGER , IN EACH TIME THE MONSTERS 
TUCH THE DIGGER , IT WILL DECREAS THE LIVES OF THE DIGGER , DIGGER LIVES IN THE BEGINING OF THE GAME ARE EQUAL TO 3 . 
THE GAME IS MANAGED BY ASPICEFIC TIME , SO THERE ARE ALIMIT OF SECONDS/MENOTS TO EAT ALL THE DIAMOND TO PASS TO THE FOLLOWING LEVEL .
TIME , LIVES , LEVEL , SCORE ARE ALL APEARS IN THE POTTOM OF THE SCREEN .
THERE ARE 4 LEVELS IN THIS GAME .
IF THE PLAYER WANT TO FINISH THE GAME HE CAN PRESS ON (Esc) , IT WILL END THE GAME DIRECTLY .
THE DIGGER MOVE IS USING THE LETTERS A,B,C,D .
IF THE USER PRESSED (A or left) THE DIGGER WILL GO TO THE LEFT.
IF THE USER PRESSED (D or right) THE DIGGER WILL GO TO THE RIGHT. 
IF THE USER PRESSED (W or up) THE DIGGER WILL GO TO THE UP. 
IF THE USER PRESSED (S or down) THE DIGGER WILL GO TO THE DOWN.   

CLASSES : 

1- Controller : in this class , i made the windo that i will work on , then i made aloop wich it continue till the game ends .

2- object : this is class of the pasic attributes of the opjects . it contain position , texture , size and type , and some functions like drow , set texture ....

3- moveable : this class inherits from object class , it used for the objects Digger and Monster .

4- unmoveable : this clas also inherits from object class , it used for the objects Wall , Diamond and Rock . 	    

5- status : used to show the timer , lives numbers , level number and the score .

6- digger : this is the object of the digger .

7- monster : this is the object of the monster .

8- diamond : this is the object of the diamond .

the same thing in 9- wall, 10- rock .

11- settings : this class used like a helper class .

12 - game : this class are the core of all the classes , it uses all th classes and functions to run the game .


TO ADD A LEVEL : 
the only thing that should do if we want to add alevel is to add the level in the board.txt .



