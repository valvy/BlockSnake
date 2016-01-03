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
#ifndef MATRIX4X4_HPP
#define MATRIX4X4_HPP
#include "Vector4.hpp"
#include "Vector3.hpp"
#include <cmath>
#include <vector>
#include "Utilities.hpp"


enum class Axis{
    X,
    Y,
    Z,
};

/*! A 4 by 4 matrix data type
 *  @author Heiko van der Heijden
 *  This struct manages a 4 by 4 matrix.. and has all the basic calculations required by opengl
 */
template<typename T>
struct Matrix4x4{
    /*!
     *  All the rows stored in a Vector4, this is done so there are never any problems
     *  With the length and order of the Matrix
     */
    Vector4<T> row1,row2,row3,row4;
    
    /*!
     *  Initializes the matrix with a identity matrix. (all zeroes except the ones diagonal)
     */
    Matrix4x4(){
        row1 = Vector4<T>(1,0,0,0);
        row2 = Vector4<T>(0,1,0,0);
        row3 = Vector4<T>(0,0,1,0);
        row4 = Vector4<T>(0,0,0,1);
    }
    
    Matrix4x4(const Matrix4x4<T>& other){
        this->row1 = other.row1;
        this->row2 = other.row2;
        this->row3 = other.row3;
        this->row4 = other.row4;
    }
    
    Matrix4x4(Vector4<T> r1, Vector4<T> r2, Vector4<T> r3, Vector4<T> r4){
        this->row1 = r1;
        this->row2 = r2;
        this->row3 = r3;
        this->row4 = r4;
    }
    
    /*!
     *  Translates the matrix to
     *  @param vector, The vector you wish to translate to
     */
    void translate(Vector3<T> vector){
        row1.w += vector.x;
        row2.w += vector.y;
        row3.w += vector.z;
      
    }
    
    void setPosition(Vector3<T> vector){
        row1.w = vector.x;
        row2.w = vector.y;
        row3.w = vector.z;
    }
    
    Matrix4x4<T> transpose(){
        Matrix4x4<T> result;
        result.row1 = Vector4<T>(row1.x, row2.x, row3.x,row4.x);
        result.row2 = Vector4<T>(row1.y, row2.y,row3.y,row4.y);
        result.row3 = Vector4<T>(row1.z, row2.z, row3.z,row4.z);
        result.row4 = Vector4<T>(row1.w, row2.w,row3.w,row4.w);
        return result;
        
    }
    

    /*!
     *  Multiplies a matrix with an other matrix
     *  @param other, the matrix you wish to multiply with
     */
    Matrix4x4<T> operator*(Matrix4x4<T> other) const{
        //generate temporary matrix
        Matrix4x4<T> result;
        //Row 1
        result.row1.x = row1.x * other.row1.x + row1.y * other.row2.x + row1.z * other.row3.x + row1.w * other.row4.x;
        result.row1.y = row1.x * other.row1.y + row1.y * other.row2.y + row1.z * other.row3.y + row1.w * other.row4.y;
        result.row1.z = row1.x * other.row1.z + row1.y * other.row2.z + row1.z * other.row3.z + row1.w * other.row4.z;
        result.row1.w = row1.x * other.row1.w + row1.y * other.row2.w + row1.z * other.row3.w + row1.w * other.row4.w;
        
        //Row2
        result.row2.x = row2.x * other.row1.x + row2.y * other.row2.x + row2.z * other.row3.x + row2.w * other.row4.x;
        result.row2.y = row2.x * other.row1.y + row2.y * other.row2.y + row2.z * other.row3.y + row2.w * other.row4.y;
        result.row2.z = row2.x * other.row1.z + row2.y * other.row2.z + row2.z * other.row3.z + row2.w * other.row4.z;
        result.row2.w = row2.x * other.row1.w + row2.y * other.row2.w + row2.z * other.row3.w + row2.w * other.row4.w;
        
        //Row3
        result.row3.x = row3.x * other.row1.x + row3.y * other.row2.x + row3.z * other.row3.x + row3.w * other.row4.x;
        result.row3.y = row3.x * other.row1.y + row3.y * other.row2.y + row3.z * other.row3.y + row3.w * other.row4.y;
        result.row3.z = row3.x * other.row1.z + row3.y * other.row2.z + row3.z * other.row3.z + row3.w * other.row4.z;
        result.row3.w = row3.x * other.row1.w + row3.y * other.row2.w + row3.z * other.row3.w + row3.w * other.row4.w;
        
        //Row4
        result.row4.x = row4.x * other.row1.x + row4.y * other.row2.x + row4.z * other.row3.x + row4.w * other.row4.x;
        result.row4.y = row4.x * other.row1.y + row4.y * other.row2.y + row4.z * other.row3.y + row4.w * other.row4.y;
        result.row4.z = row4.x * other.row1.z + row4.y * other.row2.z + row4.z * other.row3.z + row4.w * other.row4.z;
        result.row4.w = row4.x * other.row1.w + row4.y * other.row2.w + row4.z * other.row3.w + row4.w * other.row4.w;
        
        return result;
    }
    
    /*!
     *  set the data from the other matrix in itself
     *  @param other, the matrix you wish to set as this
     */
    Matrix4x4<T>& operator=(Matrix4x4 other){
        this->row1 = other.row1;
        this->row2 = other.row2;
        this->row3 = other.row3;
        this->row4 = other.row4;
        return *this;
    }
    
    Matrix4x4<T>& operator*=(Matrix4x4 other){
        Matrix4x4 <T> result = Matrix4x4<T>(row1,row2,row3,row4) * other;
        this->row1 = result.row1;
        this->row2 = result.row2;
        this->row3 = result.row3;
        this->row4 = result.row4;
        
        return *this;
    }
    
    
    
    /*!
     *  Rotates the matrix around an given axis.
     *  @param angle, the degrees you want to rotate
     *  @param axis, The axis you wish to rotate around
     */
    void rotate(T angle, Axis axis){
        angle = angle * Math::PI / 180; //convert degrees to radians
        
        switch(axis){
            case Axis::X:
                this->row2.y = cos(angle); this->row2.z = sin(angle);
                this->row3.y = -sin(angle); this->row3.z = cos(angle);
                return;
            case Axis::Y:
                this->row1.x = cos(angle); this->row1.z = sin(angle);
                this->row3.x = -sin(angle); this->row3.z = cos(angle);
                return;
            case Axis::Z:
                this->row1.x = cos(angle); this->row1.y = sin(angle);
                this->row2.y = -sin(angle); this->row2.y = cos(angle);
                return;
        }

    }
    
    /*!
     *  Mirrors the matrix with two given axis
     *  @param a, the first axis you want to swap
     *  @param b, the second axis you want to swap
     */
    void mirror(Axis a, Axis b){
        if((a == Axis::X && b == Axis::Y) ||
           (a == Axis::Y && b == Axis::X)){
            
            Vector4<T> tmp = row1;
            row1 = row2;
            row2 = tmp;
            return;
        }
        else if((a == Axis::X && b == Axis::Z) ||
                (a == Axis::Z && b == Axis::X)){
            
            Vector4<T> tmp = row1;
            row1 = row3;
            row3 = tmp;
            return;
        }
        else if((a == Axis::Y && b == Axis::Z) ||
                (a == Axis::Z && b == Axis::Y)){
            
            Vector4<T> tmp = row2;
            row2 = row3;
            row3 - tmp;
            return;
        }
    }
    
    /*!
     *  Get all the data in an Vector
     *  @return rawData The vector with all the row data
     */
    std::vector<T> getRawData() const{
        return{
            row1.x,row1.y,row1.z,row1.w,
            row2.x,row2.y,row2.z,row2.w,
            row3.x,row3.y,row3.z,row3.w,
            row4.x,row4.y,row4.z,row4.w
        };
    }
    
    
    /*!
     *  Scales the matrix with given vector
     *  @param s The vector you wish to scale with
     */
    void scale(Vector3<T> s){
        this->row1.x *= s.x;
        this->row2.y *= s.y;
        this->row3.z *= s.z;
    }
    

    
};

#endif
