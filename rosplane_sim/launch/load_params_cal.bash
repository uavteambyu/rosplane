set -x

rosservice call /fixedwing/param_load_from_file ~/rosflight_ws/param.yml
rosservice call /fixedwing/calibrate_imu
rosservice call /fixedwing/calibrate_baro
rosservice call /fixedwing/calibrate_airspeed
