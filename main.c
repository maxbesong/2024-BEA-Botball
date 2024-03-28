#include <kipr/wombat.h>

//turns the left and right wheel motors at specified speeds for a certain amount of time
void drive(int leftSpeed, int rightSpeed, int time)
{
    create_drive_direct(leftSpeed, rightSpeed*323.0/350.0);
    msleep(time);
}

//rotates the robot by a specified angle
void turn(int angle)
{
    int time = (abs(angle) * 2000.0 / 180.0);
    if(angle<0)
        drive(200, -200, time);
    else
        drive(-200, 200, time);
}

int main()
{
    printf("Hello my name is Spot Dock\n");

    //connects to the Create
    create_connect();
    create_full();
    
    msleep(100);
    
    //drive forward and begin to follow the line
    drive(-150, -150, 6500);
    drive(150, 150, 2500);
    turn(-90);
    drive(150, 150, 5000);
    turn(-90);
    drive(150, 150, 900);
    
    if(get_create_lbump()> 0 || get_create_rbump()>0)
    {
        turn(90);
    }
   
    //sets settings for line following
    int threshold = 2200;
    int speed = 250;
    
    //follows the black tape until the front bumper is pressed
    printf( "Follow the non-yellow brick road!\n");
    while ((get_create_lbump() == 0) && (get_create_rbump() ==0))
    {
        //if it senses black, turn left
        if(get_create_lfcliff_amt() > threshold)
        {
            printf("turning left %d\n", get_create_lfcliff_amt());
            create_drive_direct(0.15*speed, speed);
        }
        //otherwise, turn right
        else
        {
            printf("turning right %d\n", get_create_lfcliff_amt());
            create_drive_direct(speed, 0.5*speed);
        }
    }
}