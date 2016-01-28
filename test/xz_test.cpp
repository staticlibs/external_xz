/*
 * Copyright 2016, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   xz_test.cpp
 * Author: alex
 *
 * Created on January 28, 2016, 1:27 PM
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "lzma.h"

#include "staticlib/config/assert.hpp"

void test_lzma2() {
    std::string data{"hello lzma2"};
    std::vector<char> compressed;
    compressed.resize(192);
    {
        // compress
        lzma_stream strm = LZMA_STREAM_INIT;
        lzma_ret res_init = lzma_easy_encoder(std::addressof(strm), 2, LZMA_CHECK_CRC64);        
        slassert(LZMA_OK == res_init);

        strm.next_in = reinterpret_cast<const unsigned char*>(data.data());
        strm.avail_in = data.length();
        for(;;) {
            strm.next_out = reinterpret_cast<unsigned char*>(compressed.data());
            strm.avail_out = compressed.size();
            lzma_ret ret_xz = lzma_code(std::addressof(strm), LZMA_FINISH);
            if (ret_xz != LZMA_OK && ret_xz != LZMA_STREAM_END) {
                lzma_end(std::addressof(strm));
                throw std::runtime_error{"LZMA_FINISH failed"};
            }
            if (ret_xz == LZMA_STREAM_END) break;
        }
        lzma_end(std::addressof(strm));
        compressed.resize(strm.total_out);
        slassert(68 == compressed.size());
    }
    {
        // decompress
        std::string decompressed{};
        decompressed.resize(192);
        lzma_stream strm = LZMA_STREAM_INIT;
        lzma_ret res_dec_init = lzma_stream_decoder(std::addressof(strm), UINT64_MAX, 0);
        slassert(LZMA_OK == res_dec_init);
        strm.next_in = reinterpret_cast<const unsigned char*> (compressed.data());
        strm.avail_in = compressed.size();
        for (;;) {
            strm.next_out = reinterpret_cast<unsigned char*> (std::addressof(decompressed.front()));
            strm.avail_out = decompressed.size();
            lzma_ret ret_xz = lzma_code(std::addressof(strm), LZMA_FINISH);
            if (ret_xz != LZMA_OK && ret_xz != LZMA_STREAM_END) {
                lzma_end(std::addressof(strm));
                throw std::runtime_error{"LZMA_FINISH failed"};
            }
            if (ret_xz == LZMA_STREAM_END) break;
        }
        lzma_end(std::addressof(strm));
        decompressed.resize(strm.total_out);
        slassert(11 == decompressed.size());
        slassert(data == decompressed);
    }
}

int main() {
    try {
        test_lzma2();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
