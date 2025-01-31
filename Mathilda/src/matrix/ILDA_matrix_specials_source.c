#ifdef __ILDA_MATRIX_SPECIAL_SOURCE_CHECK__
ILDA_STATIC_ASSERT(false, "ILDA MATRIX SOURCE : file is called but it was already on");
#endif

#define __ILDA_MATRIX_SPECIAL_SOURCE_CHECK__

//matrix4x4 only
ILDA_FUN_DECL ILDA_matrix4x4 ILDA_translation(const ILDA_matrix4x4* identity, const ILDA_vector3f* translation)
{
    ILDA_ASSERT(identity, "identity matrix in ILDA_translation is nullptr")
    ILDA_ASSERT(translation, "translation ILDA_vector3f in ILDA_translation is nullptr")

    ILDA_matrix4x4 mat4x4 = { .data = { {0, 0, 0, translation->x}, {0, 0, 0, translation->y}, {0, 0, 0, translation->z}, {0, 0, 0, 0} } };
    ILDA_matrix4x4_add(&mat4x4, identity);

    return mat4x4;
}

ILDA_FUN_DECL ILDA_bool ILDA_scale(ILDA_matrix4x4* matrix4x4, const ILDA_vector3f* scale)
{
    ILDA_ASSERT(matrix4x4, "matrix4x4 in ILDA_scale is nullptr")
    ILDA_ASSERT(scale, "scale ILDA_vector3f in ILDA_scale is nullptr")

    ILDA_matrix4x4 result = { .data = { {scale->x, 0, 0, 0}, {0, scale->y, 0, 0}, {0, 0, scale->z, 0}, {0, 0, 0, 1} } };
    ILDA_matrix4x4_mul_same(matrix4x4, &result);

    return ILDA_SUCCESS;
}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_rotation(float rotation, const ILDA_vector3f* axisVector)
{
    ILDA_ASSERT(axisVector, "vector3 ILDA_vector3f in ILDA_rotation is nullptr")

    float x = axisVector->x, y = axisVector->y, z = axisVector->z;


    ILDA_matrix4x4 result = {
        .data = {
            { cosf(rotation) + x * x * (1 - cosf(rotation)), x * y * (1 - cosf(rotation)) - z * sinf(rotation), x * z * (1 - cosf(rotation)) + y * sinf(rotation), 0 },
            { y * x * (1 - cosf(rotation)) + z * sinf(rotation), cosf(rotation) + y * y * (1 - cosf(rotation)), y * z * (1 - cosf(rotation)) - x * sinf(rotation), 0 },
            { z * x * (1 - cosf(rotation)) - y * sinf(rotation), z * y * (1 - cosf(rotation)) + x * sinf(rotation), cosf(rotation) + z * z * (1 - cosf(rotation)), 0 },
            { 0, 0, 0, 1 }
        }
    };

    return result;
}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_look_at_r(const ILDA_vector3f* position, const ILDA_vector3f* target, const ILDA_vector3f* worldUp)
{
    ILDA_ASSERT(position, "ILDA_vector3f position in ILDA_matrix_look_at_r is nullptr")
    ILDA_ASSERT(target, "ILDA_vector3f target in ILDA_matrix_look_at_r is nullptr")
    ILDA_ASSERT(worldUp, "ILDA_vector3f worldUp in ILDA_matrix_look_at_r is nullptr")

    // 2. Calculate cameraDirection
    ILDA_vector3f dir;
    ILDA_vector3f_copy(&dir, target);
    ILDA_vector3f_sub(&dir, position);
    ILDA_vector3f za = ILDA_vector3f_normalize(&dir);
    // 3. Get positive right axis vector
    ILDA_vector3f zcorss = ILDA_vector3f_cross(&za, worldUp);
    ILDA_vector3f nzc = ILDA_vector3f_normalize(&zcorss);
    // 4. Calculate camera up vector
    ILDA_vector3f ya = ILDA_vector3f_cross(&nzc, &za);

    ILDA_matrix4x4 rotation = { .data = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}} };
    rotation.data[0][0] = nzc.x;
    rotation.data[1][0] = nzc.y;
    rotation.data[2][0] = nzc.z;
    rotation.data[0][1] = ya.x;
    rotation.data[1][1] = ya.y;
    rotation.data[2][1] = ya.z;
    rotation.data[0][2] =-za.x;
    rotation.data[1][2] =-za.y;
    rotation.data[2][2] =-za.z;
    rotation.data[3][0] =-ILDA_vector3f_dot(&nzc, position);
    rotation.data[3][1] =-ILDA_vector3f_dot(&ya, position);
    rotation.data[3][2] = ILDA_vector3f_dot(&za, position);

    return rotation;
}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_perspective_r(float fovy, float aspect, float zNear, float zFar)
{
    float tanHalfFovy = tanf(fovy / 2.f);

    ILDA_matrix4x4 result = { .data = {0} };
    result.data[0][0] = 1.f / (aspect * tanHalfFovy);
    result.data[1][1] = 1.f / (tanHalfFovy);
    result.data[2][2] = - (zFar + zNear) / (zFar - zNear);
    result.data[2][3] = - 1.f;
    result.data[3][2] = (2.f * zFar * zNear) / (zFar - zNear);
    return result;
}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_look_at_l(const ILDA_vector3f* position, const ILDA_vector3f* target, const ILDA_vector3f* worldUp)
{
    ILDA_ASSERT(position, "ILDA_vector3f position in ILDA_matrix_look_at_r is nullptr")
    ILDA_ASSERT(target, "ILDA_vector3f target in ILDA_matrix_look_at_r is nullptr")
    ILDA_ASSERT(worldUp, "ILDA_vector3f worldUp in ILDA_matrix_look_at_r is nullptr")

    // 2. Calculate cameraDirection
    ILDA_vector3f dir;
    ILDA_vector3f_copy(&dir, target);
    ILDA_vector3f_sub(&dir, position);
    ILDA_vector3f za = ILDA_vector3f_normalize(&dir);
    // 3. Get positive right axis vector
    ILDA_vector3f zcorss = ILDA_vector3f_cross(&za, worldUp);
    ILDA_vector3f nzc = ILDA_vector3f_normalize(&zcorss);
    // 4. Calculate camera up vector
    ILDA_vector3f ya = ILDA_vector3f_cross(&nzc, &za);

    ILDA_matrix4x4 rotation = { .data = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}} };
    rotation.data[0][0] = nzc.x;
    rotation.data[1][0] = nzc.y;
    rotation.data[2][0] = nzc.z;
    rotation.data[0][1] = ya.x;
    rotation.data[1][1] = ya.y;
    rotation.data[2][1] = ya.z;
    rotation.data[0][2] = za.x;
    rotation.data[1][2] = za.y;
    rotation.data[2][2] = za.z;
    rotation.data[3][0] =-ILDA_vector3f_dot(&nzc, position);
    rotation.data[3][1] =-ILDA_vector3f_dot(&ya, position);
    rotation.data[3][2] =-ILDA_vector3f_dot(&za, position);

    return rotation;
}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_perspective_l(float fovy, float aspect, float zNear, float zFar)
{
    float tanHalfFovy = tanf(fovy / 2.f);

    ILDA_matrix4x4 result = { .data = {0} };
    result.data[0][0] = 1.f / (aspect * tanHalfFovy);
    result.data[1][1] = 1.f / (tanHalfFovy);
    result.data[2][2] =  (zFar + zNear) / (zFar - zNear);
    result.data[2][3] =  1.f;
    result.data[3][2] = -(2.f * zFar * zNear) / (zFar - zNear);
    return result;
}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_look_at(const ILDA_vector3f* position, const ILDA_vector3f* target, const ILDA_vector3f* worldUp)
{
#   ifdef ILDA_FORCE_LEFT_HANDED
        return ILDA_look_at_l(position, target, worldUp);
#   else
        return ILDA_look_at_r(position, target, worldUp);
#   endif
}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_perspective(float fovy, float aspect, float zNear, float zFar)
{
#   ifdef ILDA_FORCE_LEFT_HANDED
        return ILDA_perspective_l(fovy, aspect, zNear, zFar);
#   else
        return ILDA_perspective_r(fovy, aspect, zNear, zFar);
#   endif

}

ILDA_FUN_DECL ILDA_matrix4x4 ILDA_eulerAngleXYZ(float x, float y, float z)
{
    float c1 = cosf(x);
    float c2 = cosf(y);
    float c3 = cosf(z);
    float s1 = sinf(x);
    float s2 = sinf(y);
    float s3 = sinf(z);

    ILDA_matrix4x4 result = { 0 };
    result.data[0][0] = c2 * c3;
    result.data[0][1] =-c1 * s3 + s1 * s2 * s3;
    result.data[0][2] = s1 * s3 + c1 * s2 * c3;
    result.data[0][3] = 0;
    result.data[1][0] = c2 * s3;
    result.data[1][1] = c1 * c3 + c1 * s2 * s3;
    result.data[1][2] =-s1 * c3 + c1 * s2 * s3;
    result.data[1][3] = 0;
    result.data[2][0] =-s2;
    result.data[2][1] = s1 * c2;
    result.data[2][2] = c1 * c2;
    result.data[2][3] = 0;
    result.data[3][0] = 0;
    result.data[3][1] = 0;
    result.data[3][2] = 0;
    result.data[3][3] = 1;

    return result;
}
