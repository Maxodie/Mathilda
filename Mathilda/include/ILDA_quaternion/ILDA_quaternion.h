#ifndef __ILDA_QUATERNION__
#define __ILDA_QUATERNION__

typedef struct ILDA_quat
{
    float x, y, z, w;
} ILDA_quat;


ILDA_quat ILDA_quat_mul(const ILDA_quat* q1, const ILDA_quat* q2);


#endif
