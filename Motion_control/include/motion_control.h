#include<ctime>
#include<iostream>
#include<math.h>
#include<Eigen/Core>

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>
#include <webots/TouchSensor.hpp>
#include <webots/Accelerometer.hpp>
#include <webots/InertialUnit.hpp>

using namespace webots;
using namespace Eigen;



class Motion_control
{
  public:
    //---构造函数---
    Motion_control();

    //---定义变量---
    const double *imu_temp;

    double time_step;

    double roll_ang,pitch_ang,yaw_ang;
    double pre_roll_ang = 0;
    double pre_pitch_ang = 0;
    double pre_yaw_ang = 0;
    double roll_ang_vel,pitch_ang_vel,yaw_ang_vel;

    MatrixXd pre_joint_ang(4,3),joint_ang(4,3);
    MatrixXd ang_vel(4,3);

    RowVectorXd contect_flag(4);

  
    
    //---机器人马达---
    const char* MOTOR_NAMES[4][3] = 
    {
      {"RF0", "RF1", "RF2"},
      {"RH0", "RH1", "RH2"},
      {"LF0", "LF1", "LF2"},
      {"LH0", "LH1", "LH2"}
    };

    //---机器人位置传感器---
    const char* SENSOR_NAMES[4][3] = 
    {
      {"RF0 sensor", "RF1 sensor", "RF2 sensor"},
      {"RH0 sensor", "RH1 sensor", "RH2 sensor"},
      {"LF0 sensor", "LF1 sensor", "LF2 sensor"},
      {"LH0 sensor", "LH1 sensor", "LH2 sensor"}
    };

    //---机器人触底传感器---
    const char* TOUCH_SENSOR_NAMES[4] = 
    {
      "RF touch sensor", "RH touch sensor", 
      "LF touch sensor", "LH touch sensor"
    };

    //---机器人质心传感器---
    const char* INERTIAL_UNIT = "inertial unit";
    const char* ACCELEROMETER = "accelerometer";

    //---webots初始化相关---
    webots_init()；
  
    //---webots其他相关(set value)---
    webots_relate()；
   
    //---姿态角速度计算---
    posture_dot()；
    
    //---关节角速度计算---
    joint_vel_dot()；
    
    //---

  
  
    
    


};
