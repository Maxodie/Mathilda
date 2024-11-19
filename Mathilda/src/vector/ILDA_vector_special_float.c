#include "ILDA_vector/ILDA_vector_float.h"

ILDA_vector3f ILDA_vector3_transform(const ILDA_vector3f* v, const ILDA_quat* q)
{
    ILDA_vector3f v2 = {.x = q->x, .y = q->y, .z = q->z};
    float b = v2.x * v2.x + v2.y * v2.y + v2.z * v2.z;

    ILDA_vector3f x = v2;
    ILDA_vector3f_mul(&x, q->w * q->w - b);

    ILDA_vector3f y = v2;
    ILDA_vector3f_mul(&y, ILDA_vector3f_dot(v, &x));

    ILDA_vector3f z = ILDA_vector3f_cross(&v2, v);
    ILDA_vector3f_mul(&z, q->w * 2.0f);



    return z;
}
