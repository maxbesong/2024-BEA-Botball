#include <kipr/wombat.h>

//Moves wheels at speed for certain times//
void drive(int leftSpeed, int rightSpeed, int time)
{  
    motor(1, leftSpeed);
    motor(0, rightSpeed);
    msleep(time);
}

int main()
{
    //wait_for_light(4);
    //shut_down_in(118);
    printf("Hello World\n");
    set_servo_position(0, 855);
    set_servo_position(3, 0);
    enable_servos();

    drive(50,50,7000);
    drive(50, 0, 1000);
    drive(50, 50, 2000);
   
    //move hook to open air lock
    set_servo_position(0, 0);

    //opening the air lock, and removing the hook
    drive(-50, -50, 1600);
    set_servo_position(0, 855);
   
    //turn to head to flip the switch
    drive(-50, -50, 2000);
    drive(0, 50, 1200);
   
   
    return 0;
}