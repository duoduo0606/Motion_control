    #include "motion_control.h"
    
    webots_init()
    {
      Motor *limb_motors[4][3];
      PositionSensor *limb_position_sensor[4][3];
      TouchSensor *limb_force_sensor[4];
      Accelerometer *acc;
      InertialUnit *imu;

      //---创建机器人---
      Robot *robot = new Robot();

      //---时间设置---
      int timeStep = (int)robot->getBasicTimeStep();

      //---质心传感器设置---
      imu = robot->getInertialUnit(INERTIAL_UNIT);
      acc = robot->getAccelerometer(ACCELEROMETER);

      //---质心传感器使能---
      imu -> enable(timeStep);
      acc -> enable(timestep);

      //---传感器设置和使能(get value and enable)---
      for(int i=0;i<4;i++)
        {
          for(int j=0;j<3;j++)
            {
              limb_motors[i][j] = robot->getMotor(MOTION_NAMES[i][j]);
              limb_motors[i][j]->setPosition(0);
              limb_position_sensor[i][j] = robot->getPositionSensor(SENSOR_NAMES[i][j]);
              limb_position_sensor[i][j]->enable(timeStep);
            }
            limb_force_sensor[i] = robot->getTouchSensor(TOUCH_SENSOR_NAMES[i]);
            limb_force_sensor[i]->enable(timeStep);
        }
    }//---end webots_init---


    //---webots其他相关(set value)---
    webots_relate()
    {
      for (int i=0; i<4; i++)
        {
          for (int j=0; j<3; j++)
            {
             joint_ang(i,j) = limb_position_sensor[i][j]->getValue();
            }
             contect_flag(i) = limb_force_sensor[i]->getValue();
        }
      
      imu_temp = imu->getRollPitchYaw();
      roll_ang = *imu_temp;
      pitch_ang = *(imu_temp+1);
      yaw_ang = *(imu_temp+2); 
      
    }


    //---姿态角速度计算---
    posture_dot()
    {
      roll_ang_vel = (roll_ang - pre_roll_ang)/time_step;
      pitch_ang_vel = (pitch_ang - pre_pitch_ang)/time_step;
      yaw_ang_vel = (yaw_ang - pre_yaw_ang)/time_step;
    
      pre_roll_ang = roll_ang;
      pre_pitch_ang = pitch_ang;
      pre_yaw_ang = yaw_ang; 
    }


    //---关节角速度计算---
    joint_vel_dot()
    {
      for(int i=0; i<4; i++)
        {  
          for(int j=0; j<3; j++)
            {
              ang_vel(i,j) = (joint_ang(i,j) - pre_joint_ang(i,j))/time_step;
              pre_joint_ang(m,n) = joint_ang(i,j);
            } 
        } 
    }