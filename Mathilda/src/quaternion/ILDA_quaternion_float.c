#include "ILDA_quaternion/ILDA_quaternion.h"

ILDA_quat ILDA_quat_mul(const ILDA_quat* q1, const ILDA_quat* q2)
{
    return (ILDA_quat) {
        .x = q1->w * q2->x + q1->x * q2->w + q1->y * q2->z - q1->z * q2->y,
        .y = q1->w * q2->y + q1->x * q2->z + q1->y * q2->w - q1->z * q2->x,
        .z = q1->w * q2->z + q1->x * q2->y + q1->y * q2->x - q1->z * q2->w,
        .w = q1->w * q2->w + q1->x * q2->x + q1->y * q2->y - q1->z * q2->z,
    };
}

