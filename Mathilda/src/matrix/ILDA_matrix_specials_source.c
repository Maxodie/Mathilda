#ifdef __ILDA_MATRIX_SPECIAL_SOURCE_CHECK__
ILDA_STATIC_ASSERT(false, "ILDA MATRIX SOURCE : file is called but it was already on");
#endif

#define __ILDA_MATRIX_SPECIAL_SOURCE_CHECK__

//matrix4x4 only
ILDA_matrix4x4 ILDA_translate(const ILDA_matrix4x4* identity, const ILDA_vector3f* translation)
{
    ILDA_matrix4x4 mat4x4 = { .rowCount = 4, .colCount = 4, .data = { {0, 0, 0, translation->x}, {0, 0, 0, translation->y}, {0, 0, 0, translation->z}, {0, 0, 0, 0} } };
    ILDA_matrix4x4_add(&mat4x4, identity);

    return mat4x4;
}

ILDA_bool ILDA_scale(ILDA_matrix4x4* matrix4x4, const ILDA_vector3f* scale)
{
    ILDA_matrix4x4 result = { .rowCount = 4, .colCount = 4, .data = { {scale->x, 0, 0, 0}, {0, scale->y, 0, 0}, {0, 0, scale->z, 0}, {0, 0, 0, 1} } };
    ILDA_matrix4x4_mul_same(matrix4x4, &result);

    return ILDA_SUCCESS;
}

ILDA_matrix4x4 ILDA_rotation(float rotation, const ILDA_vector3f* vector3)
{
    float x = vector3->x, y = vector3->y, z = vector3->z;


    ILDA_matrix4x4 result = {
        .rowCount = 4,
        .colCount = 4,
        .data = {
            { cosf(rotation) + x * x * (1 - cosf(rotation)), x * y * (1 - cosf(rotation)) - z * sinf(rotation), x * z * (1 - cosf(rotation)) + y * sinf(rotation), 0 },
            { y * x * (1 - cosf(rotation)) + z * sinf(rotation), cosf(rotation) + y * y * (1 - cosf(rotation)), y * z * (1 - cosf(rotation)) - x * sinf(rotation), 0 },
            { z * x * (1 - cosf(rotation)) - y * sinf(rotation), z * y * (1 - cosf(rotation)) + x * sinf(rotation), cosf(rotation) + z * z * (1 - cosf(rotation)), 0 },
            { 0, 0, 0, 0 }
        }
    };

    return result;
}

//Look at target right handed for opengl TODO : left handed version for directX, Metal, Vulkan
INLINE_FUN ILDA_matrix4x4 ILDA_matrix_look_at_r(const ILDA_vector3f* position, const ILDA_vector3f* target, const ILDA_vector3f* worldUp)
{
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

    ILDA_matrix4x4 rotation = { .colCount = 4, .rowCount = 4, .data = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}} };
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