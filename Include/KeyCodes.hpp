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

#ifndef KEY_CODES_HPP
#define KEY_CODES_HPP


/*! All the different keycodes for the different operating systems
 *  @author Heiko van der Heijden
 */
namespace KeyCodes {
#ifdef __APPLE__

    constexpr unsigned short SPACE_BAR = 49;
    constexpr unsigned short UP_KEY = 126;
    constexpr unsigned short DOWN_KEY = 125;
    constexpr unsigned short LEFT_KEY = 124;
    constexpr unsigned short RIGHT_KEY = 123;
    constexpr unsigned short ESCAPE_KEY = 53;

#endif
#ifdef __linux__
    constexpr unsigned short SPACE_BAR = 65;
    constexpr unsigned short UP_KEY = 111;
    constexpr unsigned short DOWN_KEY = 116;
    constexpr unsigned short LEFT_KEY = 114;
    constexpr unsigned short RIGHT_KEY = 113;
    constexpr unsigned short ESCAPE_KEY = 9;

#endif

}


#endif

