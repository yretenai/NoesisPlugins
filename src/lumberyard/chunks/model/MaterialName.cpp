//
// Created by yretenai on 6/2/2020.
//

#include "MaterialName.h"

MaterialName::MaterialName(vector<char> buffer) {
    char* ptr = buffer.data();
    Name = string(ptr, ptr + 0x80);
    ptr += 0x80;
    uint32_t count = vector_cast<uint32_t>(&ptr);
    Types = vector_cast_slice<int32_t>(&ptr, count);
    Materials = vector<string>(count);
    if(count == 1) {
        Materials[0] = Name;
    } else {
        for(int i = 0; i < count; i++) {
            string material(ptr);
            Materials[i] = material;
            ptr += material.size() + 1;
        }
    }
}
