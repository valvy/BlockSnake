/*
 * Copyright (c) 2015, Heiko van der Heijden
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef VECTOR4_HPP
#define VECTOR4_HPP

template<typename T>
struct Vector4{
    T x, y, z, w;
    Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w){}
    Vector4(){}
    
    Vector4<T>& operator=(Vector4<T> other){
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->w = other.w;
        return *this;
    }
    
    T inProduct(Vector4<T> other){
        return (this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w);
    }
    
    Vector4<T>& operator-(Vector4<T> other){
        this->x += -1 * other.x;
        this->y += -1 * other.y;
        this->z += -1 * other.z;
        this->w += -1 * other.w;
        return *this;
    }
    
    Vector4<T>& operator+(Vector4<T> other){
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        this->w += other.w;
        return *this;
    }
    
    Vector4<T>& operator* (T scale){
        this->x * scale;
        this->y * scale;
        this->z * scale;
        this->w * scale;
        return *this;
    }
    
    T dotProduct(Vector4<T> other){
        return(this->x * other.x + this->y * other.y + this->z * other.z * this->w * other.w);
    }
    
    T lenght(){
        return sqrt(pow(x,2) + pow(y,2) + pow(z, 2) + pow(w,2));
    }
    
    
};

#endif