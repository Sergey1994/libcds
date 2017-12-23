/*
    This file is a part of libcds - Concurrent Data Structures library

    (C) Copyright Maxim Khizhinsky (libcds.dev@gmail.com) 2006-2017

    Source code repo: http://github.com/khizmax/libcds/
    Download: http://sourceforge.net/projects/libcds/files/

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef CDSLIB_CONTAINER_TIMESTAMPED_DEQUE_HP_H
#define CDSLIB_CONTAINER_TIMESTAMPED_DEQUE_HP_H

#include <memory>

namespace cds { namespace container {

    /// BasketQueue related definitions
    /** @ingroup cds_nonintrusive_helper
    */
    namespace timestamped_deque {

        struct TimestampedItem
        {
            Element element;
            long timestamp;

            void setTimestamp(timestamp t) {
                timestamp = t;
            }
        };

        template <typename T, typename Traits>
        class TS_Deque {
            TS_Buffer buffer;

            public:
                typedef T  value_type;  ///< Type of value to be stored in the queue
                typedef Traits traits;  ///< Queue's traits

                void pushTop(Element element) {

                }

                Element popTop() {

                }

                // аналогично
                void pushBack(Element element) {

                }

                Element popBack() {

                }
        }

        template <typename T, typename Traits>
        class TS_Buffer {
            ThreadLocalBuffer tlBuffers[numThreads]; // массив ThreadLocalBuffer из всех потоков

            TimestampedItem insR (Element element) {} // добавить в голову(Top)

            TimestampedItem tryRemR () {} // удалить из головы(Top)

            TimestampedItem insL (Element element) {} // добавить в хвост(Back)

            TimestampedItem tryRemL () {} // удалить из хвоста(Back)

            bool isMoreR (TimestampedItem item1, TimestampedItem item2) {} // Вспомогательная функция

            bool isMoreL (TimestampedItem item1, TimestampedItem item2) {} // Вспомогательная функция

            long newTimestamp() {} // возвращает новый timestamp (скорее всего текущее время)

            void setTimestamp(TimestampedItem item, t) // устанавливает timestamp = t для item
        }

        template <typename T, typename Traits>
        class ThreadLocalBuffer {
            Node {
                Node* left,
                Node* right,
                TimestampedItem item,
                int index,
                bool taken
            };

            int nextIndex = 1;

            void init () {};

            void insRtl (TimestampedItem item) {}

            void insLtl (TimestampedItem item) {
                // Analogous to insRtl , but the index of a new node is initialized with ’ index =- nextIndex ’.
            }

            bool tryRemRtl (Node* oldRight, Node* node ) {}

            bool tryRemLtl (Node* oldRight, Node* node) {
             // Analogous to tryRemRtl .
            }

            TimestampedItem getRtl () {}

            TimestampedItem getLtl () {
            // Analogous to getRtl .
            }

        }
    };

}}  // namespace cds::container

#endif  // #ifndef CDSLIB_CONTAINER_TIMESTAMPED_DEQUE_HP_H
