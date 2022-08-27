# Orbis---Throw-them-all-
# Midterm project of Fundumental of Programming

Implementing a game from  Madness Game Studio

You must throw disks of the tower to the walls based on types of the disks and do not let the tower reach the top! 
but it might not be simple after all. However, there are not just blue and red disks! 
There are a lot of special disks such as Golden Disk which gives you double score. 


Noramal disk: * and #

Uniform disk: $

Opportunity disk: +

Golden/Coefficient disk: 2, 4

Obscure disk: ?

Stop disk: |

Attractive disk: ~

Not attractive disk: =

#Example of game senario:

At first,9 houses of the stack capacity are filled, 

from the top there are disks of factor 2, unattractive, ambiguous, "*", opportunity, attractive, "#", "*" and finally opportunity.

Now we wait for 1 second, if the user did not press a button or the button he pressed was not one of the expected buttons, 
the new disk will be added from below. But if one of the expected inputs is entered, the collisions and subsequent events
will take place. Let's say the player chooses the right move, the 2-factor disc hits each of the walls (it doesn't matter), for the next 3 moves, 
the user will get double points. Now the disk with a factor of 2 is removed from the stack. (One is subtracted from the height of the stack.)

After the collision, we wait again for 1 second. 
Suppose the player did not make a new input. So the discs move up 1 unit and a new disc is added from the bottom.
