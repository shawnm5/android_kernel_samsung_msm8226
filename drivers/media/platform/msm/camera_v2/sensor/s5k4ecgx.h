#ifndef __S5K4ECGX_H__
#define __S5K4ECGX_H__

#include "msm_sensor.h"

#undef DEBUG_LEVEL_HIGH
#undef CDBG

#define DEBUG_LEVEL_HIGH
#ifdef DEBUG_LEVEL_HIGH
#define CDBG(fmt, args...)	printk("[S5K4ECGX] %s : %d : "fmt "\n",   __FUNCTION__, __LINE__, ##args)
#endif

#define LOW_LIGHT_LEVEL    0x40
#define BURST_MODE_BUFFER_MAX_SIZE 128
#define BURST_REG 0x0F12

struct s5k4ecgx_userset {
    unsigned int metering;
    unsigned int exposure;
    unsigned int wb;
    unsigned int iso;
    unsigned int effect;
    unsigned int scenemode;
    unsigned int resolution;
    unsigned int ae_awb_lock;
    unsigned int focus_mode;
    unsigned int flash_mode;
    unsigned int lowLight;
    unsigned int is_touchaf;
    unsigned int is_preflash;
};

struct s5k4ecgx_ctrl {
    struct s5k4ecgx_userset settings;
    unsigned int op_mode;
    unsigned int prev_mode;
    unsigned int streamon;
    unsigned int exif_iso;
    unsigned int exif_shutterspeed ;
};

int32_t s5k4ecgx_sensor_config(struct msm_sensor_ctrl_t *s_ctrl,
	void __user *argp);
int32_t s5k4ecgx_sensor_native_control(struct msm_sensor_ctrl_t *s_ctrl,
	void __user *argp);
int s5k4ecgx_sensor_match_id(struct msm_camera_i2c_client *sensor_i2c_client,
	struct msm_camera_slave_info *slave_info,
	const char *sensor_name);

extern int32_t s5k4ecgx_set_flash(int mode);

#endif	//__S5K4ECGX_H__
